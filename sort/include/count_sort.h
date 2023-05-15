#ifndef COUNT_SORT_H
#define COUNT_SORT

#include "sort_utils.h"

class count_sort
{
public:
    // 计数排序使用空间换时间，务必保证序列中最大值与最小值相差不大的情况下使用该方法
    void sort(std::vector<int> &nums)
    {
        if (nums.size() <= 1) // 边界条件，只有一个数字则不用排序直接返回
        {
            return;
        }

        // 第一遍遍历得到数组中的最大值最小值
        int max_val = INT32_MIN;
        int min_val = INT32_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_val)
            {
                max_val = nums[i];
            }
            if (nums[i] < min_val)
            {
                min_val = nums[i];
            }
        }
        // 创建数组，并将其值初始化为0
        int arr_len = max_val - min_val + 1;
        int *counter_arr = new int[arr_len];
        for (int i = 0; i < arr_len; i++)
        {
            counter_arr[i] = 0;
        }

        // 第二遍遍历，填充数组
        for (int i = 0; i < nums.size(); i++)
        {
            int index = nums[i] - min_val;
            counter_arr[index]++;
        }
        // 遍历刚刚创建的数组，回写排序
        for (int i = 0, j = 0; i < arr_len; i++)
        {
            while (counter_arr[i] != 0)
            {
                nums[j++] = i + min_val;
                counter_arr[i]--;
            }
        }
    }
};

void test_count_sort(void);

#endif