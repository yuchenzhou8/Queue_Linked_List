cmake_minimum_required(VERSION 2.6)

project(QUEUE C)

aux_source_directory(src SRC_LISTS)
list(REMOVE_ITEM SRC_LISTS "src/main.c")
add_executable(index_parse ${SRC_LISTS})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)