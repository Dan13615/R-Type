cmake_minimum_required(VERSION 3.16)
project(traductor)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Error.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Traductor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TraductorElement.cpp
)

# Create a static library
add_library(traductor STATIC ${SRC})

# Output library to the "lib" directory in the root of the project
set(LIB_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INCLUDE_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/include)

set_target_properties(traductor PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
)

# Ensure output directories exist and copy files
add_custom_command(
    TARGET traductor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${INCLUDE_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:traductor> ${LIB_OUTPUT_DIR}/libtraductor.a
)
