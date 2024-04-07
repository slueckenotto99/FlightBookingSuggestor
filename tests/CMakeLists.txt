# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${FlightBookingSuggestor_SOURCE_DIR}/include/*.hpp")
set(    HEADER_LIST 
        "${PROJECT_SOURCE_DIR}/tests/test.h")

add_executable( testing test.cpp)

add_dependencies( testing util_library )

# Make an automatic library - will be static or dynamic based on user setting
#add_library(test_library test.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(testing PUBLIC ${PROJECT_SOURCE_DIR}/src)


# All users of this library will need at least C++17
target_compile_features(testing PUBLIC cxx_std_17)

target_link_libraries( testing PRIVATE util_library tripgen_library )

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

# Install the library
install(TARGETS testing
        EXPORT testing_targets
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/tests/bin)