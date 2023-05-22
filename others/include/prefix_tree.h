#ifndef PREFIX_TREE_H
#define PREFIX_TREE_H

// #define SPECIFIED_GRAPH

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "string.h"
#include "vector"
#include "list"
#include "queue"
#include "stack"

// stl 提供的排序函数
#include "algorithm"
// 对于图结构，免不了要用到哈希map/set结构
#include "unordered_map"
#include "unordered_set"

// // 图规模（节点个数）
// #define GRAPH_NODE_LIST_LENGTH 4

// // 图中节点值的取值范围
// #define MAX_RAND_NODE_VAL 100
// #define MIN_RAND_NODE_VAL -100

// // 图中边权重的取值范围（注意，一般情况下，边的权重都不小于0）
// #define MAX_RAND_EDGE_VAL 10
// #define MIN_RAND_EDGE_VAL 0

using namespace std;

class Edge; // 两个类互引，后定义的要在前面加声名

/**
 *  前缀树结构节点
 * */
class TrieNode
{
public:
    TrieNode() // 无参 default 构造函数，创建静态数组的时候必须给一个默认构造函数
    {
        pass = 0;
        end = 0;
        next = nullptr;
        // next = new TrieNode *;
        // *next = new TrieNode[26]; // 26个字符串英文字母（以小写/大写其一为例）
    };

public:
    int pass;        // 走到当前节点的路径有多少条（前缀）
    int end;         // 有多少条路径是以此节点为终点的
    TrieNode **next; // 当前节点下属有多少个其他的分支
};

/**
 *  前缀树结构
 *
 * */

class Tire
{

public:
    Tire()
    {
        *root = new TrieNode();
    }

    // 向一个前缀树中插入一个字符串
    void insert(string str)
    {
        if (str.size() == 0)
        {
            return;
        }
        // 游标先定位到跟节点
        TrieNode *cursor = new TrieNode;
        cursor = *root;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            int c_idx = c - 'a';                // 计算得出对应字母应的 index
            if (cursor->next[c_idx] == nullptr) // 如果之前还没有出现过这个字母则创建一个新节点
            {
                cursor->next[c_idx] = new TrieNode;
            }
            cursor = cursor->next[c_idx];
            cursor->next[c_idx]->pass++; // 将对应的 pass ++ 说明来到此处的路径+1
        }

        cursor->end++; // 字符串结束后，将终点在对应位置的end++
    }

public:
    TrieNode **root;
};

void test_prefix_tree(void);

#endif
