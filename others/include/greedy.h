#ifndef GREEDY_H
#define GREEDY_H

#include "stdio.h"
#include "iostream"

#include "random"

// 容器
#include "string"
#include "string.h"
#include "vector"
#include "list"
#include "queue"
#include "stack"

// stl 提供的排序函数
#include "algorithm"
#include "unordered_map"
#include "unordered_set"

using namespace std;

// 贪心算法合集
class greedy_solution
{

public:
    // 01 会议问题
    class meeting_arrangement_solution
    {
        // 会议结构体
    public:
        class meeting_unit
        {
        public:
            meeting_unit() // 默认构造函数
            {
            }
            meeting_unit(int b, int e)
            {
                begin = b;
                end = e;
            }

        public:
            int begin;
            int end;
        };

    public:
        /**
         *  从0点开始，安排到12点之前的会议
         *  贪心的策略是谁最早开完会先安排谁
         * */
        void solution(vector<meeting_unit> &result_list)
        {
            vector<meeting_unit> meeting_list;

            int end_time = 12;
            gen_meeting_list(meeting_list);

            // testing
            cout << "testing meetings = ";
            for (int i = 0; i < meeting_list.size(); i++)
            {
                cout << "{" << meeting_list[i].begin << "," << meeting_list[i].end << "},";
            }
            cout << endl;

            // 先对以上的会议列表进行排序
            qsort(&meeting_list[0], meeting_list.size(), sizeof(meeting_unit), cmp);

            int time_cursor = 0;
            // 排序后开始遍历
            for (int i = 0; i < meeting_list.size(); i++)
            {
                if (meeting_list[i].begin > time_cursor)
                {
                    result_list.push_back(meeting_list[i]);
                    time_cursor = meeting_list[i].end;
                    if (time_cursor > end_time)
                    {
                        break;
                    }
                }
            }
        }

        // 辅助函数，会议列表生成函数
        void gen_meeting_list(vector<meeting_unit> &meeting_list)
        {
            vector<pair<int, int>> p = {
                {1, 5},
                {2, 4},
                {3, 7},
                {5, 8},
                {6, 7},
                {8, 10},
            };
            for (int i = 0; i < p.size(); i++)
            {
                meeting_list.push_back(meeting_unit(p[i].first, p[i].second));
            }
        }
        // 辅助函数，会议列表排序比较函数 注意，必须要加static关键字
        static int cmp(const void *m1, const void *m2)
        {
            return (*(meeting_unit *)m1).end > (*(meeting_unit *)m2).end; // 按照升序排序，得到的列表最前面的是小值
        }
        // 下面这种写法不行，为什么
        // static int cmp(const meeting_unit &m1, const meeting_unit &m2)
        // {
        //     return m1.end - m2.end; // 按照升序排序，得到的列表最前面的是小值
        // }
    };
    // 02 最小代价问题
    class min_cut_cost_solution
    {
    public:
        void solution(int &min_cost)
        {
            vector<int> rand_arr;
            gen_rand_arr(rand_arr);
            cout << "gen rand arr : ";
            for (int i = 0; i < rand_arr.size(); i++)
            {
                cout << rand_arr[i] << ",";
            }
            cout << endl;
            // 准备一个小根堆
            priority_queue<int, vector<int>, int_cmp> cost_priority_queue;
            for (int i = 0; i < rand_arr.size(); i++)
            {
                cost_priority_queue.push(rand_arr[i]); // 全体入堆
            }
            // 开始弹堆
            while (cost_priority_queue.size() > 1)
            {
                // 每次弹两个数
                int local_cost = 0; // 当前这次切分的cost
                local_cost += cost_priority_queue.top();
                cost_priority_queue.pop();
                local_cost += cost_priority_queue.top();
                cost_priority_queue.pop();
                cost_priority_queue.push(local_cost);
                min_cost += local_cost; // 将这次切分cost加入到总体的cost中
            }
        }
        void gen_rand_arr(vector<int> &arr)
        {
            srand(time(0));
            int max_len = 10;
            int max_val = 20;
            for (int i = 0; i < rand() % max_len; i++)
            {
                arr.push_back(rand() % max_val);
            }
        }
        // 小根堆构造比较器
        class int_cmp
        {
        public:
            bool operator()(const int &a, const int &b)
            {
                return a > b;
            }
        };
    };
    // 03 最优项目
    class better_project_choice_solution
    {
    public:
        // 项目类
        class project
        {
        public:
            project() {}
            project(int c, int p)
            {
                cost = c;
                profit = p;
            }

        public:
            int cost;   // 项目所需启动资金
            int profit; // 项目净利润
        };

    public:
        void better_choice(int fund_init, int max_prj_counts, int &max_profit)
        {
            // int fund_init = 3;      // 初始启动资金
            // int max_prj_counts = 4; // 最多能做多少项目
            int fund = fund_init; // 当前资金

            vector<project> prj_list;
            gen_project_list(prj_list);
            cout << "gen prj list = ";
            for (int i = 0; i < prj_list.size(); i++)
            {
                cout << "{" << prj_list[i].cost << "," << prj_list[i].profit << "}, ";
            }
            cout << endl;

            priority_queue<project, vector<project>, cmp_s> cost_priority_queue;   // 根据cost构造的小根堆
            priority_queue<project, vector<project>, cmp_b> profit_priority_queue; // 根据profit构造的大根堆

            for (int i = 0; i < prj_list.size(); i++) // 先都放入小根堆（这里面代表当前不能做的项目）
            {
                cost_priority_queue.push(prj_list[i]);
            }

            // 由于项目限制，最多进行这么多轮次
            for (int i = 0; i < max_prj_counts; i++)
            {
                // 做项目做到现在，加上利润积累，有哪些项目能做了，扔到以利润为组织的大根堆中
                while (!cost_priority_queue.empty() && cost_priority_queue.top().cost <= fund)
                {
                    profit_priority_queue.push(cost_priority_queue.top()); // 将合格的放入大根堆
                    cost_priority_queue.pop();
                }
                if (profit_priority_queue.empty()) // 大根堆为空，说明没项目可以做了，被锁住了
                {
                    // 计算当前的利润并直接返回
                    max_profit = fund - fund_init;
                    return;
                }
                // 选择大根堆中最优的项目去做，并弹堆
                project better_prj_ref = profit_priority_queue.top();
                fund += better_prj_ref.profit;
                profit_priority_queue.pop();
            }

            max_profit = fund - fund_init; // 计算当前获利
        }

        // 生成项目列表
        void gen_project_list(vector<project> &prj_list)
        {
            srand(time(0));
            int max_prj_len = 20;
            int max_prj_cost = 8;
            int max_prj_profit = 3;
            for (int i = 0; i < rand() % max_prj_len; i++)
            {
                int rand_cost = rand() % max_prj_cost + 1;
                int rand_profit = rand() % max_prj_profit + 1;
                prj_list.push_back(project(rand_cost, rand_profit));
            }
        }

        class cmp_s
        {
        public:
            bool operator()(const project &a, const project &b)
            {
                return a.cost > b.cost; // 正序大于号是小根堆
            }
        };
        class cmp_b
        {
        public:
            bool operator()(const project &a, const project &b)
            {
                return a.profit < b.profit; // 正序小于号是大根堆
            }
        };
    };
};

void test_greedy_algorithm(void);

#endif
