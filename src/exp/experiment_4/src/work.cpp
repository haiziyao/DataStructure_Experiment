//
// Created by 17542 on 2025/11/8.
//
#include "work.h"
int question4::num = 0;
int question4::loop = 1;
std::vector<std::vector<int>> question4::arr;
std::vector<std::vector<int>> question4::back;
int question4::arr_nums = 0;
void question4::init(int n) {
    num = n;
    arr_nums = 0;
    arr.assign(num, std::vector<int>(num, 0));
}
int question4::cal_all_aty(int x, int y) {
    int ox =x ,oy =y;
    int count = 0;
    while (++x<num) count += arr[x][y];
    x = ox,y=oy;
    while (--x>=0) count += arr[x][y];
    return count;
}

int question4::cal_all_atx(int x, int y) {
    int ox =x ,oy =y;
    int count = 0;
    while (++y<num) count += arr[x][y];
    x = ox,y=oy;
    while (--y>=0) count += arr[x][y];
    return count;
}

int question4::cal_all_atrt(int x, int y) {
    int ox =x ,oy =y;
    int count = 0;
    while (++x<num&&++y<num) count += arr[x][y];
    x = ox,y=oy;
    while (--x>=0 && --y>=0) count += arr[x][y];
    return count;
}

int question4::cal_all_atlt(int x, int y) {
    int ox =x ,oy =y;
    int count = 0;
    while (++x<num&&--y>=0) count += arr[x][y];
    x = ox,y=oy;
    while (--x>=0&&++y<num) count += arr[x][y];
    return count;
}

int question4::cal_all(int x, int y) {
    return cal_all_atx(x,y)+cal_all_aty(x,y)+cal_all_atrt(x,y)+cal_all_atlt(x,y);
}

void question4::backtrace(int row) {
    if (row == num) {
        arr_nums++;
        //printArr();
        if (loop) {
            back = arr;
            loop = 0;
        }

        return;
    }

    for (int i =0;i<num;i++) {
        if (cal_all(row,i)) {
            continue;
        }

        arr[row][i] = 1;

        backtrace(row+1);

        arr[row][i] = 0;
    }

}

void question4::printArr() {
    printf("第%d种解法\n",arr_nums);

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

std::vector<std::vector<int>> question4::solve(int n) {
    init(n);
    backtrace(0);
    return  back;
}


