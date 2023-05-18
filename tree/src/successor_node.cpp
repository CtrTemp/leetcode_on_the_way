#include "successor_node.h"

void find_tree_node_successor_node(void)
{
    cout << "start to find two nodes common ancestor" << endl;

    // 创建二叉树结构
    Node<int> **tree_root = new Node<int> *;
    gen_complete_binary_tree(tree_root);

    find_successor_node_solution successor_node_obj;

    Node<int> **successor_node_ptr = new Node<int> *;
    Node<int> *selected_node = (*tree_root)->right->right;

    cout << "Selected node is : " << selected_node->value << endl;

    successor_node_obj.successor_node(tree_root, selected_node, successor_node_ptr);

    if (*successor_node_ptr != nullptr)
    {
        cout << "Current node's successor node is : " << (*successor_node_ptr)->value << endl;
    }
    else
    {
        cout << "Don't have any successor node" << endl;
    }
}