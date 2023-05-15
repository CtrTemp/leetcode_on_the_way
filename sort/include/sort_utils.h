#ifndef SORT_UTILS_H
#define SORT_UTILS_H

// // 开启debug模式，则对代码进行简单调试，取较少的数，进行单独测试
// #define DEBUG
// // test 模式下的数组长度
// #define TOTAL_DEBUG_ARR_LEN 10

// 开启test模式，则对代码进行批量测试，选用sql中的sort结果作为对照，使用对数器大规模测试
#define TEST
// test 模式下的执行轮数
#define TOTAL_TEST_LOOP 361
// test 模式下的数组长度
#define TOTAL_TEST_ARR_LEN 100

// 生成的随机数最大值
#define MAX_RAND_VAL 10000
// 生成的随机数最小值
#define MIN_RAND_VAL -10000

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "vector"
#include "list"
#include "queue"
#include "stack"

// stl 提供的排序函数
#include "algorithm"

using namespace std;

static void random_list_generator(vector<int> &arr, int length)
{
#ifdef DEBUG
    srand(time(0));
#endif
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % (MAX_RAND_VAL - MIN_RAND_VAL) + MIN_RAND_VAL;
    }

#ifdef DEBUG
    // debug 模式下允许定制数组，将你出错的数组copy到这里，从而在下次运行时复现状态
    // arr = {555, -745, 828, 890, 745, 226, 481, 192, 555, 890};

    cout
        << "generated arr = ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif
}

static void print_arr(const vector<int> arr)
{
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

static int cmp(const void *a, const void *b)
{
    // 升序
    return *(int *)a - *(int *)b;
}

static int *stl_sort(const vector<int> arr)
{
    int *ret_arr = new int[arr.size()];
    // 首先进行元素拷贝
    for (int i = 0; i < arr.size(); i++)
    {
        ret_arr[i] = arr[i];
    }
    // 使用 stl 提供的排序函数对数组进行排序
    qsort(ret_arr, arr.size(), sizeof(int), cmp);

    return ret_arr;
}

#endif
