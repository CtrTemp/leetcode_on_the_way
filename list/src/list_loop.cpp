#include "list_loop.h"

void test_list_loop(void)
{
    cout << "start to judge list loop" << endl;
    // 创建带有随机指针的单链表
    Node<int> **node_head = new Node<int> *;
    bool hasLoop = true;
    gen_list_with_loop(node_head, hasLoop);
    // print_Node_list(node_head);

    judge_list_loop_solution judge_loop_obj;
    cout << "O(n) algorithm judge result = " << (judge_loop_obj.judge_list_loop_O_n(node_head) == nullptr ? "no loop" : "has loop") << endl;
    cout << "O(1) algorithm judge result = " << (judge_loop_obj.judge_list_loop_O_1(node_head) == nullptr ? "no loop" : "has loop") << endl;
}