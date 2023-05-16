#ifndef RANDOM_LIST_H
#define RANDOM_LIST_H

#include "list_utils.h"
#include "unordered_map"

void static gen_list_with_rand_ptr(Node<int> **head)
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

    Node<int> *node_arr = new Node<int>[LIST_LENGTH];

    for (int i = 0; i < LIST_LENGTH; i++)
    {
        Node<int> *new_node = new Node<int>;
        new_node->next = nullptr;
        new_node->random = nullptr;
        new_node->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        node_arr[i] = *new_node;
    }

    for (int i = 0; i < LIST_LENGTH - 1; i++)
    {
        // cout << node_arr[i].value << " , " << endl;
        node_arr[i].next = &node_arr[i + 1];
        int rand_idx = rand() % LIST_LENGTH * 1.25;
        if (rand_idx > LIST_LENGTH - 1)
        {
            node_arr[i].random = nullptr;
        }
        else
        {
            node_arr[i].random = &node_arr[rand_idx];
        }
    }

    // 这里无法使用的一个主要原因可能是退出的时候vector被自动销毁，导致首指针消失
    // 尝试使用静态数组
    // 问题解决
    *head = &node_arr[0];

    // cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    // cursor->next = new Node<int>;
    // cursor = cursor->next;

    // cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    // cursor->next = nullptr;

#endif
}

class random_list_cpy_solution
{
public:
    // 对一个带有随机指针的链表进行拷贝
    void random_list_copy_with_hashMap(Node<int> **ori_head, Node<int> **cpy_head)
    {
        // 借助哈希表来进行拷贝
        // 注意，如果是自定义类作为Key值，则必须自定义哈希函数以及对比函数
        // 这里我们使用自定义类型的地址作为Key值来避免过于繁琐
        unordered_map<Node<int> *, Node<int> *> node_hashMap;
        Node<int> *cursor = new Node<int>;
        cursor = *ori_head;

        // 第一遍只将数据放入哈希表
        while (cursor != nullptr)
        {
            Node<int> *new_node = new Node<int>;
            new_node->value = cursor->value;
            new_node->next = nullptr;
            new_node->random = nullptr;
            node_hashMap.emplace(cursor, new_node);

            cursor = cursor->next;
        }

        // 遍历哈希表，并链接指针
        for (unordered_map<Node<int> *, Node<int> *>::iterator iter = node_hashMap.begin(); iter != node_hashMap.end(); iter++)
        {
            // key 值是原始list中的节点指针
            if ((*iter).first->next != nullptr)
            {
                (*iter).second->next = node_hashMap.at((*iter).first->next);
            }
            else
            {
                (*iter).second->next = nullptr;
            }
            if ((*iter).first->random != nullptr)
            {

                (*iter).second->random = node_hashMap.at((*iter).first->random);
            }
            else
            {
                (*iter).second->random = nullptr;
            }
        }

        // 赋值拷贝后的头指针
        *cpy_head = node_hashMap.at(*ori_head);
    }

    void random_list_copy_without_hashMap(Node<int> **ori_head, Node<int> **cpy_head)
    {

        Node<int> *cursor_ori = new Node<int>;
        cursor_ori = *ori_head;

        // 第一次遍历仅复制节点，并将赋值的节点插入在当前访问节点的下一个的位置
        while (cursor_ori != nullptr)
        {
            Node<int> *new_node = new Node<int>;
            new_node->value = cursor_ori->value;
            new_node->next = cursor_ori->next;
            new_node->random = nullptr;
            cursor_ori->next = new_node;

            cursor_ori = cursor_ori->next->next;
        }

        // 重回起点
        cursor_ori = *ori_head;
        Node<int> *cursor_cpy = new Node<int>;
        cursor_cpy = (*ori_head)->next;
        // 第二次遍历仅赋值random指针你
        while (cursor_ori != nullptr)
        {
            if (cursor_ori->random != nullptr)
            {
                cursor_cpy->random = cursor_ori->random->next;
            }
            else
            {
                cursor_cpy->random = nullptr;
            }

            cursor_ori = cursor_ori->next->next;
            if (cursor_ori == nullptr)
            {
                cursor_cpy = nullptr;
            }
            else
            {
                cursor_cpy = cursor_cpy->next->next;
            }
        }


        // 重回起点
        cursor_ori = *ori_head;
        cursor_cpy = (*ori_head)->next;
        // 赋值拷贝链表的头指针
        *cpy_head = (*ori_head)->next;

        // 第三次遍历，拆表
        while (cursor_ori != nullptr)
        {
            cursor_ori->next = cursor_cpy->next;
            cursor_ori = cursor_ori->next;

            if (cursor_ori != nullptr)
            {
                cursor_cpy->next = cursor_ori->next;
                cursor_cpy = cursor_cpy->next;
            }
            else
            {
                cursor_cpy->next = nullptr;
                cursor_cpy = cursor_cpy->next;
            }
        }
    }
};

void test_list_copy(void);

#endif