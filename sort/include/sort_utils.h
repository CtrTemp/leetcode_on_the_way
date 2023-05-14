#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#define DEBUG

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "vector"
#include "list"
#include "queue"
#include "stack"

using namespace std;

static void random_list_generator(vector<int> &arr, int length)
{
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        arr.push_back(rand() % 10);
    }

#ifdef DEBUG
    cout << "generated arr = ";
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

#endif
