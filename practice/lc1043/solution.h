
#include "../include/global_include.h"

// 0624 重写
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int max_val = arr[i - 1];
            // for (int j = i - 1; j >= 0 && i - j <= k; j--)
            // {
            //     cout << "j1 = " << j << " ";
            //     dp[i] = max(dp[i], dp[j] + (i - j) * max_val);
            //     if (j > 0)
            //     {
            //         max_val = max(max_val, arr[j - 1]);
            //     }
            // }
            cout << endl;
            for (int j = i; j > 0 && i - j < k; j--)
            {
                cout << "j2 = " << j << " ";
                dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * max_val);
                // max_val = max(max_val, arr[j]);
                if (j > 1)
                {
                    max_val = max(max_val, arr[j - 2]);
                }
            }
            cout << endl
                 << endl;
        }

        return dp[n];
    }
};
