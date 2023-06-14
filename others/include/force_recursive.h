#ifndef FORCE_RECUSIVE_H
#define FORCE_RECUSIVE_H

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
#include "unordered_map"
#include "unordered_set"

using namespace std;

/**
 *  暴力递归/回溯大类算法
 * */

class force_recursive
{

public:
    // 01 求一个字符串的子集（所有子序列，内部字符顺序无关）
    class sub_seq
    {
    public:
        vector<string> solution(string str)
        {
            vector<string> ret_vec;
            process(str, 0, string(), ret_vec);

            // 使用一个哈希表来去重
            unordered_set<string> set;
            for (int i = 0; i < ret_vec.size(); i++)
            {
                set.emplace(ret_vec[i]);
            }
            ret_vec.resize(0);
            for (unordered_set<string>::iterator iter = set.begin(); iter != set.end(); iter++)
            {
                ret_vec.push_back(*iter);
            }

            return ret_vec;
        }

        void process(string str, int pos, string local_str, vector<string> &ret_vec)
        {
            // 根据当前遍历到的位置，决策这个字符要还是不要
            // base case
            if (pos == str.size())
            {
                ret_vec.push_back(local_str);
                return;
            }

            // 要当前字符，继续遍历
            process(str, pos + 1, local_str + str[pos], ret_vec);
            // 不要当前字符，继续遍历
            process(str, pos + 1, local_str, ret_vec);
        }
    };

    // 02 字符串的全排列：permutations
    class permutations
    {
    public:
        vector<string> solution(string str)
        {
            vector<string> ret_vec;
            process(str, 0, ret_vec);

            return ret_vec;
        }

        void process(string str, int pos, vector<string> &ret_vec)
        {
            int n = str.size();
            if (pos == n)
            {
                ret_vec.push_back(str);
                return;
            }
            // 去重用到的哈希表，如果只有26个字母，也可以使用定长数组表示
            unordered_set<char> set;
            for (int i = pos; i < n; i++)
            {
                if (set.empty() || set.find(str[i]) == set.end())
                {
                    set.emplace(str[i]);
                    swap(str[i], str[pos]);
                    process(str, pos + 1, ret_vec);
                    swap(str[i], str[pos]);
                }

                // swap(str[i], str[pos]);
                // process(str, pos + 1, ret_vec, set);
                // swap(str[i], str[pos]);
            }
        }
    };

    // 03 打牌先后手
    class max_card_sum
    {
    public:
        int solution(vector<int> card_arr)
        {
            return max(first_to_choose(card_arr, 0, card_arr.size() - 1), second_to_choose(card_arr, 0, card_arr.size() - 1));
        }

        int first_to_choose(vector<int> card_arr, int l, int r)
        {
            // base case
            if (l == r)
            {
                return card_arr[l];
            }
            // 先手选，取最大值
            return max(card_arr[l] + second_to_choose(card_arr, l + 1, r), card_arr[r] + second_to_choose(card_arr, l, r - 1));
        }

        int second_to_choose(vector<int> card_arr, int l, int r)
        {
            // base case
            if (l == r) // 后手选，当前只有一个值的情况就是0了
            {
                return 0;
            }
            // 下一回合先手选，当前的先手总是给你一个更差的选择
            return min(first_to_choose(card_arr, l + 1, r), first_to_choose(card_arr, l, r - 1));
        }
    };

    // 04 逆序栈，不申请额外数据空间，将一个栈逆序
    class reverse_stack
    {
    public:
        void solution(vector<int> &st_init_vec)
        {
            stack<int> st;
            int n = st_init_vec.size();
            // initialize stack
            for (int i = 0; i < n; i++)
            {
                st.push(st_init_vec[i]);
            }
            reverse(st);
            for (int i = n - 1; i >= 0; i--)
            {
                st_init_vec[i] = st.top();
                st.pop();
            }
        }

        void reverse(stack<int> &st)
        {
            if (st.empty())
            {
                return;
            }
            int val = get_bottom(st); // 元素是依次从栈底拿出来的
            reverse(st);
            st.push(val); // 后拿出来的是原栈顶，那么我们又要将他先放回去，就变成了栈底
        }

        int get_bottom(stack<int> &st)
        {
            int result = st.top();
            st.pop();
            if (st.empty())
            {
                return result; // 返回栈底值
            }
            else
            {
                int last = get_bottom(st);
                st.push(result);
                return last; // last一直都是栈底值
            }
        }
    };
};

void test_force_recursive(void);

#endif
