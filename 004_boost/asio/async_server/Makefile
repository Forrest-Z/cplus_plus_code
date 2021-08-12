CXX=c++
BOOST_DIR=/usr/lib/x86_64-linux-gnu
FLAGS= -std=c++11   -I$(BOOST_DIR)/include 
FILES=server.o
LDFLAGS= -L$(BOOST_DIR)/ -lboost_system -lpthread

all:
	$(CXX) $(FLAGS) server.cpp -c -o server.o
	$(CXX) $(FLAGS) $(FILES) -o asynctest-server  $(LDFLAGS)
	$(CXX) $(FLAGS) client.cpp  -o asynctest-client  $(LDFLAGS)
clean:
	rm -f asynctest-client asynctest-server  *.o
