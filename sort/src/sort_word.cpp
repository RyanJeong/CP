// https://www.acmicpc.net/problem/1181
#include <bits/stdc++.h>

using namespace std;

bool cmp(string, string);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    set<string> s;
    for (int i = 1; i<=n; ++i) {
        string temp;
        cin>>temp;
        s.insert(temp);
    }
    vector<string> v;
    for (string str : s) {
        v.push_back(str);
    }
    sort(v.begin(),v.end(),cmp);
    for (string str : v) {
        cout << str << '\n';
    }

    return 0;
}

bool cmp(string s, string t)
{

    return s.size()<t.size() || (s.size()==t.size() && s<t);
}
