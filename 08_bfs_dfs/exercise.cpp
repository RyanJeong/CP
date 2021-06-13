// http://icpc.me/2667
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int  arr[27][27]; // 01234, 5 ~ 25, OOB
bool is_visited[27][27];

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 0; i<n; ++i) {
        string str;
        cin>>str;

        for (int j = 0; j<n; ++j) {
            arr[i][j]=str[j]-'0';
        }
    }

    vector<int> v;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            if (arr[i][j]==0 || is_visited[i][j]) {
                continue;
            }
            int n_house = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            is_visited[i][j] = true;

            while (!q.empty()) {
                ++n_house;
                // pair<int, int> cur = q.front(); 
                // auto cur = q.front();
                pair<int, int> cur = q.front(); 
                q.pop();

                for (int k = 0; k<4; ++k) {
                    int x = cur.X + dx[k];
                    int y = cur.Y + dy[k];

                    if (x<0 || x>=n) {
                        continue;
                    }
                    if (y<0 || y>=n) {
                        continue;
                    }
                    if (is_visited[x][y] || arr[x][y]==0) {
                        continue;
                    }
                    is_visited[x][y]=true;
                    q.push({x,y});
                }
            }
            v.push_back(n_house);
        }
    }
    sort(v.begin(),v.end());

    cout << v.size() << '\n';
    for (int i : v) {
        cout << i << '\n';
    }

    return 0;
}