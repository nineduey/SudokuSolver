/*
@File contents: Main.cpp driver file

@Purpose: To instantiate the PuzzleSolver class to take in
test data and load the PuzzleSolver with Sudoku data. Puzzle Solver
will then call on solve() to solve the puzzle. 

@Assumptions: Imported text data for loading puzzle contains 0 erroneous
data and is formatting correctly

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "puzzlesolver.h"
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
	int popSize = 10;
	int generations = 100000;
	int cullPercentage = 10;
	if(argc >= 3)
	{
		popSize = std::stoi(argv[1]);
		generations = std::stoi(argv[2]);
	}

	// Instantiating PuzzleSolver class
	PuzzleSolver sudokuMaster;

	// Load puzzle data
	cout << "Input Puzzle Data: ";
        string input;
	cin >> input;

	ofstream outFile;
	outFile.open("puzzle.txt", ofstream::out);
	outFile << input;
	outFile.close();

	ifstream inFile("puzzle.txt");

	if (!inFile) {
		cout << "File with puzzle data could not be opened." << endl;
		return 1;
	}

	istream& inFile_istream = inFile;
	
	// call on PuzzleSolver to load and solve Sudoku Puzzle testcase 1
	sudokuMaster.loadPuzzle(inFile);
	sudokuMaster.displayBoard();
	sudokuMaster.solve(popSize, generations, cullPercentage);
	//sudokuMaster.reset();

	// Loading testcase 2
	//ifstream inFile2("testcase2.txt");

	//if (!inFile2) {
	//	cout << "File with puzzle data could not be opened." << endl;
	//	return 1;
	//}


	//istream& inFile_istream2 = inFile2;
	// call on PuzzleSolver to load and solve Sudoku Puzzle test case 2
	//sudokuMaster.loadPuzzle(inFile_istream2);
	//sudokuMaster.displayBoard();
	//sudokuMaster.solve(1000000,10,1);
	
	
	// testing methods for PuzzleSolver
	//sudokuMaster.testPuzzAndSudoku();
	//sudokuMaster.testFirstGeneration();
    //sudokuMaster.testOffSpring();


}
