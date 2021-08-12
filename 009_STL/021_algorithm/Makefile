CXX_FLAGS= -std=c++11

all: for_each transform find_if sort

for_each: for_each.cpp
	$(CXX) $(CXX_FLAGS) for_each.cpp -o for_each
transform: transform.cpp
	$(CXX) $(CXX_FLAGS) transform.cpp -o transform
find_if: find_if.cpp
	$(CXX) $(CXX_FLAGS) find_if.cpp -o find_if
sort: sort.cpp
	$(CXX) $(CXX_FLAGS) sort.cpp -o sort
clean:
	rm -f for_each transform find_if sort
