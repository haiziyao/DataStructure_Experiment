//
// Created by 17542 on 2025/11/8.
//

#ifndef DATASTRUCTURE_HOMEWORK_WORK1_H
#define DATASTRUCTURE_HOMEWORK_WORK1_H
#include <iostream>
#include <fstream>
#include <vector>
#include "../../../include/json.hpp"
namespace question1 {
    using namespace std;
    using json = nlohmann::json;
struct Data {
    int sumNum;
    int sumWeight;
    std::vector<int> weightArr;
    std::vector<int> valArr;
};

    Data* getData(const std::string& jsonpath);
    void from_json(const json& j, Data& data);
    vector<vector<int>> solve(Data *data);
    void printResult(const std::vector<std::vector<int>>& result);
    vector<vector<int>> work();

}
#endif //DATASTRUCTURE_HOMEWORK_WORK1_H