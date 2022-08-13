/*
@File contents: Puzzle class data member and function declarations

@Purpose: The Puzzle class serves as an abstract class for its derived
class Sudoku. A char variable indicating the puzzle type is stored in 
the puzzle class for puzzle factory purposes. 

@Assumptions: Its derived class Sudoku class is defined.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "puzzle.h"

//----------------------------------------------------------------------------
// Puzzle(): default puzzle constructor
// Pre-conditions: none
// Post-consitions: puzzle object
Puzzle::Puzzle() {
	puzzleType = 'S';
}

//----------------------------------------------------------------------------
// ~Puzzle(): puzzle destructor
// Pre-conditions: none
// Post-consitions: deleted puzzle
Puzzle::~Puzzle() {

}

//----------------------------------------------------------------------------
// getType(): function for getting puzzle's type
// Pre-conditions: n/a
// Post-consitions: return char representing puzzle's type
char Puzzle::getType() {
	return this->puzzleType;
}

//----------------------------------------------------------------------------
// operator<<(): Overloaded cout << operator for ease of use for puzzle and
// sudoku class. Prints out the puzzle object with use of printpuzzle() which 
// is a pure virtual function for sudoku class's use with decorative border 
// for easier reading
// Pre-conditions: Puzzle class has a puzzle
// Post-consitions: Prints out puzzle for easy viewing
 ostream& operator<< (ostream& out, const Puzzle& aPuzzle) {
	 //printPuzzle helper function defined in subclass
	 aPuzzle.printPuzzle(out);
	 return out;
 }

//----------------------------------------------------------------------------
// operator>>(): Overloaded cin >> operator for ease of use for puzzle and 
// sudoku class. Takes in puzzle data to fill the puzzle's container.
// Pre-conditions: Valid puzzle data
// Post-consitions: puzzle's container has the data assigned
 istream& operator>> (istream& in, Puzzle& aPuzzle) {
	 //importData helper function defined in subclass
	 aPuzzle.importData(in);
	 return in;
 }
