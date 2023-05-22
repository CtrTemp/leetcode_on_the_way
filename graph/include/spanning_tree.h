#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "graph_utils.h"

class min_spanning_tree_solution
{

public:
    class MySets
    {
    public:
        /**
         *  MySets 结构，只有一个成员变量，用于记录图中的每个节点对应的节点列表；
         * 最开始被初始化为每个节点对应的列表只有它本身，相当于最开始默认图中的每个节点都是孤立的，
         * 等待我们去连接各个边。每连接一条边，这条边两边的两个节点将被归为一个集合内，在这个set
         * 中两个节点的地址也就会指向同一个vector地址。
         *
         *  isSameSet：判断两个节点（一条边两端的）是否在同一个集合内；
         *  unionSet：将两个不在同一集合内的节点合并，并将其list也合并；
         * */
        MySets(_Graph_ graph)
        {
            for (int i = 0; i < graph.nodes.size(); i++)
            {
                Node *node_ptr = graph.nodes.at(i);
                vector<Node *> *node_list = new vector<Node *>{node_ptr};
                sets.emplace(node_ptr, node_list);
            }
        }

        bool isSameSet(Node *node1, Node *node2)
        {
            return sets.at(node1) == sets.at(node2);
        }

        // 合并两个set
        void unionSets(Node *node1, Node *node2)
        {
            vector<Node *> *node1_related_list_ptr = sets.at(node1); // 得到node1对应set的指针
            vector<Node *> *node2_related_list_ptr = sets.at(node2); // 得到node2对应set的指针
            // 遍历node2中的所有元素
            for (int i = 0; i < node2_related_list_ptr->size(); i++)
            {
                // 将node2对应列表中的元素，导入node1对应的列表中
                sets.at(node1)->push_back((*node2_related_list_ptr)[i]);
            }
            // 最后将node2对应列表的指针指向node1对应列表的指针，使二者共享同一个列表
            sets.at(node2) = node1_related_list_ptr;
        }

    public:
        unordered_map<Node *, vector<Node *> *> sets;
    };

public:
    // 图的最小生成树生成

    /**
     *  p 算法，从节点的角度出发生成树
     * */
    void primMST(_Graph_ graph)
    {
        cout << "test primMST" << endl;
        // 在这里，我们使用C++为我们提供的堆结构，而非自己构造大根堆/小根堆，如果想用，可以参考k算法中的示例
        priority_queue<Edge, vector<Edge>, edge_cmp> edge_priority_queue;
        unordered_set<Node *> nodes_set;
        unordered_set<Edge *> result_edges;
        for (unordered_map<int, Node *>::iterator iter = graph.nodes.begin(); iter != graph.nodes.end(); iter++)
        {
            Node *node_ref = (*iter).second;                 // 先任取一个点
            if (nodes_set.find(node_ref) == nodes_set.end()) // 节点不在 set 中
            {
                nodes_set.emplace(node_ref); // 则将节点加入set，表示当前已经连入的节点
                // 由当前节点解锁一系列与之相关的边
                for (int i = 0; i < node_ref->edges.size(); i++)
                {
                    Edge *related_edge_ref = node_ref->edges[i];
                    edge_priority_queue.push(*related_edge_ref); // 这直接相当于 heap_insert
                }
                while (!edge_priority_queue.empty())
                {
                    Edge edge_ref = edge_priority_queue.top();      // 小根堆结构可以保证这条边一定是当前权重最小的
                    edge_priority_queue.pop();                      // 这直接相当于pop之后进行了 heapify
                    Node *to_node = edge_ref.to;                    // 看是否要将这个点拉入
                    if (nodes_set.find(to_node) == nodes_set.end()) // 如果这个点不在已经连通的集合中
                    {

                        nodes_set.emplace(to_node);                                                  // 则将此节点拉入
                        result_edges.emplace(new Edge(edge_ref.weight, edge_ref.from, edge_ref.to)); // 这条边被视为最小生成树的边之一
                        // 遍历这个节点关联的边，并将其加入小根堆
                        for (int i = 0; i < to_node->edges.size(); i++)
                        {
                            // 思考：这里不会重复么？
                            // 虽然会重复放入，但并不会影响对应的结果，，，，（增加常数时间）
                            // 可以再准备一个set，用空间换取时间
                            edge_priority_queue.push(*to_node->edges[i]);
                        }
                    }
                }
            }
            // for 循环的意义是要兼顾“森林”问题，可能不止有一棵树
            // 如果确定没有森林，则在此break即可
            // break;
        }
        // 打印所有边进行验证
        cout << "spanning tree edge(weight) list = ";
        for (unordered_set<Edge *>::iterator iter = result_edges.begin(); iter != result_edges.end(); iter++)
        {
            cout << (*iter)->weight << ", ";
        }
        cout << endl;
    }

