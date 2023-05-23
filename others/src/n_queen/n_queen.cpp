#include "n_queen.h"

void test_n_queen(void)
{
     // n 皇后问题
     cout << "start to get n queen" << endl;
     n_queen_solution n_queen_obj;

     cout << "n queen when num = 1, solution is: " << n_queen_obj.n_queen(1) << endl;
     cout << "n queen when num = 2, solution is: " << n_queen_obj.n_queen(2) << endl;
     cout << "n queen when num = 3, solution is: " << n_queen_obj.n_queen(3) << endl;
     cout << "n queen when num = 4, solution is: " << n_queen_obj.n_queen(4) << endl;
     cout << "n queen when num = 5, solution is: " << n_queen_obj.n_queen(5) << endl;
     cout << "n queen when num = 6, solution is: " << n_queen_obj.n_queen(6) << endl;
     cout << "n queen when num = 7, solution is: " << n_queen_obj.n_queen(7) << endl;
     cout << "n queen when num = 8, solution is: " << n_queen_obj.n_queen(8) << endl;

     clock_t begin, end;
     begin = clock();
     cout << "n queen when num = 12, solution is: " << n_queen_obj.n_queen(12) << "  ";
     end = clock();
     cout << "time cost = " << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
     begin = clock();
     cout << "n queen when num = 13, solution is: " << n_queen_obj.n_queen(13) << "  ";
     end = clock();
     cout << "time cost = " << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

     // 常数时间优化，非常明显的加速，利用位运算
     begin = clock();
     cout << "n queen when num = 13, solution is: " << n_queen_obj.n_queen_opt(13) << "  ";
     end = clock();
     cout << "optimized time cost = " << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}