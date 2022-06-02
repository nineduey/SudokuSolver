#include "puzzle.h"

// Default Constructor
Puzzle::Puzzle() {
	puzzleType = 'S';
}

//Default Destructor
Puzzle::~Puzzle() {}


char Puzzle::getType() {
	return this->puzzleType;
}


 ostream& operator<< (ostream& out, const Puzzle& aPuzzle) {
	 aPuzzle.printPuzzle(out);
	 return out;
 }


 istream& operator>> (istream& in, Puzzle& aPuzzle) {

	 aPuzzle.importData(in);
	 return in;
 }