    // 构造小根堆辅助函数，构造自定义类优先级队列所需的比较器结构（小根堆结构）
    class edge_cmp
    {
    public:
        bool operator()(const Edge &e1, const Edge &e2)
        {
            return e1.weight > e2.weight;
        }
    };

    /**
     *  k 算法，从边的角度出发生成树
     * */
    void kruskalMST(_Graph_ graph)
    {
        cout << "test kruskalMST" << endl;
        // 构建一种“类似于并查集”的结构
        MySets mysets(graph);
        unordered_set<Edge *> result_edges; // 构成最小生成树的边集

        /**
         *  由于 k 算法从边的角度出发进行考虑，应该是对边进行遍历，首先应该对边按照权重进行排序
         * */
        // 以下我们使用堆排序，遍历图中的所有边，构建大根堆
        vector<Edge> edge_heap;
        for (unordered_set<Edge *>::iterator iter = graph.edges.begin(); iter != graph.edges.end(); iter++)
        {
            node_heap_insert(edge_heap, *(*iter));
        }

        // 依次取堆顶，入栈，出栈时得到的就是一个edge关于权重的升序序列
        stack<Edge> edge_sorted_stack;

        int heap_size = edge_heap.size();
        for (int i = 0; i < edge_heap.size(); i++)
        {
            edge_sorted_stack.push(edge_heap[0]);
            // swap 头尾节点
            Edge swap_val = edge_heap[0];
            edge_heap[0] = edge_heap[heap_size - 1];
            edge_heap[heap_size - 1] = swap_val;
            heap_size--;
            node_heapify(edge_heap, heap_size);
        }

        // 现在 edge_sorted_stack 出栈时得到的就是一个edge关于权重的升序序列，开始弹栈
        while (!edge_sorted_stack.empty())
        {
            Edge edge_ref = edge_sorted_stack.top();
            edge_sorted_stack.pop();
            // 如果这条边链接的两个节点不在同一个集合中
            if (!mysets.isSameSet(edge_ref.from, edge_ref.to))
            {
                // 则对二者进行union
                mysets.unionSets(edge_ref.from, edge_ref.to);
                // 这条边被纳入考虑（被算作是最小生成树的一条边）
                result_edges.emplace(new Edge(edge_ref.weight, edge_ref.from, edge_ref.to));
            }
        }
        // 结束后myset中得到的就是结果
        // 打印验证
        cout << "spanning tree edge(weight) list = ";
        for (unordered_set<Edge *>::iterator iter = result_edges.begin(); iter != result_edges.end(); iter++)
        {
            cout << (*iter)->weight << ", ";
        }
        cout << endl;
    }

    // 辅助函数 构造大根堆
    void node_heap_insert(vector<Edge> &edge_heap, Edge edge)
    {
        edge_heap.push_back(edge);
        int cursor_idx = edge_heap.size() - 1;
        while (cursor_idx > 0)
        {
            int parent_idx = (cursor_idx - 1) / 2;
            if (edge_heap[cursor_idx].weight > edge_heap[parent_idx].weight)
            {
                // swap val
                Edge swap_val = edge_heap[cursor_idx];
                edge_heap[cursor_idx] = edge_heap[parent_idx];
                edge_heap[parent_idx] = swap_val;
                cursor_idx = parent_idx;
            }
            else
            {
                break;
            }
        }
    }
    // 辅助函数 头节点被弹出后，重构数组结构，使其还满足大根堆
    void node_heapify(vector<Edge> &edge_heap, int heap_size)
    {
        if (heap_size <= 1)
        {
            return;
        }

        int cursor_idx = 0;
        int l_child_idx = cursor_idx * 2 + 1;
        while (l_child_idx < heap_size)
        {
            int max_val_idx = l_child_idx + 1 < heap_size &&
                                      edge_heap[l_child_idx + 1].weight > edge_heap[l_child_idx].weight
                                  ? l_child_idx + 1
                                  : l_child_idx;
            max_val_idx = edge_heap[max_val_idx].weight > edge_heap[cursor_idx].weight ? max_val_idx : cursor_idx;
            if (max_val_idx == cursor_idx) // 说明已经到了最优位置，可以认为现在就是大根堆结构了
            {
                // 直接断出
                break;
            }
            // swap
            Edge swap_val = edge_heap[max_val_idx];
            edge_heap[max_val_idx] = edge_heap[cursor_idx];
            edge_heap[cursor_idx] = swap_val;
            // 并且更改当前指针位置
            cursor_idx = max_val_idx;
            l_child_idx = cursor_idx * 2 + 1;
        }
    }
};

void test_generating_spanning_tree(void);

#endif