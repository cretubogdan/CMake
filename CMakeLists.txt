cmake_minimum_required(VERSION 3.5.0)
project(app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

include(CTest)
enable_testing()

message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# Specify the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Specify the output directory for libraries (if needed)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
message("CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

# Optionally, specify the output directory for archives (static libraries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

add_subdirectory(src/static_module)
add_subdirectory(src/dynamic_module)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE math_static_lib)
target_link_libraries(app PRIVATE math_dynamic_lib)

add_executable(unittests unittests/test.cpp)
target_link_libraries(unittests PRIVATE math_static_lib)
target_link_libraries(unittests PRIVATE math_dynamic_lib)


add_test(NAME UnitTests COMMAND unittests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
