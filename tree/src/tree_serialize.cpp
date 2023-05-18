#include "tree_serialize.h"

void test_tree_encode_decode(void)
{

    tree_serialize_solution tree_serialize_obj;
    string tree_str;

    cout << "start to test tree encode" << endl;
    // 创建二叉树结构
    Node<int> **ori_tree_root = new Node<int> *;
    gen_complete_binary_tree(ori_tree_root);

    tree_serialize_obj.tree_encode(*ori_tree_root, &tree_str);

    cout << "encoded str = " << tree_str << endl;

    cout << "start to test tree decode" << endl;
    Node<int> **decoded_tree_root = new Node<int> *;
    tree_serialize_obj.tree_decode(tree_str, decoded_tree_root);

    width_first_travseral_print(decoded_tree_root);
}