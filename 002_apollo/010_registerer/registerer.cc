
#include "registerer.h"

namespace apollo {
namespace perception {
namespace lib {

BaseClassMap &GlobalFactoryMap() {
  static BaseClassMap factory_map;
  return factory_map;
}

bool GetRegisteredClasses(
    const std::string &base_class_name,
    std::vector<std::string> *registered_derived_classes_names) {
  if (registered_derived_classes_names == nullptr) {
    std::cout << "registered_derived_classes_names is not available"<<std::endl;
    return false;
  }
  BaseClassMap &map = GlobalFactoryMap();
  auto iter = map.find(base_class_name);
  if (iter == map.end()) {
    std::cout << "class not registered:" << base_class_name<<std::endl;
    return false;
  }
  for (auto pair : iter->second) {
    registered_derived_classes_names->push_back(pair.first);
  }
  return true;
}

}  // namespace lib
}  // namespace perception
}  // namespace apollo
