/**
 * @File contents: Fitness class functions and data members
 * 
 * @Purpose: The fitness class operate in conjuction with puzzle and ultimately 
 * with sudoku to check the sudoku classes's "board" data member on the "board's"
 * fitness level and then provide an int for that same object's fitnessScore data 
 * member. This is used to determine the level of completion for the sudoku puzzle.
 * 0 = complete and solved sudoku.
 * 
 * @Assumptions: That derived class SudokuFitness is finished and defined
 * 
 * @Authors: Amanda Todakonzie, Logan Hoskisson, Adriel Mercado
 */
#ifndef FITNESS_H
#define FITNESS_H
#include "puzzle.h"
#include "sudoku.h"
#include <vector>

class Fitness {

public:
   Fitness(); // Default constructor
   virtual ~Fitness(); // Destructor
   virtual int howFit(Puzzle& aPuzzle) const = 0; // Pure virtual howFit method

};

#endif
