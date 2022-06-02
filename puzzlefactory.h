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

//----------------------------------------------------------------------------
// PuzzleFactory(): Default Constructor
// Pre-conditions:None
// Post-conditions: An Puzzle Factory object is instantiated
	PuzzleFactory();

//----------------------------------------------------------------------------
// ~PuzzleFactory(): Virtual destructor
// Pre-conditions:None
// Post-conditions: Puzzle Factory object is deleted
	virtual ~PuzzleFactory();

//----------------------------------------------------------------------------
// createPuzzle(): Pure virtual function that will be used by derived classes
// to instantiate Puzzles of a specific type.
// Pre-conditions: A char variable indicating type of the specific type of
// puzzle (i.e. a Sudoky Puzzle has type S). 
// Post-conditions: An object of the specified type of Puzzle is instantiated
	virtual Puzzle* createPuzzle() = 0;
	virtual Puzzle* createOffSpring(Puzzle& aPuzzle) const = 0;

protected:
	//Reproduction object that will produce new puzzles or mutated puzzles
	SudokuOffSpring sudokuReproducer;
};

#endif
