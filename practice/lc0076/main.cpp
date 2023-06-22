#include "solution.h"

int main(void)
{

    cout << "lc76 test" << endl;

    Solution solution_obj;

    // string s = "ADOBECODEBANC";
    // string p = "ABC";
    string s = "a";
    string p = "a";
    // string s = "a";
    // string p = "aa";

    string result = solution_obj.minWindow(s, p);

    cout << "result = " << result << endl;

    return 0;
}
