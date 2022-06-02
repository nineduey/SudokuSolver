#ifndef PUZZLE_H
#define PUZZLE_H
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

class Puzzle {

	friend ostream &operator<<(ostream& out, const Puzzle& aPuzzle);
	friend istream &operator>>(istream& in, Puzzle& aPuzzle);

public:
	Puzzle();
	virtual ~Puzzle();
	virtual Puzzle* create() const = 0;
	virtual void importData(istream& in) = 0;
	virtual void printPuzzle(ostream& out) const = 0;
	virtual void quickPrint() const = 0;
	virtual void setFitness(int score) = 0;
	virtual int getFitScore() const = 0;
	virtual int getVal(int x, int y) const = 0;
	virtual vector<vector<int>> getBoard() const = 0;
	virtual void setVal(int x, int y, int value) = 0;
	virtual bool isFixed(int x, int y) const = 0;
	char getType();

	//virtual comparison operators
	virtual Puzzle& operator=(const Puzzle&) = 0;
	virtual bool operator<(const Puzzle&) const = 0;
	virtual bool operator>(const Puzzle&) const = 0;
	virtual bool operator==(const Puzzle&) const = 0;
	virtual bool operator!=(const Puzzle&) const = 0;


protected:
	char puzzleType;

};

#endif