project(HydraulicLib)

add_library(HydraulicLib
        src/NetworkSolve.cpp
        )
target_include_directories(HydraulicLib PUBLIC include)   # PUBLIC to allow main.cpp to access it

target_link_libraries(HydraulicLib PUBLIC    # PUBLIC so my 'users' also link to Eigen
        Eigen3::Eigen
        )

add_executable(basic_tests
        src/main.cpp
        src/read_write_test.cpp
        src/NetworkSolve_test.cpp)
target_link_libraries(basic_tests HydraulicLib)
target_include_directories(basic_tests PRIVATE include)

add_test(NAME basic_tests COMMAND basic_tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src)