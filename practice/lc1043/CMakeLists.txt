# app 顶层 CMakeList 文件
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 指定当前测试app工程名
project(lc1043 LANGUAGES CXX)

# 允许GDB调试
set(CMAKE_BUILD_TYPE DEBUG)

aux_source_directory(.  MAIN_SRC_LIST)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${MAIN_SRC_LIST})

# message(STATUS "PRJ:'${PROJECT_NAME}' executable file will be written to ${PROJECT_SOURCE_DIR}/bin")

# 在当前文件夹下 创建目录承接生成的可执行文件
# file(MAKE_DIRECTORY "./bin")

# set(ROOT_DIR "1234")
# message(STATUS "${PROJECT_SOURCE_DIR}")


# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

string(REGEX REPLACE "/practice/${CURRENT_FOLDER}" "" ROOT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

message(STATUS "${ROOT_FOLDER}")

set(SORT_ROOT "${ROOT_FOLDER}/sort/lib/libSORT_UTILS.a")


include_directories(
    .
    # ../../sort/include
    # ../../list/include
    # ../../tree/include
    # ../../graph/include
)

# Done !!!!!

# target_link_libraries(${PROJECT_NAME} 
#     ${ROOT_FOLDER}/sort/lib/libSORT_UTILS.a
#     ${ROOT_FOLDER}/list/lib/libLIST_UTILS.a
#     ${ROOT_FOLDER}/tree/lib/libTREE_UTILS.a
#     ${ROOT_FOLDER}/graph/lib/libGRAPH_UTILS.a)

