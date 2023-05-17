#include "search_tree.h"

void judge_search_tree(void)
{
    cout << "start to judge search tree" << endl;

    Node<int> **tree_root = new Node<int> *;

    gen_complete_binary_tree(tree_root);

    judge_search_tree_solution search_tree_obj;
    // if (search_tree_obj.judge_search_tree(tree_root))
    if (search_tree_obj.judge_search_tree_ano(tree_root))
    {
        cout << "Current tree is a search binary tree!!!" << endl;
    }
    else
    {
        cout << "NOT a search binary tree" << endl;
    }
}