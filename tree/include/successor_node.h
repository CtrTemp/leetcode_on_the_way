#ifndef SUCCESSOR_NODE_H
#define SUCCESSOR_NODE_H

#include "tree_utils.h"

class find_successor_node_solution
{
public:
    // 给定一个节点，求该节点的后继节点
    /**
     *  实际上可以通过中序遍历的结果搞定，但需要遍历整张表，复杂度/成本过大，不考虑
     * 借助parent指针，可以考虑使用以下的方法
     * */
    void successor_node(Node<int> **root, Node<int> *node, Node<int> **successor_node_ptr)
    {
        // 空树
        if (*root == nullptr)
        {
            *successor_node_ptr = nullptr;
            return;
        }

        Node<int> *cursor = new Node<int>;

        // 情况1：给定的节点有右子树
        if (node->right != nullptr)
        {
            // 则这棵右子树的最左节点就是当前节点的后继节点
            cursor = node->right;
            while (cursor->left != nullptr)
            {
                cursor = cursor->left;
            }
            *successor_node_ptr = cursor;
            return;
        }
        // 情况2：给定的节点没有右子树
        else
        {
            // 一直向上回溯，直到当前节点是其父节点的左孩子
            cursor = node;
            while (cursor->parent != nullptr && cursor->parent->left != cursor)
            {
                cursor = cursor->parent;
            }
            // 情况3：当前节点没有后继节点
            if (cursor->parent == nullptr)
            {
                *successor_node_ptr = nullptr;
                return;
            }
            // 来到父节点
            cursor = cursor->parent;
            // 父节点没有右孩子，则这个节点就是该选中节点的后继
            if (cursor->right == nullptr)
            {
                *successor_node_ptr = cursor;
                return;
            }
            // 如果父节点有右孩子
            else
            {
                // 则这棵右子树的最左节点就是当前节点的后继节点
                cursor = cursor->right;
                while (cursor->left != nullptr)
                {
                    cursor = cursor->left;
                }
                *successor_node_ptr = cursor;
                return;
            }
            // while(cursor)
        }
    }
};

void find_tree_node_successor_node(void);

#endif