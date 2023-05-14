#include "quick_sort.h"

void test_quick_sort(void)
{
    vector<int> arr;
    // 数据生成
    random_list_generator(arr, 10);
    // 数据排序
    quick_sort quick_sort_obj;
    // quick_sort_obj.sort_recursive(arr, 0, arr.size() - 1);

    quick_sort_obj.sort_recursive_ano(arr, 0, arr.size() - 1);

#ifdef DEBUG
    cout << "sorted arr = ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif
}
