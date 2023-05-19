#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include "graph_utils.h"

class topological_sort_solution
{
public:
    // 图的拓扑排序
    void sort(_Graph_ graph, vector<int> &result)
    {

        unordered_map<Node *, int> inMap; // 一个记录当前节点入度的哈希表
        queue<Node *> zero_in_node;       // 只有入度为0的进这个队列

        // 首先找到图中第一个入度为0的节点
        // 注意当前是传值，而非传引用，所以不会改变graph的原本结构
        // 遍历图的所有节点
        for (int i = 0; i < graph.nodes.size(); i++)
        {
            Node *current_node = graph.nodes.at(i);
            int in = current_node->in;
            inMap.emplace(current_node, in); // 记录这个节点的入度
            if (in == 0)                     // 找到入度为0的那个节点，放入队列
            {
                zero_in_node.push(current_node);
            }
        }

        while (zero_in_node.size() != 0)
        {
            Node *node_ref = zero_in_node.front();
            result.push_back(node_ref->value); // 排序结果加入数组
            zero_in_node.pop();
            // 遍历当前节点指向的所有节点
            for (int i = 0; i < node_ref->nexts.size(); i++)
            {
                Node *cur_node = node_ref->nexts[i];
                int in = inMap.at(cur_node) - 1; // 抹除当前节点指向它们的边
                inMap.emplace(cur_node, in);
                if (in == 0) // 如果此时哪个节点的入度降为0 则将其加入队列
                {
                    zero_in_node.push(cur_node);
                }
            }
        }
    }
};

void test_topological_sort(void);

#endif