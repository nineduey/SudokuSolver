/*
@File contents: Sudoku class data member and function declarations

@Purpose: Sudoku is a derived class of Puzzle. Sudoku holds the board data within
a vector of vectors of integers, ( a 2 dimensional vector). Sudoku class also holds
an integer to store the fitness score of its board, and a mirror board, a vector
of vectors of boolean values that is used to look up spaces in the board that are 
filled with fixed values from the original board data that is imported prior to solving
the puzzle

@Assumptions: Parent class Puzzle is defined. 

@Authors: Amanda Todakonzie, Logan Hoskisson & Adriel Mercado
*/
#include "sudoku.h"

//----------------------------------------------------------------------------
// Sudoku(): default sudoku constructor 
// Pre-conditions: n/a
// Post-consitions: sudoku object
Sudoku::Sudoku() {
   fitnessScore = INT_MAX;
}

//----------------------------------------------------------------------------
// ~Sudoku(): default sudoku destructor
// Pre-conditions: n/a
// Post-consitions: n/a
Sudoku::~Sudoku() {
}

//----------------------------------------------------------------------------
// create(): helper function for other classes' use to quickly make new sudoku
// objects 
// Pre-conditions: n/a
// Post-consitions: new sudoku object
Puzzle* Sudoku::create() const {
	return new Sudoku;
}

//----------------------------------------------------------------------------
// quickPrint(): function for quickly seeing the sudoku's board data 
// Pre-conditions: sudoku w/ board data
// Post-consitions: n/a
void Sudoku::quickPrint() const {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << this->board[i][j];
      }
   }
}

//----------------------------------------------------------------------------
// printPuzzle(): helper function for cout data to show sudoku's board container
// Pre-conditions: sudoku's 2D vector(board) has int data
// Post-consitions: n/a
void Sudoku::printPuzzle(ostream& out) const {
   string border;
   border += "+";
   for (int i = 1; i <= 21; i++) {
      border += "-";
      if (i % 7 == 0) {
         border += "+";
      }
   }
   out << border << endl;
   int y = 0;

   for (int i = 1; i <= 9; i++) {
      int x = 0;
      out << "|";
      for (int j = 1; j <= 24; j++) {
         if (j % 2 != 0) {
            out << " ";
         }
         if (j % 2 == 0) {
            if (j % 8 == 0) {
               out << "|";
            }
            else {
               out << this->board[y][x];
               x++;
            }
         }
      }
      out << endl;
      if (i % 3 == 0) {
         out << border << endl;
      }
      y++;
   }
}

//----------------------------------------------------------------------------
// importData(): helper function for cin data to put into sudoku's board container 
// Pre-conditions: istream data
// Post-consitions: Sudoku's 2D vector(board) has int data
void Sudoku::importData(istream& in) {
   cout << "\n Loading sudoku puzzle...\n" << endl;

   //while input has not reached the end of
   while (in.peek() != -1) {

      //placeholder for individual row 
      vector<int> row;
      vector<bool> fixedValues;
      for (int i = 0; i < 9; i++) {


         // boolean to determine if value is fixed
         bool fixed = true;
         //get input char into curr
         char c;
         in >> c;
         if (c >= '0' || c <= '9') {
            int num = (int)c;
            //push num into row vector
            num = num - 48;
            row.push_back(num);

            // if space is 0, push back a boolean as falsed 
            // into mirror board of boolean values
            // this allows the program to store which values are fixed original 
            // values of that puzzle that cannot be changed
            if (num == 0) {
               fixed = false;
               fixedValues.push_back(fixed);
            }
            else {
               fixedValues.push_back(fixed);
            }
         }
         else {
            continue;
         }
      }
      //push row into temporary 2d vector
      board.push_back(row);
      fixedSpaces.push_back(fixedValues);
   }
}

//----------------------------------------------------------------------------
// setFitness(): function for setting the fitness level of a sudoku object 
// board's "completeness" towards correct completion
// Pre-conditions: Sudoku object w/ board data that can be given or should have
// fitness score
// Post-consitions: changes the sudoku's fitness score for its board
void Sudoku::setFitness(int score) {
   fitnessScore = score;
}

