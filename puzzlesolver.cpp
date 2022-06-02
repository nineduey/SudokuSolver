#include "puzzlesolver.h"


PuzzleSolver::PuzzleSolver() {
	originBoard = nullptr;
	solvedBoard = nullptr;
}

PuzzleSolver::~PuzzleSolver() {
	delete originBoard;
	delete solvedBoard;
	originBoard = nullptr;
	solvedBoard = nullptr;
}


//----------------------------------------------------------------------------
// loadPuzzle(): reads in puzzle data and builds a new puzzle object based
// on the data imported from a text file. This puzzle object created will be
// kept in memory as the "origin puzzle", for tracking and referencing
// througout the program
// @pre: must be passed a referenced istream object that encapsulates a valid text file
// proper formatting is assumed
// @post: a Puzzle object is instatiated and loaded with the data imported from the text file,
// private data member originBoard is set to the Puzzle object
void PuzzleSolver::loadPuzzle(istream& inFile) {

		Puzzle* tempPuzzle;
		tempPuzzle = puzzFac.createPuzzle();

		if (inFile.eof()) {
			cout << "File is invalid, please review importing file." << endl;
			return;
		}

		inFile >> *tempPuzzle;
		originBoard = tempPuzzle;
}


//----------------------------------------------------------------------------
// solve(): function will take the origin puzzle and initiate the program to 
// to generate a popuation of sudoku puzzles and proceed to evaluate each puzzle
// using the fitness object's evaluation algorithm. 
// @pre: method assumes a properly instantiated and loaded Sudoku puzzle is passed
// in as a referenced argument
// @post: method provides a pointer to be assigned to the private data member "solvedBoard"
// one the algorithm is completed and the puzzle is solved with a best score of 0
void PuzzleSolver::solve(Puzzle& origin) {

	// instantiate the population object to hold sudoku puzzles
	SudokuPopulation pop(*originBoard);

	//initial generation of 1st population
	pop.generate();
	
	// obtain the best fitness score of the intial population
	int bestScore = INT_MAX;
	pop.cull(puzzEval);
	bestScore = pop.bestFitness(); // obtain intial best score

	// enter generation algorithm
	while (bestScore != 0) {
		pop.newGeneration(puzzFac);
		pop.cull(puzzEval);
		bestScore = pop.bestFitness();
	}
	// return the solved puzzle object
	solvedBoard = pop.bestIndividual();
}

void PuzzleSolver::testFirstGeneration() {
	cout << "Beginning testFirstGeneration()" << endl;
	SudokuPopulation pop(*originBoard);
	pop.generate();
	cout << "1st Generaton Successful" << endl;
	int bestScore = INT_MAX;
	pop.cull(puzzEval);
	cout << "1st Cull Successful" << endl;
	bestScore = pop.bestFitness(); // obtain intial best score
	cout << "1st Generaton Tst Successful" << endl;
}



void PuzzleSolver::testOffSpring() {
	cout << "Beginning testOffSpring()" << endl;
	SudokuPopulation pop(*originBoard);
	pop.generate();

	int bestScore = INT_MAX;
	pop.cull(puzzEval);
	cout << "1st Cull Successful" << endl;
	bestScore = pop.bestFitness(); // obtain intial best score
	cout << "Best Score: " << bestScore << endl;

	pop.newGeneration(puzzFac); // offspring generation
	cout << "2nd Generation Successful" << endl;
	pop.cull(puzzEval);
	cout << "1st Cull Successful" << endl;
	bestScore = pop.bestFitness();
	cout << "Best Score: " << bestScore << endl;

	cout << "testOffSpring Successful" << endl;
}


//----------------------------------------------------------------------------
// displayBoard(): function will send a output to the console to display the
// origina puzzle and puzzle that is contained within the population that
// possesses the best fitness score of the whole generation
// @pre: none
// @post: the private data members of originBoard are displayed, along with either the
// solvedBoard if the algorithm is completed and puzzle is solved, OR it will display
// best individual sudoku puzzle object that is returned from the bestIndividual() function
// from the Population class. 
void PuzzleSolver::displayBoard() {

	cout << "Origin Board:\n" << endl;
	cout << *originBoard;

	cout << "------------------------------------------------------" << endl;

	if (solvedBoard != nullptr) {
		cout << "Solved Board\n" << endl;
		cout << *solvedBoard;
	}

	cout << "Puzzle not yet solved." << endl;
	cout << "Best Score Board:" << endl;
	cout << endl;
	//Puzzle* bestScoreBoard= puzzPop.bestIndividual();
	//cout << bestScoreBoard;

}



void PuzzleSolver::testPuzzAndSudoku() {

	cout << "Testing assignment operator" << endl;
	Puzzle* aCopy = new Sudoku;
	*aCopy = *originBoard;

	cout << "\nTesting quickprint" << endl;
	aCopy->quickPrint();

	cout << "\nTesting getVal" << endl;
	cout << aCopy->getVal(0, 5);
	cout << originBoard->getVal(0, 5);


	cout << "\nTesting setVal" << endl;
	aCopy->setVal(0, 5, 2);
	cout << aCopy->getVal(0, 5);

	cout << "\nTesting setFitness" << endl;
	aCopy->setFitness(50);
	originBoard->setFitness(20);
	cout << "aCopy Board Score: " << aCopy->getFitScore();
	cout << "origin Board Score: " << originBoard->getFitScore();
	
	cout << "\nTesting > operator" << endl;
	if (*originBoard > *aCopy) {
		cout << "true";
	}
	else {
		cout << "originBoard is not greater than aCopy" << endl;
		cout << "false";
	}
	

	cout << "\nTesting < operator" << endl;
	if (*originBoard < *aCopy) {
		cout << "originBoard is less than aCopy" << endl;
		cout << "true";
	}
	else {
		cout << "false";
	}

	cout << "\nTesting == operator" << endl;
	if (*originBoard == *aCopy) {
		cout << "true";
	}
	else {
		cout << "originBoard is not equal to aCopy" << endl;
		cout << "false";
	}

	cout << "\nTesting != operator" << endl;
	if (*originBoard != *aCopy) {
		cout << "originBoard is not equal to aCopy" << endl;
		cout << "true";
	}
	else {
		cout << "false";
	}
}