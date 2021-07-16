
#include "vehicle_factory.h"

void VehicleFactory::RegisterVehicleFactory(){
	register();
}

std::unique_ptr<AbstractVehicleFactory> VehicleFactory::CreateVehicle(
	const VehicleParameter &vehicle_parameter){
	
	auto abstract_factory = CreateObject();
	if(!abstract_factory){
		std::cout<<"error"<<std::endl;
	}else{
		abstract_factory->SetVehicle(vehicle_parameter);
		std::cout<<"sucessfully create~"<<std::endl;
	}
	return abstract_factory;
}

