cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0091 NEW)
project(r-type_ecs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.6.2 COMPONENTS graphics window system audio REQUIRED)
find_package(Lua REQUIRED)

file(GLOB_RECURSE COMPONENTS_SOURCES
    "src/Components/*/*.cpp"
)

add_executable(r-type_ecs
    ${COMPONENTS_SOURCES}
    src/Main.cpp
    src/Application/Application.cpp
    src/ECS/ECS.cpp
    src/ComponentManager/ComponentManager.cpp
    src/Systems/Systems.cpp
    src/Systems/Systems.hpp
    include/Interface/ISystems.hpp
    include/Abstract/ASystems.hpp
    include/Abstract/ASystems.cpp
)

if(MSVC)
    # Ajout d'options spécifiques à Visual Studio
    target_compile_options(r-type_ecs PRIVATE /W4) # Niveau d'avertissements élevé pour MSVC
else()
    # Ajout d'options pour GCC ou Clang
    target_compile_options(r-type_ecs PRIVATE)
endif()

target_include_directories(r-type_ecs PUBLIC include/Interface)
target_include_directories(r-type_ecs PUBLIC include/Abstract)
target_include_directories(r-type_ecs PRIVATE src/Components)

target_include_directories(r-type_ecs PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(r-type_ecs PRIVATE ${LUA_LIBRARIES})
target_include_directories(r-type_ecs PRIVATE src)
target_link_libraries(r-type_ecs PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
