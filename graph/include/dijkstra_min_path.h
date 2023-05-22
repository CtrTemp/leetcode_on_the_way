#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph_utils.h"

class dijsktra_solution
{
public:
    /**
     *  dijkstra 算法，最短路径算法
     *  给定图中任意一个点，找到这个点到其他点的最短路径
     * */
    void dijkstra(_Graph_ graph, Node *head, unordered_map<Node *, int> &distanceMap)
    {
        // head 就是给定的“任意节点”
        // distanceMap 记录从这个节点到图中其他节点的最小距离
        distanceMap.emplace(head, 0); // 将自己到自己的距离先设定为0
        // 已经确定了最小距离的点，将被放在这个集合中，在之后的遍历过程中，不再去访问这些节点
        unordered_set<Node *> selectedNodes;
        // 找到一个列表中距离最小的，初始状态下，这个节点总是它本身
        Node *minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
        while (minNode != nullptr)
        {
            int distance = distanceMap.at(minNode); // 当前距离值
            // 下一步是找几个相关节点，看加上距离后会不会让值变大
            for (int i = 0; i < minNode->edges.size(); i++)
            {
                Edge *edge_ref = minNode->edges[i]; // 当前节点的关联边
                Node *to_node = edge_ref->to;       // 当前节点关联边指向的节点
                int weight = edge_ref->weight;      // 关联边/路径的权重（距离）
                // 如果to_node在distanceMap没有记录 或 已记录的值大于当前值
                if (distanceMap.find(to_node) == distanceMap.end() || distanceMap.at(to_node) > distance + weight)
                {
                    distanceMap.emplace(to_node, distance + weight);
                }
            }
            // 将当前的距离最小的边加入"已访问列表"，之后便不再考虑
            selectedNodes.emplace(minNode);
            // 找到下一个minNode，更新
            minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
        }
    }

    // 在distanceMap中找一个最小的记录进行处理，但这个节点不能出现在已经处理过的列表中（相当于是一个刷选）
    Node *getMinDistanceAndUnselectedNode(unordered_map<Node *, int> distanceMap, unordered_set<Node *> selectedNodes)
    {
        Node *ret_node = new Node;
        int minDistance = INT32_MAX;
        // 这里我们是使用遍历的方式选取的distanceMap中的最小值，还有可优化的空间，比如使用堆
        for (unordered_map<Node *, int>::iterator iter = distanceMap.begin(); iter != distanceMap.end(); iter++)
        {
            // 值更小，且这个节点还没有在 selected node 中出现过
            if (selectedNodes.find((*iter).first) == selectedNodes.end() && minDistance > (*iter).second)
            {
                minDistance = (*iter).second;
                ret_node = (*iter).first;
            }
        }
        if (minDistance == INT32_MAX) // new Node 返回不是 nullptr
        {
            return nullptr;
        }

        return ret_node;
    }
};

void test_dijkstra_min_path(void);

#endif