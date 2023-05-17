#ifndef FULL_TREE_H
#define FULL_TREE_H

#include "tree_utils.h"

class judge_full_tree_solution
{

public:
    // 预定义从左右孩子节点返回的信息类/结构体
    class retType
    {
    public:
        retType()
        {
            isFull = false;
            treeHeight = 0;
        };
        retType(bool f, int h)
        {
            isFull = f;
            treeHeight = h;
        };
        bool isFull;
        int treeHeight;
    };

    retType process(Node<int> *node)
    {
        // 首先考虑 base 情况，空指针的情况下认定为是满二叉树
        if (node == nullptr)
        {
            return retType(true, 0);
        }

        retType ret_l = process(node->left);  // 左边是不是满二叉树？
        retType ret_r = process(node->right); // 右边是不是满二叉树？

        bool isFull = ret_l.isFull && ret_r.isFull && (ret_l.treeHeight == ret_r.treeHeight);
        int treeHeight = ret_l.treeHeight + 1; // 任取左右一个树的高度即可

        // 左右两边都是满二叉树才可认为根节点是一颗满二叉树
        return retType(isFull, treeHeight);
    }

    // 判断一棵树是否为满二叉树，这是一个树型DP问题
    /**
     *  描述为，如果可以将问题分解为一棵树都从它的两个孩子索取“信息”从而解答问题，则称为树型DP问题
     * */
    bool judge_full_tree(Node<int> **root)
    {
        return process(*root).isFull;
    }
};

void judge_full_tree_test(void);

#endif