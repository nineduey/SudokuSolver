#ifndef SUDOKUFITNESS_H
#define SUDOKUFITNESS_H
#include "fitness.h"
#include <limits.h>
#include "sudoku.h"
#include <vector>


class SudokuFitness : public Fitness {

public:
   SudokuFitness();
   ~SudokuFitness();
   virtual int howFit(Puzzle& aPuzzle) const;

private:
   //int evaluate(vector<int>& vec, int place, int& count);
   int evalRows(const vector<vector<int>>& twoDim) const;
   int evalCols(const vector<vector<int>>& twoDim) const;
   int evalMinis(const vector<vector<int>>& twoDim, int row, int column) const;
};

#endif