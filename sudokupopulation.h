
/*
@File contents: Sudoku Population class data member and function declarations

@Purpose: The Sudoku class is a derived class of Population and serves as a container
for Sudoku objects. It stores Sudoku objects within a vector of Puzzle pointers within
the Population parent class. The SudokuPopulation class holds the priority queue used for
culling the population, as well as the best score reached and the puzzle instance with the
best score. All the virtual functions declared in the parent class Population are 
define in the SudokuPopulation.cpp

@Assumptions: Its parent class Population is defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/

#ifndef SUDOKU_POPULATION_H
#define SUDOKU_POPULATION_H
#include "population.h"
#include "sudoku.h"
#include "sudokufactory.h"
#include "sudokufitness.h"
#include <queue>
#include <limits>
#include <utility>
#include <stdlib.h>
#include <time.h>

class SudokuPopulation : public Population
{
   // typedefined pair of variable used in the priority queue for cull()
   typedef pair<int, Sudoku*> puzzPair;

private:
   bool culled = false; // boolean value that stores the status of culled or not culled
   // the integer that stores the best score of a sudoku instance
   int bestFitnessScore = std::numeric_limits<int>::max(); 
   // a Puzzle pointer that stores the memory location of the best sudoku instance
   Puzzle* bestSudoku = nullptr;
   // priority queue that assists with culling the population
   std::priority_queue<puzzPair> mostFit;

public:

//----------------------------------------------------------------------------
// SudokuPopulation(): Constructor with just initial puzzle 
// Pre-conditions: An intial sudoku constructed 
// Post-conditions: A population initialized
   SudokuPopulation(const Puzzle& initialPuzzle);

//----------------------------------------------------------------------------
// SudokuPopulation(): Constructor with initial sudoku, size and cull percentage 
// Pre-conditions: An intial sudoku constructed
// Post-conditions: A population initialized with the given size
   SudokuPopulation(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage);

//----------------------------------------------------------------------------
// ~Population(): sudoku population destructor 
// Pre-conditions: none 
// Post-conditions: all sudokus in population are freed from memory 
   ~SudokuPopulation();

//----------------------------------------------------------------------------
// generate(): generates initial population 
// Pre-conditions: size must be initialized 
// Post-conditions: "size" sudokus are created 
   virtual void generate();

//----------------------------------------------------------------------------
// bestFitness(): returns the best fitness score from the current population 
// Pre-conditions: cull must have been called 
// Post-conditions: none 
   virtual int bestFitness() const;

//----------------------------------------------------------------------------
// bestIndividual(): returns the best sudoku from the current population 
// Pre-conditions: cull must have been called 
// Post-conditions: none
   virtual Puzzle* bestIndividual() const;

//----------------------------------------------------------------------------
// newGeneration(): creates a new generation after cull has been called 
// Pre-conditions: cull has been called 
// Post-conditions: population is back to its full size 
   virtual void newGeneration(const PuzzleFactory& factory);

//----------------------------------------------------------------------------
// cull(): removes cullPercentage percent of the population keeping those with the best fitness 
// Pre-conditions: generate or newGeneration should have been called before 
// Post-conditions: population is reduced to cullPercentage of is original size and contains the most fit sudokus
//                 of the previous population 
   virtual void cull(const Fitness& fitnessModel);
};
#endif
