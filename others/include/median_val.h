#ifndef MEDIAN_VAL_H
#define MEDIAN_VAL_H

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

#define MAX_RAND_VAL 10
#define MIN_RAND_VAL 0

#define MAX_RAND_LEN 30

class median_solution
{
public:
    // 维护一个序列，使其可以在log(n)时间内找到其中位数
    void init_list()
    {
        srand(time(0));
        cout << "init list : ";
        for (int i = 0; i < rand() % MAX_RAND_LEN; i++)
        {
            int rand_val = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
            cout << rand_val << ", ";
            insert_val(rand_val);
        }
        cout << endl;
    }
    void insert_val(int val) // 数据生成有问题，出错了，奇数序列长度有概率出错，偶数必出错
    {
        if (larger_priority_queue.empty())
        {
            larger_priority_queue.push(val);
            return;
        }
        int top_val = larger_priority_queue.top();
        if (val < top_val)
        {
            larger_priority_queue.push(val);
        }
        else
        {
            smaller_priority_queue.push(val);
        }
        // 当两个堆的size差距不小于2时，对二者进行调整
        int size_s = smaller_priority_queue.size();
        int size_l = larger_priority_queue.size();
        // 这里注意 size 函数返回的是 size_t 无符号类型，必须转化为int，否则不认负数
        // cout << "s size - l size = " << size_s - size_l << endl;
        if (size_s - size_l >= 2) // 小根堆多
        {
            larger_priority_queue.push(smaller_priority_queue.top());
            smaller_priority_queue.pop();
        }
        else if (size_l - size_s >= 2) // 大根堆多
        {

            smaller_priority_queue.push(larger_priority_queue.top());
            larger_priority_queue.pop();
        }
    }
    float get_median() // 因为可能会有中位数为平均值的情况，故这里返回float类型
    {
        if (larger_priority_queue.empty() && smaller_priority_queue.empty())
        {
            return (float)NAN;
        }
        int larger_size = larger_priority_queue.size();
        int smaller_size = smaller_priority_queue.size();
        if (larger_size == smaller_size) // 二者都为奇数或偶数的长度
        {
            return ((float)larger_priority_queue.top() + (float)smaller_priority_queue.top()) / 2;
        }
        else
        {
            if (larger_size > smaller_size)
            {
                return (float)larger_priority_queue.top();
            }
            else
            {
                return (float)smaller_priority_queue.top();
            }
        }
    }

public:
    class cmp_b // 大根堆比较器
    {
    public:
        bool operator()(const int &a, const int &b)
        {
            return a < b;
        }
    };
    class cmp_s // 小根堆比较器
    {
    public:
        bool operator()(const int &a, const int &b)
        {
            return a > b;
        }
    };

public:
    priority_queue<int, vector<int>, cmp_b> larger_priority_queue;  // 记录序列中较小的数字
    priority_queue<int, vector<int>, cmp_s> smaller_priority_queue; // 记录序列中较大的数字
};

void test_median_val(void);

#endif
