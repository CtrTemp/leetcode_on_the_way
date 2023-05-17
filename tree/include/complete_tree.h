#ifndef COMPLETE_TREE_H
#define COMPLETE_TREE_H

#include "tree_utils.h"

class judge_complete_tree_solution
{

public:
    // 判断一棵树是否为完全二叉树：借助宽度优先遍历
    bool judge_complete_tree(Node<int> **root)
    {

        // 空树被认为是一颗完全二叉树
        if (*root == nullptr)
        {
            return true;
        }

        bool mark = false; // 当遇到第一个左右孩子不双全的节点后，这个标志位翻转

        queue<Node<int> *> node_queue;
        node_queue.push(*root);
        while (node_queue.size() != 0)
        {
            Node<int> *node_ref = node_queue.front();
            node_queue.pop();

            // 如果 mark 已经被置为 true 了，则需要之后的所有访问的节点都为叶子节点才能保证树是完全二叉树
            if (mark)
            {
                if (node_ref->left != nullptr || node_ref->right != nullptr)
                {
                    cout << endl;
                    // 如果还有左右孩子的，一律返回为false
                    return false;
                }
            }
            if (node_ref->left != nullptr && node_ref->right != nullptr) // 左右孩子双全
            {
                node_queue.push(node_ref->left);
                node_queue.push(node_ref->right);
            }
            else if (node_ref->left != nullptr) // 仅左孩子存在
            {
                node_queue.push(node_ref->left);
                mark = true;
            }
            else if (node_ref->right != nullptr) // 仅右孩子存在
            {
                cout << endl;
                // 左子树为空的情况下右子树不为空，则直接返回false
                return false;
            }

            cout << node_ref->value << ", ";
        }
        cout << endl;

        return true;
    }
};

void judge_complete_tree_test(void);

#endif