if(EXISTS "/home/public/Project/cplus_plus_code/002_apollo/006_gtest/build/test/unit_tests[1]_tests.cmake")
  include("/home/public/Project/cplus_plus_code/002_apollo/006_gtest/build/test/unit_tests[1]_tests.cmake")
else()
  add_test(unit_tests_NOT_BUILT unit_tests_NOT_BUILT)
endif()