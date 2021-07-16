#include "factory.h"
#include <memory>

class example{
public:
	example():num_ptr(new int){}
	~example(){}

private:
	std::shared_ptr<int> num_ptr = NULL;

};



int main(int argc, char** argv){
	apollo::common::util::Factory<int, example> A;
//	A.register(1, func);   //需要完善
	example B;
	return 0;
}
