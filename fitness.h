#ifndef FITNESS_H
#define FITNESS_H
#include "puzzle.h"
#include "sudoku.h"
#include <vector>

class Fitness {

public:
   Fitness();
   virtual ~Fitness();
   virtual int howFit(Puzzle& aPuzzle) const = 0;

};

#endif