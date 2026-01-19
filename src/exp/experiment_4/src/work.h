//
// Created by 17542 on 2025/11/8.
//

#ifndef DATASTRUCTURE_HOMEWORK_WORK4_H
#define DATASTRUCTURE_HOMEWORK_WORK4_H
#include "../../experiment_1/src/work.h"
namespace question4{
    extern int num;
    extern int loop;
    extern std::vector<std::vector<int>> arr;
    extern std::vector<std::vector<int>> back;
    extern int arr_nums;
    void init(int n);
    int cal_all_aty(int x,int y);
    int cal_all_atx(int x,int y);
    int cal_all_atrt(int x,int y);
    int cal_all_atlt(int x,int y);
    int cal_all(int x,int y);
    void backtrace(int row);
    std::vector<std::vector<int>> solve(int);
    void printArr();

}
#endif //DATASTRUCTURE_HOMEWORK_WORK4_H