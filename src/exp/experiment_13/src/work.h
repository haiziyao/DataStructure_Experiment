#ifndef DATASTRUCTURE_HOMEWORK_WORK13_H
#define DATASTRUCTURE_HOMEWORK_WORK13_H
#include <iostream>
#include <fstream>
#include <vector>
#include "../../../include/json.hpp"
namespace question13 {
    using json = nlohmann::json;
    struct Data {
        std::vector<std::vector<int>> maze;
        int begin_x;
        int begin_y;
        int end_x;
        int end_y;
    };
    void from_json(const json& j, Data& data);
    void printAll(std::vector<std::vector<int>>& maze);
    Data* getData(const std::string& jsonpath);
    std::vector<std::vector<int>> slove(Data* data);
    bool travel(int, int, int, int, std::vector<std::vector<int>>&);
    void work();
}
#endif //DATASTRUCTURE_HOMEWORK_WORK13_H