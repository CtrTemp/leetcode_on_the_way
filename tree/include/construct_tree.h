#ifndef CONSTRUCT_TREE_H
#define CONSTRUCT_TREE_H

#include "tree_utils.h"

class traverse_tree_solution
{
public:
};

void test_tree_construct(void);

// 从先序、中序中构造树
static Node<int> *process_pre_in(vector<int> &preorder, int pre_left, int pre_right, vector<int> &inorder, int in_left, int in_right)
{
    if (pre_left > pre_right || in_left > in_right)
    {
        return nullptr;
    }
    int in_mid_val = preorder[pre_left];
    int in_mid_idx = 0;
    for (int i = in_left; i <= in_right; i++)
    {
        if (inorder[i] == in_mid_val)
        {
            in_mid_idx = i;
            break;
        }
    }

    Node<int> *root = new Node<int>(in_mid_val);

    int left_tree_seq_len = in_mid_idx - in_left;

    root->left = process_pre_in(preorder, pre_left + 1, pre_left + left_tree_seq_len, inorder, in_left, in_mid_idx - 1);
    root->right = process_pre_in(preorder, pre_left + left_tree_seq_len + 1, pre_right, inorder, in_mid_idx + 1, in_right);

    return root;
}

static Node<int> *construc_tree_pre_in(vector<int> &preorder, vector<int> &inorder)
{
    return process_pre_in(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

// 从后序、中序中构造树
static Node<int> *process_post_in(vector<int> &postorder, int post_left, int post_right, vector<int> &inorder, int in_left, int in_right)
{
    if (post_left > post_right || in_left > in_right)
    {
        return nullptr;
    }
    int in_mid_val = postorder[post_right];
    int in_mid_idx = 0;

    for (int i = in_left; i <= in_right; i++)
    {
        if (inorder[i] == in_mid_val)
        {
            in_mid_idx = i;
            break;
        }
    }

    Node<int> *root = new Node<int>(in_mid_val);

    int tree_right_seq_len = in_right - in_mid_idx;

    root->left = process_post_in(postorder, post_left, post_right - tree_right_seq_len - 1, inorder, in_left, in_mid_idx - 1);
    root->right = process_post_in(postorder, post_right - tree_right_seq_len, post_right - 1, inorder, in_mid_idx + 1, in_right);

    return root;
}

static Node<int>* construc_tree_post_in(vector<int> &postorder, vector<int> &inorder)
{
    return process_post_in(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
}



// 

#endif