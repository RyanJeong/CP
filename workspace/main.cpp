// https://www.acmicpc.net/problem/12094
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
        }
    }
    dfs(arr,n,0,res);
    cout << res;

    return 0;
}

void dfs(vector<vector<int>>& arr, int n, int depth, int& res)
{
    static vector<int> max_per_depth(n); // 0-based

    int max_val = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            max_val=max(max_val,arr[i][j]);
        }
    }
    // 현재 상태에서 최대값을 절대 만들 수 없는 경우
    if (max_val<=max_per_depth[depth]) {
        return;
    }
    // 최대 깊이일 때, 최대값을 구하고 해당 최대값을 구하기 위한 중간 과정값을 기록
    if (depth==10) {
        res=max(res,max_val);

        int tmp = res;
        while (depth--) {
            max_per_depth[depth]=tmp;
            tmp/=2;
        }

        return;
    }

    // backup
    vector<vector<int>> tmp(arr);
    for (int d = 0; d<4; ++d) { 
        // move
        switch (d) {
        case 0: // left
            for (int i = 1; i<=n; ++i) {
                vector<int> ith_row(n+1);
                int idx=1;
                for (int j = 1; j<=n; ++j) {
                    if (!tmp[i][j]) {
                        continue;
                    }
                    if (!ith_row[idx]) {
                        ith_row[idx]=tmp[i][j];
                    } 
                    else if (ith_row[idx]==tmp[i][j]) {
                        ith_row[idx++]*=2;
                    } 
                    else {
                        ith_row[++idx]=tmp[i][j];
                    }
                }
                tmp[i]=ith_row;
            }
            break;
        case 1: // bottom
            break;
        case 2: // right
            for (int i = 1; i<=n; ++i) {
                vector<int> ith_row(n+1);
                int idx=n;
                for (int j = 1; j<=n; ++j) {
                    if (!tmp[i][j]) {
                        continue;
                    }
                    if (!ith_row[idx]) {
                        ith_row[idx]=tmp[i][j];
                    } 
                    else if (ith_row[idx]==tmp[i][j]) {
                        ith_row[idx--]*=2;
                    } 
                    else {
                        ith_row[--idx]=tmp[i][j];
                    }
                }
                tmp[i]=ith_row;
            }
            break;
        case 3: // up
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
            // recovery
            arr=tmp;
        }
    }

    return;
}