#include "bubble_sort.h"

void test_bubble_sort(void)
{
    vector<int> arr;
    // 数据生成
    random_list_generator(arr, 10);
    // 数据排序
    bubble_sort bubble_sort_obj;
    bubble_sort_obj.sort(arr);

#ifdef DEBUG
    cout << "sorted arr = ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif
}
