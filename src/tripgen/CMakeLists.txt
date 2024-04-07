cmake_minimum_required(VERSION 3.12...3.28)

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${FlightBookingSuggestor_SOURCE_DIR}/include/*.hpp")
# set(    HEADER_LIST 
#         "${FlightBookingSuggestor_SOURCE_DIR}/include/lib.hpp")

set( HEADER_LIST 
                            tripgen_obj.h
                            )

# Make an automatic library - will be static or dynamic based on user setting
add_library( tripgen_library
                            tripgen_obj.cpp 
                            tripgen_io.cpp
                            oneway_gen.cpp
                            ${HEADER_LIST}
                            )

# All users of this library will need at least C++17
target_compile_features(tripgen_library PUBLIC cxx_std_17)

# Ensure libraries are built and installed before building executable
add_dependencies( tripgen_library util_library )

# We need this directory, and users of our library will need it too
target_include_directories(tripgen_library PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Install the library
install(TARGETS tripgen_library
        EXPORT tripgen_library_targets
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# Install header files to include directory
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/tripgen/
        DESTINATION ${PROJECT_SOURCE_DIR}/include/tripgen
        FILES_MATCHING PATTERN "*.h")