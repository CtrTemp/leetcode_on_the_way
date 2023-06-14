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


using namespace std;


/**
 *  前缀树结构节点（哈希表存储，支持任意字符存储）
 * */
class TrieNode
{
public:
    TrieNode()
    {
        pass = 0;
        end = 0;
    }

public:
    unordered_map<char, TrieNode*> next; // [char, node_ptr]
    int pass;
    int end;
};

/**
 *  前缀树结构
 * */

class Trie
{

public:
    Trie()
    {
        root = new TrieNode *;
        *root = new TrieNode;
    }

    // 向一个前缀树中插入一个字符串
    void insert_str(string str)
    {
        TrieNode * cursor = *root;
        int n = str.size();
        cursor->pass++;


        for(int i=0; i<n; i++)
        {
            if(!cursor->next.empty() && cursor->next.find(str[i])!=cursor->next.end())
            {
                cursor = cursor->next.at(str[i]);
                cursor->pass++;
            }
            else
            {
                TrieNode * new_node = new TrieNode();
                cursor->next.emplace(str[i], new_node);
                cursor = new_node;
                cursor->pass++;
            }
        }

        cursor->end++;
    }

    // 查询一个word在这个树中被加入了几次？
    int search_str(string str)
    {
        TrieNode * cursor = *root;
        int n = str.size();

        for(int i=0; i<n; i++)
        {
            if(!cursor->next.empty() && cursor->next.find(str[i])!=cursor->next.end())
            {
                cursor = cursor->next.at(str[i]);
            }
            else
            {
                return 0;
            }
        }
        return cursor->end;
    }

    // 如果查询到有这个word，则删除它
    bool delete_str(string str) // delete 是 C++ 关键字
    {
        if(!search_str(str)) // 前缀树中没有这个word,直接返回 false 表示删除失败
        {
            return false; 
        }

        TrieNode * cursor = *root;
        int n = str.size();
        cursor->pass--;

        for(int i=0; i<n; i++)
        {
            cursor = cursor->next.at(str[i]);
            cursor->pass--;
        }
        cursor->end--;

        return true;
    }

public:
    TrieNode **root;
};

void test_prefix_tree_hash(void);

#endif
