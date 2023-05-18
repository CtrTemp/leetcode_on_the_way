#include "common_ancestor.h"

void find_tree_node_common_ancestor(void)
{
    cout << "start to find two nodes common ancestor" << endl;

    // 创建二叉树结构
    Node<int> **tree_root = new Node<int> *;
    gen_complete_binary_tree(tree_root);

    find_common_ancestor_solution common_ancestor_obj;

    Node<int> **common_ancestor_ptr = new Node<int> *;
    Node<int> *node1 = (*tree_root)->left->left;
    Node<int> *node2 = (*tree_root)->left->right;

    cout << "Selected nodes are : " << node1->value << ", " << node2->value << endl;
    // 这里如何随机选取树上的两个节点？？？
    // 2023-05-17 end
    common_ancestor_obj.common_ancestor(tree_root, node1, node2, common_ancestor_ptr);
    if (*common_ancestor_ptr == nullptr)
    {
        cout << "the selected nodes don't have any common ancestor" << endl;
    }
    else
    {
        cout << (*common_ancestor_ptr)->value << " is the commom ancestor of the selected nodes" << endl;
    }
}