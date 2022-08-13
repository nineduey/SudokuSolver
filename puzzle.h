/*
@File contents: Puzzle class data member and function declarations

@Purpose: The Puzzle class serves as an abstract class for its derived
class Sudoku. A char variable indicating the puzzle type is stored in 
the puzzle class for puzzle factory purposes. 

@Assumptions: Its derived class Sudoku class is defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#ifndef PUZZLE_H
#define PUZZLE_H
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

class Puzzle {
	// ostream << operator method
	friend ostream &operator<<(ostream& out, const Puzzle& aPuzzle);
	// istream >> operator method
	friend istream &operator>>(istream& in, Puzzle& aPuzzle);

public:
	Puzzle(); 		   							// Default constructor
	virtual ~Puzzle(); 							// Destructor
	virtual Puzzle* create() const = 0; 		// virtual create method
	virtual void importData(istream& in) = 0;	// virtual import data method
	virtual void printPuzzle(ostream& out) const = 0; // virtual print method
	virtual void quickPrint() const = 0;		// virtual quick print method
	virtual void setFitness(int score) = 0;		// virtual set fitness score method
	virtual int getFitScore() const = 0;		// virtual get fitness score method
	virtual void setVal(int x, int y, int value) = 0; // virtual set value method
	virtual int getVal(int x, int y) const = 0;	// virtual get value method
	virtual vector<vector<int>> getBoard() const = 0; // get board method
	virtual bool isFixed(int x, int y) const = 0; // virtual method to see if value is fixed
	char getType(); 							// get puzzle type method

	//virtual comparison operators
	virtual Puzzle& operator=(const Puzzle&) = 0;
	virtual bool operator<(const Puzzle&) const = 0;
	virtual bool operator>(const Puzzle&) const = 0;
	virtual bool operator==(const Puzzle&) const = 0;
	virtual bool operator!=(const Puzzle&) const = 0;


protected:
	char puzzleType;
};

#endif