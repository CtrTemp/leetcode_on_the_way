#include "dijkstra_min_path.h"

void test_dijkstra_min_path(void)
{
    // 建图
    _Graph_ graph;
    int **nodeList_ptr = new int *;
    int ***E_Matrix_ptr = new int **;
    construct_graph_from_adjancency_matrix(graph, true, nodeList_ptr, E_Matrix_ptr); // 构建一张有向图（该图必须无环）
    print_graph_node_list(nodeList_ptr, GRAPH_NODE_LIST_LENGTH);                     // 打印图的节点列表
    print_graph_edge_matrix(E_Matrix_ptr, GRAPH_NODE_LIST_LENGTH);                   // 打印图的邻接矩阵

    clock_t begin, end;

    cout << "start to find min path(dijkstra)" << endl;
    begin = clock();
    dijsktra_solution dijsktra_obj;

    unordered_map<Node *, int> distanceMap;
    Node *rand_node = graph.nodes[0];
    dijsktra_obj.dijkstra(graph, rand_node, distanceMap);

    cout << "selected node is : " << rand_node->value << endl;
    cout << "distance Map = " << endl;
    for (unordered_map<Node *, int>::iterator iter = distanceMap.begin(); iter != distanceMap.end(); iter++)
    {
        cout << "Node:" << (*iter).first->value << ",  distance: " << (*iter).second << endl;
    }
    end = clock();
    cout << "time cost = " << (double)(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    cout << endl;

    cout << "start to find min path(dijkstra optimized algorithm)" << endl;
    begin = clock();
    dijsktra_solution_opt dijsktra_opt_obj;

    unordered_map<Node *, int> distanceMap_opt;
    dijsktra_opt_obj.dijkstra(graph, rand_node, distanceMap_opt);

    cout << "selected node is : " << rand_node->value << endl;
    cout << "distance Map = " << endl;
    for (unordered_map<Node *, int>::iterator iter = distanceMap_opt.begin(); iter != distanceMap_opt.end(); iter++)
    {
        cout << "Node:" << (*iter).first->value << ",  distance: " << (*iter).second << endl;
    }
    end = clock();
    cout << "time cost = " << (double)(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    cout << endl;
}