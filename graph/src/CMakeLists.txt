# 生成 GRAPH_UTILS 排序相关的库文件

aux_source_directory(. GRAPH_SRC_LIST)

add_library(GRAPH_UTILS ${GRAPH_SRC_LIST})
