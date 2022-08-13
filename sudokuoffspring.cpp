/*
@File contents: SudokuOffSpring function definitions

@Purpose: SudokuOffSpring is an object that handles producing a new Sudoku
 object with a board that has been changed (mutated) from another Sudoku object that
 is passed in by reference to its makeOffSpring() function

@Assumptions: Parent class Reprodution has been defined and Sudoku objects being 
 passed in contain valid board values 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/

#include "sudokuoffspring.h"
#include <set>


//----------------------------------------------------------------------------
// SudokuOffSpring(): Default Constructor
// @pre:None
// @post: A SudokuOffSpring object is instantiated
SudokuOffSpring::SudokuOffSpring() {
}


//----------------------------------------------------------------------------
// ~SudokuOffSpring(): Destructor 
// @pre:None
// @post: 
SudokuOffSpring::~SudokuOffSpring() {
}


//----------------------------------------------------------------------------
// makeOffSpring(): Virtual function to call on factory to produce a Sudoku
// object that has a board copied over from a Sudoku object passed in as the
// parameter. A mutate() function is called upon the object once its created
// and be returned as a Puzzle pointer
// @pre: Puzzle object passed in by reference
// @post: A mutated puzzle object pointer is returned 
Puzzle* SudokuOffSpring::makeOffSpring(Puzzle& aPuzzle) const {

   // call on puzzle factory to produce a Sudoku object
   // getType() is called to retrieve the key of the object
   // that will be looked up in the puzzle factory map
   char puzzType = aPuzzle.getType();
   if (puzzleMap.find(puzzType) == puzzleMap.end()) {
      return nullptr;
   }
   else {
      int subscript = puzzleMap.at(puzzType);
      Puzzle* offSpringPuzzle = puzzleFac[subscript]->create();

      //create deep copy of param aPuzzle to the new offSpring puzzle
      *(offSpringPuzzle) = aPuzzle;
      // mutate the puzzle
      mutate(*offSpringPuzzle);
      // return newly mutated offspring puzzle
      return offSpringPuzzle;
   }
}

//----------------------------------------------------------------------------
// mutate(): method that will change the puzzle object's board values. The
// puzzle object is cast as its subclass in order to access its data members
// @pre: Puzzle object passed in by reference
// @post: Puzzle object's board values have been altered
void SudokuOffSpring::mutate(Puzzle& aPuzzle) const {
   Sudoku& aSudoku = static_cast<Sudoku&>(aPuzzle);

      // simple mutate function to randomly change values to random values
   for(int row = 0; row < 9; row++)
      for(int col = 0; col < 9; col++)
         if(!aSudoku.isFixed(row, col))
            if(rand()%100 < 2) //2 percent chance
               aSudoku.setVal(row, col, rand()%9+1);
}