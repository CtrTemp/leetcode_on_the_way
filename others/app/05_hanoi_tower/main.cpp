#include "hanoi_tower.h"

class Solution
{
public:
    vector<string> permutation(string s)
    {
        unordered_map<char, int> str_map; // [s[i], count]
        vector<string> result;

        for (int i = 0; i < s.size(); i++)
        {
            if (!str_map.empty() && str_map.find(s[i]) != str_map.end())
            {
                str_map.at(s[i])++;
                continue;
            }
            str_map.emplace(s[i], 1);
        }

        for (unordered_map<char, int>::iterator iter = str_map.begin(); iter != str_map.end(); iter++)
        {
            cout << "[" << (*iter).first << ", " << (*iter).second << "]" << endl;
        }

        string local_str = "";
        process(str_map, s.size(), local_str, result);

        return result;
    }

    void process(unordered_map<char, int> str_map, int str_lasted, string local_str, vector<string> &str_vec)
    {
        cout << "str_lasted = " << str_lasted << endl;
        if (str_lasted == 1)
        {
            cout << "shoud push " << local_str << endl;
            str_vec.push_back(local_str);
            return;
        }

        for (unordered_map<char, int>::iterator iter = str_map.begin(); iter != str_map.end(); iter++)
        {
            if ((*iter).second == 0)
            {
                continue;
            }

            cout << "(*iter).first = " << (*iter).first << endl;
            local_str.push_back((*iter).first);
            str_map.at((*iter).first)--;
            process(str_map, str_lasted - 1, local_str, str_vec);
        }
    }
};

int main(void)
{
    // std::cout << "this is hanoi tower problem test prj" << std::endl;

    // test_hanoi_tower();

    Solution solution;

    solution.permutation("bcaa");

    return 0;
}
