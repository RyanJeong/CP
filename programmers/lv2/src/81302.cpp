#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    for (vector<string> place : places) {
        vector<pair<int, int>> pos;
        for (int i = 0; i<5; ++i) {
            for (int j = 0; j<5; ++j) {
                if (place[i][j]=='P') {
                    pos.push_back({i,j});
                }
            }
        }

        bool is_safe = true;
        for (auto p : pos) {
            queue<pair<int, int>> q;
            q.push(p);
            vector<vector<int>> dist(5,vector<int>(5));
            fill(dist.begin(),dist.end(),vector<int>(5,-1));
            dist[p.first][p.second]=0;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                const vector<pair<int, int>> adjacency = {
                    {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                };
                for (auto d : adjacency) {
                    int x = cur.first+d.first;                
                    int y = cur.second+d.second;                

                    if (x<0 || x>=5) {
                        continue;
                    }
                    if (y<0 || y>=5) {
                        continue;
                    }
                    if (place[x][y]=='X' || dist[x][y]!=-1) {
                        continue;
                    }
                    q.push({x,y});
                    dist[x][y]=dist[cur.first][cur.second]+1;
                    if (place[x][y]=='P' && dist[x][y]<=2) {
                        is_safe=false;
                    }
                }
            }
            if (!is_safe) {
                break;
            }            
        }
        answer.push_back((is_safe) ? 1 : 0);
    }

    return answer;
}