#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <limits.h>
#include "puzzle.h"
#include <string>
#include <vector>
using namespace std;

class Sudoku : public Puzzle {


public:
	Sudoku();
	virtual ~Sudoku();
	virtual Puzzle* create() const;
	virtual void importData(istream& in);
	virtual void printPuzzle(ostream& out) const;
	virtual void quickPrint() const;
	virtual void setFitness(int score);
	virtual int getFitScore() const;
	virtual int getVal(int x, int y) const;
	virtual vector<vector<int>> getBoard() const;
	virtual void setVal(int x, int y, int value);
	virtual bool isFixed(int x, int y) const;


	// virtual comparison operators
	virtual Puzzle& operator=(const Puzzle&);
	virtual bool operator<(const Puzzle&) const;
	virtual bool operator>(const Puzzle&) const;
	virtual bool operator==(const Puzzle&) const;
	virtual bool operator!=(const Puzzle&) const;

protected:
	int fitnessScore;
	vector<vector<int>> board;
	vector <vector<bool>> fixedSpaces;

};

#endif

