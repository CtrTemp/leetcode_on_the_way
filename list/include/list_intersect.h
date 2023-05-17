#ifndef LIST_INTERSECT_H
#define LIST_INTERSECT_H

#include "list_utils.h"
#include "list_loop.h"

static void gen_list_with_public_part(Node<int> **head1, Node<int> **head2, Node<int> **public_head)
{
    srand(time(0));
    *head1 = new Node<int>;
    *head2 = new Node<int>;
    Node<int> *h1_cursor = *head1;
    Node<int> *h2_cursor = *head2;

    int public_part_len = LIST_LENGTH * 0.5;

    // 先生成各自的非公共部分
    for (int i = 0; i < LIST_LENGTH - public_part_len - 1; i++)
    {
        h1_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        h1_cursor->next = new Node<int>;
        h1_cursor = h1_cursor->next;

        h2_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        h2_cursor->next = new Node<int>;
        h2_cursor = h2_cursor->next;
    }
    h1_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    h2_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;

    // 公共节点，二者在此相交
    Node<int> *public_cursor = new Node<int>;

    // 各自链表指向公共部分的首节点
    h1_cursor->next = public_cursor;
    h2_cursor->next = public_cursor;

    // 😃 记录公共部分头
    *public_head = public_cursor;

    for (int i = 0; i < public_part_len - 1; i++)
    {
        public_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
        public_cursor->next = new Node<int>;
        public_cursor = public_cursor->next;
    }

    public_cursor->value = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    public_cursor->next = nullptr;
}

class judge_list_intersection_solution
{
public:
    // 对一个链表是否有环状结构进行判断，有环的话返回第一个带环的节点的指针，空间复杂度 O(1) 的解法
    Node<int> *judge_list_intersection(Node<int> **head1, Node<int> **head2)
    {
        judge_list_loop_solution loop_judge_obj;
        Node<int> *loop1_entrance = new Node<int>;
        Node<int> *loop2_entrance = new Node<int>;
        loop1_entrance = loop_judge_obj.judge_list_loop_O_1(head1);
        loop2_entrance = loop_judge_obj.judge_list_loop_O_1(head2);

        // 如果其中一个有环，则二者如果相交则相交点必定在入环节点
        if (loop1_entrance != nullptr && loop1_entrance == loop2_entrance)
        {
            return loop1_entrance;
        }
        // 如果二者都是无环的
        else if (loop1_entrance == nullptr && loop2_entrance == nullptr)
        {

            Node<int> *cursor1 = new Node<int>;
            Node<int> *cursor2 = new Node<int>;
            // 先找两个链表长度差
            cursor1 = *head1;
            cursor2 = *head2;
            int list1_length = 0;
            int list2_length = 0;
            while (cursor1 != nullptr)
            {
                cursor1 = cursor1->next;
                list1_length++;
            }
            while (cursor2 != nullptr)
            {
                cursor2 = cursor2->next;
                list2_length++;
            }

            // 归位
            cursor1 = *head1;
            cursor2 = *head2;
            // list2 长一些
            if (list2_length > list1_length)
            {
                // list2 先走长度差的步数
                for (int i = 0; i < list2_length - list1_length; i++)
                {
                    cursor2 = cursor2->next;
                }
            }
            // list1 长一些
            else if (list1_length > list2_length)
            {
                // list2 先走长度差的步数
                for (int i = 0; i < list1_length - list2_length; i++)
                {
                    cursor1 = cursor1->next;
                }
            }

            while (cursor1 != nullptr) // 用 cursor1 或 cursor2 无所谓
            {
                // 说明找到了二者的公共部分
                if (cursor1 == cursor2)
                {
                    return cursor1;
                }
                cursor1 = cursor1->next;
                cursor2 = cursor2->next;
            }

            // 二者没有公共部分
            return nullptr;
        }
        // 否则二者无交点
        else
        {
            return nullptr;
        }
    }
};

void test_list_intersect(void);

#endif