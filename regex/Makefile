FLAGS=-Wall -std=c++11  

all: regex-test regex

regex-test: regex_test.cc
	$(CXX) regex_test.cc -o regex-test $(FLAGS)
regex: regex.cpp
	$(CXX) $(FLAGS)  regex.cpp -o regex

clean:
	rm -rf regex-test regex

