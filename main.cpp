#include "puzzlesolver.h"
#include <fstream>
#include <iostream>

int main() {

	PuzzleSolver puzzSolver;

	ifstream inFile("testcase1.txt");

	if (!inFile) {
		cout << "File with puzzle data could not be opened." << endl;
		return 1;
	}

	istream& inFile_istream = inFile;
	puzzSolver.loadPuzzle(inFile_istream);

	puzzSolver.displayBoard();

	//puzzSolver.testPuzzAndSudoku();

	puzzSolver.testFirstGeneration();

	//puzzSolver.testOffSpring();


}