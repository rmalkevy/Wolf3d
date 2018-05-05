cmake_minimum_required(VERSION 3.8)
project(Wolfenstain)

set(CMAKE_C_STANDARD 99)

include_directories(inc includes minilibx)
link_directories(minilibx)

set(SOURCE_FILES main.c wolf.h draw.c key.c window.c map_reader.c determine_map_size.c free_allocated_memory.c)
add_executable(Wolfenstain ${SOURCE_FILES})

target_link_libraries(Wolfenstain libmlx.a "-framework OpenGL" "-framework AppKit")