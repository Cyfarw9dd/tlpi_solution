# 创建us_xfr_cl可执行文件
add_executable(us_xfr_cl us_xfr_cl.c)
target_link_libraries(us_xfr_cl PRIVATE tlpi_lib)

# 创建us_xfr_sv可执行文件
add_executable(us_xfr_sv us_xfr_sv.c)
target_link_libraries(us_xfr_sv PRIVATE tlpi_lib)

# 设置输出目录
set_target_properties(us_xfr_cl us_xfr_sv
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/sockets"
)