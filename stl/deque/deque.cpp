// http://icpc.me/10866
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    deque<int> dq;

    while (n--) {
        string str;
        cin>>str;

        if(str=="push_back") {
            int v;
            cin>>v;

            dq.push_back(v);
        } 
        else if(str=="push_front") {
            int v;
            cin>>v;

            dq.push_front(v);
        } 
        else if (str=="pop_front") {
            if(dq.empty()) {
                cout << -1 << '\n';
            } 
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } 
        else if (str=="pop_back") {
            if(dq.empty()) {
                cout << -1 << '\n';
            } 
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } 
        else if (str=="size") {
            cout << dq.size() << '\n';
        } 
        else if(str=="empty") {
            cout << dq.empty() << '\n';
        } 
        else if (str=="front") {
            cout << (dq.empty()) ? -1 : dq.front() << '\n';
        } 
        else if (str=="back") {
            cout << (dq.empty()) ? -1 : dq.back() << '\n';
        }
    }

    return 0;
}