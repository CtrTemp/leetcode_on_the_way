#ifndef MERGE_SORT_H
#define MERGE_SORT

#include "sort_utils.h"

class merge_sort
{
public:
    void merge(std::vector<int> &nums, int idx_l, int idx_m, int idx_r)
    {
        int l_cursor = idx_l;
        int r_cursor = idx_m + 1;
        vector<int> temp_arr;
        while (l_cursor <= idx_m && r_cursor <= idx_r)
        {
            if (nums[l_cursor] < nums[r_cursor])
            {
                temp_arr.push_back(nums[l_cursor]);
                l_cursor++;
            }
            else
            {
                temp_arr.push_back(nums[r_cursor]);
                r_cursor++;
            }
        }
        while (l_cursor <= idx_m)
        {
            temp_arr.push_back(nums[l_cursor]);
            l_cursor++;
        }
        while (r_cursor <= idx_r)
        {
            temp_arr.push_back(nums[r_cursor]);
            r_cursor++;
        }

        for (int i = 0; i < temp_arr.size(); i++)
        {
            nums[idx_l + i] = temp_arr[i];
        }
    }

    void sort_recursive(std::vector<int> &nums, int idx_l, int idx_r) // 区间左闭右闭
    {
        if (idx_l == idx_r)
        {
            return;
        }

        // 后面改成位运算试试
        int idx_m = idx_l + (idx_r - idx_l) / 2;
        sort_recursive(nums, idx_l, idx_m);
        sort_recursive(nums, idx_m + 1, idx_r);

        merge(nums, idx_l, idx_m, idx_r);
    }
};

void test_merge_sort(void);

#endif