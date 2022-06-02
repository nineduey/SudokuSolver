#include "sudokufactory.h"

//----------------------------------------------------------------------------
// SudokuFactory(): 
SudokuFactory::SudokuFactory() {

}



//----------------------------------------------------------------------------
//~SudokuFactory(): Destructor of SudokuFactory class
// @pre: None
// @post: Deletes the Puzzle objects of 'puzzleFac' vector from memory
SudokuFactory::~SudokuFactory() {
}



//----------------------------------------------------------------------------
// createPuzzle(): Instantiates Puzzle object to equal puzzle object of the type
// associated with the char variable passed in
// @pre: puzzleFac contains the Puzzle object of type associated with
// the char variable passed as the function's argument AND map contains a
// key-value pair in which the key is equal passed in char variable
// @post: An object of the specified type of Puzzle is instantiated
Puzzle* SudokuFactory::createPuzzle()  {
   return sudokuReproducer.createSudoku();
}

//----------------------------------------------------------------------------
// createOffSpring(): Instantiates Puzzle object that is a mutation of the Puzzle
// object passed in as a reference to an existing puzzle
// @pre: 
// @post
Puzzle* SudokuFactory::createOffSpring(Puzzle& aPuzzle) const {

   return sudokuReproducer.makeOffSpring(aPuzzle);
}

