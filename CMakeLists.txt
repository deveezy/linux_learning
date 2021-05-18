cmake_minimum_required(VERSION 3.0.0)

set(proj LearningLinux)
project(${proj} C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/apue.h)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/error.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/pathalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/prmask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/tellwait.c
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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/mem_print.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/write_to_file.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/file_rw_b.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/struct_serialize_json_simple.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/read_array_struct.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch5/yt_io/dir_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch6/time_demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch7/fig7.9_cmd_process.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch7/fig7.11_set_jmp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch7/long_jump.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch7/fig7.13.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.6.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.22.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.28.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.29.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.30.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/fig8.31.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/dup2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/incorrect_fork.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/proc_unix_yt/wait_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch8/exercises/8.7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch9/fig9.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cool_examples/cache_friendly_malloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.10.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.11.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.15.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.18.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.20.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.22.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.23.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.25.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.26.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.28.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.29.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/10.31.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/test_sigprocmask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/jumps.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/jumps2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/jumps_signals.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/1_basic_signal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/2_pause_hangs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/3_intr_malloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/4_sigprocmask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/5_sigaction_info.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/6_sigaction_mask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/sys_prog/9_sigsuspend.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/exercises/e2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/exercises/e6.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch10/exercises/e12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.10.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.11.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.14.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.15.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/11.16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch11/heapsort.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${proj} ${HEADERS} ${SRC})
