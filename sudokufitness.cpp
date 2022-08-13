/**
 * @File contents: SudokuFitness class's functions and data members
 * 
 * @Purpose: Work in conjuction with Sudoku to evaluate Sudoku 
 * class's "board" data member and evaulate the two dimensional 
 * vector's amount of repeating numbers per row, column, and 3x3
 * square block. This class then gives back an int which is stored
 * in Sudoku class object's "fitnessScore" data member.
 * 
 * @Assumptions: Sudoku and parent-class puzzle are completed with 
 * necessary data members and function calls. As well as active 
 * parent class Fitness is also completed.
 * 
 * @Authors: Amanda Todakonzie, Logan Hoskisson, Adriel Mercado
 * 
 */
#include "sudokufitness.h"

//----------------------------------------------------------------------------
// SudokuFitness(): default SudokuFitness constructor
// Pre-conditions: n/a
// Post-consitions: n/a
SudokuFitness::SudokuFitness() {
}

//----------------------------------------------------------------------------
// ~SudokuFitness(): default SudokuFitness destructor
// Pre-conditions: n/a
// Post-consitions: n/a
SudokuFitness::~SudokuFitness() {}


//----------------------------------------------------------------------------
// howFit(): function for evaluating how fit a puzzle and in this case sudoku
// puzzle and returns an int of the sudoku puzzle object's fitness for its board
// Pre-conditions: sudoku puzzle object with board data to evaluate for fitness
// Post-consitions: int of fitness
int SudokuFitness::howFit(Puzzle& aPuzzle) const {
    const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

  //create all sets in one pass through board 
  //sets 0-8 are columns 9-17 are rows and 18-26 are minis
  vector<set<int>> sets; 
  sets.resize(27);
  for(int row = 0; row < 9; row++)
  {
    for(int col = 0; col < 9; col++)
    {
      sets[col].insert(aSudoku.getVal(row, col));
      sets[9+row].insert(aSudoku.getVal(row, col));
      sets[18+(col/3)+((row/3)*3)].insert(aSudoku.getVal(row, col));
    }
  }

  //evaluate sets
  int score = 0;
  for(int i = 0; i < 27; i++)
    score += (9-sets[i].size());

  return score;
}
