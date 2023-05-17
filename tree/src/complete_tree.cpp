#include "complete_tree.h"

void judge_complete_tree_test(void)
{
    cout << "start to judge complete tree" << endl;

    Node<int> **tree_root = new Node<int> *;

    gen_incomplete_binary_tree(tree_root);

    judge_complete_tree_solution complete_tree_obj;
    if (complete_tree_obj.judge_complete_tree(tree_root))
    {
        cout << "True!!!" << endl;
    }
    else
    {
        cout << "Not a complete binary tree~" << endl;
    }
}