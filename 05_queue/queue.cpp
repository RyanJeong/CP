// http://icpc.me/10845
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        if(str=="push") {
            int v;
            cin >> v;

            q.push(v);
        } 
        else if (str=="pop") {
            if(q.empty()) {
                cout << -1 << '\n';
            } 
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } 
        else if (str=="size") {
            cout << q.size() << '\n';
        } 
        else if(str=="empty") {
            cout << q.empty() << '\n';
        } 
        else if (str=="front") {
            cout << (q.empty()) ? -1 : q.front() << '\n';
        } 
        else if (str=="back") {
            cout << (q.empty()) ? -1 : q.back() << '\n';
        }
    }

    return 0;
}