#include "sudokuoffspring.h"
#include <set>

SudokuOffSpring::SudokuOffSpring() {
}

SudokuOffSpring::~SudokuOffSpring() {
}

Puzzle* SudokuOffSpring::makeOffSpring(Puzzle& aPuzzle) const {

   char puzzType = aPuzzle.getType();
   if (puzzleMap.find(puzzType) == puzzleMap.end()) {
      return nullptr;
   }
   else {
      int subscript = puzzleMap.at(puzzType);
      Puzzle* offSpringPuzzle = puzzleFac[subscript]->create();

      //create deep copy of param aPuzzle to the new offSpring puzzle
      *(offSpringPuzzle) = aPuzzle;
      // mutate the puzzle
      mutate(*offSpringPuzzle);
      // return newly mutated offspring puzzle
      return offSpringPuzzle;
   }
}

//string SudokuOffSpring::missingValues(set<int>& values) const{
//   string missing = "";
//
//   for (int i = 1; i <= 9; i++) {
//      for (int j = 0; j < 9; j++) {
//         if (values[j] != i) {
//            missing += to_string(i);
//         }
//      }
//   }
//   return missing;
//}



void SudokuOffSpring::mutate(Puzzle& aPuzzle) const {

   Sudoku& aSudoku = static_cast<Sudoku&>(aPuzzle);
   
   // set of ints to track unique values within the row, column, 3x3 minis
   int row;
   int col;
   // scanning rows
   for (row = 0; row < 9; row++) {

      set<int> unique;
      unordered_map<int, int> firstOccurence;
      unordered_map<int, int> duplicateMap;

      for (col = 0; col < 9; col++) {

         // test to see if value already exists in unique set
         if (unique.count(aSudoku.getVal(row, col)) == 0) {
            // add value to the unique set
            int val = aSudoku.getVal(row, col);
            unique.insert(val);
            // add index position of the value to the first Occurence map
            firstOccurence.insert(pair<int, int>(val, col));
         }
         else { // if the value does exist, that means its a duplicate, 
            //proceed to push position of duplicate into dupMap
            duplicateMap.insert(pair<int, int>(row, col));
         }
      }

      // once done scanning row, proceed to change values of duplicates

      for (auto& i : duplicateMap) {
         // if position of duplicate is not a fixed value
         // proceed to change
         if (!aSudoku.isFixed(i.first, i.second)) {
            int mutantVal = aSudoku.getVal(i.first, i.second);
            // if value is less than 9, increase
            if (mutantVal != 9) {
               aSudoku.setVal(i.first, i.second, mutantVal + 1);
            }
            else { // if value is a 9, decrease
               aSudoku.setVal(i.first, i.second, mutantVal - 1);
            }

         }
         else { // if the duplicateMap position is a fixed position, change the first Occurence position
           
               int mutantVal = aSudoku.getVal(i.first, i.second);

               if (mutantVal != 9) {
                  int index = firstOccurence[mutantVal];
                  aSudoku.setVal(row, index, mutantVal + 1);
               }
               else { // if value is a 9, decrease
                  int index = firstOccurence[mutantVal];
                  aSudoku.setVal(row, index, mutantVal - 1);
               }
         }
      }

   }

}