# 创建ptmr_sigev_signal可执行文件
add_executable(simple_thread simple_thread.c)
target_link_libraries(simple_thread PRIVATE tlpi_lib)

# 创建thread_incr可执行文件
add_executable(thread_incr thread_incr.c)
target_link_libraries(thread_incr PRIVATE tlpi_lib)

# 创建thread_test可执行文件
add_executable(thread_test thread_test.c)
target_link_libraries(thread_test PRIVATE tlpi_lib)

# 设置输出目录
set_target_properties(simple_thread thread_incr thread_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/threads"
)