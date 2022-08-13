/*
@File contents: Sudoku class data member and function declarations

@Purpose: Sudoku is a derived class of Puzzle. Sudoku holds the board data within
a vector of vectors of integers, ( a 2 dimensional vector). Sudoku class also holds
an integer to store the fitness score of its board, and a mirror board, a vector
of vectors of boolean values that is used to look up spaces in the board that are 
filled with fixed values from the original board data that is imported prior to solving
the puzzle

@Assumptions: Parent class Puzzle is defined. 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <limits.h>
#include "puzzle.h"
#include <string>
#include <vector>
using namespace std;

class Sudoku : public Puzzle {


public:
	Sudoku(); 								// Default Constructor
	virtual ~Sudoku(); 						// Destructor
	virtual Puzzle* create() const; 		// create method
	virtual void importData(istream& in);	// import data into board method
	virtual void printPuzzle(ostream& out) const; // print board
	virtual void quickPrint() const; 		// quick print will print board as string
	virtual void setFitness(int score); 	// method to change the fitnessScore variable
	virtual int getFitScore() const; 		// method to retrieve the fitnessScore variable
	virtual void setVal(int x, int y, int value); // method to change the value of the x,y on the board
	virtual int getVal(int x, int y) const; // method to retrieve the value of the x,y on the board
	virtual vector<vector<int>> getBoard() const; // method to retrive the board as a vector<vector<int>> object
	virtual bool isFixed(int x, int y) const; // method to return boolean value that indicated an original board value


	// virtual comparison operators
	virtual Puzzle& operator=(const Puzzle&);
	virtual bool operator<(const Puzzle&) const;
	virtual bool operator>(const Puzzle&) const;
	virtual bool operator==(const Puzzle&) const;
	virtual bool operator!=(const Puzzle&) const;

protected:

	int fitnessScore; // integer variable that holds the fitness score of the board
	vector<vector<int>> board; // the board represented as a 2D vector of integers
	vector <vector<bool>> fixedSpaces; // a mirror board that reflects which spaces are fixed original values
};

#endif

