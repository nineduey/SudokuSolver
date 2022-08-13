# SudokuSolver
Designed and implemented by Amanda Todakonzie, Logan Hoskisson, and Adriel Mercado

Our program is designed to solve a sudoku puzzle using a genetic algorithm. Upon running it will prompt the user to input the puzzle data as a string of 81 numbers and the desired number of generations and the population size. 

To run the program, run the Makefile, then execute the program by ./puzzlesolver <generations> <population size>

For our program, we highly suggest inputting "100000" for the number of generations and "10" for the population size. We found in our testing that this size population performed the best out of all the testing we did. 
 ***HOWEVER, for hard puzzles, 100,000 generations may not be enough generations. Our program may run very fast, but is luck based on the randomized values being inputted into the puzzle. Sometimes hard puzzles are solved in less than 25k generations, sometimes over 100,000k generations. 

PuzzleSolver is the manager class that instantiates the Population class, the PuzzleFactory class and the Fitness Class. The PuzzleSolver is designed to load the intial puzzle data via cin>> input from the user, and call upon the Population to generate the first population of puzzles. From there, it hands over the Factory and the Fitness objects for Population to use in its quest to find a solutiont to the puzzle. 

An overview of the classes implemented are:

<-- indicates inheritance

+PuzzleSolver

+Puzzle <-- +Sudoku
  
+Population <-- +SudokuPopulation
               
+PuzzleFactory <-- +SudokuFactory
  
+Reproduction <-- +SudokuOffSpring
                 
+Fitness <-- +SudokuFitness
