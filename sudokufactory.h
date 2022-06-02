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

//----------------------------------------------------------------------------
// SudokuFactory(): Declares elements in 'Puzzlemap' HashMap and initializes them
// with keys equal to char variables of every possible puzzle type
// and values equal to integers ranging from 0  to the number of puzzle types
// - 1. Declares elements in 'puzzleFac' vector and initializes them to new Puzzle
// objects of every possible puzzle type
// Pre-conditions:None
// Post-conditions: Elements of map and puzzleFac are initialized.
	SudokuFactory();

//----------------------------------------------------------------------------
//~SudokuFactory(): Destructor of SudokuFactory class
// Pre-conditions: None
// Post-Conditions: Deletes the Puzzle objects of 'puzzleFac' vector from memory
	virtual ~SudokuFactory();

//----------------------------------------------------------------------------
// createPuzzle(): Instantiates Puzzle object to equal Puzzle object of the type
// associated with the char variable passed in
// Pre-conditions: puzzleFac contains the Puzzle object of type associated with
// the char variable passed as the function's argument AND map contains a
// key-value pair in which the key is equal passed in char variable
// Post-conditions: An object of the specified type of Puzzle is instantiated
	virtual Puzzle* createPuzzle() ;

//----------------------------------------------------------------------------
// createOffSpring(): Instantiates Puzzle object that is a mutation of the Puzzle
// object passed in as a reference to an existing puzzle
// @pre: 
// @post
	virtual Puzzle* createOffSpring(Puzzle& aPuzzle) const ;

};

#endif