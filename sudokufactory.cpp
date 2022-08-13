/*
@File contents: SudokuFactory function definitions

@Purpose: Creates and returns a new Sudoku object by calling on 
 the Reproduction class object contained within the Parent class Reproduction
 to create it. 

@Assumptions: Parent Class Puzzle Factory is defined. Classes Puzzle
 and Sudoku are defined. 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "sudokufactory.h"

//----------------------------------------------------------------------------
// SudokuFactory(): 
SudokuFactory::SudokuFactory() {

}

//----------------------------------------------------------------------------
//~SudokuFactory(): Destructor of SudokuFactory class
// @pre: None
// @post: SudokuFactory object is destroyed
SudokuFactory::~SudokuFactory() {
}

//----------------------------------------------------------------------------
// createPuzzle(): calls upon the reproduction object that is contained within
// the Parent class Reproduction to instantiate a new Sudoku object
// @pre: none
// @post: An object of the specified type of Puzzle is instantiated
Puzzle* SudokuFactory::createPuzzle()  {
   return sudokuReproducer.createSudoku();
}

//----------------------------------------------------------------------------
// createOffSpring(): calls upon the reproduction object that is contained within
// the Parent class Reproduction to instantiate a new Sudoku object that is an offsping
// of the Puzzle object passed in my reference
// @pre: A Puzzle object is passed in my reference
// @post: An object of the specfied type of Puzzle instantiated and mutated
Puzzle* SudokuFactory::createOffSpring(Puzzle& aPuzzle) const {

   return sudokuReproducer.makeOffSpring(aPuzzle);
}