//----------------------------------------------------------------------------
// getFitScore(): function for returning the fitness level of a sudoku object 
// board's "completeness" towards correct completion
// Pre-conditions: Sudoku object w/ board data that was evaluated for its fitness
// Post-consitions: the data member fitnessScore that is stored within the Sudoku class
// is returned
int Sudoku:: getFitScore() const {
   return fitnessScore;
}

//----------------------------------------------------------------------------
// getVal(): function for returning the int value w/in sudoku's 2D vector(board) 
// Pre-conditions: Sudoku object w/ 2D vector(board) data to return an int, and
// 2 given int coordinates to choose which value from the 9x9 2D vector
// Post-consitions: the value that is stored in the x, y position is returned as
// an integer
int Sudoku::getVal(int x, int y) const {
   int value = this->board[x][y];

   if (value > 9) {
      return value - 48;
   }
   return value;
}

//----------------------------------------------------------------------------
// setVal(): function enables setting the int value in the sudoku object's 2D
// vector (board)
// Pre-conditions: Sudoku object w/ 2D vector, and 2 int coordinates and 1 int
// for setting the space in the 2D vector w/ the new Value
// Post-conditions: n/a
void Sudoku::setVal(int x, int y, int value) {
   this->board[x][y] = value;
}

//----------------------------------------------------------------------------
// isFixed(): helper function for importdata() is used during the importing 
// process to mark spaces that are already given an int so the board's initial
// numbers aren't over-written and cheating the game
// Pre-conditions: sudoku object w/ 2d vector during import, and 2 int coordinates
// Post-consitions: a boolean value is returned indicating if the value in current 
// space x,y is fixed
bool Sudoku::isFixed(int x, int y) const {
   return this->fixedSpaces[x][y];
}

//----------------------------------------------------------------------------
// getBoard(): function returns a 2D vector being the sudoku's board 
// Pre-conditions: Sudoku object
// Post-consitions: 2D vector for return
vector<vector<int>> Sudoku::getBoard() const {
   return board;
}

//----------------------------------------------------------------------------
// operator=(): deep copy constructor function of overloaded operator "=" 
// Pre-conditions: puzzle for copying
// Post-consitions: A deep copy of the Puzzle object passed in as parameter is made
// into the current instance of the Puzzle 
Puzzle& Sudoku::operator=(const Puzzle& aPuzzle) {
   const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

   this->board = aSudoku.board;
   this->fixedSpaces = aSudoku.fixedSpaces;
   this->fitnessScore = aSudoku.fitnessScore;
   return *this;
}

//----------------------------------------------------------------------------
// operator<: function for overloaded comparison operator "<" to compare 2
// sudoku puzzle's fitness levels
// Pre-conditions: puzzle for comparison
// Post-consitions: boolean value is returned indicating is lesser than
bool Sudoku::operator<(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);
	
   return !(this->fitnessScore > aSudoku.fitnessScore);
	
}

//----------------------------------------------------------------------------
// operator>: function for overloaded comparison operator ">" to compare 2
// sudoku puzzle's fitness levels 
// Pre-conditions: puzzle for comparison
// Post-consitions: boolean value is returned indicating if greater than
bool Sudoku::operator>(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

	if (this->fitnessScore > aSudoku.fitnessScore) {
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// operator==: function for overloaded comparison operator "==" to compare 2
// sudoku puzzle's fitness levels 
// Pre-conditions: puzzle for comparison
// Post-consitions: boolean value is return indicated if equal
bool Sudoku::operator==(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

   return (this->fitnessScore == aSudoku.fitnessScore);
}

//----------------------------------------------------------------------------
// ooperator!=: function for overloaded comparison operator "!=" to compare 2
// sudoku puzzle's fitness levels
// Pre-conditions: puzzle for comparison
// Post-consitions: boolean value is returned indicating if not equal
bool Sudoku::operator!=(const Puzzle& aPuzzle) const {
	return !this->operator==(aPuzzle);
}