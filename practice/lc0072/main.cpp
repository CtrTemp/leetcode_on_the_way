#include "solution.h"

int main(void)
{

    cout << "lc72 test" << endl;


    Solution solution_obj;

    string word1 = "horse";
    string word2 = "ros";

    int result = solution_obj.minDistance(word1, word2);

    cout << "result = " << result << endl;

    return 0;
}
