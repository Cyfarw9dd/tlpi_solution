# 添加signal_functions库
add_library(signal_functions STATIC
    signal_functions.c
)

target_include_directories(signal_functions PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/lib  # 添加这一行
)

# 创建sig_sender可执行文件
add_executable(sig_sender sig_sender.c)
target_link_libraries(sig_sender PRIVATE tlpi_lib signal_functions)

# 创建sig_receiver可执行文件
add_executable(sig_receiver sig_receiver.c)
target_link_libraries(sig_receiver PRIVATE tlpi_lib signal_functions)

# 创建sig_ignore可执行文件
add_executable(sig_ignore sig_ignore.c)
target_link_libraries(sig_ignore PRIVATE tlpi_lib signal_functions)

# 创建sig_flags可执行文件
add_executable(my_abort my_abort.c)
target_link_libraries(my_abort PRIVATE tlpi_lib signal_functions)

# 设置输出目录
set_target_properties(sig_sender sig_receiver sig_ignore my_abort
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)