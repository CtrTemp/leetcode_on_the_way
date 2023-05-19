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

        void unionSets(Node *node1, Node *node2)
        {
            vector<Node *> *node1_related_list_ptr = sets.at(node1);
            vector<Node *> *node2_related_list_ptr = sets.at(node2);
            for (int i = 0; i < node2_related_list_ptr->size(); i++)
            {
                sets.at(node1)->push_back((*node2_related_list_ptr)[i]);
                sets.emplace((*node2_related_list_ptr)[i], sets.at(node1));
            }
        }

    public:
        unordered_map<Node *, vector<Node *> *> sets;
    };

public:
    // 图的最小生成树生成

    /**
     *  p 算法，从节点的角度出发生成树
     * */
    void
    primMST()
    {
    }

    /**
     *  k 算法，从边的角度出发生成树
     * */
    void kruskalMST(_Graph_ graph)
    {
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

        // // 打印验证
        // cout << "construced heap = ";
        // for (int i = 0; i < edge_heap.size(); i++)
        // {
        //     cout << edge_heap[i]->weight << ", ";
        // }
        // cout << endl;

        stack<Edge> edge_sorted_stack;

        int heap_size = edge_heap.size();
        for (int i = 0; i < edge_heap.size(); i++)
        {
            edge_sorted_stack.push(edge_heap[0]);
            // 头尾值互换
            int swap_val = edge_heap[0].weight;
            edge_heap[0].weight = edge_heap[heap_size - 1].weight;
            edge_heap[heap_size - 1].weight = swap_val;
            heap_size--;
            node_heapify(edge_heap, heap_size);
        }

        // 打印验证
        // cout << "sorted edge weight = ";
        // for (int i = 0; i < edge_heap.size(); i++)
        // {
        //     cout << edge_sorted_stack.top().weight << ", ";
        //     edge_sorted_stack.pop();
        // }
        // cout << endl;

        // 现在 edge_sorted_stack 得到的就是edge从小到大排序的结果，开始遍历

        while (!edge_sorted_stack.empty())
        {
            Edge edge_ref = edge_sorted_stack.top();
            edge_sorted_stack.pop();
            // 如果这条边链接的两个节点不在同一个集合中
            if (!mysets.isSameSet(edge_ref.from, edge_ref.to))
            {
                // 则对二者进行union
                mysets.unionSets(edge_ref.from, edge_ref.to);
                result_edges.emplace(&edge_ref);
            }
        }
        // 结束后myset中得到的就是结果
    }

    void node_heap_insert(vector<Edge> &edge_heap, Edge edge)
    {
        edge_heap.push_back(edge);
        int cursor_idx = edge_heap.size() - 1;
        while (cursor_idx > 0)
        {
            int parent_idx = (cursor_idx - 1) / 2;
            if (edge_heap[cursor_idx].weight > edge_heap[parent_idx].weight)
            {
                // swap
                int val_temp = edge_heap[cursor_idx].weight;
                edge_heap[cursor_idx].weight = edge_heap[parent_idx].weight;
                edge_heap[parent_idx].weight = val_temp;
                cursor_idx = parent_idx;
            }
            else
            {
                break;
            }
        }
    }
    // 头节点被弹出后，重构数组结构，使其还满足大根堆
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
            // 否则值互换
            int val_temp = edge_heap[max_val_idx].weight;
            edge_heap[max_val_idx].weight = edge_heap[cursor_idx].weight;
            edge_heap[cursor_idx].weight = val_temp;
            // 并且更改当前指针位置
            cursor_idx = max_val_idx;
            l_child_idx = cursor_idx * 2 + 1;
        }
    }
};

void test_generating_spanning_tree(void);

#endif