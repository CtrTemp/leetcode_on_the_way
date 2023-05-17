#include "common_ancestor.h"

void find_tree_node_common_ancestor(void)
{
    cout << "start to find two nodes common ancestor" << endl;
    // 创建二叉树结构

    // 创建二叉树结构
    Node<int> **tree_root = new Node<int> *;
    gen_complete_binary_tree(tree_root);

    find_common_ancestor_solution common_ancestor_obj;

    Node<int> **common_ancestor_ptr = new Node<int> *;
    // 这里如何随机选取树上的两个节点？？？
    // 2023-05-17 end
    // common_ancestor_obj.common_ancestor(common_ancestor_ptr);
}