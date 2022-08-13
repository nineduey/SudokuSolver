/*
@File contents: PuzzleFactory data members and function declarations

@Purpose: PuzzleFactory is an abstract class that contains a Reproduction
 object that will produce new and mutated Sudoku objects

@Assumptions: Child Class SudokuFactory is defined and Classes Puzzle & Sudoku
are defined

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#ifndef PUZZLEFACTORY_H
#define PUZZLEFACTORY_H
#include "puzzle.h"
#include <map>
#include <string>
#include "sudokuoffspring.h"
#include "reproduction.h"
#include <vector>
using namespace std;


class PuzzleFactory {

	friend Reproduction;

public:

	PuzzleFactory(); // default constructor
	virtual ~PuzzleFactory(); // destructor
	virtual Puzzle* createPuzzle() = 0;
	virtual Puzzle* createOffSpring(Puzzle& aPuzzle) const = 0;

protected:
	//Reproduction object that will produce new puzzles and mutated puzzles
	SudokuOffSpring sudokuReproducer;
};

#endif
