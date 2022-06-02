#ifndef SUDOKU_POPULATION_H
#define SUDOKU_POPULATION_H
#include "population.h"
#include "sudoku.h"
#include "sudokufactory.h"
#include "sudokufitness.h"
#include "sudokuoffspring.h"
#include <queue>
#include <limits>
#include <utility>
#include <stdlib.h>
#include <time.h>

class SudokuPopulation : public Population
{
private:
   bool culled = false;
   int bestFitnessScore = std::numeric_limits<int>::max();
   Puzzle* bestSudoku = nullptr;

   class compareFitness
   {
   public:
      bool operator()(Sudoku* a, Sudoku* b)
      {
         return *a > *b;
      }
   };
   std::priority_queue<Sudoku*, std::vector<Sudoku*>, compareFitness> mostFit;

public:

   SudokuPopulation(const Puzzle& initialPuzzle);
   SudokuPopulation(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage);
   virtual ~SudokuPopulation();
   virtual void generate();
   virtual int bestFitness() const;
   virtual Puzzle* bestIndividual() const;
   virtual void newGeneration(const PuzzleFactory& factory);
   virtual void cull(const Fitness& fitnessModel);
};
#endif