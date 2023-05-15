#ifndef INSERT_SORT_H
#define INSERT_SORT

#include "sort_utils.h"

class insert_sort
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
            int cursor = i;
            while (cursor > 0)
            {
                // 如果游标位置处的值小于其前一位置处的值，则交换（升序）
                if (nums[cursor] < nums[cursor - 1])
                {
                    nums[cursor] = nums[cursor] ^ nums[cursor - 1];
                    nums[cursor - 1] = nums[cursor] ^ nums[cursor - 1];
                    nums[cursor] = nums[cursor] ^ nums[cursor - 1];
                }
                cursor--;
            }
        }
    }
};

void test_insert_sort(void);

#endif