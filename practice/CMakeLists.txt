
# 顶层 CMakeList 文件 这个文件应该负责将所有必要源文件编译成库
# 并且指定调用特定的测试程序，为其生成可执行文件。顶层文件不应该生成其本身的可执行文件


# C++ 最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定总工程名
project(graphPack LANGUAGES CXX)

# # 允许GDB调试
set(CMAKE_BUILD_TYPE DEBUG)





add_subdirectory(./lc0004)
add_subdirectory(./lc0051)
add_subdirectory(./lc0072)
add_subdirectory(./lc0076)
add_subdirectory(./lc0297)
 


