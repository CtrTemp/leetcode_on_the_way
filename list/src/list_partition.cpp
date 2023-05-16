#include "list_partition.h"

void test_list_partition(void)
{
    cout << "start test list partition" << endl;
    // 创建单链表
    Node<int> **list_head = new Node<int> *;
    gen_random_Node_list(list_head);
    print_Node_list(list_head);

    // 分割 partition
    list_partition_solution partition_obj;
    partition_obj.partition(list_head, 0);
    print_Node_list(list_head);
}