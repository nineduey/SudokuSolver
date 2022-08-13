/*
@File contents: Reproduction data member and function declarations

@Purpose: Reproduction uses a factory pattern to produce new Sudoku objects that
 are empty boards. Child Class SudokuOffSpring handles the reproduction of mutated
 Sudoku objects based on Sudoku objects handed off by reference. 

@Assumptions: Child Class SudokuOffSpring is defined. Classes Puzzle and Sudoku are defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/

#ifndef REPRODUCTION_H
#define REPRODUCTION_H
#include "puzzle.h"
#include "sudoku.h"
#include <unordered_map>
using namespace std;

class Reproduction {

public:
	// Default Constructor
	Reproduction();
	// Destructor
	virtual ~Reproduction();

	// createSudoku():
	Puzzle* createSudoku() const;

	// virtual makeOffSpring() that will produce a mutated Puzzle object based on
	// the Puzzle passed in by reference
	virtual Puzzle* makeOffSpring(Puzzle& aPuzzle) const = 0;


protected:
	// HashMap with keys equal to char variables of every
	// possible puzzle type and values equal to integers
	// ranging from 0  to the number of puzzle types - 1.
	unordered_map<char, int> puzzleMap;

	// Vector with elements that are initialized as new
	// Puzzle objects of every possible puzzle subtype
	vector<Puzzle*> puzzleFac;
};

#endif

