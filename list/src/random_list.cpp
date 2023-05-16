#include "random_list.h"

void test_list_copy(void)
{
    cout << "start test reverse list" << endl;
    // 创建带有随机指针的单链表
    Node<int> **node_head = new Node<int> *;
    gen_list_with_rand_ptr(node_head);
    print_Node_list(node_head);

    // 随机指针单链表拷贝
    random_list_cpy_solution list_cpy_obj;
    Node<int> **cpy_head = new Node<int> *;
    // list_cpy_obj.random_list_copy_with_hashMap(node_head, cpy_head);
    list_cpy_obj.random_list_copy_without_hashMap(node_head, cpy_head);

    print_Node_list(cpy_head);

    bool judgement = true;
    Node<int> *cursor_ori = new Node<int>;
    cursor_ori = *node_head;
    Node<int> *cursor_cpy = new Node<int>;
    cursor_cpy = *cpy_head;
    while (cursor_ori != nullptr)
    {
        if (cursor_ori->value != cursor_cpy->value)
        {
            judgement = false;
            break;
        }
        if (cursor_ori->next != nullptr && cursor_ori->next->value != cursor_cpy->next->value)
        {
            judgement = false;
            break;
        }
        if (cursor_ori->random != nullptr && cursor_ori->random->value != cursor_cpy->random->value)
        {
            judgement = false;
            break;
        }
        cursor_ori = cursor_ori->next;
        cursor_cpy = cursor_cpy->next;
    }

    if (!judgement)
    {
        cout << "error occurred when copying the list with random ptr! please check." << endl;
        // print_Node_list(cpy_head);

        cursor_ori = *node_head;
        cursor_cpy = *cpy_head;
        cout << "print random ori = ";
        while (cursor_ori != nullptr)
        {
            if (cursor_ori->random != nullptr)
            {
                cout << cursor_ori->random->value << ", ";
            }
            else
            {
                cout << "*, ";
            }
            cursor_ori = cursor_ori->next;
        }
        cout << endl;

        cout << "print random cpy = ";
        while (cursor_cpy != nullptr)
        {
            if (cursor_cpy->random != nullptr)
            {
                cout << cursor_cpy->random->value << ", ";
            }
            else
            {
                cout << "*, ";
            }
            cursor_cpy = cursor_cpy->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Congratulations! Copy operation passed the test!" << endl;
    }
}