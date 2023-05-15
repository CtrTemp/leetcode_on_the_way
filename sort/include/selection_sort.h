#ifndef SELECTION_SORT_H
#define SELECTION_SORT

#include "sort_utils.h"

class selection_sort
{
public:
    void sort(std::vector<int> &nums)
    {
        if (nums.size() <= 1) // 边界条件，只有一个数字则不用排序直接返回
        {
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int loop_max = INT32_MIN;
            int loop_max_index = 0;
            for (int j = 0; j < nums.size() - i; j++)
            {
                if (nums[j] > loop_max)
                {
                    loop_max = nums[j];
                    loop_max_index = j;
                }
            }


            // 交换（最大值可能就是当前轮的最后一个，所以不能使用位运算交换）
            nums[loop_max_index] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = loop_max;
        }
    }
};

void test_selection_sort(void);

#endif