// http://icpc.me/10828
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    stack<int> s;

    while (n--) {
        string str;
        cin>>str;

        if(str=="push") {
            int v;
            cin>>v;

            s.push(v);
        } 
        else if (str=="pop") {
            if(s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } 
        else if (str=="size") {
            cout << s.size() << '\n';
        } 
        else if (str=="empty") {
            cout << s.empty() << '\n';
        } 
        else if (str=="top") {
            cout << (s.empty()) ? -1 : s.top() << '\n';
        }
    }

    return 0;
}