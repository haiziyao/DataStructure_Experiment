// work.cpp
#include "work.h"
namespace question13 {
    void work() {
        std::string path = "../experiment_13/Data/data2.json";
        Data* data = getData(path);
        std::cout << "原始矩阵" << std::endl;
        printAll(data->maze);
        std::vector<std::vector<int>> newmaze = slove(data);
        printAll(newmaze);
    }
    bool travel(int cur_x, int cur_y, int e_x, int e_y, std::vector<std::vector<int>>& maze) {
        if (cur_x == e_x && cur_y == e_y) {
            maze[cur_x][cur_y] = 2;
            std::cout << "已经找到路径" << std::endl;
            return true;
        }
        if (cur_x < 0 || cur_x >= maze.size() ||
            cur_y < 0 || cur_y >= maze[0].size() ||
            maze[cur_x][cur_y] != 1) {
            return false;
        }
        maze[cur_x][cur_y] = 2;
        if (travel(cur_x - 1, cur_y, e_x, e_y, maze)) {
            return true;
        }
        if (travel(cur_x, cur_y + 1, e_x, e_y, maze)) {
            return true;
        }
        if (travel(cur_x + 1, cur_y, e_x, e_y, maze)) {
            return true;
        }
        if (travel(cur_x, cur_y - 1, e_x, e_y, maze)) {
            return true;
        }
        maze[cur_x][cur_y] = 1;
        return false;
    }
    std::vector<std::vector<int>> slove(Data* data) {
        const int b_x = data->begin_x;
        const int b_y = data->begin_y;
        const int e_x = data->end_x;
        const int e_y = data->end_y;
        std::vector<std::vector<int>> maze = data->maze;
        int cur_x = b_x;
        int cur_y = b_y;
        bool found = travel(b_x, b_y, e_x, e_y, maze);
        if (found) {
            std::cout << "找到通路" << std::endl;
            return maze;
        }
        std::cout << "未找到通路" << std::endl;
        return maze;
    }
    void from_json(const json& j, Data& data) {
        data.maze = j["maze"].get<std::vector<std::vector<int>>>();
        data.begin_x = j["start"]["x"].get<int>();
        data.begin_y = j["start"]["y"].get<int>();
        data.end_x = j["end"]["x"].get<int>();
        data.end_y = j["end"]["y"].get<int>();
    }
    Data* getData(const std::string& jsonpath) {
        std::ifstream ifs(jsonpath);
        if (!ifs.is_open()) {
            std::cerr << "无法打开文件：" << jsonpath << std::endl;
            return nullptr;
        }
        nlohmann::json j;
        ifs >> j;
        ifs.close();
        Data* data = new Data();
        j.get_to(*data);
        return data;
    }
    void printAll(std::vector<std::vector<int>>& maze) {
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[0].size(); j++) {
                std::cout << maze[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}