#include "balance_tree.h"

void judge_balance_tree_test(void)
{
    cout << "start to judge balance tree" << endl;

    Node<int> **tree_root = new Node<int> *;

    gen_incomplete_binary_tree(tree_root);

    judge_balance_tree_solution balance_tree_obj;
    if (balance_tree_obj.judge_balance_tree(tree_root))
    {
        cout << "Current tree is a balance binary tree!!!" << endl;
    }
    else
    {
        cout << "NOT a balance binary tree" << endl;
    }
}