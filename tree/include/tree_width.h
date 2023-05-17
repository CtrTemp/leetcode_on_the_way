#ifndef TRAVERSE_TREE_H
#define TRAVERSE_TREE_H

#include "tree_utils.h"

class tree_max_width_solution
{
public:
    // 给定一棵树，求这棵树的最大宽度
    int get_tree_max_width(Node<int> **root)
    {

        if (*root == nullptr)
        {
            return 0;
        }

        // 记录当前节点在第几层？
        unordered_map<Node<int> *, int> depth_map;

        queue<Node<int> *> node_queue;
        node_queue.push(*root);
        depth_map.emplace(*root, 0); // 记录根节点在第0层
        while (node_queue.size() != 0)
        {
            Node<int> *node_ref = node_queue.front();
            node_queue.pop();
            if (node_ref->left != nullptr)
            {
                node_queue.push(node_ref->left);
                depth_map.emplace(node_ref->left, depth_map.at(node_ref) + 1);
            }
            if (node_ref->right != nullptr)
            {
                node_queue.push(node_ref->right);
                depth_map.emplace(node_ref->right, depth_map.at(node_ref) + 1);
            }
        }

        // 记录第几层有几个节点
        unordered_map<int, int> width_map;
        for (unordered_map<Node<int> *, int>::iterator iter = depth_map.begin(); iter != depth_map.end(); iter++)
        {
            // 说明还没记录过这个层
            if (width_map.find((*iter).second) == width_map.end())
            {
                width_map.emplace((*iter).second, 1);
            }
            else
            {
                width_map.at((*iter).second)++;
            }
        }

        int max_width = 0;

        for (unordered_map<int, int>::iterator iter = width_map.begin(); iter != width_map.end(); iter++)
        {
            // 说明还没记录过这个层
            // cout << (*iter).second << ", ";
            if (max_width < (*iter).second)
            {
                max_width = (*iter).second;
            }
        }
        return max_width;
    }
};

void test_tree_max_width(void);

#endif