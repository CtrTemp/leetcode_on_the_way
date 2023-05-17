# 生成 SORT_UTILS 排序相关的库文件

aux_source_directory(. LIST_SRC_LIST)

add_library(LIST_UTILS ${LIST_SRC_LIST})
