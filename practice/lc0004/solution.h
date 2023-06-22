
#include "../include/global_include.h"

// 确实要用二分查找，每次都要排除一定长度的序列

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int total_size = nums1.size() + nums2.size();

        cout << "total_size = " << total_size << endl;

        if (total_size % 2 == 1)
        {
            return get_kth_min(nums1, nums2, (1 + total_size) / 2);
        }
        else
        {
            return (get_kth_min(nums1, nums2, total_size / 2) + get_kth_min(nums1, nums2, total_size / 2 + 1)) / 2.0;
        }
    }

    int get_kth_min(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();

        int offset_1 = 0;
        int offset_2 = 0;

        while (true)
        {
            // 边界条件
            // 01：序列1边界越界，返回序列2当前的第k小的数字即可
            if (offset_1 == m)
            {
                // cout << "result1 = " << offset_2 + k - 1 << endl;
                return nums2[offset_2 + k - 1];
            }
            // 02：序列2边界越界，返回序列1当前的第k小的数字即可
            if (offset_2 == n)
            {
                // cout << "result2 = " << nums1[offset_1 + k - 1] << endl;
                return nums1[offset_1 + k - 1];
            }
            // 03：k=1则返回两个序列第一小的数，比较序列头即可
            if (k == 1)
            {
                // cout << "result3 = " << min(nums1[offset_1], nums2[offset_2]) << endl;
                return min(nums1[offset_1], nums2[offset_2]);
                // return nums1[offset_1]<nums2[offset_2] ? nums1[offset_1] : nums2[offset_2];
            }

            // 这里考虑越界问题，如果超出边界，则取序列最右侧的值
            int new_idx1 = min(k / 2 - 1 + offset_1, m - 1);
            int new_idx2 = min(k / 2 - 1 + offset_2, n - 1);
            // int new_idx1 = k/2-1+offset_1;
            // int new_idx2 = k/2-1+offset_2;

            int val_1 = nums1[new_idx1];
            int val_2 = nums2[new_idx2];

            // 序列1当前值更小，则应该将序列1的 offset 进行更新
            if (val_1 <= val_2)
            {
                k -= (new_idx1 - offset_1 + 1);
                offset_1 = new_idx1 + 1;
            }
            // 序列2当前值更小，则应该将序列2的 offset 进行更新
            else
            {
                k -= (new_idx2 - offset_2 + 1);
                offset_2 = new_idx2 + 1;
            }

            // cout << "k = ??" << k << endl;
        }
    }
};
