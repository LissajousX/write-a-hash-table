# 设置最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(HashTableProject)

# 设置 C 标准版本
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

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
