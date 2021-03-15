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
add_executable(SimpleHydraulicNetwork main.cpp include/read_write.h include/ConvEigen.h)
target_link_libraries(SimpleHydraulicNetwork Eigen3::Eigen)
