//
// Created by 17542 on 2025/11/8.
//
#include "work.h"
#include <string>
using namespace std;

question1::Data * question1::getData(const std::string &jsonpath) {
    ifstream ifs(jsonpath);
    if (!ifs.is_open()) {
        cerr<<"无法打开文件"<<jsonpath<<endl;
        return  nullptr;
    }
    json j;
    ifs>>j;
    ifs.close();
    Data* data = new Data();
    j.get_to(*data);
    return data;
}

void question1::from_json(const json &j, Data &data) {
    data.sumNum = j["sumNum"].get<int>();
    data.sumWeight = j["sumWeight"].get<int>();
    data.weightArr = j["weightArr"].get<vector<int>>();
    data.valArr = j["valArr"].get<vector<int>>();

}

vector<vector<int>> question1::solve(Data *data) {
    int N = data->sumNum;
    int W = data->sumWeight;
    vector<int> weightArr = data->weightArr;
    vector<int> valtArr = data->valArr;
    vector<vector<int>> dp(N+1,vector<int>(W+1));
    for (int i=1;i<=N;i++) {
        for (int w = 1;w<=W;w++) {
            //超重，不装了
            if (weightArr[i-1]>w) {
                   dp[i][w] = dp[i-1][w];
            }else {
                dp[i][w] = max(
                    dp[i-1][w-weightArr[i-1]]+valtArr[i-1],
                    dp[i-1][w]);
            }
        }
    }
    return dp;
 }

vector<vector<int>> question1::work() {
    string filepath = "../Resource/exp1_data/data.json";
    Data* data = getData(filepath);
    vector<vector<int>> result = solve(data);
    printResult(result);
    return result;
}

void question1::printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
