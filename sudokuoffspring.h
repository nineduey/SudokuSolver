#ifndef SUDOKUOFFSPRING_H
#define SUDOKUOFFSPRING_H
#include "puzzle.h"
#include "reproduction.h"
#include<set>
#include <string>
#include "sudoku.h"

using namespace std;



class SudokuOffSpring : public Reproduction {


public:
	SudokuOffSpring();
	virtual ~SudokuOffSpring();
	virtual Puzzle* makeOffSpring(Puzzle& aPuzzle) const;
	void mutate(Puzzle& aPuzzle) const;
	//string missingValues(set<int>& values) const;
};

#endif