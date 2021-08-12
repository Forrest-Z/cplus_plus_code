
all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp Makefile
	g++ $< -o $@ -std=c++14 -pedantic

clean:
	rm *.out
