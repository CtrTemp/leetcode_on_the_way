# 生成 PREFIX_TREE 排序相关的库文件

aux_source_directory(. PREFIX_TREE_GRAPH)

# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
# get root folder absolute path
string(REGEX REPLACE "/src/prefix_tree" "" ROOT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_FOLDER}/lib)

add_library(PREFIX_TREE ${PREFIX_TREE_GRAPH})
