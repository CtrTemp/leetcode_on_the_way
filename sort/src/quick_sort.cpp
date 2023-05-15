#include "quick_sort.h"

void test_quick_sort(void)
{
    vector<int> arr;

#ifdef DEBUG
    cout << "Current MODE is DEBUG" << endl;
    arr.resize(TOTAL_DEBUG_ARR_LEN);
    // 数据生成
    random_list_generator(arr, TOTAL_DEBUG_ARR_LEN);
    // 数据排序
    quick_sort quick_sort_obj;
    // quick_sort_obj.sort_recursive(arr, 0, arr.size() - 1);
    quick_sort_obj.sort_recursive_ano(arr, 0, arr.size() - 1);

    cout << "sorted arr = ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif

#ifdef TEST
    cout << "Current MODE is TEST" << endl;
    arr.resize(TOTAL_TEST_ARR_LEN);

    bool mark = true;
    int loop_counter = 0;

    // 以下数组用于记录发生排序错误的数组
    vector<int> error_arr;

    // 思考如何生成不同的随机数序列（）
    while (loop_counter < TOTAL_TEST_LOOP && mark)
    {

        // 数据生成
        random_list_generator(arr, TOTAL_TEST_ARR_LEN);
        // 数据排序(个人书写的测试版本)
        quick_sort quick_sort_obj;
        // quick_sort_obj.sort_recursive(arr, 0, arr.size() - 1);
        quick_sort_obj.sort_recursive_ano(arr, 0, arr.size() - 1);

        // 数据排序(借助stl中qsort实现的稳定版本)
        int *stl_sorted_arr = stl_sort(arr);

        // 对照个人排序的结果与stl标准结果是否一致
        for (int i = 0; i < TOTAL_TEST_ARR_LEN; i++)
        {
            if (arr[i] != stl_sorted_arr[i])
            {
                mark = false;
            }
        }

        // 如果发生错误则记录错误结果
        if (!mark)
        {
            for (int i = 0; i < TOTAL_TEST_ARR_LEN; i++)
            {
                error_arr.push_back(arr[i]);
            }
        }
        loop_counter++;
    }
    if (mark)
    {
        cout << "your own quick sort result has passed the test!" << endl;
    }
    else
    {
        cout << "Error occured for your sort algorithm, please check" << endl;
        for (int i = 0; i < TOTAL_TEST_ARR_LEN; i++)
        {
            cout << error_arr[i] << ",";
        }
        cout << endl;
    }

#endif
}
