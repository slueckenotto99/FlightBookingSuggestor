cmake_minimum_required(VERSION 3.12...3.28)

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${FlightBookingSuggestor_SOURCE_DIR}/include/*.hpp")
# set(    HEADER_LIST 
#         "${FlightBookingSuggestor_SOURCE_DIR}/include/lib.hpp")

set( HEADER_LIST 
                            util.h
                            )

# Make an automatic library - will be static or dynamic based on user setting
add_library( util_library
                            util.cpp 
                            ${HEADER_LIST}
                            )

# All users of this library will need at least C++17
target_compile_features(util_library PUBLIC cxx_std_17)

# We need this directory, and users of our library will need it too
target_include_directories(util_library PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Install the library
install(TARGETS util_library
        EXPORT util_library_targets
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# Install header files to include directory
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/util/
        DESTINATION ${PROJECT_SOURCE_DIR}/include/util
        FILES_MATCHING PATTERN "*.h")