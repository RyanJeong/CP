// https://www.acmicpc.net/problem/12789
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    stack<int> s;
    int next = 1;
    while (n--) {
        int tmp;
        cin>>tmp;
        s.push(tmp);
        while (!s.empty() && s.top()==next) {
            ++next;
            s.pop();
        }
    }
    cout << ((s.empty()) ? "Nice" : "Sad");

    return 0;
}