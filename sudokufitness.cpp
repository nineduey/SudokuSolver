#include "sudokufitness.h"

SudokuFitness::SudokuFitness() {
}

SudokuFitness::~SudokuFitness() {}

 int SudokuFitness::howFit(Puzzle& aPuzzle) const {
   const Sudoku& aSudoku = static_cast<const Sudoku&>(aPuzzle);

   int score = 0;

   score += evalRows(aSudoku.getBoard());
   score += evalCols(aSudoku.getBoard());

   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         score += evalMinis(aSudoku.getBoard(), i, j);
      }
   }

   return score;
}

//evaluates the whole board's rows for repeats during 1 use
int SudokuFitness::evalRows(const vector<vector<int>>& twoDim) const {
   int score = 0;
   //this part checks the 2d vector's rows
   for (int i = 1; i <= 9; i++) {
      for (int j = 0; j < 9; j++) {
         //vector to compare and check for unique numbers
         vector<bool> unique(9, true);

         for (int k = 0; k < 9; k++) {
            //compares row's numbers with i to see for repeats
            if (twoDim[j][k] == i) {
               //the 1-9 number exists
               if (unique[j] == true) {
                  unique[j] = false;
               }
               //the same number has been found; repeating number
               if (unique[j] == false) {
                  score++;
               }
            }
         }
      }
   }
   return score;
}

//evaluates the whole board's columns for repeats during 1 use
int SudokuFitness::evalCols(const vector<vector<int>>& twoDim) const {
   int score = 0;
   for (int i = 1; i <= 9; i++) {
      for (int j = 0; j < 9; j++) {
         //vector to compare and check for unique numbers
         vector<bool> unique(9, true);

         for (int k = 0; k < 9; k++) {
            //compares column's numbers with i to see for repeats
            if (twoDim[k][j] == i) {
               //the 1-9 number exists
               if (unique[j] == true) {
                  unique[j] = false;
               }
               //the same number has been found; repeating number
               if (unique[j] == false) {
                  score++;
               }
            }
         }
      }
   }
   return score;
}

//checks only 1 3x3 square per use
int SudokuFitness::evalMinis(const vector<vector<int>>& twoDim, int row, int column) const{
   //vector to compare and check for unique numbers
   vector<bool> unique(9, true);
   int score = 0;

   //this is for the comparison value
   for (int i = 1; i <= 9; i++) {
      //row and column are used to maintain the placement within the current 3x3
      //e.g. center 3x3 would be row = 1 column = 1, j = 1*3=3, j < 3+3 = 6 (3 to 6 for 2d vector)
      for (int j = 0 + (row * 3); j < (3 + row * 3); j++) {
         //following previous example column = 1, k = 0 + 1*3 = 3, k < 3 + 1*3 = 6
         //(=>analyzes columns 3 to 6 for 2d vector, checking 2d[3][3] to 2d[6][6])
         for (int k = 0 + (column * 3); k < (3 + column * 3); k++) {
            //compares all ints in 3x3 to i
            if (twoDim[j][k] == i) {
               //the 1-9 number exists
               if (unique[i - 1] == true) {
                  unique[i - 1] = false;
               }
               //the same number has been found; repeating number
               if (unique[i - 1] == false) {
                  score++;
               }
            }
         }
      }
   }
   return score;
}

/*int SudokuFitness::eval(vector<int>& vec, int place, int& count) {

    for (int i = 0; i < vec.size; i++) {
        //if checked to the end of the vector and reached the end
        if (place == vec.size() && place == i) {
            return count;
        }
        //if the place equals the number in the vector
        if (place == vec[i]) {
            count++;
            vec.erase(vec.begin()+i);
        }
    }
    count += eval(vec, place++, count);
    return count;
}*/