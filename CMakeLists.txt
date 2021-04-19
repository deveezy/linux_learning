cmake_minimum_required(VERSION 3.0.0)

set(proj LearningLinux)
project(${proj} C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/apue.h)

set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/error.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/pathalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dup2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mycat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.9.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.12-chmod.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/file_hole_demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.23.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.25.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/time_demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/dir_traverse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/mycp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/fig5.4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/fig5.5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/fig5.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/fig5.13_temp_file.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/fig5.15.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/bin_out.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${proj} ${HEADERS} ${SRC})
