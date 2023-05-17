#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "tree_utils.h"

class judge_search_tree_solution
{

public:
    // 中序遍历，中序遍历的结果如果一直是升序的就说明这个树是二叉搜索/排序树
    bool judge_search_tree(Node<int> **root)
    {

        int max_val = INT32_MIN;
        // 如果是空树也被认定为二叉搜索/排序树
        if (*root == nullptr)
        {
            return true;
        }
        stack<Node<int> *> node_stack;
        Node<int> *cursor = new Node<int>;
        cursor = *root;

        // 初始化：根节点左孩子全都入栈
        while (cursor != nullptr)
        {
            node_stack.push(cursor);
            cursor = cursor->left;
        }

        while (node_stack.size() != 0)
        {
            Node<int> *node_ref = node_stack.top();
            node_stack.pop();
            cout << node_ref->value << ", "; // 弹出时打印节点
            if (node_ref->value > max_val)
            {
                max_val = node_ref->value;
            }
            else
            {
                cout << endl;
                // 若出现反序现象，则说明不是二叉搜索/排序树
                return false;
            }
            if (node_ref->right != nullptr) // 访问被弹出节点的右子树
            {
                cursor = node_ref->right;
                while (cursor != nullptr) // 右子树的根如果有左孩子，则将所有树上的左孩子一并压入栈
                {
                    node_stack.push(cursor);
                    cursor = cursor->left;
                }
            }
        }
        cout << endl;

        return true;
    }

    /*************************************** && ***************************************/

    // 看过后面的05和06后，发现搜索二叉树的判断也可以用树型DP的思想来解

    // 预定义从左右孩子节点返回的信息类/结构体
    class retType
    {
    public:
        retType()
        {
            isSearch = false;
            maxVal = INT32_MIN;
            minVal = INT32_MAX;
        };
        retType(bool f, int max, int min)
        {
            isSearch = f;
            maxVal = max;
            minVal = min;
        };
        bool isSearch;
        int maxVal;
        int minVal;
    };

    retType process(Node<int> *node)
    {
        // 首先考虑 base 情况，空指针的情况下认定为是搜索/排序二叉树
        if (node == nullptr)
        {
            return retType(true, INT32_MIN, INT32_MAX);
        }

        retType ret_l = process(node->left);  // 左边是不是搜索/排序二叉树？
        retType ret_r = process(node->right); // 右边是不是搜索/排序二叉树？

        // 仅当左边是 搜索/排序二叉树 右边也是 搜索/排序二叉树，且有 当前节点值大于左边最大值，当前节点值小于右边最小值
        bool isSearch = ret_l.isSearch && ret_r.isSearch && (ret_l.maxVal < node->value) && (node->value < ret_r.minVal);
        int maxVal = ret_r.maxVal == INT32_MIN ? node->value : ret_r.maxVal; // 当前这棵树上的最大值应该是它右子树上的最大值
        int minVal = ret_l.minVal == INT32_MAX ? node->value : ret_l.minVal; // 当前这棵树上的最小值应该是它左子树上的最小值

        return retType(isSearch, maxVal, minVal);
    }

    // 判断一棵树是否为搜索/排序二叉树，这是一个树型DP问题
    /**
     *  描述为，如果可以将问题分解为一棵树都从它的两个孩子索取“信息”从而解答问题，则称为树型DP问题
     * */
    bool judge_search_tree_ano(Node<int> **root)
    {
        return process(*root).isSearch;
    }
};

void judge_search_tree(void);

#endif