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

class dijsktra_solution_opt
{

public:
    class NodeRecord
    {
    public:
        NodeRecord(Node *n, int d)
        {
            node = n;
            distance = d;
        }

    public:
        Node *node;
        int distance;
    };

public:
    // 修改堆结构进行解题，注意我们构造的是小根堆
    class NodeHeap
    {
        // 构造函数
    public:
        NodeHeap(int s)
        {
            nodes = new Node *[s]; // heap 就是一个数组，先为数组建立空间分配
            size = 0;              // heap size
            // 是否需要对 unordered_map 也进行初始化呢？
        }

        // 堆基础操作
    public:
        /**
         *  注意这里不仅仅是单纯的heapInsert，这个函数的意思是：
         *  对在idx位置处的节点进行heapify
         *  但这里提供的第一个参数的意义是啥呢？
         * */
        //
        // void insertHeapify(Node *node, int idx)
        void insertHeapify(int idx)
        {
            while (distanceMap.at(nodes[idx]) < distanceMap.at(nodes[(idx - 1) / 2]))
            {
                swap(idx, (idx - 1) / 2);
                idx = (idx - 1) / 2;
            }
        }
        void heapify(int idx, int size) // 从哪里开始向下heapify
        {
            // 这里已经是交换后了，idx指示被交换节点的位置，注意我们维护的是小根堆
            int idx_l = idx * 2 + 1;
            while (idx_l < size)
            {
                int smaller_idx = (idx_l + 1 < size && distanceMap.at(nodes[idx_l]) > distanceMap.at(nodes[idx_l + 1]))
                                      ? idx_l + 1
                                      : idx_l;
                smaller_idx = (distanceMap.at(nodes[smaller_idx]) < distanceMap.at(nodes[idx]))
                                  ? smaller_idx
                                  : idx;
                if (smaller_idx == idx) // 如果不再需要进行交换了，则断出
                {
                    break;
                }
                swap(smaller_idx, idx);
                idx = smaller_idx;
                idx_l = idx * 2 + 1;
            }
        }
        NodeRecord pop()
        {
            NodeRecord record(nodes[0], distanceMap.at(nodes[0]));
            swap(0, size - 1);
            // -1表示虽然它还能在这个unordered_map中被查询到，也就是进入过堆，但它已经不在现在的堆中了
            heapIndexMap.at(nodes[size - 1]) = -1;
            distanceMap.erase(nodes[size - 1]); // distance map 中直接清除这个节点即可
            // delete nodes[size - 1]; // 是这样释放内存么
            nodes[size - 1] = nullptr; // 这里不代表释放了内存，要如何释放内存呢？

            heapify(0, size - 1); // 0位置上heapify
            size--;

            return record;
        }
        // 其他堆操作
    public:
        bool empty() // 判断当前 NodeHeap 是否为空
        {
            return size == 0;
        }

        // 判断给定的节点是否已经被放入了indexMap，或之前进来过，后被弹出，也会返回true
        // 这是因为实际上我们“弹出”只是对堆结构进行了元素交换，“被弹出”的元素被放在了数组最后面大于heap size的位置
        bool entered(Node *node)
        {
            return heapIndexMap.find(node) != heapIndexMap.end();
        }

        // 判断给定的节点是否在当前的堆中（位置必须小于heap size）
        // 后面的判断基于的设计是：一旦我们pop出某个元素，则将其heapIndexMap中对应的值设为-1
        bool inHeap(Node *node)
        {
            // bool condition1 = entered(node);
            // bool condition2 = (heapIndexMap.at(node) != -1);
            return entered(node) && (heapIndexMap.at(node) != -1);
        }

        // swap 方法，交换堆中两个元素的位置
        // 不仅要交换数组中的位置，也需要将 heapIndexMap 中的值进行交换
        void swap(int idx1, int idx2)
        {
            heapIndexMap.at(nodes[idx1]) = idx2;
            heapIndexMap.at(nodes[idx2]) = idx1;

            Node *swap_temp_val = nodes[idx1];
            nodes[idx1] = nodes[idx2];
            nodes[idx2] = swap_temp_val;
        }

        // 题解附加操作
        void addOrUpdateOrIgnore(Node *node, int distance)
        {
            // 如果当前这个节点在当前堆中，distance小于原位置则对其进行更新
            if (inHeap(node))
            {
                distanceMap.at(node) = min(distance, distanceMap.at(node));
                insertHeapify(heapIndexMap.at(node));
            }
            // 如果这个节点就从来没进入过当前的堆，则直接将其加入堆即可
            if (!entered(node))
            {
                nodes[size] = node;
                distanceMap.emplace(node, distance);
                heapIndexMap.emplace(node, size);
                insertHeapify(size);
                size++;
            }
            // 剩下一种情况就是进入过堆，但不在当前的堆上，这种情况就说明这个节点已经达到距离最优化了，
            // 被pop出去了，所以什么都不做即可
        }

    public:
        Node **nodes;                            // 堆的本质是数组
        unordered_map<Node *, int> heapIndexMap; // 一个数在堆数组中的什么位置？
        unordered_map<Node *, int> distanceMap;  // 记录一个node到指定节点(head)当前的最短距离
        int size;                                // heap size
    };

public:
    /**
     *  dijkstra 算法的优化解法
     *  同样是给定图中任意一个点，找到这个点到其他点的最短路径
     *  这里需要对堆结构进行改写
     * */
    void dijkstra(_Graph_ graph, Node *head, unordered_map<Node *, int> &distanceMap)
    {
        NodeHeap nodeHeap(graph.nodes.size()); // 建立辅助数据结构
        nodeHeap.addOrUpdateOrIgnore(head, 0);
        while (!nodeHeap.empty())
        {
            NodeRecord record = nodeHeap.pop();
            Node *node_ref = record.node;
            int distance = record.distance;
            for (int i = 0; i < node_ref->edges.size(); i++)
            {
                Edge *edge_ref = node_ref->edges[i];
                nodeHeap.addOrUpdateOrIgnore(edge_ref->to, edge_ref->weight + distance);
            }
            distanceMap.emplace(node_ref, distance);
        }
    }
};

void test_dijkstra_min_path(void);

#endif