#ifndef TREE_SERIALIZE_H
#define TREE_SERIALIZE_H

#include "tree_utils.h"

class tree_serialize_solution
{
public:
    // 给定一棵树，将该树编码为字符串，要求唯一，可解码
    // 这里仅展示先序遍历编码
    void tree_encode(Node<int> *root, string *ser_tree)
    {
        if (root == nullptr) // 代表null
        {
            ser_tree->append("#_");
            return;
        }
        else // 代表当前值
        {
            string value = to_string(root->value);
            ser_tree->append(value);
            ser_tree->append("_");
        }
        tree_encode((root)->left, ser_tree);
        tree_encode((root)->right, ser_tree);
    }

    // 给定代表一棵树的编码字符串，将其解码还原为一棵树
    void tree_decode(string ser_tree, Node<int> **root)
    {
        // 第一步先将字符串按照下划线分开，变成数组
        // 借助 strtok 方法
        char *s_input = (char *)ser_tree.c_str();
        char *split_arr = strtok(s_input, "_"); // 注意这是一个c函数，需要引入 string.h 单单引入string是不够的

        // 将字符串使用下划线进行分割，放入队列中
        queue<string> node_val_queue;

        while (split_arr != NULL)
        {
            node_val_queue.push(split_arr);
            split_arr = strtok(NULL, "_");
        }

        // 依次弹队列，递归构造树（反序列化）
        *root = construct_true_recursive(node_val_queue);
    }

    Node<int> *construct_true_recursive(queue<string> &node_val_queue)
    {
        string node_val = node_val_queue.front();
        node_val_queue.pop();
        if (node_val == "#") // base case
        {
            return nullptr;
        }

        Node<int> *head = new Node<int>;
        head->value = atoi(node_val.c_str());
        head->left = construct_true_recursive(node_val_queue);
        head->right = construct_true_recursive(node_val_queue);

        return head;
    }
};

void test_tree_encode_decode(void);

#endif