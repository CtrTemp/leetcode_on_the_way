#ifndef REVERSE_LIST_H
#define REVERSE_LIST_H

#include "list_utils.h"

class reverse_list_solution
{
public:
    // 压栈法，时间复杂度O(n)，空间复杂度O(n)
    void reverse_list_O_n(Node<int> **head)
    {
        // 栈结构只需要记录值即可，不需要将整个节点入栈
        stack<int> node_value_stack;

        // 遍历链表并压栈
        Node<int> *list_cursor = *head;
        while (list_cursor != nullptr)
        {
            node_value_stack.push(list_cursor->value);
            list_cursor = list_cursor->next;
        }

        // 弹栈重构
        list_cursor = *head;

        while (node_value_stack.size() > 0)
        {
            list_cursor->value = node_value_stack.top();
            list_cursor = list_cursor->next;
            node_value_stack.pop();
        }
    }

    // 头插法，时间复杂度O(n)，空间复杂度O(1)
    // 这里有错误（2023-04-16）
    // void reverse_list_O_1(Node<int> **head)
    // {

    // // xxx
    // Node<int> *before_tail = (*head)->next;
    // // 先将链表头节点置为空
    // (*head)->next = nullptr;
    // Node<int> *cursor = *head;
    // Node<int> *temp = new Node<int>;

    // while (cursor != nullptr)
    // {
    //     temp = cursor; // 暂存
    //     cursor = cursor->next;
    //     temp->next = (*head)->next;
    //     (*head)->next = temp;
    // }

    // before_tail->next = (*head);
    // *head = (*head)->next;
    // before_tail->next->next = nullptr;
    // 1 + 1;
    // }

    // 三指针法，时间复杂度O(n)，空间复杂度O(1)
    void reverse_list_O_1(Node<int> **head)
    {
        Node<int> *cursor_1 = new Node<int>;
        Node<int> *cursor_2 = new Node<int>;
        Node<int> *cursor_3 = new Node<int>;

        cursor_1 = *head;
        cursor_2 = cursor_1->next;
        cursor_3 = cursor_1->next;
        cursor_1->next = nullptr;

        while (cursor_2 != nullptr)
        {
            cursor_3 = cursor_2->next;
            cursor_2->next = cursor_1;
            cursor_1 = cursor_2;
            cursor_2 = cursor_3;
        }

        *head = cursor_1;
    }

    // // 这次尝试将整个节点压入栈
    // void reverse_list_ano(Node<int> *node)
    // {
    //     // 栈结构只需要记录值即可，不需要将整个节点入栈
    //     stack<int> node_value_stack;

    //     // 遍历链表并压栈
    //     Node<int> *list_cursor = node;
    //     while (list_cursor != nullptr)
    //     {
    //         node_value_stack.push(list_cursor->value);
    //         list_cursor = list_cursor->next;
    //     }

    //     // 弹栈重构
    //     list_cursor = node;

    //     while (node_value_stack.size() > 0)
    //     {
    //         list_cursor->value = node_value_stack.top();
    //         list_cursor = list_cursor->next;
    //         node_value_stack.pop();
    //     }
    // }

    void reverse_d()
    {
    }
};

void test_reverse_list(void);

#endif