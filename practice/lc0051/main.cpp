#include "solution.h"

int main(void)
{

    cout << "lc51 test" << endl;

    Solution solution_obj;

    // vector<vector<string>> str_vec = solution_obj.solveNQueens(4);
    vector<vector<string>> str_vec = solution_obj.solveNQueens(4);

    cout << "result = " << endl;
    for (int i = 0; i < str_vec.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < str_vec[0].size(); j++)
        {
            cout << str_vec[i][j] << " | ";
        }

        cout << "]" << endl;
    }

    return 0;
}
