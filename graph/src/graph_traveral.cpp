#include "graph_traversal.h"

void test_tree_traversal(void)
{
    // 建图
    _Graph_ graph;
    int **nodeList_ptr = new int *;
    int ***E_Matrix_ptr = new int **;
    // construct_graph_from_adjancency_matrix(graph, true, nodeList_ptr, E_Matrix_ptr); // 构建一张有向图
    construct_graph_from_adjancency_matrix(graph, false, nodeList_ptr, E_Matrix_ptr); // 构建一张无向图
    print_graph_node_list(nodeList_ptr, GRAPH_NODE_LIST_LENGTH);                      // 打印图的节点列表
    print_graph_edge_matrix(E_Matrix_ptr, GRAPH_NODE_LIST_LENGTH);                    // 打印图的邻接矩阵

    cout << "start to traverse tree" << endl;

    width_first_traversal_print(graph.nodes.at(0));
    depth_first_traversal_print(graph.nodes.at(0));
}