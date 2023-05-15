#ifndef RADIX_SORT_H
#define RADIX_SORT

#include "sort_utils.h"

class radix_sort
{
public:
    void sort(std::vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return;
        }
        sort(nums, 0, nums.size() - 1, maxbits(nums));
    }

    // 默认十进制，digit 表示这一组数据中最大的一个数有多少个十进制位
    void sort(std::vector<int> &nums, int idx_l, int idx_r, int digit) // 区间左闭右闭
    {
        // 表示我们使用的是十进制
        const int radix = 10;

        if (nums.size() <= 1) // 边界条件，只有一个数字则不用排序直接返回
        {
            return;
        }

        // 开辟一个桶空间
        int *bucket = new int[idx_r - idx_l + 1];
        for (int i = 0; i < 10; i++)
        {
            bucket[i] = 0;
        }
        

        for (int d = 0; d < digit; d++)
        {
            // d 表示当前在遍历哪个十进制位

            // 第一步开辟额外空间用于记录在某个位上的具体数值个数
            int *count = new int[radix];
            for (int i = idx_l; i <= idx_r; i++)
            {
                int j = get_digit(nums[i], d);
                count[j]++;
            }

            // 第二步，将 count 数组将表示为一个offset，表示当前十进制位之前有多少个数
            for (int i = 1; i < radix; i++)
            {
                count[i] = count[i] + count[i - 1];
            }

            // 第三步将数组中的数字放入桶
            for (int i = idx_r; i >= idx_l; i--)
            {
                int j = get_digit(nums[i], d);
                bucket[count[j] - 1] = nums[i];
                count[j]--;
            }

            // 第四步出桶
            for (int i = idx_l, j = 0; i <= idx_r; i++, j++)
            {
                nums[i] = bucket[j];
            }

        }
    }

    // 寻找一个数组中最大值的十进制位数
    int maxbits(std::vector<int> &nums)
    {
        int max_val = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_val)
            {
                max_val = nums[i];
            }
        }

        int ret_maxbit_val = 0;
        while (max_val != 0)
        {
            max_val /= 10;
            ret_maxbit_val++;
        }

        return ret_maxbit_val;
    }

    // 取 val 中的第 digit 位的十进制数字
    int get_digit(int val, int digit)
    {
        for (int i = 0; i < digit; i++)
        {
            val /= 10;
        }
        return val % 10;
    }
};

void test_radix_sort(void);

#endif