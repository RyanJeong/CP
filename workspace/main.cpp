<<<<<<< HEAD
// https://www.acmicpc.net/problem/1389
=======
// https://www.acmicpc.net/problem/2870
>>>>>>> cb7420272c8de0f67e8e23020cb8152542066050
#include <bits/stdc++.h>

using namespace std;

bool cmp(string&, string&);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
<<<<<<< HEAD

    int n, m;
    cin>>n>>m;
    vector<vector<int>> d(n+1,vector<int>(n+1));
    fill(d.begin(),d.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        d[i][i]=0;
    }
    while (m--) {
        int a, b;
        cin>>a>>b;
        d[a][b]=1;
        d[b][a]=1;
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
=======

	int n;
    cin>>n;
    
    vector<string> res;
    while (n--) {
        string str;
        cin>>str;

        string tmp;
        for (char& c : str) {
            if (isdigit(c)) {
                tmp+=c;
            }
            else {
                if (tmp.empty()) {
                    continue;
                }
                while (tmp.front()=='0' && tmp.size()>1) {
                    tmp.erase(0,1);
                }
                res.push_back(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty()) {
            while (tmp.front()=='0' && tmp.size()>1) {
                tmp.erase(0,1);
>>>>>>> cb7420272c8de0f67e8e23020cb8152542066050
            }
            res.push_back(tmp);
            tmp.clear();
        }
    }
<<<<<<< HEAD

    int idx = 0;
    int min_edge = 1e9;
    for (int i = 1; i<=n; ++i) {
        int tmp = 0;
        for (int j = 1; j<=n; ++j) {
            tmp+=d[i][j];
        }
        if (min_edge>tmp) {
            min_edge=tmp;
            idx=i;
        }
=======
    sort(res.begin(),res.end(),cmp);
    for (string& str : res) {
        cout << str << '\n';
    }

    return 0;
}

bool cmp(string& a, string& b) 
{ 
    if (a.size()!=b.size()) {

        return a.size()<b.size();
    }

    int n = a.size();
    for (int i = 0; i<n; ++i) {
        if (a[i]==b[i]) {
            continue;
        }

        return a[i]<b[i];
>>>>>>> cb7420272c8de0f67e8e23020cb8152542066050
    }
    cout << idx;

    return true;
}