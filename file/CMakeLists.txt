# 创建cp_hollow_file可执行文件
add_executable(cp_hollow_file cp_hollow_file.c)
target_link_libraries(cp_hollow_file PRIVATE tlpi_lib)

# 创建my_tee可执行文件
add_executable(my_tee my_tee.c)
target_link_libraries(my_tee PRIVATE tlpi_lib)

# 创建large_file可执行文件
add_executable(large_file large_file.c)
target_link_libraries(large_file PRIVATE tlpi_lib)

# 创建file_test可执行文件
add_executable(file_test file_test.c)
target_link_libraries(file_test PRIVATE tlpi_lib)

# 创建my_dup可执行文件
add_executable(my_dup my_dup.c)
target_link_libraries(my_dup PRIVATE tlpi_lib)

# 创建my_dup2可执行文件
add_executable(my_dup2 my_dup2.c)
target_link_libraries(my_dup2 PRIVATE tlpi_lib)

# 创建copy可执行文件
add_executable(copy copy.c)
target_link_libraries(copy PRIVATE tlpi_lib)

# 创建t_readv可执行文件
add_executable(t_readv t_readv.c)
target_link_libraries(t_readv PRIVATE tlpi_lib)

# 创建tail可执行文件
add_executable(tail tail.c)
target_link_libraries(tail PRIVATE tlpi_lib)


# 设置输出目录
set_target_properties(my_tee cp_hollow_file large_file file_test my_dup my_dup2 copy t_readv tail
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/file"
)