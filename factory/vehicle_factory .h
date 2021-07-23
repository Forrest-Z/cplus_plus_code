
#pragma once
 
#include "factory"

enum VehicleBrand {
  LINCOLN_MKZ = 0,
  GEM = 1,
  LEXUS = 2,
  TRANSIT = 3,
  GE3 = 4,
  WEY = 5,
  ZHONGYUN = 6,
  CH = 7
};


class VehicleFactory : public apollo::util::Factory<VehicleBrand, AbstractVehicleFactory>{
public:
	void RegisterVehicleFactory();

	std::unique_ptr<AbstractVehicleFactory> CreateVehicle(const VehicleParameter &vehicle_parameter);
};





