#ifndef COMMON_ANCESTOR_H
#define COMMON_ANCESTOR_H

#include "tree_utils.h"

class find_common_ancestor_solution
{
public:
    class retType
    {
    public:
        retType()
        {
            l_contain = false;
            r_contain = false;
            self = false;
        }
        retType(bool l, bool r, bool s)
        {
            l_contain = l;
            r_contain = r;
            self = s;
        }

        bool l_contain; // 左边是否包含二选中节点其一
        bool r_contain; // 右边是否包含二选中节点其一
        bool self;      // 当前节点本身是否包含二选中节点其一
    };

    retType process(Node<int> *root, Node<int> *node1, Node<int> *node2, Node<int> **common_ancestor_ptr)
    {
        // base case 当前节点为null则返回全false,不可能为公共祖先
        if (root == nullptr)
        {
            return retType(false, false, false);
        }

        // 分别处理左右部分
        retType ret_l = process(root->left, node1, node2, common_ancestor_ptr);
        retType ret_r = process(root->right, node1, node2, common_ancestor_ptr);

        // 左边包含：左树的三个判断值只要有一个成立即可
        bool l_contain = ret_l.l_contain || ret_l.r_contain || ret_l.self;
        // 右边包含：右树的三个判断值只要有一个成立即可
        bool r_contain = ret_r.l_contain || ret_r.r_contain || ret_r.self;
        // 当前节点本身是否是选中节点之一
        bool self = (node1 == root) || (node2 == root);

        // 这个判断的逻辑是基于：三者中有两者为true，则当前节点为公共祖先；且一定不会出现三者都为true的情况
        if ((l_contain || r_contain || self) && (l_contain ^ r_contain ^ self == false))
        {
            *common_ancestor_ptr = root;
        }

        return retType(l_contain, r_contain, self);
    }

    // 给定两个节点，求树的最大公共祖先，同样尝试使用树型DP问题的套路来解决
    void common_ancestor(Node<int> **root, Node<int> *node1, Node<int> *node2, Node<int> **common_ancestor_ptr)
    {
        // 空树
        if (*root == nullptr)
        {
            *common_ancestor_ptr = nullptr;
            return;
        }
        // 给定俩节点就是同一个节点，直接返回
        if (node1 == node2)
        {
            *common_ancestor_ptr = node2;
            return;
        }
        // 先将公共祖先指向null，后开始递归解决问题
        *common_ancestor_ptr = nullptr;
        process(*root, node1, node2, common_ancestor_ptr);
    }
};

void find_tree_node_common_ancestor(void);

#endif