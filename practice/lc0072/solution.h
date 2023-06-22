
#include "../include/global_include.h"

// 进行一维数组优化

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> dp(n+1, 0);

        // 两个单一变量的加入用于保存 dp[i-1][j-1] 的值
        int last_val = 0;
        int cur_val = 0;

        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                cur_val = dp[j];
                // 边界条件 01
                if(i==0)
                {
                    dp[j] = j;
                    last_val = cur_val;
                    continue;
                }
                // 边界条件 02
                if(j==0)
                {
                    dp[j] = i;
                    last_val = cur_val;
                    continue;
                }


                if(word1[i-1] == word2[j-1])
                {
                    dp[j] = last_val;
                }
                else
                {
                    dp[j] = min(last_val, min(dp[j], dp[j-1]))+1;
                }

                last_val = cur_val;
            }
        }
        
        return dp[n];
    }
};



// class Solution
// {
// public:
//     int minDistance(string word1, string word2)
//     {
//         int m = word1.size();
//         int n = word2.size();

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for (int i = 0; i <= m; i++)
//         {
//             for (int j = 0; j <= n; j++)
//             {
//                 // 边界条件 01
//                 if (i == 0)
//                 {
//                     dp[i][j] = j;
//                     continue;
//                 }
//                 // 边界条件 02
//                 if (j == 0)
//                 {
//                     dp[i][j] = i;
//                     continue;
//                 }

//                 if (word1[i-1] == word2[j-1])
//                 {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//                 }
//             }
//         }

//         for (int i = 0; i <= m; i++)
//         {
//             for (int j = 0; j <= n; j++)
//             {
//                 cout << dp[i][j] << ", ";
//             }
//             cout << endl;
//         }

//         return dp[m][n];
//     }
// };