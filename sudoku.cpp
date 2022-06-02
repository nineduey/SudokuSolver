#include "sudoku.h"


Sudoku::Sudoku() {
   fitnessScore = INT_MAX;
}

Sudoku::~Sudoku() {
}

Puzzle* Sudoku::create() const {
	return new Sudoku;
}


void Sudoku::quickPrint() const {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << this->board[i][j];
      }
   }
}



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

void Sudoku::importData(istream& in) {
   cout << "Taking sudoku puzzle...\n";


   //while input has not reached the end of
   while (!in.eof()) {

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


void Sudoku::setFitness(int score) {
   fitnessScore = score;
}

int Sudoku:: getFitScore() const {
   return fitnessScore;
}


int Sudoku::getVal(int x, int y) const {
   int value = this->board[x][y];

   if (value > 9) {
      return value - 48;
   }
   return value;
}

void Sudoku::setVal(int x, int y, int value) {
   this->board[x][y] = value;
}

bool Sudoku::isFixed(int x, int y) const {
   return this->fixedSpaces[x][y];
}

vector<vector<int>> Sudoku::getBoard() const {
   return board;
}

Puzzle& Sudoku::operator=(const Puzzle& aPuzzle) {
   const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

   this->board = aSudoku.board;
   this->fixedSpaces = aSudoku.fixedSpaces;
   this->fitnessScore = aSudoku.fitnessScore;
   return *this;
}


bool Sudoku::operator<(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);
	
   return !(this->fitnessScore > aSudoku.fitnessScore);
	
}

bool Sudoku::operator>(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

	if (this->fitnessScore > aSudoku.fitnessScore) {
		return true;
	}
	return false;
}

bool Sudoku::operator==(const Puzzle& aPuzzle) const {
	const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

   return (this->fitnessScore == aSudoku.fitnessScore);
}


bool Sudoku::operator!=(const Puzzle& aPuzzle) const {
	return !this->operator==(aPuzzle);
}