#  ---- SETUP ---- #
cmake_minimum_required(VERSION 3.16)
project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#  ---- FIND PACKAGES ---- #
find_package(Boost 1.70 REQUIRED COMPONENTS system)
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window system audio network)

#  ---- LIBRARIES ---- #
set(RTYPE_LIBRARIES
    gradeDe
    papaya
    rfcArgParser
    traductor
)

foreach(LIB ${RTYPE_LIBRARIES})
    add_subdirectory(lib/${LIB})
endforeach()

#  ---- SOURCES ---- #
file(GLOB_RECURSE SOURCES
    "src/**/**/**/**/**/**/**/*.cpp"
    "src/**/**/**/**/**/**/*.cpp"
    "src/**/**/**/**/**/*.cpp"
    "src/**/**/**/**/*.cpp"
    "src/**/**/**/*.cpp"
    "src/**/**/*.cpp"
    "src/**/*.cpp"
    "src/*.cpp"
)

#  ---- EXECUTABLE ---- #
add_executable(r-type_client ${SOURCES})

#  ---- COMPILE OPTIONS ---- #
if(MSVC)
    target_compile_options(r-type_client PRIVATE /W4)
else()
    target_compile_options(r-type_client PRIVATE)
endif()

#  ---- INCLUDES ---- #
foreach(LIB ${RTYPE_LIBRARIES})
    target_include_directories(r-type_client PRIVATE "lib/${LIB}/include/")
endforeach()

target_include_directories(r-type_client PRIVATE
    ${Boost_INCLUDE_DIRS}
    "src/"
)

#  ---- LINK LIBRARIES ---- #
target_link_libraries(r-type_client PRIVATE
    ${RTYPE_LIBRARIES}
    sfml-graphics sfml-window sfml-system sfml-audio sfml-network
    Boost::system
)

#  ---- POST BUILD ---- #
add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ${CMAKE_SOURCE_DIR}
)
