#include "sudokupopulation.h"


SudokuPopulation::SudokuPopulation(const Puzzle& initialPuzzle) :
   Population(initialPuzzle)
{
   generate();
}

SudokuPopulation::SudokuPopulation(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage) :
   Population(initialPuzzle, size, cullPercentage)
{
   generate();
}

SudokuPopulation::~SudokuPopulation()
{
   int size = population.size();
   for (int i = 0; i < size; i++)
   {
      delete population.back();
      population.pop_back();
   }
}

void SudokuPopulation::generate()
{
   //find empty points
   std::vector<std::pair<int, int>> emptyPoints;
   for (int x = 0; x < 9; x++)
      for (int y = 0; y < 9; y++)
         if (initialPuzzle.getVal(x, y) == 0)
            emptyPoints.emplace_back(x, y);

   //generate initial population
   srand(time(NULL));
   for (int i = 0; i < size; i++)
   {
      Puzzle* s = new Sudoku();
      for (int j = 0; j < emptyPoints.size(); j++)
      {
         int x = std::get<0>(emptyPoints[j]);
         int y = std::get<1>(emptyPoints[j]);

         s->setVal(x, y, rand() % 9 + 1);
      }
      population.push_back(s);
   }
   culled = false;
}

int SudokuPopulation::bestFitness() const
{
   return bestFitnessScore;
}

Puzzle* SudokuPopulation::bestIndividual() const
{
   return bestSudoku;
}

void SudokuPopulation::newGeneration(const PuzzleFactory& factory)
{
   while (population.size() != size)
   {
      for (int i = 0; i < size - cullAmount; i++)
      {
         population.push_back(factory.createOffSpring(*population[i]));
         if (population.size() == size)
            break;
      }
   }
   culled = false;
}

void SudokuPopulation::cull(const Fitness& fitnessModel)
{
   //evaluate fitness of each possible solution and add to max heap
   for (int i = 0; i < population.size(); i++)
   {
      Sudoku* s = static_cast<Sudoku*>(population.back());
      population.pop_back();
      if (s != nullptr)
      {
         int fitness = fitnessModel.howFit(*s);
         s->setFitness(fitness);
         mostFit.push(s);

         //check if best fitness
         if (fitness < bestFitnessScore)
         {
            bestFitnessScore = fitness;
            bestSudoku = s;
         }
      }
      else
         throw "bad cast"; //remove after testing
   }

   //remove cullAmount from the population 
   for (int i = 0; i < cullAmount; i++)
   {
      delete mostFit.top();
      mostFit.pop();
   }

   //place remaining sudokus back into population 
   for (int i = 0; i < mostFit.size(); i++)
   {
      population.insert(population.begin(), mostFit.top());
      mostFit.pop();
   }
   culled = true;
}