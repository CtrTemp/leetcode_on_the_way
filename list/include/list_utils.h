#ifndef LIST_UTILS_H
#define LIST_UTILS_H

// 加入这个宏定义将会使得整个工程使用以下个人定义的确切数组构成链表，而非随机数字链表，用于检查一些特殊情况
// #define SPECIFIED_LIST

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

// 生成测试链表长度
#define LIST_LENGTH 10

// 链表值的取值范围
#define MAX_RAND_VAL 10
#define MIN_RAND_VAL -10

using namespace std;

// 单链表结构
template <class V>
class Node
{
public:
    Node()
    {
        value = 0;
        next = nullptr;
        random = nullptr;
    };
    V value;
    Node *next;
    Node *random;
};

// 双链表结构
template <class V>
class dNode
{
public:
    V value;
    dNode *next;
    dNode *last;
};

void static gen_random_Node_list(Node<int> **head)
{
    srand(time(0));
    *head = new Node<int>;
    Node<int> *cursor = *head;
#ifdef SPECIFIED_LIST
    // vector<int> specified_list = {1, 2, 3, 4, 5, 4, 3, 2, 1}; // 用于回文判断
    vector<int> specified_list = {1, -2, 3, 0, 0, 4, -3, -2, 1}; // 用于链表分割（最普遍的情况）
    // vector<int> specified_list = {1, 3, 0, 0, 4, 1}; // 用于链表分割（没有小于部分）
    // vector<int> specified_list = {1, -2, 3, 4, -3, -2, 1}; // 用于链表分割（没有等于部分）
    // vector<int> specified_list = {-1, -2, 0, 0, -4, -3, -2, -1}; // 用于链表分割（没有大于部分）
    for (int i = 0; i < specified_list.size(); i++)
    {
        cursor->value = specified_list[i];
        if (i == specified_list.size() - 1)
        {
            cursor->next = nullptr;
            break;
        }
        cursor->next = new Node<int>;
        cursor = cursor->next;
    }

#else

    for (int i = 0; i < LIST_LENGTH - 1; i++)
    {
        cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        cursor->next = new Node<int>;
        cursor = cursor->next;
    }
    cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    cursor->next = nullptr;

#endif
}

void static print_Node_list(Node<int> **head)
{
    cout << "print own list : ";
    Node<int> *cursor = *head;
    while (cursor != nullptr)
    {
        cout << cursor->value << ", ";
        cursor = cursor->next;
    }
    cout << endl;
}

void static gen_random_dNode_list(dNode<int> **head, dNode<int> **tail)
{
    srand(time(0));
    *head = new dNode<int>;
    *tail = new dNode<int>;
    dNode<int> *cursor = *head;
    (*head)->last = nullptr;
    for (int i = 0; i < LIST_LENGTH - 1; i++)
    {
        cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        cursor->next = new dNode<int>;
        cursor->next->last = cursor;
        cursor = cursor->next;
    }
    *tail = cursor;
    cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    cursor->next = nullptr;
}

void static print_dNode_list(dNode<int> **head, dNode<int> **tail)
{
    cout << "print own dlist : " << endl;

    cout << "head to tail: ";
    dNode<int> *cursor = *head;
    while (cursor != nullptr)
    {
        cout << cursor->value << ", ";
        cursor = cursor->next;
    }
    cout << endl;

    cout << "tail to head: ";
    cursor = *tail;
    while (cursor != nullptr)
    {
        cout << cursor->value << ", ";
        cursor = cursor->last;
    }
    cout << endl;
}

#endif
