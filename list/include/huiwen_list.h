#ifndef HUIWEN_LIST_H
#define HUIWEN_LIST_H

#include "list_utils.h"

class huiwen_list_solution
{
public:
    // 回文结构判断
    bool judge_huiwen(Node<int> **head)
    {

        bool res = true; // 默认它是一个回文结构

        if ((*head) == nullptr)
        {
            // 空指针，不为回文结构
            return false;
        }
        if ((*head)->next == nullptr)
        {
            // 只有一个节点肯定是回文结构
            return true;
        }
        // 双指针法（快慢指针）
        Node<int> *cursor_1 = new Node<int>;
        cursor_1 = (*head);
        Node<int> *cursor_2 = new Node<int>;
        cursor_2 = (*head)->next;

        // 慢指针一次一步；快指针一次两步
        // 注意提前返回的原则，前者判断为false提前返回，反过来写这句就是错的！
        while (cursor_2->next != nullptr && cursor_2->next->next != nullptr)
        {
            cursor_2 = cursor_2->next->next;
            cursor_1 = cursor_1->next;
        }

        // 无论如何都是要向下移动一个节点，得到后半部分的头一个节点
        cursor_2 = cursor_1->next;

        // 注意，如果此时我们选择使用压栈的方法，那么额外空间复杂度就变成O(n)了，肯定不是最优解

        // 如果允许对链表结构进行改变的话，则使用以下方法，让链表的后半段进行翻转

        cursor_1->next = nullptr; // 让中间节点指向空，它后面的节点要进行翻转操作了
        Node<int> *cursor_3 = new Node<int>;
        while (cursor_2 != nullptr)
        {
            cursor_3 = cursor_2->next;
            cursor_2->next = cursor_1;
            cursor_1 = cursor_2;
            cursor_2 = cursor_3;
            // 作图理解，不多说
        }
        // 结束后，cursor_1 记录着后半段翻转后的头节点

        // 现在开始判断是否为回文结构，让cursor_2暂存前半部分头节点，cursor_3暂存后半部分头节点
        cursor_2 = *head;
        cursor_3 = cursor_1;
        while (cursor_2 != nullptr && cursor_1 != nullptr)
        {
            if (cursor_1->value != cursor_2->value)
            {
                res = false;
                break;
            }
            cursor_2 = cursor_2->next;
            cursor_1 = cursor_1->next;
        }

        // 由于之前打乱了链表的原有结构，现在需要将结构进行恢复
        // 之前的 cursor_3 保存了后半部分的头节点，按照规则进行翻转恢复即可
        cursor_1 = cursor_3->next;
        cursor_2 = cursor_3->next;
        cursor_3->next = nullptr;
        while (cursor_2 != nullptr)
        {
            cursor_1 = cursor_2->next;
            cursor_2->next = cursor_3;
            cursor_3 = cursor_2;
            cursor_2 = cursor_1;
            // 作图理解，不多说
        }

        return res;
    }
};

void test_huiwen_list(void);

#endif