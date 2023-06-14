#ifndef HANOI_H
#define HANOI_H

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

class hanoi_tower_solution
{
public:
    /**
     *  经典汉诺塔问题：
     *  左中右三个杆，有套环从小到大，依次由上到下套在左边杆子上，现一次移动一个套环
     * 借助中间的杆子，将所有的套环移动到右边，要求是移动过程中不能出现大环压住小环
     * 的情况。请将移动策略打印出
     * */
    void hanoi(int n)
    {
        if (n > 0)
        {
            process(n, "左", "右", "中"); // 将 n 个套环从左边杆子移动到右边杆子，借助中间杆子
        }
    }

    // 辅助函数
    void process(int i, string from, string to, string other)
    {
        // 思路分三步（其实就是递归拆解）：
        /**
         *  1、第一步将前1～i-1个套环从 from 移动到 other（此时to将充当other的角色）
         *  2、第二步将第i个套环从 from 移动到 to，这步可以直接打印
         *  3、第三步将 other 上的 i-1 个套环移动到 to（此时from将充当other的角色）
         * */
        if (i == 1) // base case
        {
            cout << "Move " << i << " from " << from << " to " << to << endl;
        }
        else
        {
            process(i - 1, from, other, to);
            cout << "Move " << i << " from " << from << " to " << to << endl;
            process(i - 1, other, to, from);
        }
    }
};

void test_hanoi_tower(void);

#endif
