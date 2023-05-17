#include "tree_width.h"

void test_tree_max_width(void)
{
    cout << "start to test tree width" << endl;
    // 创建二叉树结构

    // 创建二叉树结构
    Node<int> **tree_root = new Node<int> *;
    gen_complete_binary_tree(tree_root);

    tree_max_width_solution tree_width_obj;
    int max_width = tree_width_obj.get_tree_max_width(tree_root);
    cout << "max width of current tree = " << max_width << endl;
}