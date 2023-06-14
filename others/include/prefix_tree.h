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
 *  前缀树结构节点（数组存储，之支持存放小写字母）
 * */
class TrieNode
{
public:
    TrieNode() // 无参 default 构造函数，创建静态数组的时候必须给一个默认构造函数
    {
        pass = 0;
        end = 0;
        next = new TrieNode *[26]; // 26个字符串英文字母（以小写/大写其一为例）
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
        } // 初始化这些指针都为空
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
        if (str.size() == 0)
        {
            return;
        }
        // 游标先定位到跟节点
        TrieNode *cursor = new TrieNode;
        cursor = *root;
        cursor->pass++;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            int c_idx = c - 'a';                // 计算得出对应字母应的 index
            if (cursor->next[c_idx] == nullptr) // 如果之前还没有出现过这个字母则创建一个新节点
            {
                cursor->next[c_idx] = new TrieNode;
            }
            cursor = cursor->next[c_idx];
            cursor->pass++; // 将对应的 pass ++ 说明来到此处的路径+1
        }

        cursor->end++; // 字符串结束后，将终点在对应位置的end++
    }

    // 查询一个word在这个树中被加入了几次？
    int search_str(string str)
    {
        if (str.size() == 0)
        {
            return 0;
        }
        TrieNode *cursor = new TrieNode;
        cursor = *root;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            int c_idx = c - 'a';
            if (cursor->next[c_idx] == nullptr) // 说明这个字符没有出现过
            {
                return 0;
            }
            cursor = cursor->next[c_idx];
        }
        // cout << "end = " << cursor->end << endl;
        return cursor->end;
    }

    // 如果查询到有这个word，则删除它
    bool delete_str(string str) // delete 是 C++ 关键字
    {
        if (!search_str(str)) // 如果没有找到这个str则直接返回false
        {
            return false;
        }

        TrieNode *cursor = new TrieNode;
        cursor = *root;
        cursor->pass--;
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            int c_idx = c - 'a';
            if (--cursor->next[c_idx]->pass == 0)
            {
                cursor->next[c_idx] = nullptr; // 仅这样做会导致后面的区域的内存没有被释放
                // C++内存回收需要自己做，要遍历后面的所有节点并且依次调用每个节点的析构函数（这里我们先不做）
                return true;
            }
            cursor = cursor->next[c_idx];
        }
        cursor->end--;
        return true;
    }

public:
    TrieNode **root;
};

void test_prefix_tree(void);

#endif
