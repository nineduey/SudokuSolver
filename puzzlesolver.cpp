/*
@File contents: PuzzleSolver data member and function delarations

@Purpose: To instantiate SudokuFactory and SudokuFitness objects that will
 take in text data to be pcocessed and instantiate a Sudoku object containing
 a board of the text data provided. PuzzleSolver acts as a manager of the objects
 in order to solve the Sudoku puzzle provided.

@Assumptions: Puzzle & subclasses, Population & subclasses, Fitness & subclasses,
and Reproduction and subclasses are defined. Text data to be imported is assumed to contain
no erroneous data and is formatting properly.

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "puzzlesolver.h"

//----------------------------------------------------------------------------
// PuzzleSolver(): Default Constructor
// @pre:None
// @post: An Puzzle Solver object is instantiated
PuzzleSolver::PuzzleSolver() {
	originBoard = nullptr;
	solvedBoard = nullptr;
}

//----------------------------------------------------------------------------
// ~PuzzleSolver(): Destructor
// @pre:None
// @post: deletes the pointers to originBoard and solvedBoard, set to nullptr
PuzzleSolver::~PuzzleSolver() {
	delete originBoard;
	delete solvedBoard;
	originBoard = nullptr;
	solvedBoard = nullptr;
}

void PuzzleSolver::reset(){
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

		Puzzle* tempPuzzle = puzzFac.createPuzzle();
		// check if file is empty
		if (inFile.eof()) {
			cout << "File is invalid, please review importing file." << endl;
			return;
		}
		// call on >> method of puzzle to import data
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
void PuzzleSolver::solve(int generations, int populationSize, int cullPercentage) {

	// instantiate the population object to hold sudoku puzzles
	SudokuPopulation pop(*originBoard, populationSize, cullPercentage);
	
	// obtain the best fitness score of the intial population
	int bestScore = INT_MAX;
	pop.cull(puzzEval); // call on population cull method
	bestScore = pop.bestFitness(); // obtain intial best score
	int i = 2; // counter of generations
	cout << "Solving Puzzle... please sit tight :)" << endl;

	// enter genetic algorithm
	while (bestScore != 0) {
		pop.newGeneration(puzzFac); // call to create new generation based on culled population
		pop.cull(puzzEval); // call to cull the generation
		bestScore = pop.bestFitness(); // obtain best score of the generation
		//cout << "Best Score of Population " << i << ": " << bestScore << endl;
		if (i == generations) {
			break;
		}
		i++;
	}

	// if puzzle is solved, retrieve solved board & display
	if (bestScore == 0) {
		cout << "\n\n*** Puzzle has been solved! ***" << endl;
		cout << "Best Score of Population " << i << ": " << bestScore << endl;
		cout << "Solved Board: " << endl;
		// return the solved puzzle object
		cout << *(pop.bestIndividual());
	} else{
	// retrieve best of board and display
		cout << i << " generations done, puzzle not solved" << endl;
		cout << "Best Score of Population " << i << ": " << bestScore << endl;
		cout << *(pop.bestIndividual());
	}
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
	cout << "Origin Board:" << endl;
	cout << *originBoard;

}


//----------------------------------------------------------------------------
// testPuzzAndSudoku(): method to test the functions of the parent class Puzzle
// and the child class Sudoku
// @pre: None
// @post: None
void PuzzleSolver::testPuzzAndSudoku() {

	cout << "Testing assignment operator" << endl;
	Puzzle* aCopy = new Sudoku();
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

//----------------------------------------------------------------------------
// testFirstGeneration(): method to test the Population class and Fitness class
// and their functionalies
// @pre: None
// @post: None
void PuzzleSolver::testFirstGeneration() {
	cout << "Beginning testFirstGeneration()" << endl;
	SudokuPopulation pop(*originBoard);
	cout << "1st Generaton Successful" << endl;
	pop.cull(puzzEval);
	cout << "1st Cull Successful" << endl;
	cout << "Best Sudoku Score: " << pop.bestFitness() << endl; // obtain intial best score
	cout << "1st Generaton Test Successful" << endl;
}


//----------------------------------------------------------------------------
// testOffSpring(): method to test the Population class, the Fitness, and the 
// Reproduction class, and their functionalies
// @pre: None
// @post: None
void PuzzleSolver::testOffSpring() {
	cout << "Beginning testOffSpring()" << endl;
	SudokuPopulation pop(*originBoard);

	pop.cull(puzzEval);
	cout << "1st Cull Successful" << endl;
	cout << "Best Sudoku Score: " << pop.bestFitness() << endl; // obtain intial best score

	pop.newGeneration(puzzFac); // offspring generation

	cout << "2nd Generation Successful" << endl;

	pop.cull(puzzEval);
	cout << "2nd Cull Successful" << endl;
	cout << "Best Sudoku Score: " << pop.bestFitness() << endl; // obtain 2nd generation best score
	cout << "testOffSpring Successful" << endl;
}
