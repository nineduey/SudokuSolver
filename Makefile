main : main.cpp puzzlesolver.o sudoku.o sudokupopulation.o sudokufactory.o sudokuoffspring.o sudokufitness.o \
       puzzle.o puzzlesolver.h 
	g++ -g main.cpp puzzlesolver.o sudoku.o sudokupopulation.o sudokufactory.o sudokuoffspring.o \
        sudokufitness.o puzzle.o puzzlefactory.o reproduction.o fitness.o -o puzzlesolver
puzzlesolver.o : puzzlesolver.cpp puzzlesolver.h fitness.h population.h puzzlefactory.h sudokufactory.h \
                 sudokupopulation.h reproduction.h sudoku.h puzzle.h puzzlefactory.cpp \
                 sudokufactory.cpp sudokupopulation.cpp reproduction.cpp sudoku.cpp puzzle.cpp
	g++ -g -c puzzlesolver.cpp sudokufitness.cpp reproduction.cpp sudokupopulation.cpp puzzlefactory.cpp \
        sudokufactory.cpp fitness.cpp sudoku.cpp puzzle.cpp 
sudokupopulation.o : sudokupopulation.cpp sudokupopulation.h population.h sudoku.h sudoku.cpp \
                     puzzle.h puzzle.cpp sudokufactory.h sudokufactory.cpp puzzlefactory.h puzzlefactory.cpp \
                     fitness.h fitness.cpp sudokufitness.h sudokufitness.cpp
	g++ -g -c sudokupopulation.cpp sudoku.cpp puzzle.cpp sudokufactory.cpp puzzleFactory.cpp fitness.cpp \
        sudokufitness.cpp 
sudokufactory.o : sudokufactory.cpp sudokufactory.h puzzle.h puzzle.cpp puzzlefactory.h puzzlefactory.cpp \
                  sudokuoffspring.h sudokuoffspring.cpp sudoku.h sudoku.cpp reproduction.h reproduction.cpp
	g++ -g -c sudokufactory.cpp puzzle.cpp puzzlefactory.cpp sudokuoffspring.cpp sudoku.cpp reproduction.cpp
sudokuoffspring.o : sudokuoffspring.cpp sudokuoffspring.h puzzle.h puzzle.cpp reproduction.h reproduction.cpp \
                    sudoku.h sudoku.cpp
	g++ -g -c sudokuoffspring.cpp puzzle.cpp reproduction.cpp sudoku.cpp
sudokufitness.o : sudokufitness.cpp sudokufitness.h fitness.h fitness.cpp
	g++ -g -c sudokufitness.cpp fitness.cpp
sudoku.o : sudoku.cpp sudoku.h puzzle.h puzzle.cpp
	g++ -g -c sudoku.cpp puzzle.cpp
puzzle.o : puzzle.cpp puzzle.h
	g++ -g -c puzzle.cpp
puzzlefactory.o : puzzlefactory.cpp puzzlefactory.h
	g++ -g -c puzzlefactory.cpp
reproduction.o : reproduction.cpp reproduction.h
	g++ -g -c reproduction.cpp
fitness.o : fitness.cpp fitness.h
	g++ -g -c fitness.cpp
clean : 
	rm puzzlesovler puzzlesolver.o sudoku.o sudokupopulation.o sudokufactory.o sudokuoffspring.o \
        sudokufitness.o sudoku.o puzzle.o puzzlefactory.o reproduction.o fitness.o
