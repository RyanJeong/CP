#include <iostream>
///// WIP
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    for (auto cur : skill) {
        int type = cur[0];
        int x_max = cur[3];
        int y_max = cur[4];
        int deg = cur[5];
        for (int x = cur[1]; x<=x_max; ++x) {
            for (int y = cur[2]; y<=y_max; ++y) {
                board[x][y]=board[x][y]+((type==1) ? -deg : deg);
            }
        }
    }

    int answer = 0;
    for (auto row : board) {
        for (auto e : row) {
            if (e>0) {
                ++answer;
            }
        }
    }
    
    return answer;
}
/////

int main(void)
{
    cout << solution({{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}},{{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}}) << '\n'; 
    cout << solution({{1,2,3},{4,5,6},{7,8,9}}, {{1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100}}) << '\n';
    return 0;
}
