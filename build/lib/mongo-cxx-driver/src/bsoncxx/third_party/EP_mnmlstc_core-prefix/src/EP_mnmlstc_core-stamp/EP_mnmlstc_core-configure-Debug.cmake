

set(command "/usr/bin/cmake;-DCMAKE_C_COMPILER=/usr/bin/gcc;-DCMAKE_CXX_COMPILER=/usr/bin/g++;-DCMAKE_BUILD_TYPE=Debug;-DBUILD_TESTING=Off;-DCMAKE_INSTALL_PREFIX:PATH=/usr/local/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc;-DINCLUDE_INSTALL_DIR=.;-GUnix Makefiles;/home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/bsoncxx/third_party/EP_mnmlstc_core-prefix/src/EP_mnmlstc_core")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/bsoncxx/third_party/EP_mnmlstc_core-prefix/src/EP_mnmlstc_core-stamp/EP_mnmlstc_core-configure-out.log"
  ERROR_FILE "/home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/bsoncxx/third_party/EP_mnmlstc_core-prefix/src/EP_mnmlstc_core-stamp/EP_mnmlstc_core-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/bsoncxx/third_party/EP_mnmlstc_core-prefix/src/EP_mnmlstc_core-stamp/EP_mnmlstc_core-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "EP_mnmlstc_core configure command succeeded.  See also /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver/src/bsoncxx/third_party/EP_mnmlstc_core-prefix/src/EP_mnmlstc_core-stamp/EP_mnmlstc_core-configure-*.log")
  message(STATUS "${msg}")
endif()
