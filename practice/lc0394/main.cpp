#include "solution.h"

int main(void)
{

    cout << "lc394 test" << endl;

    string str = "10[a]2[bc]";

    Solution solution_obj;

    string decoded_str = solution_obj.decodeString(str);

    cout << "decoded string = " << decoded_str << endl;

    return 0;
}
