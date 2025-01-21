# 设置最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(HashTableProject)

# 设置 C 标准版本
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 设置默认的构建类型为 Debug（如果未指定）
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 指定源文件路径
set(SRC_FILES
    src/hash_table.c
    src/prime.c
    src/main.c
)

# 添加可执行文件
add_executable(hash_table_program ${SRC_FILES})

# 链接数学库
target_link_libraries(hash_table_program m)

# 设置调试选项
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")

# 为目标添加调试符号
target_compile_options(hash_table_program PRIVATE -g -O0 -Wall -Wextra -pedantic)

