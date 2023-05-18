#ifndef LIST_UTILS_H
#define LIST_UTILS_H

// #define SPECIFIED_TREE

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "string.h"
#include "vector"
#include "list"
#include "queue"
#include "stack"

// stl 提供的排序函数
#include "algorithm"
// 对于图结构，免不了要用到哈希map/set结构
#include "unordered_map"
#include "unordered_set"

// 图规模（节点个数）
#define GRAPH_NODE_LIST_LENGTH 6

// 图中节点值的取值范围
#define MAX_RAND_NODE_VAL 100
#define MIN_RAND_NODE_VAL -100

// 图中边权重的取值范围（注意，一般情况下，边的权重都不小于0）
#define MAX_RAND_EDGE_VAL 10
#define MIN_RAND_EDGE_VAL 0

using namespace std;

class Edge; // 两个类互引，后定义的要在前面加声名

/**
 *  图结构节点
 * */
class Node
{

public:
    Node() // 无参 default 构造函数，创建静态数组的时候必须给一个默认构造函数
    {
        value = 0;
        in = 0;
        out = 0;
    };
    Node(int val)
    {
        value = val;
        in = 0;
        out = 0;
    };

public:
    int value;            // 节点取值
    int in;               // 入度
    int out;              // 出度
    vector<Node *> nexts; // 从当前节点发散出去，指向的节点有哪些？
    vector<Edge *> edges; // 从当前节点发散出去的边有哪些
};

/**
 *  图结构边
 * */

class Edge
{
public:
    Edge(int w, Node *f, Node *t)
    {
        weight = w;
        from = f;
        to = t;
    }

public:
    int weight; // 边取值/权重
    Node *from; // 指向src节点
    Node *to;   // 指向dst节点
};

// 图结构
/**
 *
 * */
class _Graph_
{
public:
    _Graph_() = default;

public:
    unordered_map<int, Node *> nodes; // 图中的所有节点使用哈希表表示
    unordered_set<Edge *> edges;      // 图中的所有边使用哈希集合表示
};

// 从一张邻接表中创建出一个图
void static construct_graph_from_adjancency_matrix(_Graph_ &graph, bool isDirected, int **nodeList, int ***E_Matrix)
{
    srand(time(0));
    // 边邻接表生成
    *E_Matrix = new int *[GRAPH_NODE_LIST_LENGTH];
    for (int i = 0; i < GRAPH_NODE_LIST_LENGTH; i++)
    {
        (*E_Matrix)[i] = new int[GRAPH_NODE_LIST_LENGTH];
    }
    for (int i = 0; i < GRAPH_NODE_LIST_LENGTH; i++)
    {
        for (int j = i; j < GRAPH_NODE_LIST_LENGTH; j++)
        {
            if (i == j)
            {
                (*E_Matrix)[i][j] = 0; // 主对角线上的值一定为0
            }
            else
            {
                int rand_val = rand() % (MAX_RAND_EDGE_VAL + MIN_RAND_EDGE_VAL) + MIN_RAND_EDGE_VAL;
                (*E_Matrix)[i][j] = rand_val;
                if (!isDirected) // 如果规定是无向图，该矩阵应该按照主对角线对称
                {
                    (*E_Matrix)[j][i] = rand_val;
                }
                else
                {
                    (*E_Matrix)[j][i] = rand() % (MAX_RAND_EDGE_VAL + MIN_RAND_EDGE_VAL) + MIN_RAND_EDGE_VAL;
                }
            }
        }
    }
    // 创建节点
    Node *node_vec = new Node[GRAPH_NODE_LIST_LENGTH];
    *nodeList = new int[GRAPH_NODE_LIST_LENGTH];
    for (int i = 0; i < GRAPH_NODE_LIST_LENGTH; i++)
    {
        int rand_val = rand() % (MAX_RAND_NODE_VAL - MIN_RAND_NODE_VAL) + MIN_RAND_NODE_VAL;
        Node new_node(rand_val);
        node_vec[i] = new_node;
        (*nodeList)[i] = rand_val; // 同样为要返回的节点列表赋值
    }

    // 从邻接表构图
    for (int i = 0; i < GRAPH_NODE_LIST_LENGTH; i++)
    {
        for (int j = i; j < GRAPH_NODE_LIST_LENGTH; j++)
        {
            int edge_weight = (*E_Matrix)[i][j];
            if (edge_weight != 0) // 当前边存在，从 i 指向 j
            {
                Edge *new_edge = new Edge(edge_weight, &node_vec[i], &node_vec[j]);
                // 为节点 i 添加一条指向 j 节点的边
                node_vec[i].nexts.push_back(&node_vec[j]); // 添加由 i 指向的节点
                node_vec[i].edges.push_back(new_edge);     // 添加由 i 发散出去的边
                node_vec[i].out++;                         // i 节点的出度++
                node_vec[j].in++;                          // j 节点的入度++
                graph.edges.emplace(new_edge);             // 将新创建的边加入图的哈希集合
            }
        }
    }
    // 将编辑好的节点加入图的哈希表
    for (int i = 0; i < GRAPH_NODE_LIST_LENGTH; i++)
    {
        graph.nodes.emplace(i, &node_vec[i]);
    }
}

