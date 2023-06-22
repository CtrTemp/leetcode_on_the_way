#include "solution.h"

int main(void)
{

    cout << "lc4 test" << endl;

    // vector<int> nums1{1, 3, 4, 9};
    // vector<int> nums2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vector<int> nums1{1, 2};
    // vector<int> nums2{3, 4};
    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    Solution solution_obj;

    double result = solution_obj.findMedianSortedArrays(nums1, nums2);

    cout << "result = " << result << endl;

    return 0;
}
