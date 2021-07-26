
#ifndef CYBER_CLASS_LOADER_SHARED_LIBRARY_EXCEPTIONS_H_
#define CYBER_CLASS_LOADER_SHARED_LIBRARY_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace apollo {
namespace cyber {
namespace class_loader {

#define DECLARE_SHARED_LIBRARY_EXCEPTION(CLS, BASE)             \
  class CLS : public BASE {                                     \
   public:                                                      \
    explicit CLS(const std::string& err_msg) : BASE(err_msg) {} \
    ~CLS() throw() {}                                           \
  };

DECLARE_SHARED_LIBRARY_EXCEPTION(LibraryAlreadyLoadedException,
                                 std::runtime_error);
DECLARE_SHARED_LIBRARY_EXCEPTION(LibraryLoadException, std::runtime_error);
DECLARE_SHARED_LIBRARY_EXCEPTION(SymbolNotFoundException, std::runtime_error);

}  // namespace class_loader
}  // namespace cyber
}  // namespace apollo

#endif  // CYBER_CLASS_LOADER_SHARED_LIBRARY_EXCEPTIONS_H_
