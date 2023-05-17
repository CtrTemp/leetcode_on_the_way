#ifndef BALANCE_TREE_H
#define BALANCE_TREE_H

#include "tree_utils.h"

class judge_balance_tree_solution
{

public:
    // 预定义从左右孩子节点返回的信息类/结构体
    class retType
    {
    public:
        retType()
        {
            isBalance = false;
            treeHeight = 0;
        };
        retType(bool f, int h)
        {
            isBalance = f;
            treeHeight = h;
        };
        bool isBalance;
        int treeHeight;
    };

    retType process(Node<int> *node)
    {
        // 首先考虑 base 情况，空指针的情况下认定为是平衡二叉树
        if (node == nullptr)
        {
            return retType(true, 0);
        }

        retType ret_l = process(node->left);  // 左边是不是平衡二叉树？
        retType ret_r = process(node->right); // 右边是不是平衡二叉树？

        // 要满足左右子树的高度相差不超过1，且左右子树都应该是平衡二叉树
        bool isBalance = ret_l.isBalance && ret_r.isBalance && (abs(ret_l.treeHeight - ret_r.treeHeight) < 2);
        int treeHeight = max(ret_l.treeHeight, ret_r.treeHeight) + 1; // 左右高度取最大值+1

        return retType(isBalance, treeHeight);
    }

    // 判断一棵树是否为平衡二叉树，这是一个树型DP问题
    /**
     *  描述为，如果可以将问题分解为一棵树都从它的两个孩子索取“信息”从而解答问题，则称为树型DP问题
     * */
    bool judge_balance_tree(Node<int> **root)
    {
        return process(*root).isBalance;
    }
};

void judge_balance_tree_test(void);

#endif