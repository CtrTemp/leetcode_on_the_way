# 生成 MEDIAN 取中位数算法相关的库文件
include_directories(.)
aux_source_directory(. MEDIAN_SRC_LIST)

# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
# get root folder absolute path
string(REGEX REPLACE "/src/prefix_tree" "" ROOT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_FOLDER}/lib)

add_library(MEDIAN_VAL ${MEDIAN_SRC_LIST})
