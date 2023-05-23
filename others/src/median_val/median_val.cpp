#include "median_val.h"

void test_median_val(void)
{

     // 维护一个序列，并在其中使用较快的时间找到找中位数
     cout << "start to get median val in log(n)" << endl;
     median_solution median_obj;
     median_obj.init_list();
     cout << "median val = " << median_obj.get_median() << endl;
}