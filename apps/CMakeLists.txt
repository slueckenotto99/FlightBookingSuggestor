cmake_minimum_required(VERSION 3.12...3.28)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  FlightBookingSuggestor
  VERSION 0.0.1
  LANGUAGES CXX)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
#add_library(MyLibExample simple_lib.cpp simple_lib.hpp)

# Link each target with other targets or add options, etc.

# Adding something we can run - Output name matches target name
add_executable( FBS 
                FBS_exec.cpp)

# Ensure libraries are built and installed before building executable
add_dependencies( FBS tripgen_library )

# target_include_directories(FBS PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(FBS PRIVATE tripgen_library util_library)

# Install the library
install(TARGETS FBS
        EXPORT FBS_targets
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# Install header files to include directory
install(DIRECTORY ${PROJECT_SOURCE_DIR}/apps/
        DESTINATION ${PROJECT_SOURCE_DIR}/include/
        FILES_MATCHING PATTERN "*.h")