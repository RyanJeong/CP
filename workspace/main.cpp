#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin,str);
    stack<bool> s;
    while (getline(cin,str), str!="고무오리 디버깅 끝") {
        if (str=="문제") {
            s.push(true);
        }
        else if (str=="고무오리") {
            if (s.empty()) {
                s.push(true);
                s.push(true);
            }
            else {
                s.pop();
            }
        }
    }
    if (s.empty()) {
        cout << "고무오리야 사랑해";
    }
    else {
        cout << "힝구";
    }

    return 0;
}