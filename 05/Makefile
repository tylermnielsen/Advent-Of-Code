
all: brute_force_1 brute_force_2

.PHONY: brute_force_2
brute_force_2:
	g++ -Wall brute_force_2.cpp -o brute_force_2.out

run_brute_force_2: brute_force_2
	time ./brute_force_2 inputs/input.txt

.PHONY: brute_force_1
brute_force_1: 
	g++ -Wall brute_force_1.cpp -o brute_force_1.out

run_brute_force_1: brute_force_1
	time ./brute_force_1 inputs/input.txt

format: 
	clang-format -i -style=Google *.cpp 

clean: 
	rm brute_force_1 brute_force_2