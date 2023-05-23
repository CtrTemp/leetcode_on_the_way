#ifndef N_QUEEN_H
#define N_QUEEN_H

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

class n_queen_solution
{
public:
    /**
     *  经典n皇后问题：返回N*N棋盘格内的棋子摆放方法
     *  要求是，一个棋子的横竖斜几个方向上均不能出现其他棋子
     * */
    int n_queen(int n)
    {
        int res = 0;
        int *record = new int[n];
        return process_n_queen(0, record, n);
    }

    /**
     *  辅助函数
     *  i: 当前所在第几行
     *  record：各个行当前已经摆放的棋子记录，数组下标代表第几行，数字代表第几列摆放了棋子
     *  n：表示是n*n的棋盘格
     * */
    int process_n_queen(int i, int *record, int n)
    {
        if (i == n) // base case 说明来到了最后一行的下一行，说明这种排列方式是适用的
        {
            return 1; // 表示这种排列方式被计入
        }
        int res = 0;
        for (int j = 0; j < n; j++) // 处理这一行的不同种情况，j代表不同列
        {
            if (isValid(i, j, record, n)) // 如果在第 i 行的第 j 列摆放一个棋子合规
            {
                record[i] = j;                            // 则将棋子放入
                res += process_n_queen(i + 1, record, n); // 对下一行进行处理
            }
        }

        return res;
    }

    bool isValid(int row, int col, int *record, int n) // 在第 row 行的第 col 列摆放一个棋子是否合规
    {
        for (int i = 0; i < row; i++)
        {
            int forbid_num1 = col;             // 重列情况
            int forbid_num2 = col + (row - i); // 右侧斜对角线
            int forbid_num3 = col - (row - i); // 左侧斜对角线
            // 如果出现以上任意不合规情况，则返回false
            if (record[i] == forbid_num1 || record[i] == forbid_num2 || record[i] == forbid_num3)
            {
                return false;
            }
        }
        return true;
    }

    /**
     *
     *   以下是常数时间优化后的方法
     *
     */

    int n_queen_opt(int n)
    {
        if (n > 32 || n < 0)
        {
            cout << "invalid num, please input a num between 0~32";
            return (int)NAN;
        }

        int limit = (n == 32) ? -1 : (1 << n) - 1;

        return process_n_queen_opt(limit, 0, 0, 0);
    }

    int process_n_queen_opt(int limit, int colLim, int leftDiaLim, int rightDiaLim)
    {
        // colLim 列限制
        // leftDiaLim 左对角线限制
        // rightDiaLim 右对角线限制
        if (colLim == limit) // base case 说明所有的列都被填满了，已经来到了最后一行的下一行，可以直接返回
        {
            return 1;
        }

        int res = 0;
        // 之后就是计算下一行的限制
        int pos = limit & (~(colLim | leftDiaLim | rightDiaLim)); // 得到这一行有哪些位置可以放置皇后（这些位置被标记为1）
        int most_right_one = 0;                                   // 取上面这个数最右边不为1的位置，并将那一位置为1
        // 看到后面就有点看不懂了哈哈哈（困） 2023/05/23
        while (pos != 0)
        {
            most_right_one = pos & (~pos + 1); // 后面这句话的意思是把一个二进制数中最右侧的 1 提取出来
            pos = pos - most_right_one;
            res += process_n_queen_opt(limit,
                                       colLim | most_right_one,
                                       (leftDiaLim | most_right_one) << 1,
                                       (rightDiaLim | most_right_one) >> 1);
        }

        return res;
    }
};

void test_n_queen(void);

#endif
