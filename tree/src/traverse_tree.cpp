#include "traverse_tree.h"

void test_tree_traversal(void)
{
    cout << "start to test tree traversal" << endl;

    Node<int> **tree_root = new Node<int> *;

    gen_complete_binary_tree(tree_root);

    // 先序遍历，两种方法 迭代/递归
    cout << "pre order / depth first traversal" << endl;
    preOrder_print_iterative(tree_root);
    cout << endl;
    preOrder_print_recursive(tree_root);
    cout << endl;
    cout << endl;

    // 中序遍历，两种方法 迭代/递归
    cout << "in order traversal" << endl;
    inOrder_print_iterative(tree_root);
    cout << endl;
    inOrder_print_recursive(tree_root);
    cout << endl;
    cout << endl;

    // 后序遍历，两种方法 迭代/递归
    cout << "post order traversal" << endl;
    postOrder_print_iterative(tree_root);
    cout << endl;
    postOrder_print_recursive(tree_root);
    cout << endl;
    cout << endl;

    cout << "width first traversal" << endl;
    width_first_travseral_print(tree_root);
    cout << endl;
}