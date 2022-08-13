/*
@File contents: PuzzleFactory function defintions

@Purpose: PuzzleFactory is an abstract class that contains a Reproduction
 object that will produce new and mutated Sudoku objects

@Assumptions: Child Class SudokuFactory is defined and Classes Puzzle & Sudoku
are defined

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "puzzlefactory.h"

//----------------------------------------------------------------------------
// PuzzleFactory(): Default Constructor
// @pre:None
// @post: An Puzzle Factory object is instantiated
PuzzleFactory::PuzzleFactory() {}

// PuzzleFactory(): Virtual Destructor
// @pre:None
// @post: PuzzleFactory object is deleted
PuzzleFactory::~PuzzleFactory() {}