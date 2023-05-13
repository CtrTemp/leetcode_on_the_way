# 生成 SORT_UTILS 排序相关的库文件

aux_source_directory(. SORT_SRC_LIST)

add_library(SORT_UTILS ${SORT_SRC_LIST})