// 打印一张图的节点信息
void static print_graph_node_list(int **nodeList_ptr, int length)
{
    cout << "graph node list: ";
    for (int i = 0; i < length; i++)
    {
        cout << (*nodeList_ptr)[i] << ", ";
    }
    cout << endl;
}

// 打印一张图的信息
void static print_graph_edge_matrix(int ***edge_matrix_ptr, int matrix_size)
{
    cout << "graph edge matrix: " << endl;
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout << (*edge_matrix_ptr)[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

// 图的宽度优先遍历打印
void static width_first_traversal_print(Node *rand_node)
{
    cout << "Width first traverse & print graph node : ";
    queue<Node *> node_queue;                // 将要继续向深层访问的队列
    unordered_set<Node *> accessed_node_set; // 记录已经访问过的节点，避免重复进队列

    if (rand_node == nullptr)
    {
        cout << "selected node is a null or giving a void graph" << endl;
        return;
    }
    node_queue.push(rand_node);
    accessed_node_set.emplace(rand_node);

    while (node_queue.size() != 0)
    {
        Node *node_ref = node_queue.front();
        node_queue.pop();
        // 宽度优先遍历的操作位置，这里进行打印节点值的操作（宽度优先遍历是在pop的时候处理事件）
        cout << node_ref->value << ", ";
        for (int i = 0; i < node_ref->nexts.size(); i++)
        {
            if (accessed_node_set.find(node_ref->nexts[i]) == accessed_node_set.end())
            {
                // 当前节点没有被访问过，则将其push入队列
                node_queue.push(node_ref->nexts[i]);
                accessed_node_set.emplace(node_ref->nexts[i]);
            }
        }
    }
    cout << endl;
}

void static depth_first_traversal_print(Node *rand_node)
{
    cout << "Depth first traverse & print graph node : ";
    stack<Node *> node_stack;                // 将要继续向深层访问的队列
    unordered_set<Node *> accessed_node_set; // 记录已经访问过的节点，避免重复进队列

    if (rand_node == nullptr)
    {
        cout << "selected node is a null or giving a void graph" << endl;
        return;
    }

    node_stack.push(rand_node);
    cout << rand_node->value << ", ";
    accessed_node_set.emplace(rand_node);

    while (node_stack.size() != 0)
    {
        Node *node_ref = node_stack.top();
        node_stack.pop();
        for (int i = 0; i < node_ref->nexts.size(); i++)
        {
            if (accessed_node_set.find(node_ref->nexts[i]) == accessed_node_set.end())
            {
                // 当前节点没有被访问过，则将其push入队列
                node_stack.push(node_ref);                     // 将当前刚刚弹出的节点重新压栈
                node_stack.push(node_ref->nexts[i]);           // 再将这个没访问过的压栈
                accessed_node_set.emplace(node_ref->nexts[i]); // 加入已访问列表
                // 以上是为了保证当前栈中永远保持当前访问的深度节点序列
                // push 的时候进行一些深度优先遍历需要你进行的操作，这里是打印
                cout << node_ref->nexts[i]->value << ", ";
                break;
            }
        }
    }
    cout << endl;
}

#endif
