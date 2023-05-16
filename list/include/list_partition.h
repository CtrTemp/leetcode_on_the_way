#ifndef HUIWEN_LIST_H
#define HUIWEN_LIST_H

#include "list_utils.h"

class list_partition_solution
{
public:
    // 给定一个数字，使得链表的左边区域小于该值，中间区域等于该值，右边区域大于该值（链表中的荷兰国旗问题）
    // 要求是必须要保持原来链表中节点的相对位置顺序
    // 时间复杂度 O(n) 空间复杂度 O(1)
    void partition(Node<int> **head, int pivot)
    {
        Node<int> *SH = new Node<int>;
        Node<int> *ST = new Node<int>;
        Node<int> *EH = new Node<int>;
        Node<int> *ET = new Node<int>;
        Node<int> *LH = new Node<int>;
        Node<int> *LT = new Node<int>;
        SH = nullptr;
        ST = nullptr;
        EH = nullptr;
        ET = nullptr;
        LH = nullptr;
        LT = nullptr;

        Node<int> *cursor = new Node<int>;
        cursor = *head;

        while (cursor != nullptr)
        {
            Node<int> *cursor_next = cursor->next;
            cursor->next = nullptr;
            if (cursor->value < pivot)
            {
                if (SH == nullptr)
                {
                    SH = cursor;
                    ST = cursor;
                }
                else
                {
                    ST->next = cursor;
                    ST = cursor;
                }
            }

            else if (cursor->value == pivot)
            {
                if (EH == nullptr)
                {
                    EH = cursor;
                    ET = cursor;
                }
                else
                {
                    ET->next = cursor;
                    ET = cursor;
                }
            }

            else
            {
                if (LH == nullptr)
                {
                    LH = cursor;
                    LT = cursor;
                }
                else
                {
                    LT->next = cursor;
                    LT = cursor;
                }
            }

            cursor = cursor_next;
        }

        // 连表，考虑多重边界条件
        if (SH != nullptr) // 有小于的部分
        {
            ST->next = EH == nullptr ? LH : EH; // 如果没有等于部分则直接连大于部分
            if (ET != nullptr)
            {
                ET->next = LH;
            }
            *head = SH; // 将表头重置为小于部分的头
        }
        else if (EH != nullptr) // 没有小于的部分而有等于的部分
        {
            ET->next = LH;
            *head = EH; // 将表头重置为等于部分的头
        }
        else // 没有小于的部分，也没哟等于的部分
        {
            *head = LH; // 将表头重置为大于部分的头
        }
    }
};

void test_list_partition(void);

#endif