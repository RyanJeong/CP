// https://programmers.co.kr/learn/courses/30/lessons/42748
// K번째수
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    int t = commands.size();
    for (int i = 0; i<t; ++i) {
        vector<int> tmp(array);
        int from = commands[i][0]-1;
        int to = commands[i][1];
        int idx = commands[i][2]-1;
        sort(tmp.begin()+from,tmp.begin()+to);
        answer.push_back(tmp[from+idx]);
    }
    
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<vector<int>> c(m, vector<int>(3));
    for (int i = 0; i<m; ++i) {
        for (int j = 0; j<3; ++j) {
            cin>>c[i][j];
        }
    }
    vector<int> res = solution(a,c);
    for (auto i : res) {
        cout << i << ' ';
    }

    return 0;
}

        

