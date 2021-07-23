CXX=c++
FLAGS=-std=c++11 

all: persist_vector em

persist_vector: persist_vector.cc
	$(CXX) -Wall $(FLAGS) persist_vector.cc -o persist_vector
em: em.cc
	$(CXX) -Wall $(FLAGS) em.cc -o em
clean:
	rm -f persist_vector
	rm -f em
