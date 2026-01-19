//
// Created by 17542 on 2025/11/9.
//
#include "work.h"

#include <algorithm>
using namespace std;
namespace question2 {
     vector<string> stateStr;
     vector<int> stateInt;
}
bool question2::isSafe(int state) {
     int sheep = (state >> 0) & 1;
     int cabbage = (state >> 1) & 1;
     int wolf = (state >> 2) & 1;
     int farmer = (state >> 3) & 1;

     if (farmer != wolf && wolf == sheep) {
          return false;
     }
     if (farmer != sheep && sheep == cabbage) {
          return false;
     }
     return true;
}

std::string question2::getStateDescription(int state) {
     string south, north;

     int farmer = (state >> 3) & 1;
     int wolf = (state >> 2) & 1;
     int cabbage = (state >> 1) & 1;
     int sheep = state & 1;


     if (farmer == 0) south += "农夫 ";
     if (wolf == 0) south += "狼 ";
     if (cabbage == 0) south += "白菜 ";
     if (sheep == 0) south += "羊 ";
     if (south.empty()) south = "无";
     else south = south.substr(0, south.length() - 1);


     if (farmer == 1) north += "农夫 ";
     if (wolf == 1) north += "狼 ";
     if (cabbage == 1) north += "白菜 ";
     if (sheep == 1) north += "羊 ";
     if (north.empty()) north = "无";
     else north = north.substr(0, north.length() - 1);

     return "南岸：" + south + "|    北岸：" + north;
}

std::vector<int> question2::solve() {
     const int start = 0x00;
     const int target = 0x0F;

     int visited[16];
     fill(visited, visited + 16, -1);
     queue<int>  q;
     q.push(start);
     visited[start] = start;

     while (!q.empty()) {
          int current = q.front();
          q.pop();

          if (current==target) break;

          int moves[] = {
               0x08,  // 仅农夫移动（1000）
               0x0C,  // 农夫+狼（1100）
               0x0A,  // 农夫+白菜（1010）
               0x09   // 农夫+羊（1001）
           };

          for (int move : moves) {
               int farmerPos = (current >> 3) & 1;
               int itemPosMask = move & 0x07;

               bool canCarry = (itemPosMask == 0) || (((current & itemPosMask) != 0) == (farmerPos == 1));

               if (canCarry) {
                    int nextState = current ^ move;
                    if (isSafe(nextState) && visited[nextState] == -1) {
                         visited[nextState] = current;
                         q.push(nextState);
                    }
               }
          }
     }


     vector<int> path;
     int current = target;
     if (visited[current] == -1) return path;
     while (true) {
          path.push_back(current);
          if (current == start) break;
          current = visited[current];
     }
     reverse(path.begin(), path.end());
     stateInt = path;
     return path;
}
string question2::getMoveDescription(int from, int to) {
     int farmerFrom = (from >> 3) & 1;
     string direction = (farmerFrom == 0) ? "过河到北岸" : "返回南岸";

     // 计算状态差异（找出移动的物品）
     int diff = from ^ to;
     string carry;
     if (diff & 0x04) carry = "狼";
     else if (diff & 0x02) carry = "白菜";
     else if (diff & 0x01) carry = "羊";
     else carry = "";

     return "农夫" + (carry.empty() ? "独自" : ("带" + carry)) + direction;
}


vector<string> question2::work() {
     vector<int> path = question2::solve();

     if (path.empty()) {
          cout<<("未找到解决方案！")<<endl;
          return stateStr;
     }


     stateStr.push_back("农夫过河的步骤如下（共" + std::to_string(path.size() - 1) + "步）：");
     stateStr.push_back("");


     for (int i = 0; i < path.size(); ++i) {
          if (i == 0) {

               string line = "初始状态：" + question2::getStateDescription(path[i]);
               stateStr.push_back(line);
          } else {

               string line = "第" + std::to_string(i) + "步："
                               + question2::getMoveDescription(path[i-1], path[i]) + " → "
                               + question2::getStateDescription(path[i]);
               stateStr.push_back(line);
          }
     }
     for (const std::string& line : stateStr) {
          std::cout << line << std::endl;
     }
     return stateStr;
}
