#include "huiwen_list.h"

void test_huiwen_list(void)
{
    cout << "start judge huiwen list" << endl;
    // 创建单链表
    Node<int> **list_head = new Node<int> *;
    gen_random_Node_list(list_head);
    print_Node_list(list_head);

    // 回文判断
    huiwen_list_solution huiwen_obj;
    bool isHuiWen = huiwen_obj.judge_huiwen(list_head);
    cout << "whether huiwen? " << (isHuiWen ? "true" : "false") << endl;
    print_Node_list(list_head);
}