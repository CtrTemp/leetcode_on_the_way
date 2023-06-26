
#include "../include/global_include.h"

// 0624 重写
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        int n = s.size();

        // 遍历字符串，分情况讨论出入栈
        for (int i = 0; i < n; i++)
        {
            // 当前是右括号的时候，一直pop直到找到一个左括号
            if (s[i] == ']')
            {
                // 记录重复字符串，并使用一个栈来存储
                string repeat_str;
                while (st.top() != '[')
                {
                    repeat_str.insert(0, 1, st.top());
                    st.pop();
                }
                st.pop(); // 弹出左括号

                // 记录重复次数的数字
                string repeat_num_str;
                while (!st.empty() && isdigit(st.top()))
                {
                    repeat_num_str.insert(0, 1, st.top());
                    st.pop();
                }
                int repeat_num = 1;
                if (!repeat_num_str.empty())
                {
                    repeat_num = stoi(repeat_num_str);
                }

                // 将重复的字符串压回当前栈
                for (int j = 0; j < repeat_num; j++)
                {
                    for (int k = 0; k < repeat_str.size(); k++)
                    {
                        cout << "repeat_str[k] = " << repeat_str[k] << endl;
                        st.push(repeat_str[k]);
                    }
                }
            }
            else
            {
                // base case
                st.push(s[i]);
            }
        }

        string ret_s;

        while (!st.empty())
        {
            ret_s.insert(0, 1, st.top());
            st.pop();
        }

        return ret_s;
    }
};
