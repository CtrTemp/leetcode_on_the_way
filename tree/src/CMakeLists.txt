# 生成 TREE_UTILS 排序相关的库文件

aux_source_directory(. TREE_SRC_LIST)

add_library(TREE_UTILS ${TREE_SRC_LIST})
