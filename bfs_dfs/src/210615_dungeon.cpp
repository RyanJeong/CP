//http://icpc.me/6593
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int dx[] = {1,0,-1,0,0,0};
    const int dy[] = {0,1,0,-1,0,0}; 
    const int dz[] = {0,0,0,0,1,-1}; 

    while (1) {
        int l, r, c;
        cin>>l>>r>>c;
        if (!l && !r && !c) {
            break;
        }
        // Init.
        int arr[31][31][31]; // 0, 1 ~ 30
        bool is_visited[31][31][31];
        memset(is_visited, 0, sizeof is_visited);

        // dimension, x, y
        queue<pair<int, pair<int, int>>> q, exit;
        for (int i = 1; i<=l; ++i) {
            for (int j = 1; j<=r; ++j) {
                string str;
                cin>>str;
                int k = 1;

                for (char c : str) {
                    switch (c) {
                    // 'S' '.' -> 0, '#' -> -1, 'E' -> 1
                    case 'S':
                        arr[i][j][k]=0;
                        q.push({i,make_pair(j,k)});
                        is_visited[i][j][k]=true;;
                        break;
                    case '.':
                        arr[i][j][k]=0;
                        break;
                    case '#':
                        arr[i][j][k]=0;
                        is_visited[i][j][k]=true;
                        break;
                    case 'E':
                        arr[i][j][k]=-1;
                        exit.push({i,make_pair(j,k)});
                        break;
                    default:
                        break;
                    }
                    ++k;
                }
            }
        }

        // find the quickest way
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int d = 0; d<6; ++d) {
                int dim = cur.first+dz[d];
                int x = cur.second.first+dx[d];
                int y = cur.second.second+dy[d];

                if (dim<1 || dim>l) {
                    continue;
                }
                if (x<1 || x>r) {
                    continue;
                }
                if (y<1 || y>c) {
                    continue;
                }
                // if the position is on rock or is already visited
                if (is_visited[dim][x][y]) {
                    continue;
                }
                if (arr[dim][x][y]>=arr[cur.first][cur.second.first][cur.second.second]+1) {
                    continue;
                }
                dim[arr][x][y]=arr[cur.first][cur.second.first][cur.second.second]+1;
                q.push({dim,make_pair(x,y)});
                is_visited[dim][x][y]=true;
            }
        }
        int exit_dim = exit.front().first;
        int exit_x = exit.front().second.first;
        int exit_y = exit.front().second.second;

        if (is_visited[exit_dim][exit_x][exit_y]) {
            cout << "Escaped in " << arr[exit_dim][exit_x][exit_y] << " minute(s)." << '\n';
        }
        else {
            cout << "Trapped!" << '\n';
        }
    }

    return 0;
}