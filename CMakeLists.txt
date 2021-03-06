cmake_minimum_required(VERSION 3.0.0)

set(proj LearningLinux)
project(${proj} C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/apue.h)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/error.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/pathalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/prmask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/tellwait.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/setfl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/openmax.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/clrfl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/locktest.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/lockreg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/lockfile.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/setfd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/spipe.c
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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch12/12.8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch12/12.13.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch12/12.16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch12/12.17.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch13/fig13.1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch13/fig13.7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch14/fig14.1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch14/fig14.7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch14/fig14.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch14/fig14.27.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch14/demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.6.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.11.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.14.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch15/fig15.18.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch16/clcconn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch16/connect_oriented_client.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch16/connect_oriented_server.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch16/initserver.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch17/serv_listen.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch17/serv_accept.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch17/open.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch17/open.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch18/fig18.10.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ch18/ttyname.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/1_clone.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/clone.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/4_not_atomic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/6_bad_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/7_spin_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/8_futex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/10_cthreads_1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/11_cthread_bad_detach.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/12_cthread_detach.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/simple_condvar.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/gcc_thread.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/threads/thread_stacks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/users/set_userid.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/advio/1_nonblock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/advio/2_flock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/advio/3_fcntl_lock.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/3_fs_proc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/4_shared_mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/10_pipe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/11_advanced_pipe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/12_exec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/pipe_simulating.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/proc/multiple_pipes.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/1_simple_sort.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/3_mem_sort.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/test_mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/5_key_t.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/6_msg_get.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/8_sem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/11_shm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/12_sem_posix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/13_sockpair.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/14_sock_dgram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/ipc/15_sock_server.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/8_net/2_getaddrinfo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sys_prog/8_net/3_client.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${proj} ${HEADERS} ${SRC})
