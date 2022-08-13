/**
 * @File contents: SudokuFitness class's functions and data members
 * 
 * @Purpose: Work in conjuction with Sudoku to evaluate Sudoku 
 * class's "board" data member and evaulate the two dimensional 
 * vector's amount of repeating numbers per row, column, and 3x3
 * square block. This class then gives back an int which is stored
 * in Sudoku class object's "fitnessScore" data member.
 * 
 * @Assumptions: Sudoku and parent-class puzzle are completed with 
 * necessary data members and function calls. As well as active 
 * parent class Fitness is also completed.
 * 
 * @Authors: Amanda Todakonzie, Logan Hoskisson, Adriel Mercado
 * 
 */
#ifndef SUDOKUFITNESS_H
#define SUDOKUFITNESS_H
#include "fitness.h"
#include <limits.h>
#include <set>
#include "sudoku.h"
#include <vector>


class SudokuFitness : public Fitness {

public:
   SudokuFitness(); // Default constructor
   virtual ~SudokuFitness(); // Destructor
   virtual int howFit(Puzzle& aPuzzle) const; // howFit method

};

#endif
