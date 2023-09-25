#include "construct_tree.h"

void test_tree_construct(void)
{
    cout << "start to test tree construct" << endl;

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Node<int> *tree_pre_in = construc_tree_pre_in(preorder, inorder);
    Node<int> *tree_post_in = construc_tree_post_in(postorder, inorder);

    width_first_travseral_print(&tree_pre_in);
    width_first_travseral_print(&tree_post_in);
}
