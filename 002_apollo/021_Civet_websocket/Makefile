CXX_FLAGS=-std=c++11
TOP_PATH = $(shell pwd)
LDFLAGS= -lpthread -lgflags libcheck.a libcompat.a libcivetweb.a
CPP_FILES := $(wildcard *.cc)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cc=.o)))
OUTPUT_NAME=websocket



%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<
  
all: $(OBJ_FILES) 
	$(CXX) $(OBJ_FILES) -fPIC -o $(OUTPUT_NAME)  $(LDFLAGS)

clean:
	rm -f $(OUTPUT_NAME) *.o 

