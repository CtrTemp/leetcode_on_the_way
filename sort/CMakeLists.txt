
# 顶层 CMakeList 文件 这个文件应该负责将所有必要源文件编译成库
# 并且指定调用特定的测试程序，为其生成可执行文件。顶层文件不应该生成其本身的可执行文件


# C++ 最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定总工程名
project(sortPack LANGUAGES CXX)

# # 允许GDB调试
# set(CMAKE_BUILD_TYPE DEBUG)

# 添加头文件引用路径
# 注意，使用 INCLUDE_DIRECTORIES 包含的头文件路径可以被各级子目录中的目标所用，是可以传递下去的
# 而使用 TARGET_INCLUDE_DIRECTORIES 包含的头文件路径只能被特定目标所使用
# 所以对于上层目录中的CMakeList文件，我们只需要将本层可见的include的加入即可，
# 之后的 add_subdirectory 会将顶层目录中的头文件引入下级目录中
include_directories(./include ./src)


# 以下的底层调用CMakeList.txt将为其生成对应的库文件（默认生成静态库.a）
add_subdirectory(./src)



add_subdirectory(./app/01_test_bubble_sort)
add_subdirectory(./app/02_test_quick_sort)
add_subdirectory(./app/03_test_insert_sort)

 


