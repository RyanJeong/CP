// https://www.acmicpc.net/problem/11328
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    string tmp;
    while (n--) {
        cin>>tmp;
        vector<char> a;
        for (char c : tmp) {
            a.push_back(c);
        }
        cin>>tmp;
        vector<char> b;
        for (char c : tmp) {
            b.push_back(c);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while (!a.empty() && !b.empty()) {
            if (a.back()!=b.back()) {
                break;
            }
            a.pop_back();
            b.pop_back();
        }
        cout << ((a.empty() && b.empty()) ? "Possible" : "Impossible") << '\n';
    }

    return 0;
}