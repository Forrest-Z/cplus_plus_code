
#include <iostream>
#include "registerer.h"


class BaseClass {
 public:
  BaseClass() = default;
  ~BaseClass() = default;
  virtual std::string Name() const { return "BaseClass1"; }
};
PERCEPTION_REGISTER_REGISTERER(BaseClass);
#define PERCEPTION_REGISTER_TEST(name) \
  PERCEPTION_REGISTER_CLASS(BaseClass, name)

class DerivedClass1 : BaseClass {
 public:
  DerivedClass1() = default;
  ~DerivedClass1() = default;
  virtual std::string Name() const { return "DerivedClass1"; }
};
PERCEPTION_REGISTER_TEST(DerivedClass1);


int main(int argc, char** argv){

  BaseClass* ptr = nullptr;
  ptr = BaseClassRegisterer::GetInstanceByName("DerivedClass1");
  if(ptr == nullptr){
    std::cout<<"error"<<std::endl;
  }
  std::cout<<"ptr->Name()="<<ptr->Name()<<std::endl;
  ptr = BaseClassRegisterer::GetInstanceByName("NotExists");
  BaseClassRegisterer::IsValid("DerivedClass1");
  BaseClassRegisterer::IsValid("NotExists");
  BaseClassRegisterer::GetUniqInstanceName();
  BaseClass* ptr1 = BaseClassRegisterer::GetUniqInstance();
  std::vector<std::string> derived_classes;
  apollo::perception::lib::GetRegisteredClasses("BaseClass", &derived_classes);
  apollo::perception::lib::GetRegisteredClasses("BaseClass2", &derived_classes);
  derived_classes.size();
  derived_classes[0];
  ObjectFactoryDerivedClass1 obj_factory_drived1;
  obj_factory_drived1.NewInstance();
  apollo::perception::lib::Any any;
  // TODO(all) enable this check
  // EXPECT_EQ(any.content_, nullptr);
}



