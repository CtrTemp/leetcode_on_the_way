
#include "../include/global_include.h"

// N 皇后问题
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ret_vec;
        vector<string> local_vec;

        // record_arr 用于记录每一行的哪个位置（哪一列）放置了皇后
        int *record_arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            record_arr[i] = 0;
        }

        process(record_arr, 0, n, ret_vec, local_vec);

        return ret_vec;
    }

    // 现在的问题是策略不成功的时候你没有一个有效的方法去清空local_vec!!!
    // 现在问题又来了，传引用和传值效果居然是一样的，难道对于string类型的vector有什么特殊之处么？？
    // 并且这里又进一步验证了一个事情：传引用真的比传值更加省空间，也省时间
    void process(int *record_arr, int i, int n, vector<vector<string>> &ret_vec, vector<string> &local_vec)
    {
        if (i == n) // 当前策略成功
        {
            ret_vec.push_back(local_vec);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            // 判断在第i行第j列的这个位置是否可放置皇后
            if (isValid(i, j, record_arr))
            {
                record_arr[i] = j; // 说明这一行的这个位置可以放置皇后
                local_vec.push_back(gen_local_str(n, j));
                process(record_arr, i + 1, n, ret_vec, local_vec); // 往下一行走
                // 我本来以为这里不需要pop_back，因为我们是传值，这里需要回来探讨
                local_vec.pop_back();
            }
        }
    }

    bool isValid(int row, int col, int *record_arr)
    {
        for (int i = 0; i < row; i++)
        {
            int forbid_1 = col;
            int forbid_2 = col + (row - i);
            int forbid_3 = col - (row - i);
            if ((record_arr[i] == forbid_1) || (record_arr[i] == forbid_2) || (record_arr[i] == forbid_3))
            {
                return false;
            }
        }
        return true;
    }

    string gen_local_str(int n, int pos)
    {
        string ret_str;
        for (int i = 0; i < n; i++)
        {
            ret_str.push_back((i == pos ? 'Q' : '.'));
        }

        return ret_str;
    }
};
