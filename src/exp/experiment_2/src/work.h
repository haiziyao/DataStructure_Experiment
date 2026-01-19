//
// Created by 17542 on 2025/11/9.
//

#ifndef DATASTRUCTURE_HOMEWORK_WORK2_H
#define DATASTRUCTURE_HOMEWORK_WORK2_H


#include <iostream>
#include <queue>
#include <vector>
#include <string>
namespace question2 {
    using namespace std;
    extern vector<string> stateStr;
    extern vector<int> stateInt;


    bool isSafe(int state);
    string getStateDescription(int state);
    string getMoveDescription(int from, int to) ;
    vector<int> solve();
    vector<string> work();
}


#endif //DATASTRUCTURE_HOMEWORK_WORK2_H