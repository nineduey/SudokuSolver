#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include "fitness.h"
#include "population.h"
#include "puzzlefactory.h"
#include "sudokufactory.h"
#include "sudokupopulation.h"
#include "reproduction.h"
#include <iostream>

class PuzzleSolver {


public:

	PuzzleSolver();
	~PuzzleSolver();

//----------------------------------------------------------------------------
// loadPuzzle(): reads in puzzle data and builds a new puzzle object based
// on the data imported from a text file. This puzzle object created will be
// kept in memory as the "origin puzzle", for tracking and referencing
// througout the program
	void loadPuzzle(istream&);


//----------------------------------------------------------------------------
// solve(): function will take the origin puzzle and initiate the program to 
// to generate a popuation of sudoku puzzles and proceed to evaluate each puzzle
// using the fitness object's evaluation algorithm. 
	void solve(Puzzle& origin);

//----------------------------------------------------------------------------
// displayBoard(): function will send a output to the console to display the
// origina puzzle and puzzle that is contained within the population that
// possesses the best fitness score of the whole generation
	void displayBoard();

	void testPuzzAndSudoku();
	void testFirstGeneration();
	void testOffSpring();

private:
	
	// origin puzzle built from data imported via istream
	Puzzle* originBoard;
	Puzzle* solvedBoard;

	SudokuFactory puzzFac;

	// Fitness object that will be used to evaluate the population object that contains
	// a generation of sudoku puzzle objects
	SudokuFitness puzzEval;
};
#endif