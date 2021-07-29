// https://www.acmicpc.net/problem/12100
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& arr, int n, int depth, int& res);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int res = 0;
    vector<vector<int>> arr(n+1,vector<int>(n+1)); // 1-based
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
            res=max(res,arr[i][j]);
        }
    }
    dfs(arr,n,0,res);
    cout << res;

    return 0;
}

void dfs(vector<vector<int>>& arr, int n, int depth, int& res)
{
    const int limit = 5;
    static vector<int> max_per_depth(limit+1); // depth: 0~5

    int max_val = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            max_val=max(max_val,arr[i][j]);
        }
    }
    // 최대 깊이일 때, 최대값을 구하고 해당 최대값을 구하기 위한 
    // 중간 과정에서의 최소값을 기록
    if (depth==limit) {
        res=max(res,max_val);

        int tmp = res;
        while (depth) {
            max_per_depth[depth--]=tmp;
            tmp/=2;
        }

        return;
    }
    // 현재 상태에서 최대값을 절대 만들 수 없는 경우
    if (max_val<=max_per_depth[depth]) {

        return;
    }

    // push arr to tmp
    vector<vector<int>> tmp(arr);

    for (int d = 0; d<4; ++d) { 
        // move
        queue<int> q;
        switch (d) {
        case 0: // left
            for (int i = 1; i<=n; ++i) {
                for (int j = 1; j<=n; ++j) {
                    if (arr[i][j]) {
                        q.push(arr[i][j]);
                        arr[i][j]=0;
                    }
                }
                int idx = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (!arr[i][idx]) {
                        arr[i][idx]=cur;
                    }
                    else if (arr[i][idx]==cur) {
                        arr[i][idx++]*=2;
                    }
                    else {
                        arr[i][++idx]=cur;
                    }
                }
            }
            break;
        case 1: // top
            for (int j = 1; j<=n; ++j) {
                for (int i = 1; i<=n; ++i) {
                    if (arr[i][j]) {
                        q.push(arr[i][j]);
                        arr[i][j]=0;
                    }
                }
                int idx = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (!arr[idx][j]) {
                        arr[idx][j]=cur;
                    }
                    else if (arr[idx][j]==cur) {
                        arr[idx++][j]*=2;
                    }
                    else {
                        arr[++idx][j]=cur;
                    }
                }
            }
            break;
        case 2: // right
            for (int i = 1; i<=n; ++i) {
                for (int j = n; j>0; --j) {
                    if (arr[i][j]) {
                        q.push(arr[i][j]);
                        arr[i][j]=0;
                    }
                }
                int idx = n;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (!arr[i][idx]) {
                        arr[i][idx]=cur;
                    }
                    else if (arr[i][idx]==cur) {
                        arr[i][idx--]*=2;
                    }
                    else {
                        arr[i][--idx]=cur;
                    }
                }
            }
            break;
        case 3: // bottom
            for (int j = 1; j<=n; ++j) {
                for (int i = n; i>0; --i) {
                    if (arr[i][j]) {
                        q.push(arr[i][j]);
                        arr[i][j]=0;
                    }
                }
                int idx = n;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if (!arr[idx][j]) {
                        arr[idx][j]=cur;
                    }
                    else if (arr[idx][j]==cur) {
                        arr[idx--][j]*=2;
                    }
                    else {
                        arr[--idx][j]=cur;
                    }
                }
            }
            break;
        default:
            break;
        }

        // 4방향 중 한 방향으로 이동했을 때 결과가 동일하다면, 
        // depth를 1만큼 손해를 본다. 따라서 해당 경우는 더 이상
        // 계산하지 않는다. 
        bool is_same = true;
        for (int i = 1; is_same && i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                if (arr[i][j]!=tmp[i][j]) {
                    is_same=false;
                    break;
                }
            }
        }
        if (!is_same) {
            dfs(arr,n,depth+1,res);

            // pop arr from tmp
            arr=tmp;
        }
    }

    return;
}
