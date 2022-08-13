/*
@File contents: SudokuOffSpring class function declarations

@Purpose: SudokuOffSpring is an object that handles producing a new Sudoku
 object with a board that has been changed (mutated) from another Sudoku object that
 is passed in by reference to its makeOffSpring() function

@Assumptions: Parent class Reprodution has been defined and Sudoku objects being 
 passed in contain valid board values 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#ifndef SUDOKUOFFSPRING_H
#define SUDOKUOFFSPRING_H
#include "puzzle.h"
#include "reproduction.h"
#include <set>
#include <string>
#include "sudoku.h"
#include <time.h>

using namespace std;

class SudokuOffSpring : public Reproduction {

public:
	SudokuOffSpring(); // default constructor
	virtual ~SudokuOffSpring(); // destructor
	virtual Puzzle* makeOffSpring(Puzzle& aPuzzle) const; // makeoffSpring method to reproduce Sudokus
	void mutate(Puzzle& aPuzzle) const; // mutate method
};

#endif