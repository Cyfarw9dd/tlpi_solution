# 添加time库
add_library(time STATIC
    curr_time.c
)

target_include_directories(time PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/lib  # 添加这一行
)