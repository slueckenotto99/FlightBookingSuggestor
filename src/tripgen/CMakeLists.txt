cmake_minimum_required(VERSION 3.10...3.28)

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${FlightBookingSuggestor_SOURCE_DIR}/include/*.hpp")
# set(    HEADER_LIST 
#         "${FlightBookingSuggestor_SOURCE_DIR}/include/lib.hpp")

set(    HEADER_LIST 
                            tripgen_obj.h
                            )

# Make an automatic library - will be static or dynamic based on user setting
add_library(tripgen_library
                            tripgen_obj.cpp 
                            tripgen_io.cpp
                            ${HEADER_LIST}
                            )

# All users of this library will need at least C++17
target_compile_features(tripgen_library PUBLIC cxx_std_17)

# We need this directory, and users of our library will need it too
target_include_directories(tripgen_library PUBLIC
                            ${CMAKE_CURRENT_SOURCE_DIR}
                            )

# Install the library's executable
install(TARGETS tripgen_library
                            EXPORT tripgen_library_targets
                            LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../lib
                            ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../lib
                            RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../bin
                            INCLUDES DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../include
                            )

# Install the header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../include/tripgen
                            DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../include
                            )