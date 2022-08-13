/*
@File contents: PuzzleSolver data member and function delarations

@Purpose: To instantiate SudokuFactory and SudokuFitness objects that will
 take in text data to be pcocessed and instantiate a Sudoku object containing
 a board of the text data provided. PuzzleSolver acts as a manager of the objects
 in order to solve the Sudoku puzzle provided.

@Assumptions: Puzzle & subclasses, Population & subclasses, Fitness & subclasses,
and Reproduction and subclasses are defined. Text data to be imported is assumed to contain
no erroneous data and is formatting properly.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
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

	PuzzleSolver(); // Default Constructor
	~PuzzleSolver(); // Destructor

//----------------------------------------------------------------------------
// loadPuzzle(): reads in puzzle data and builds a new puzzle object based
// on the data imported from a text file. This puzzle object created will be
// kept in memory as the "origin puzzle", for tracking and referencing
// througout the program
// @pre:
// @post:
	void loadPuzzle(istream&);

//----------------------------------------------------------------------------
// solve(): function will take the origin puzzle and initiate the program to 
// to generate a popuation of sudoku puzzles and proceed to evaluate each puzzle
// using the fitness object's evaluation algorithm.
// @pre: function takes three integers that represent the number of generations desired, 
// the population size and the cull percentage of the population
// @post: the original sudoku puzzle is solved and will store the pointer to the solved
// board within the data member "solvedBoard"
	void solve(int generations, int populationSize, int cullPercentage);
	
//----------------------------------------------------------------------------
// displayBoard(): function will send a output to the console to display the
// origina puzzle and puzzle that is contained within the population that
// possesses the best fitness score of the whole generation
// @pre:
// @post:
	void displayBoard();
	
	void reset();

//----------------------------------------------------------------------------
// Test functions to test phases of algorithm
// Testing Puzzle & Sudoku classes
	void testPuzzAndSudoku();
// Testing Population object and generation of first population
	void testFirstGeneration();
// Testing Population, Fitness and Reproduction Objects
	void testOffSpring();

private:
	
	// origin puzzle built from data imported via istream
	Puzzle* originBoard;
	Puzzle* solvedBoard;

	// Sudoku Factory object that will produce new and mutated Sudoku objects
	SudokuFactory puzzFac;
	// Fitness object that will be used to evaluate the population object that contains
	// a generation of sudoku puzzle objects
	SudokuFitness puzzEval;
};
#endif