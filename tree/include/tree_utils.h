#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#define SPECIFIED_TREE

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "vector"
#include "list"
#include "queue"
#include "stack"

// stl 提供的排序函数
#include "algorithm"

// 生成完全二叉树节长度
#define TREE_LIST_LENGTH 7

// 树中节点值的取值范围
#define MAX_RAND_VAL 10
#define MIN_RAND_VAL -10

using namespace std;

// 树状结构
template <class V>
class Node
{
public:
    Node()
    {
        value = 0;
        left = nullptr;
        right = nullptr;
    };
    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    V value;
    Node *left;
    Node *right;
};

// 注释掉以下的一行 使其生成一棵树非完全二叉树，树中节点的值给定
void static gen_incomplete_binary_tree(Node<int> **root)
{
    *root = new Node<int>(1);
    (*root)->left = new Node<int>(2);
    (*root)->right = new Node<int>(3);
    (*root)->left->left = new Node<int>(4);
    (*root)->left->right = new Node<int>(5);
    (*root)->right->left = new Node<int>(6);
    (*root)->right->right = new Node<int>(7);
    (*root)->left->left->left = new Node<int>(8);
    (*root)->left->left->right = new Node<int>(9);
    (*root)->left->right->left = new Node<int>(10);
    // (*root)->left->right->right = new Node<int>(11);  // 注释它使其变成非完全二叉树
    (*root)->right->left->left = new Node<int>(12);
    (*root)->right->left->right = new Node<int>(13);
    (*root)->right->right->left = new Node<int>(14);
    (*root)->right->right->right = new Node<int>(15);

    (*root)->left->left = nullptr; // 添加这句使得树变成非平衡二叉树
}

// 生成一棵树完全二叉树，树中节点的值完全随机
void static gen_complete_binary_tree(Node<int> **root)
{
    srand(time(0));
    cout << "gen tree list:";

#ifdef SPECIFIED_TREE

    vector<int> tree_val_list = {8, 4, 10, 2, 6, 9, 16, -1, 3, 5, 7};

    Node<int> *tree_node_list = new Node<int>[tree_val_list.size()];
    for (int i = 0; i < tree_val_list.size(); i++)
    {
        int rand_val = tree_val_list[i];
        tree_node_list[i].value = rand_val;
        tree_node_list[i].left = nullptr;
        tree_node_list[i].right = nullptr;

        cout << rand_val << ", ";
    }
    cout << endl;

    // 连接左右孩子
    for (int i = 0; i < tree_val_list.size(); i++)
    {
        int idx_l = i * 2 + 1;
        int idx_r = i * 2 + 2;
        if (idx_l < tree_val_list.size())
        {
            tree_node_list[i].left = &tree_node_list[idx_l];
        }
        if (idx_r < tree_val_list.size())
        {
            tree_node_list[i].right = &tree_node_list[idx_r];
        }
    }

#else
    // 首先准备一个静态数组创建空节点，数值随机，左右孩子置为空
    Node<int> *tree_node_list = new Node<int>[TREE_LIST_LENGTH];
    for (int i = 0; i < TREE_LIST_LENGTH; i++)
    {
        int rand_val = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        tree_node_list[i].value = rand_val;
        tree_node_list[i].left = nullptr;
        tree_node_list[i].right = nullptr;

        cout << rand_val << ", ";
    }
    cout << endl;

    // 连接左右孩子
    for (int i = 0; i < TREE_LIST_LENGTH; i++)
    {
        int idx_l = i * 2 + 1;
        int idx_r = i * 2 + 2;
        if (idx_l < TREE_LIST_LENGTH)
        {
            tree_node_list[i].left = &tree_node_list[idx_l];
        }
        if (idx_r < TREE_LIST_LENGTH)
        {
            tree_node_list[i].right = &tree_node_list[idx_r];
        }
    }

#endif

    // 静态数组不会自动注销，如果你使用的是vector那就完蛋了，函数结束会让你的root指向的内容被free掉
    *root = tree_node_list;
}

// 先序遍历打印 根左右
// 注意，这也是二叉树的深度优先遍历的方法

