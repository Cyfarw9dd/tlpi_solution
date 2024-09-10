cmake_minimum_required(VERSION 3.10)
project(lib)

# 指定 C 标准
set(CMAKE_C_STANDARD 11)

# 包含根目录下的所有文件
include_directories(${CMAKE_SOURCE_DIR})

# 添加源文件
set(SOURCE_FILES
    ./sig_receiver.c
    ./signal_functions.c)

# 添加可执行文件
add_executable(lib ${SOURCE_FILES})

# 指定可执行文件的输出目录
set_target_properties(lib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# 链接数学库
target_link_libraries(lib m)

