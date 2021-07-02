// https://www.acmicpc.net/problem/10814
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string>, pair<int, string>);

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<pair<int, string>> v;
    for (int i = 1; i<=n; ++i) {
        int age;
        cin>>age;
        string name;
        cin>>name;
        v.push_back({age,name});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for (auto cur : v) {
        cout << cur.first << ' ' << cur.second << '\n';
    }

	return 0;
}

bool cmp(pair<int, string> s, pair<int, string> t)
{

    return s.first<t.first;
}