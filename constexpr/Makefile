CXX=c++
FLAGS=-Wall -std=c++11 
all: constexpr constexpr-test constexpr_example
constexpr: constexpr.cc
	$(CXX)  $(FLAGS)  constexpr.cc -o constexpr
constexpr-test: constexpr-test.cc
	$(CXX)  $(FLAGS)  constexpr-test.cc -o constexpr-test
constexpr_example: constexpr_example.cpp
	$(CXX) $(FLAGS) constexpr_example.cpp -o constexpr_example
clean:
	rm -f constexpr constexpr-test constexpr_example
