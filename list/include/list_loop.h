#ifndef LIST_LOOP_H
#define LIST_LOOP_H

#include "list_utils.h"
#include "unordered_map"
#include "unordered_set"

static void gen_list_with_loop(Node<int> **head, bool hasLoop)
{
    srand(time(0));
    *head = new Node<int>;
    Node<int> *cursor = *head;

    for (int i = 0; i < LIST_LENGTH - 1; i++)
    {
        cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        cursor->next = new Node<int>;
        cursor = cursor->next;
    }
    cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    if (!hasLoop)
    {
        cursor->next = nullptr;
    }
    else // 选取一个链表上的随机节点，让尾指针指向它，从而构成环
    {
        Node<int> *rand_cursor = new Node<int>;
        rand_cursor = *head;
        int steps = rand() % LIST_LENGTH;
        while (steps--)
        {
            rand_cursor = rand_cursor->next;
        }
        cursor->next = rand_cursor;
    }
}

class judge_list_loop_solution
{
public:
    // 对一个链表是否有环状结构进行判断，有环的话返回第一个带环的节点的指针，空间复杂度 O(1) 的解法
    Node<int> *judge_list_loop_O_1(Node<int> **head)
    {
        if ((*head) == nullptr)
        {
            return nullptr;
        }
        // 思路是快慢指针
        Node<int> *cursor_s = new Node<int>;
        Node<int> *cursor_f = new Node<int>;
        cursor_s = *head;
        cursor_f = (*head)->next;

        // 第一轮，直到二者相交
        while (cursor_f != nullptr && cursor_f->next != nullptr && cursor_f != cursor_s)
        {
            cursor_f = cursor_f->next->next;
            cursor_s = cursor_s->next;
        }
        if (cursor_f != cursor_s) // 说明无环
        {
            return nullptr;
        }

        // 快指针回起点，开始下一轮，进行到这里，说明一定是有环的
        cursor_f = *head;
        // 慢指针再向前一步，补全差值步数，这样相当于在以上的循环中，快指针一定比慢指针多走了环上一圈的步数
            cursor_s = cursor_s->next;

        // 这轮快慢指针都是一次走一步
        while (cursor_f != cursor_s)
        {
            cursor_f = cursor_f->next;
            cursor_s = cursor_s->next;
        }
        // 环的入口一定在二者第二次相交位置
        return cursor_s;
    }

    Node<int> *judge_list_loop_O_n(Node<int> **head) // 空间复杂度 O(n) 的解法
    {
        // 借助 hashSet 实现即可，通过地址判断是否已经访问过目标节点
        unordered_set<Node<int> *> set;
        Node<int> *cursor = new Node<int>;
        cursor = *head;
        while (cursor != nullptr)
        {
            // 如果访问到过这个节点，则直接返回，说明该位置就是入环位置
            if (set.find(cursor) != set.end())
            {
                return cursor;
            }
            set.emplace(cursor);
            cursor = cursor->next;
        }
        // 走到这里说明是无环的
        return nullptr;
    }
};

void test_list_loop(void);

#endif