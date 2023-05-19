#include "topological_sort.h"

void test_topological_sort(void)
{
    // 建图
    _Graph_ graph;
    int **nodeList_ptr = new int *;
    int ***E_Matrix_ptr = new int **;
    construct_graph_from_adjancency_matrix(graph, true, nodeList_ptr, E_Matrix_ptr); // 构建一张有向图（该图必须无环）
    print_graph_node_list(nodeList_ptr, GRAPH_NODE_LIST_LENGTH);                     // 打印图的节点列表
    print_graph_edge_matrix(E_Matrix_ptr, GRAPH_NODE_LIST_LENGTH);                   // 打印图的邻接矩阵

    cout << "start to topological sort" << endl;

    topological_sort_solution topological_sort_obj;
    vector<int> result;
    topological_sort_obj.sort(graph, result);
    cout << "sort result = ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << endl;
}