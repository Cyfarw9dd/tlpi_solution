# 添加timer库
add_library(timer STATIC
    itimerspec_from_str.c
)

target_include_directories(timer PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/lib  # 添加这一行
)

# 创建ptmr_sigev_signal可执行文件
add_executable(ptmr_sigev_signal ptmr_sigev_signal.c)
target_link_libraries(ptmr_sigev_signal PRIVATE tlpi_lib time timer)

# 创建t_nanosleep可执行文件
add_executable(t_nanosleep t_nanosleep.c)
target_link_libraries(t_nanosleep PRIVATE tlpi_lib time timer)

# 创建my_alarm可执行文件
add_executable(my_alarm my_alarm.c)
target_link_libraries(my_alarm PRIVATE tlpi_lib time timer)

# 创建real_timer可执行文件
add_executable(real_timer real_timer.c)
target_link_libraries(real_timer PRIVATE tlpi_lib time timer)

# 设置输出目录
set_target_properties(ptmr_sigev_signal t_nanosleep my_alarm real_timer
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/timer"
)