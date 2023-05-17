#include "full_tree.h"

void judge_full_tree_test(void)
{
    cout << "start to judge full tree" << endl;

    Node<int> **tree_root = new Node<int> *;

    gen_complete_binary_tree(tree_root);

    judge_full_tree_solution full_tree_obj;
    if (full_tree_obj.judge_full_tree(tree_root))
    {
        cout << "Current tree is a full binary tree!!!" << endl;
    }
    else
    {
        cout << "NOT a full binary tree" << endl;
    }
}