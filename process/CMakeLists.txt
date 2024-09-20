# 创建t_fork可执行文件
add_executable(t_fork t_fork.c)
target_link_libraries(t_fork PRIVATE tlpi_lib)

# 创建fork_file_sharing可执行文件
add_executable(fork_file_sharing fork_file_sharing.c)
target_link_libraries(fork_file_sharing PRIVATE tlpi_lib)

# 创建footprint可执行文件
add_executable(footprint footprint.c)
target_link_libraries(footprint PRIVATE tlpi_lib)

# 创建t_vfork可执行文件
add_executable(t_vfork t_vfork.c)
target_link_libraries(t_vfork PRIVATE tlpi_lib)

# 创建fork_whos_on_first可执行文件
add_executable(fork_whos_on_first fork_whos_on_first.c)
target_link_libraries(fork_whos_on_first PRIVATE tlpi_lib)

# 创建vfork_fd_test可执行文件
add_executable(vfork_fd_test vfork_fd_test.c)
target_link_libraries(vfork_fd_test PRIVATE tlpi_lib)

# 创建fork_sig_sync可执行文件
add_executable(fork_sig_sync fork_sig_sync.c)
target_link_libraries(fork_sig_sync PRIVATE tlpi_lib time)

set_target_properties(t_fork fork_file_sharing footprint t_vfork vfork_fd_test fork_whos_on_first fork_sig_sync
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/process"
)