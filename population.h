/*
@File contents: Population class data member and function declarations

@Purpose: The Population class serves as an abstract class for its derived
class Sudoku Population and as a container for Sudoku objects. It stores Sudoku
objects withina vector of Puzzle pointers. Population instantiates const 
variables that represent the size of population, the cull percentage, and the
cull amount. The population stores a Puzzle object that holds the origin
board's values. The popluation constructor is responsible for generating the first
population of Sudoku objects based on the intial puzzle passed in, as well as setting
its const variables size, cullPercentage, and cullAmount. Its virtual functions 
are defined in its child class SudokuPopulation.

@Assumptions: Its derived class SudokuPopulation class is defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/

#ifndef POPULATION_H
#define POPULATION_H
#include "puzzle.h"
#include "puzzlefactory.h"
#include "fitness.h"
#include "reproduction.h"
#include <cstdint>
#include <vector>

#define POPULATION_SIZE_DEFAULT 10000
#define POPULATION_CULL_PERCENTAGE_DEFAULT 1

class Population
{
protected:
   const uint32_t size;
   const float cullPercentage;
   const uint32_t cullAmount;
   const Puzzle& initialPuzzle;
   std::vector<Puzzle*> population;

public:

//----------------------------------------------------------------------------
// Population(): Constructor with just initial puzzle 
// Pre-conditions: An intial puzzle constructed 
// Post-conditions: A population initialized
   Population(const Puzzle& initialPuzzle) :
      initialPuzzle(initialPuzzle), size(POPULATION_SIZE_DEFAULT),
      cullPercentage(POPULATION_CULL_PERCENTAGE_DEFAULT),
      cullAmount((uint32_t)size* (1 - (cullPercentage / 100)))
   {
   }

//----------------------------------------------------------------------------
// Population(): Constructor with initial puzzle, size and cull percentage 
// Pre-conditions: An intial puzzle constructed
// Post-conditions: A population initialized with the given size
   Population(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage) :
   initialPuzzle(initialPuzzle), size(size), cullPercentage(cullPercentage),
   cullAmount((uint32_t) size * (cullPercentage / 100))
   {
   }

//----------------------------------------------------------------------------
// ~Population(): pure virtual destructor 
// Pre-conditions: none 
// Post-conditions: none
   virtual ~Population() = default;

//----------------------------------------------------------------------------
// generate(): generates initial population 
// Pre-conditions: size must be initialized 
// Post-conditions: "size" puzzles are created 
   virtual void generate() = 0;

//----------------------------------------------------------------------------
// bestFitness(): returns the best fitness score from the current population 
// Pre-conditions: cull must have been called 
// Post-conditions: none 
   virtual int bestFitness() const = 0;

//----------------------------------------------------------------------------
// bestIndividual(): returns the best puzzle from the current population 
// Pre-conditions: cull must have been called 
// Post-conditions: none
   virtual Puzzle* bestIndividual() const = 0;

//----------------------------------------------------------------------------
// newGeneration(): creates a new generation after cull has been called 
// Pre-conditions: cull has been called 
// Post-conditions: population is back to its full size 
   virtual void newGeneration(const PuzzleFactory& factory) = 0;

//----------------------------------------------------------------------------
// cull(): removes cullPercentage percent of the population keeping those with the best fitness 
// Pre-conditions: generate or newGeneration should have been called before 
// Post-conditions: population is reduced to cullPercentage of is original size and contains the most fit puzzles
//                 of the previous population 
   virtual void cull(const Fitness& fitnessModel) = 0;
};
#endif
