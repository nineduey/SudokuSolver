/*
@File contents: SudokuFactory function declarations

@Purpose: Creates and returns a new Sudoku object by calling on 
 the Reproduction class object contained within the Parent class Reproduction
 to create it. 

@Assumptions: Parent Class Puzzle Factory is defined. Classes Puzzle
 and Sudoku are defined. 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#ifndef SUDOKUFACTORY_H
#define SUDOKUFACTORY_H
#include "puzzle.h"
#include "puzzlefactory.h"
#include "sudokuoffspring.h"
#include "sudoku.h"
#include <unordered_map>
#include <vector>

class SudokuFactory : public PuzzleFactory {

public:

	SudokuFactory(); // Default Constructor
	virtual ~SudokuFactory(); // Destructor
	virtual Puzzle* createPuzzle() ; // createPuzzle method
	virtual Puzzle* createOffSpring(Puzzle& aPuzzle) const ; //create offSpring method

};

#endif