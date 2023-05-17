#include "list_intersect.h"

void test_list_intersect(void)
{
    cout << "start to judge list loop" << endl;
    // 创建带有随机指针的单链表
    Node<int> **node_head1 = new Node<int> *;
    Node<int> **node_head2 = new Node<int> *;
    Node<int> **public_head = new Node<int> *;
    bool hasPubilc = true;
    gen_list_with_public_part(node_head1, node_head2, public_head);
    print_Node_list(node_head1);
    print_Node_list(node_head2);
    cout << "public node val : " << (*public_head)->value << endl;

    judge_list_intersection_solution judge_interection_obj;
    cout << "Judge result = "
         << (judge_interection_obj.judge_list_intersection(node_head1, node_head2) == nullptr ? "no intersection" : "has intersection")
         << endl;
}