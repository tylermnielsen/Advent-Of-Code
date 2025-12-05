
all: brute_force 

brute_force: 
	g++ -Wall brute_force.cpp -o brute_force

run_brute_force: brute_force
	time ./brute_force

format: 
	clang-format -i -style=Google *.cpp 

clean: 
	rm brute_force