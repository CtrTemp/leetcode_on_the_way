#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT

#include "sort_utils.h"

class bubble_sort
{
public:
    void sort(std::vector<int> &nums)
    {
        if (nums.size() <= 1) // 边界条件，只有一个数字则不用排序直接返回
        {
            return;
        }
        // 两层循环出结果
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] < nums[i])
                {
                    nums[j] = nums[j] ^ nums[i];
                    nums[i] = nums[j] ^ nums[i];
                    nums[j] = nums[j] ^ nums[i];
                }
            }
        }
    }
};

void test_bubble_sort(void);

#endif