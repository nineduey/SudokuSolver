#ifndef POPULATION_H
#define POPULATION_H
#include "puzzle.h"
#include "puzzlefactory.h"
#include "fitness.h"
#include "reproduction.h"
#include <cstdint>
#include <vector>

#define POPULATION_SIZE_DEFAULT 10000
#define POPULATION_CULL_PERCENTAGE_DEFAULT 10

class Population
{
protected:
   const uint32_t size;
   const float cullPercentage;
   const uint32_t cullAmount;
   const Puzzle& initialPuzzle;
   std::vector<Puzzle*> population;

public:

   Population(const Puzzle& initialPuzzle) :
      initialPuzzle(initialPuzzle), size(POPULATION_SIZE_DEFAULT),
      cullPercentage(POPULATION_CULL_PERCENTAGE_DEFAULT),
      cullAmount((uint32_t)size* (cullPercentage / 100))
   {
      population.resize(size);
   }

   Population(const Puzzle& initialPuzzle, uint32_t size, float cullPercentage) :
      initialPuzzle(initialPuzzle), size(size), cullPercentage(cullPercentage),
      cullAmount((uint32_t)size* (cullPercentage / 100))
   {
      population.resize(size);
   }

   virtual ~Population();
   virtual void generate() = 0;
   virtual int bestFitness() const = 0;
   virtual Puzzle* bestIndividual() const = 0;
   virtual void newGeneration(const PuzzleFactory& factory) = 0;
   virtual void cull(const Fitness& fitnessModel) = 0;
};
#endif