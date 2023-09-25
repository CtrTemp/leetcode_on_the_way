#ifndef TRAVERSE_TREE_H
#define TRAVERSE_TREE_H

#include "tree_utils.h"

class traverse_tree_solution
{
public:
};

void test_tree_traversal(void);

void test_tree_traversal_ano(void);

// 深度优先遍历 DFS

// 中序遍历：左中右
void static dfs_inOrder_recursive(Node<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    dfs_inOrder_recursive(root->left);
    cout << root->value << ',';
    dfs_inOrder_recursive(root->right);
}

// 迭代写法，模拟压栈，中序遍历单栈即可解决
// 策略是左侧压栈一压到底，弹栈的时候打印
void static dfs_inOrder_iterative(Node<int> *root)
{
    stack<Node<int> *> st;
    while (root != nullptr)
    {
        st.push(root);
        root = root->left;
    }
    while (!st.empty())
    {
        Node<int> *node_temp = st.top();
        st.pop();
        cout << node_temp->value << ',';
        node_temp = node_temp->right;
        while (node_temp != nullptr)
        {
            st.push(node_temp);
            node_temp = node_temp->left;
        }
    }
}

// 先序遍历：中左右
void static dfs_preOrder_recursive(Node<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->value << ',';
    dfs_preOrder_recursive(root->left);
    dfs_preOrder_recursive(root->right);
}

// 迭代写法，模拟压栈，先序遍历单栈即可解决
// 策略是弹栈打印，并按右左的顺序将当前节点的左右孩子入栈
void static dfs_preOrder_iterative(Node<int> *root)
{
    stack<Node<int> *> st;
    st.push(root);
    while (!st.empty())
    {
        Node<int> *node_temp = st.top();
        st.pop();
        cout << node_temp->value << ',';
        if (node_temp->right != nullptr)
        {
            st.push(node_temp->right);
        }
        if (node_temp->left != nullptr)
        {
            st.push(node_temp->left);
        }
    }
}

// 后序遍历：左右中
void static dfs_postOrder_recursive(Node<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    dfs_postOrder_recursive(root->left);
    dfs_postOrder_recursive(root->right);
    cout << root->value << ',';
}

// 迭代写法，模拟压栈，后序遍历需要双栈解决，压栈顺序与中序相反
void static dfs_postOrder_iterative(Node<int> *root)
{
    stack<Node<int> *> st;
    stack<Node<int> *> st_print;

    st.push(root);

    while (!st.empty())
    {
        Node<int> *node_temp = st.top();
        st_print.push(node_temp);
        st.pop();
        if (node_temp->left != nullptr)
        {
            st.push(node_temp->left);
        }
        if (node_temp->right != nullptr)
        {
            st.push(node_temp->right);
        }
    }

    while (!st_print.empty())
    {
        cout << st_print.top()->value << ',';
        st_print.pop();
    }
}

// 广度优先遍历 层序遍历 BFS
// 一般借助队列结构，从上到下遍历
void static bfs_tree_traversal(Node<int> *root)
{
    queue<Node<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<int> *node_temp = q.front();
        q.pop();
        cout << node_temp->value << ',';
        if (node_temp->left != nullptr)
        {
            q.push(node_temp->left);
        }
        if (node_temp->right != nullptr)
        {
            q.push(node_temp->right);
        }
    }
}

// BFS 并且能够实时获取当前的深度
void static bfs_tree_traversal_with_depth(Node<int> *root)
{
    // 使用pair，单给一个变量存深度
    queue<pair<Node<int> *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        Node<int> *node_temp = q.front().first;
        int depth = q.front().second;
        q.pop();
        cout << node_temp->value << ',';
        if (node_temp->left != nullptr)
        {
            q.push({node_temp->left, depth+1});
        }
        if (node_temp->right != nullptr)
        {
            q.push({node_temp->right, depth+1});
        }
    }
}

// 如何实现从下到上的遍历呢？
void static bfs_tree_traversal_from_bottom(Node<int> *root)
{

}





#endif