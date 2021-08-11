#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> is_visited(m,vector<bool>(n));
    for (int i = 0; i<m; ++i) {
        for (int j = 0; j<n; ++j) {
            if (!picture[i][j] || is_visited[i][j]) {
                continue;
            }
            int target = picture[i][j];
            int area = 0;
            queue<pair<int, int>> q;
            q.push({i,j});
            is_visited[i][j]=true;
            ++number_of_area;
            while (!q.empty()) {
                ++area;
                auto cur = q.front();
                q.pop();

                const vector<pair<int, int>> adjacency = {
                    {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                };
                for (auto d : adjacency) {
                    int x = cur.first+d.first;
                    int y = cur.second+d.second;

                    if (x<0 || x>=m) {
                        continue;
                    }
                    if (y<0 || y>=n) {
                        continue;
                    }
                    if (picture[x][y]!=target || is_visited[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    is_visited[x][y]=true;
                }
            }
            max_size_of_one_area=max(max_size_of_one_area,area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}