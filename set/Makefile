
FLAGS= -std=c++11

all: set-test set_example

set-test: set.cpp
	$(CXX) $(FLAGS) set.cpp -o set-test
set_example:set_example.cpp
	$(CXX) $(FLAGS) set_example.cpp -o set_example

clean:
	rm -f set-test set_example
