if(EXISTS "/home/kayvan/Repos/custom_backend/build/tests_tests-b12d07c.cmake")
  include("/home/kayvan/Repos/custom_backend/build/tests_tests-b12d07c.cmake")
else()
  add_test(tests_NOT_BUILT-b12d07c tests_NOT_BUILT-b12d07c)
endif()