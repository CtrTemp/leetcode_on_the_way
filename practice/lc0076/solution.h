
#include "../include/global_include.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int cursor_f = 0;
        int cursor_s = 0;
        string ret_str;
        int len = INT32_MAX;

        int m = s.size();
        int n = t.size();

        unordered_map<char, int> ori_map;   // [char, count]
        unordered_map<char, int> check_map; // [char, count]

        int left_record = -1;

        for (int i = 0; i < n; i++)
        {
            if (ori_map.empty() || ori_map.find(t[i]) == ori_map.end())
            {
                ori_map.emplace(t[i], 1);
            }
            else
            {
                ori_map.at(t[i])++;
            }
        }

        while (cursor_f < m)
        {
            // 如果当前快指针访问到的字符是模板字符串中的字符，则要将其加入check map中
            if (ori_map.find(s[cursor_f]) != ori_map.end())
            {
                check_map[s[cursor_f]]++;
            }

            // 如果当前快慢指针范围内的窗口能够覆盖模板子串，且慢指针在快指针左侧，则需要考虑收缩滑动窗口
            while (check_valid(ori_map, check_map) && cursor_s <= cursor_f)
            {
                // 如果当前窗口长度更小，则需要更最小覆盖子串
                if (len > cursor_f - cursor_s + 1)
                {
                    len = cursor_f - cursor_s + 1;
                    // ret_str = s.substr(cursor_s, len);
                    left_record = cursor_s;
                }
                // 如果当前慢指针指定的字符在子串中，需要将check_map中的该字符移除
                if (ori_map.find(s[cursor_s]) != ori_map.end())
                {
                    check_map[s[cursor_s]]--;
                }

                cursor_s++;
            }
            cursor_f++;
        }

        return left_record == -1 ? string() : s.substr(left_record, len);
    }

    bool check_valid(unordered_map<char, int> ori_map, unordered_map<char, int> check_map)
    {
        for (const auto &iter : ori_map)
        {
            if (check_map[iter.first] < iter.second)
            {
                return false;
            }
        }

        return true;
    }
};
