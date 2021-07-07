CXX=c++
FLAGS= -O2 -Wall -std=c++11  

all: move_test move-test2 move-test3

move_test: move_test.cc
	$(CXX) move_test.cc -o move_test $(FLAGS)
move-test2: move_test2.cc
	$(CXX) move_test2.cc -o move-test2 $(FLAGS)
move-test3: move_test3.cc
	$(CXX) move_test3.cc -o move-test3 $(FLAGS)
clean:
	rm -f move_test move-test2 move-test3
