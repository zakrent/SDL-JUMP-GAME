cmake_minimum_required(VERSION 3.6)
project(SDL-JUMP)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(./lib)


file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        "src/*.h"
        )

add_executable(SDL-JUMP ${SOURCE_FILES} src/entity/Entity.h)

target_link_libraries(SDL-JUMP SDL2-static SDL2main)

include_directories(${SDL2_SOURCE_DIR}/include)

file(COPY textures/ DESTINATION bin/textures/)
file(COPY data/ DESTINATION bin/)

