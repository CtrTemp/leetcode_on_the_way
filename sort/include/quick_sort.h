
#ifndef QUICK_SORT_H
#define QUICK_SORT

#include "sort_utils.h"

class quick_sort
{
public:
    // 将一个数组分为两部分，分别为 “小于等于” 以及 “大于”
    int partition(std::vector<int> &nums, int idx_l, int idx_r, int partation_val)
    {
        // 定义边界情况
        int less_range = idx_l - 1;
        int cursor = idx_l;
        while (cursor <= idx_r)
        {
            /* code */
            // 若游标位置处的值小于或等于给定值，则将左边界下一个位置处的值与游标位置处的值作交换，且左边界右移
            if (nums[cursor] <= partation_val)
            {
                int val_exchange_temp = nums[less_range + 1];
                nums[less_range + 1] = nums[cursor];
                nums[cursor] = val_exchange_temp;
                less_range++;
                cursor++;
            }
            // 若游标位置处的值大于给定值，则游标移动到下一个位置
            else
            {
                cursor++;
            }
        }

        return less_range++;
    }
    // 将一个数组分为三部分，分别为 “小于”、“大于”以及“等于”
    void partition_tri(std::vector<int> &nums, int idx_l, int idx_r, int partation_val, int *eq_range)
    {

        // 定义边界情况
        int less_range = idx_l - 1;
        int larger_range = idx_r + 1;
        int cursor = idx_l;

        while (cursor < larger_range)
        {
            /* code */
            // 若游标位置处的值小于给定值，则将左边界下一个位置处的值与游标位置处的值作交换，且左边界右移
            if (nums[cursor] < partation_val)
            {
                int val_exchange_temp = nums[less_range + 1];
                nums[less_range + 1] = nums[cursor];
                nums[cursor] = val_exchange_temp;
                less_range++;
                cursor++;
            }
            // 若游标位置处的值等于给定值，则游标移动到下一个位置
            else if (nums[cursor] == partation_val)
            {
                cursor++;
            }
            // 若游标位置处的值小于给定值，则将右边界前一个位置处的值与游标位置处的值作交换，且右边界左移
            else
            {
                int val_exchange_temp = nums[larger_range - 1];
                nums[larger_range - 1] = nums[cursor];
                nums[cursor] = val_exchange_temp;
                larger_range--;
                // 注意，这种情况下游标不会向下移动
            }

            // cout << "cursor = " << cursor << "   less = " << less_range << "   larger = " << larger_range << endl;
            // print_arr(nums);

            // cout << endl
            //      << endl;
        }
        eq_range[0] = less_range + 1;
        eq_range[1] = larger_range - 1;
    }

    void sort_recursive(std::vector<int> &nums, int idx_l, int idx_r) // 区间左闭右闭
    {
        int range_size = idx_r - idx_l + 1;
        int offset = idx_l;
        // 区间内只有一个元素，直接返回
        if (range_size <= 1)
        {
            return;
        }

        // 选取数组对应区段随机位置处的一个值作为划分值
        // srand(time(0)); // 有时候使用不恰当反而会害了你
        // 关于 srand 时间内会生成相同的序列，导致下面的rand得到的是相同值，这就使得取得的划分值可能永远在同一个位置
        // 导致结果就是：如果上次分区得到的range将区域分为了0和n长度的两段（这是由于你选取的随机数值恰好为区段内的最值）
        // 则下次还会分成同样的两段，陷入循环，直到下一次的srand取到其他值
        int rand_idx = offset + rand() % range_size;

        // 将这个数与数组中的最后一个数做交换
        int exchange_temp = nums[rand_idx];
        nums[rand_idx] = nums[idx_r];
        nums[idx_r] = exchange_temp;

        int range = partition(nums, idx_l, idx_r, nums[idx_r]);

        sort_recursive(nums, idx_l, range - 1);
        sort_recursive(nums, range, idx_r);
    }

    void sort_recursive_ano(std::vector<int> &nums, int idx_l, int idx_r) // 区间左闭右闭
    {
        int range_size = idx_r - idx_l + 1;
        int offset = idx_l;
        // 区间内只有一个元素，直接返回
        if (range_size <= 1)
        {
            return;
        }

        // 选取数组对应区段随机位置处的一个值作为划分值
        int rand_idx = offset + rand() % range_size;

        // 将这个数与数组中的最后一个数做交换
        int exchange_temp = nums[rand_idx];
        nums[rand_idx] = nums[idx_r];
        nums[idx_r] = exchange_temp;

        // cout << "partition val = " << nums[idx_r] << endl;

        int eq_range[2];

        partition_tri(nums, idx_l, idx_r, nums[idx_r], eq_range);

        sort_recursive(nums, idx_l, eq_range[0] - 1);
        sort_recursive(nums, eq_range[1] + 1, idx_r);
    }
};

void test_quick_sort(void);

#endif