#include "solution.h"

int main(void)
{

    cout << "lc1043 test" << endl;

    vector<int> tets_arr = {1,4,1,5,7,3,6,1,9,9,3};

    Solution solution_obj;

    int result = solution_obj.maxSumAfterPartitioning(tets_arr, 4);

    cout << "result = " << result << endl;

    return 0;
}
