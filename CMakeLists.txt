cmake_minimum_required(VERSION 3.12)
project(SimpleHydraulicNetwork)
set(CMAKE_CXX_STANDARD 20)
# check if Doxygen is installed
find_package(Doxygen)
find_package(Eigen3 3.3)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.doxygen)
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")
    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_compile_options(-Wall -Wextra -pedantic -Wmissing-include-dirs -Wformat=2 -Wunused -Wcast-align)

# this can only be applied to C++ sources
set(CMAKE_CXX_FLAGS "-Wnon-virtual-dtor -Woverloaded-virtual")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message("No build type specified, defaulting to Debug (no optimizations, include debug symbols), use -DCMAKE_BUILD_TYPE=RelWithDebInfo or =Release to build a release)")
endif()
enable_testing()
add_subdirectory(HydraulicLib)
add_executable(SimpleHydraulicNetwork main.cpp)
#target_link_libraries(SimpleHydraulicNetwork Eigen3::Eigen)
target_link_libraries(SimpleHydraulicNetwork PRIVATE
        HydraulicLib
        )

if (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
    set(TARGETBITS 32)
else()
    set(TARGETBITS 64)
endif()

message("")
message("SimpleHydraulic configured to run on:  ${CMAKE_SYSTEM_NAME} ${TARGETBITS} bit, ${CMAKE_BUILD_TYPE} Mode")
message("SimpleHydraulic will be built in:      ${CMAKE_BINARY_DIR}")
#message("SimpleHydraulic will be installed in:  ${CMAKE_INSTALL_PREFIX}")  # not applicable here
message("\n")