void static preOrder_print_recursive(Node<int> **root) // 递归方法
{
    if (*root == nullptr)
    {
        return;
    }
    cout << (*root)->value << ", ";
    preOrder_print_recursive(&((*root)->left));
    preOrder_print_recursive(&((*root)->right));
}

void static preOrder_print_iterative(Node<int> **root) // 借助栈，迭代方法
{
    if (*root == nullptr)
    {
        return;
    }
    stack<Node<int> *> node_stack;
    node_stack.push(*root);
    while (node_stack.size() != 0)
    {
        Node<int> *node_ref = node_stack.top();
        node_stack.pop();
        cout << node_ref->value << ", ";
        if (node_ref->right != nullptr)
        {
            node_stack.push(node_ref->right);
        }
        if (node_ref->left != nullptr)
        {
            node_stack.push(node_ref->left);
        }
    }
}

// 中序遍历 左根右

void static inOrder_print_recursive(Node<int> **root) // 递归方法
{
    if (*root == nullptr)
    {
        return;
    }
    inOrder_print_recursive(&((*root)->left));
    cout << (*root)->value << ", ";
    inOrder_print_recursive(&((*root)->right));
}

void static inOrder_print_iterative(Node<int> **root) // 借助栈，迭代方法
{
    if (*root == nullptr)
    {
        return;
    }
    stack<Node<int> *> node_stack;
    Node<int> *cursor = new Node<int>;
    cursor = *root;

    // 初始化：根节点左孩子全都入栈
    while (cursor != nullptr)
    {
        node_stack.push(cursor);
        cursor = cursor->left;
    }

    while (node_stack.size() != 0)
    {
        Node<int> *node_ref = node_stack.top();
        node_stack.pop();
        cout << node_ref->value << ", "; // 弹出时打印节点
        if (node_ref->right != nullptr)  // 访问被弹出节点的右子树
        {
            cursor = node_ref->right;
            while (cursor != nullptr) // 右子树的根如果有左孩子，则将所有树上的左孩子一并压入栈
            {
                node_stack.push(cursor);
                cursor = cursor->left;
            }
        }
    }
}

// 后序遍历 左右根

void static postOrder_print_recursive(Node<int> **root) // 递归方法
{
    if (*root == nullptr)
    {
        return;
    }
    postOrder_print_recursive(&((*root)->left));
    postOrder_print_recursive(&((*root)->right));
    cout << (*root)->value << ", ";
}

void static postOrder_print_iterative(Node<int> **root) // 借助栈，迭代方法
{
    if (*root == nullptr)
    {
        return;
    }
    stack<Node<int> *> node_stack;
    stack<Node<int> *> print_stack;
    node_stack.push(*root);
    while (node_stack.size() != 0)
    {
        Node<int> *node_ref = node_stack.top();
        node_stack.pop();
        // cout << node_ref->value << ", ";
        print_stack.push(node_ref);
        if (node_ref->left != nullptr)
        {
            node_stack.push(node_ref->left);
        }
        if (node_ref->right != nullptr)
        {
            node_stack.push(node_ref->right);
        }
    }
    while (print_stack.size() != 0)
    {
        int node_val = print_stack.top()->value;
        cout << node_val << ", ";
        print_stack.pop();
    }
}

// 宽度优先遍历
// 借助队列实现，先进先出
void static width_first_travseral_print(Node<int> **root)
{

    if (*root == nullptr)
    {
        return;
    }

    // 还是借助宽度优先遍历的方法，但这次需要获取当前节点在树中的深度信息
    vector<int> tree_layer_width;
    int current_layer = 0;

    queue<Node<int> *> node_queue;
    node_queue.push(*root);
    while (node_queue.size() != 0)
    {
        Node<int> *node_ref = node_queue.front();
        node_queue.pop();
        if (node_ref->left != nullptr)
        {
            node_queue.push(node_ref->left);
        }
        if (node_ref->right != nullptr)
        {
            node_queue.push(node_ref->right);
        }
        cout << node_ref->value << ", ";
    }
}

#endif
