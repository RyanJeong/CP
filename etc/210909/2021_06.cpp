#include <iostream>
///////////////////
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<int> card;

const int board_size = 4;
int r, c;

int bfs(int dest)
{
    const int dx[] = {1,-1,0,0};
    const int dy[] = {0,0,1,-1};

    vector<vector<bool>> is_checked(board_size,vector<bool>(board_size));
    queue<pair<pair<int,int>,int>> q;
    q.push({make_pair(r,c),0});
    is_checked[r][c] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (board[cur.first.first][cur.first.second]==dest) {
            board[cur.first.first][cur.first.second]=0;
            r=cur.first.first;
            c=cur.first.second;

            return cur.second+1; // cnt+1
        }

        // move one cell
        for (int d = 0; d<4; ++d) {
            int x = cur.first.first+dx[d];
            int y = cur.first.second+dy[d];
            int cnt = cur.second;

            if (x<0 || x>=4) {
                continue;
            }
            if (y<0 || y>=4) {
                continue;
            }
            if (is_checked[x][y]) {
                continue;
            }
            is_checked[x][y]=true;
            q.push({make_pair(x,y),cnt+1});
        }

        // move the cell nearest on the border
        for (int d = 0; d<4; ++d) {
            int x = cur.first.first;
            int y = cur.first.second;
            int cnt = cur.second;

           	while (x+dx[d]>=0 && y+dy[d]>=0 && x+dx[d]<4 && y+dy[d]<4) {
                x+=dx[d];    
                y+=dy[d];
                if (board[x][y]) {
                    break;
                }
            }
            if (is_checked[x][y]) {
                continue;
            }
            is_checked[x][y]=true;
            q.push({make_pair(x,y),cnt+1});
        }
    }

    return -1;
}

int solution(vector<vector<int>> b, int row, int col) 
{
    const int max_num = 6;

    vector<bool> is_card_used(max_num+1); // 1-based
    for (int i = 0; i<board_size; i++) {
        for (int j = 0; j<board_size; j++) {
            if (b[i][j]) {
                is_card_used[b[i][j]]=true;
            }
        }
    }
    for (int i = 1; i<=max_num; i++) {
        if (is_card_used[i]) {
            card.push_back(i);
        }
    }

    int answer = 0x3f3f3f3f;
    do {
        board=b;
        r=row;
        c=col;
        int tmp = 0;
        for (auto c : card) {
            tmp+=bfs(c);
            tmp+=bfs(c);
        }
        answer=min(answer,tmp);
    } while(next_permutation(card.begin(),card.end()));

    return answer;
}
//////////////////

int main(void)
{
    //cout << solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}},1,0) << '\n';
    cout << solution({{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}},0,1) << '\n';
    return 0;
}