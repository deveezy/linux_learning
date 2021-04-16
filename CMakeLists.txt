cmake_minimum_required(VERSION 3.0.0)

set(proj LearningLinux)
project(${proj} C)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/apue.h)

set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/error.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dup2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mycat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.12-chmod.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/file_hole_demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/fig4.16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch4/link_demo.c
)
    # ${CMAKE_CURRENT_SOURCE_DIR}/proc.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${proj} ${HEADERS} ${SRC})
