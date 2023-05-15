#ifndef HEAP_SORT_H
#define HEAP_SORT

#include "sort_utils.h"

class heap_sort
{
public:
    // 给定一个数字在树结构数组上的位置，将其移动到其在大根堆应该所处的位置（自下而上）
    void heap_insert(std::vector<int> &nums, int idx)
    {
        if (idx <= 0 || idx >= nums.size())
        {
            return;
        }
        int idx_cursor = idx;

        // 如果当前节点值大于其父节点
        while (idx_cursor > 0 && nums[idx_cursor] > nums[(idx_cursor - 1) / 2])
        {
            // 则应该与父节点交换值，直到当前节点处的值小于其父节点
            nums[idx_cursor] = nums[idx_cursor] ^ nums[(idx_cursor - 1) / 2];
            nums[(idx_cursor - 1) / 2] = nums[idx_cursor] ^ nums[(idx_cursor - 1) / 2];
            nums[idx_cursor] = nums[idx_cursor] ^ nums[(idx_cursor - 1) / 2];
            idx_cursor = (idx_cursor - 1) / 2;
        }
    }

    // 已经有了一个类似的堆结构，将某个节点向下考虑，放到其应该所处的位置（自上而下）
    void heapify(std::vector<int> &nums, int idx, int heap_size)
    {
        if (idx >= nums.size())
        {
            throw runtime_error("error! cannot construct a heap at current node: the node you indicated beyond the arr size");
            return;
        }
        if (nums.size() <= 1)
        {
            return;
        }

        int idx_l = idx * 2 + 1;
        while (idx_l < heap_size)
        {
            // 比较左右两个孩子的节点值，并将较大值的下标赋值
            int largest_val_idx = idx_l + 1 < heap_size && nums[idx_l + 1] > nums[idx_l] ? idx_l + 1 : idx_l;

            // 比较当前节点值和其左右两个孩子中较大的值，并赋值下标
            largest_val_idx = nums[largest_val_idx] > nums[idx] ? largest_val_idx : idx;

            // 如果这个下标就是当前节点位置，则说明它比两个孩子都大，我们已经找到了其正确的位置，可以断出了
            if (largest_val_idx == idx)
            {
                break;
            }

            // 否则要进行值交换
            nums[largest_val_idx] = nums[largest_val_idx] ^ nums[idx];
            nums[idx] = nums[largest_val_idx] ^ nums[idx];
            nums[largest_val_idx] = nums[largest_val_idx] ^ nums[idx];

            // 之后更新下标
            idx = largest_val_idx;
            idx_l = idx * 2 + 1;
        }
    }

    void sort(std::vector<int> &nums)
    {
        if (nums.size() <= 1) // 边界条件，只有一个数字则不用排序直接返回
        {
            return;
        }

        // 第一步，构造堆结构
        for (int i = 0; i < nums.size(); i++)
        {
            heap_insert(nums, i);
        }

        // 第二步，排序
        int heap_size = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            // 将最大值移动到最末尾
            int swap_temp = nums[heap_size - 1];
            nums[heap_size - 1] = nums[0];
            nums[0] = swap_temp;
            // 减小堆长度
            heap_size--;
            // 重新构建大根堆
            heapify(nums, 0, heap_size);
        }

    }
};

void test_heap_sort(void);

#endif