
all: part1

part1: format
	g++ -Wall playground_1.cpp -o part1.out

part2: format 
	g++ -Wall playground_2.cpp -o part2.out

format: 
	clang-format -i -style=Google *.cpp

clean: 
	rm *.out