FLAGS=-Wall -std=c++11 
all: atomic

atomic: atomic.cpp
	$(CXX) $(FLAGS) atomic.cpp -o atomic -pthread
clean:
	rm -f atomic
