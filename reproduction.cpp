#include "reproduction.h"


//----------------------------------------------------------------------------
// Reproduction(): default constructor that declares elements in 'map' HashMap 
// and initializes them with keys equal to char variables of every possible 
// puzzle subtype and values equal to integers ranging from 0  to the number 
// of puzzle types - 1. Declares elements in'puzzleFac' vector and initializes
// them to new Puzzle objects of every possible puzzle subtype
// @pre:None
// @post: Elements of map and puzzleFac are initialized.
Reproduction::Reproduction() {
   puzzleFac.push_back(new Sudoku);
   puzzleMap.insert({ 'S', 0 });
}

//----------------------------------------------------------------------------
// ~Reproduction(): virtual destructor
// @pre: None
// @post: Deletes the Puzzle objects of 'puzzleFac' vector from memory
Reproduction::~Reproduction() {
   int size = puzzleFac.size();

   for (int i = 0; i < size; i++) {
      delete puzzleFac[i];
      puzzleFac[i] = nullptr;
   }
}


//----------------------------------------------------------------------------
// createSudoku(): Instantiates Puzzle object to equal puzzle object of the type
// associated with the char variable passed in
// @pre: puzzleFac contains the Puzzle object of type associated with
// the char variable passed as the function's argument AND map contains a
// key-value pair in which the key is equal passed in char variable
// @post: An object of the specified type of Puzzle is instantiated (empty puzzle)
//----------------------------------------------------------------------------
Puzzle* Reproduction::createSudoku() const {

   char puzzType = 'S';

   if (puzzleMap.find(puzzType) == puzzleMap.end()) {
      return nullptr;
   }
   else {
      int subscript = puzzleMap.at(puzzType);
      return puzzleFac[subscript]->create();
   }
}

