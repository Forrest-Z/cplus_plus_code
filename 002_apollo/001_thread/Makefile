CXX_FLAGS=-std=c++11
LDFLAGS= -lpthread
CPP_FILES := $(wildcard *.cc)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cc=.o)))
OUTPUT_NAME=thread_example

%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<
  
all: $(OBJ_FILES) 
	$(CXX) $(OBJ_FILES) -fPIC -o $(OUTPUT_NAME)  $(LDFLAGS)

clean:
	rm -f $(OUTPUT_NAME) *.o 

