# app 顶层 CMakeList 文件

# 指定当前测试app工程名
project(greedy_is_good LANGUAGES CXX)

# 允许GDB调试
set(CMAKE_BUILD_TYPE DEBUG)

aux_source_directory(.  MAIN_SRC_LIST)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${MAIN_SRC_LIST})

message(STATUS "PRJ:'${PROJECT_NAME}' executable file will be written to ${PROJECT_SOURCE_DIR}/bin")

# 在当前文件夹下 创建目录承接生成的可执行文件
file(MAKE_DIRECTORY "./bin")

target_link_libraries(${PROJECT_NAME} GREEDY_UTILS)

