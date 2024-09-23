# 创建my_tee可执行文件
add_executable(my_tee my_tee.c)
target_link_libraries(my_tee PRIVATE tlpi_lib)

# 设置输出目录
set_target_properties(my_tee 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/file"
)