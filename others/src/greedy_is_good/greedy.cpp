#include "greedy.h"

void test_greedy_algorithm(void)
{

    // 01 会议问题
    cout << "start to test greedy templete 01 -- meeting arangement" << endl;
    greedy_solution::meeting_arrangement_solution meeting_arrangement_obj;
    vector<greedy_solution::meeting_arrangement_solution::meeting_unit> meeting_result_list;
    meeting_arrangement_obj.solution(meeting_result_list);

    cout << "selected meetings = ";
    for (int i = 0; i < meeting_result_list.size(); i++)
    {
        cout << "{" << meeting_result_list[i].begin << "," << meeting_result_list[i].end << "}, ";
    }
    cout << endl
         << endl;

    // 02 最优切分问题（最小切分代价）
    cout << "start to test greedy templete 02 -- min cost" << endl;
    greedy_solution::min_cut_cost_solution min_cut_cost_obj;
    int min_cut_cost = 0;
    min_cut_cost_obj.solution(min_cut_cost);
    cout << "min cut cost = " << min_cut_cost << endl
         << endl;

    // 03 最优项目选择
    cout << "start to test greedy templete 03 -- better project choice" << endl;
    greedy_solution::better_project_choice_solution better_prj_choice_obj;
    int fund_init = 3;
    int max_prj_counts = 4;
    int max_profit = 0;
    cout << "fund start up = " << fund_init << endl;
    cout << "max prj can be process = " << max_prj_counts << endl;
    better_prj_choice_obj.better_choice(fund_init, max_prj_counts, max_profit);
    cout << "max profit = " << max_profit << endl
         << endl;
}