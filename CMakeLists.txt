cmake_minimum_required(VERSION 3.27)
project(Projet_c_2ESGI C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_c_2ESGI
        src/main.c)

target_link_libraries(Projet_c_2ESGI SDL2main SDL2)
