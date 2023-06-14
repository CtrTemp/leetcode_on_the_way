
#include "force_recursive.h"

void test_force_recursive(void)
{
    // std::cout << "force recursive 01 : sub seq" << std::endl;

    // force_recursive::sub_seq solution_obj;

    // string str = "abbbc";
    // vector<string> sub_seq = solution_obj.solution(str);

    // cout << "test str = '" << str << "'" << endl;
    // cout << "it's sub seq = " << endl;
    // for (int i = 0; i < sub_seq.size(); i++)
    // {
    //     cout << sub_seq[i] << endl;
    // }

    // std::cout << "force recursive 02 : permutations" << std::endl;

    // force_recursive::permutations permutations_solution_obj;

    // string str = "abbc";
    // vector<string> permutations_vec = permutations_solution_obj.solution(str);

    // cout << "test str = '" << str << "'" << endl;
    // cout << "it's permutations seq = " << endl;
    // for (int i = 0; i < permutations_vec.size(); i++)
    // {
    //     cout << permutations_vec[i] << endl;
    // }

    // std::cout << "force recursive 03 : smart card player" << std::endl;

    // force_recursive::max_card_sum card_solution_obj;

    // vector<int> card_test_arr{1, 2, 20, 4};

    // int max_card_sum = card_solution_obj.solution(card_test_arr);

    // cout << "test arr = [";
    // for (int i = 0; i < card_test_arr.size(); i++)
    // {
    //     cout << card_test_arr[i] << ", ";
    // }
    // cout << "]" << endl;
    // cout << "winner socre = " << max_card_sum << endl;

    std::cout << "force recursive 04 : reverse stack" << std::endl;

    force_recursive::reverse_stack reverse_stack_obj;

    vector<int> reverse_stack_test_arr{1, 2, 3, 4};

    cout << "before reverse = [";
    for (int i = 0; i < reverse_stack_test_arr.size(); i++)
    {
        cout << reverse_stack_test_arr[i] << ", ";
    }
    cout << "]" << endl;

    reverse_stack_obj.solution(reverse_stack_test_arr);

    cout << "after reverse = [";
    for (int i = 0; i < reverse_stack_test_arr.size(); i++)
    {
        cout << reverse_stack_test_arr[i] << ", ";
    }
    cout << "]" << endl;
}
