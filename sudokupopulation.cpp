/*
@File contents: Sudoku Population class function definitions

@Purpose: The Sudoku class is a derived class of Population and serves as a container
for Sudoku objects. It stores Sudoku objects within a vector of Puzzle pointers within
the Population parent class. The SudokuPopulation class holds the priority queue used for
culling the population, as well as the best score reached and the puzzle instance with the
best score. All the virtual functions declared in the parent class Population are 
define in the SudokuPopulation.cpp

@Assumptions: Its parent class Population is defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "sudokupopulation.h"



//----------------------------------------------------------------------------
// SudokuPopulation(): Constructor with just initial puzzle 
// @pre: An intial sudoku constructed 
// @post: A population initialized
SudokuPopulation::SudokuPopulation(const Puzzle& initialPuzzle) :
   Population(initialPuzzle)
{
   generate();
}

//----------------------------------------------------------------------------
// SudokuPopulation(): Constructor with initial sudoku, size and cull percentage 
// @pre: An intial sudoku constructed
// @post: A population initialized with the given size
SudokuPopulation::SudokuPopulation(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage) :
   Population(initialPuzzle, size, cullPercentage)
{
   generate();
}

//----------------------------------------------------------------------------
// ~Population(): sudoku population destructor 
// @pre: none 
// @post: all sudokus in population are freed from memory 
SudokuPopulation::~SudokuPopulation()
{
   //int size = population.size();
   //for (int i = 0; i < size; i++)
   //{
      //delete population.back();
      //population.back() = nullptr;
      //population.pop_back();
   //}

   for (vector<Puzzle*>::iterator i = population.begin(); i != population.end(); ++i) {
      delete* i;
   }
}

//----------------------------------------------------------------------------
// generate(): generates initial population 
// @pre: size must be initialized 
// @post: "size" sudokus are created 
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
      *s = initialPuzzle;
      for (int j = 0; j < emptyPoints.size(); j++)
      {
         int x = std::get<0>(emptyPoints[j]);
         int y = std::get<1>(emptyPoints[j]);

         int val = rand() % 9 + 1;
         s->setVal(x, y, val);
      }
      population.push_back(s);
   }
   culled = false;
}

//----------------------------------------------------------------------------
// bestFitness(): returns the best fitness score from the current population 
// @pre: cull must have been called 
// @post: none 
int SudokuPopulation::bestFitness() const
{
   return bestFitnessScore;
}

//----------------------------------------------------------------------------
// bestIndividual(): returns the best sudoku from the current population 
// @pre: cull must have been called 
// @post: none
Puzzle* SudokuPopulation::bestIndividual() const
{
   return bestSudoku;
}

//----------------------------------------------------------------------------
// newGeneration(): creates a new generation after cull has been called 
// @pre: cull has been called 
// @post: population is back to its full size 
void SudokuPopulation::newGeneration(const PuzzleFactory& factory)
{
   int currPopSize = population.size();
   int offSpringToProduce = size * (1-(cullPercentage / 100));
   // save current culled population into oldGeneration vector
   vector<Puzzle*> oldGeneration = population;
   population.clear();

   while(population.size() != offSpringToProduce)
   {
      // create "offSpringToProduce" number for each puzzle within the old generation
      // this number is based on the size multiplied by the cullPercentage
      for (int i = 0; i < currPopSize; i++)
      {
         // push new offspring puzzle into population
         population.push_back(factory.createOffSpring(*oldGeneration[i]));
      }
   }

   // delete old generation;

   for (vector<Puzzle*>::iterator i = oldGeneration.begin(); i != oldGeneration.end(); ++i) {
      delete* i;
   }


   culled = false;
}

//----------------------------------------------------------------------------
// cull(): removes cullPercentage percent of the population keeping those with the best fitness 
// @pre: generate or newGeneration should have been called before 
// @post: population is reduced to cullPercentage of is original size and contains the most fit sudokus
//                 of the previous population 
void SudokuPopulation::cull(const Fitness& fitnessModel)
{
   int popSize = population.size();
   //evaluate fitness of each possible solution and add to max heap
   for (int i = 0; i < popSize; i++)
   {
      Sudoku* s = static_cast<Sudoku*>(population.back());
      population.pop_back();
      if (s != nullptr)
      {
         //cout << *s << endl;
         int fitness = fitnessModel.howFit(*s);
         s->setFitness(fitness);
         mostFit.push(make_pair(fitness, s));

         //check if best fitness
         if (fitness < bestFitnessScore)
         {
            bestFitnessScore = fitness;
            bestSudoku = s;
         }
      }
   }

   //remove cullAmount from the population
   int discardAmount = mostFit.size() * (1 - (cullPercentage / 100));
   for (int i = 0; i < discardAmount; i++)
   {
      delete mostFit.top().second;
      mostFit.pop();
   }

   int mostFitSize = mostFit.size();

   //place remaining sudokus back into population
   for (int i = 0; i < mostFitSize; i++)
   {
      Puzzle* aPuzz = mostFit.top().second;
      population.push_back(aPuzz);
      mostFit.pop();
   }

   culled = true;
}
