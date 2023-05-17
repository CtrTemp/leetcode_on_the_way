#include "reverse_list.h"

void test_reverse_list(void)
{
    cout << "start to test reverse list" << endl;
    // 创建单链表
    Node<int> **node_head = new Node<int> *;
    gen_random_Node_list(node_head);
    print_Node_list(node_head);

    // 翻转单链表
    reverse_list_solution reverse_obj;
    // reverse_obj.reverse_list_O_n(node_head);     // O(n) 空间复杂度（笔试）
    reverse_obj.reverse_list_O_1(node_head); // O(1) 空间复杂度（面试）
    print_Node_list(node_head);

    cout << endl;

    cout << "start to test double link list" << endl;

    // 创建双链表
    dNode<int> **dnode_head = new dNode<int> *;
    dNode<int> **dnode_tail = new dNode<int> *;
    gen_random_dNode_list(dnode_head, dnode_tail);
    print_dNode_list(dnode_head, dnode_tail);

    // 翻转双链表（没有意义，实际上就是头尾指针对掉）
}