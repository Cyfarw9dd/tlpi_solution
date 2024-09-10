cmake_minimum_required(VERSION 3.10)
project(signals)

# 指定 C 标准
set(CMAKE_C_STANDARD 11)

# 包含根目录下的所有文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

# 添加 lib 目录下的所有源文件
file(GLOB LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/*.c")

# 添加 signals 目录下的所有源文件
file(GLOB SIGNALS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# 合并所有源文件
set(SOURCE_FILES ${LIB_SOURCES} ${SIGNALS_SOURCES})

# 添加可执行文件
add_executable(signals ${SOURCE_FILES})

# 指定可执行文件的输出目录
set_target_properties(signals PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# 链接数学库
target_link_libraries(signals m)

