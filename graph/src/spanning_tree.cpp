#include "spanning_tree.h"

void test_generating_spanning_tree(void)
{
    // 建图
    _Graph_ graph;
    int **nodeList_ptr = new int *;
    int ***E_Matrix_ptr = new int **;
    construct_graph_from_adjancency_matrix(graph, false, nodeList_ptr, E_Matrix_ptr); // 构建一张无向图
    print_graph_node_list(nodeList_ptr, GRAPH_NODE_LIST_LENGTH);                      // 打印图的节点列表
    print_graph_edge_matrix(E_Matrix_ptr, GRAPH_NODE_LIST_LENGTH);                    // 打印图的邻接矩阵

    cout << "start to generating minimum spanning tree" << endl;

    min_spanning_tree_solution spanning_tree_obj;
    // spanning_tree_obj.p();
    spanning_tree_obj.kruskalMST(graph);
}