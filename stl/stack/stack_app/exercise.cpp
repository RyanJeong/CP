// https://www.acmicpc.net/problem/2504
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 0;
    int temp = 1;
    bool is_invalid = false;
    string str;
    cin>>str;
    stack<char> s;
    char prev;
    for (char c : str) {
        if (c=='(') {
            s.push(c);
            temp*=2;
        }
        else if (c=='[') {
            s.push(c);
            temp*=3;
        }
        else if (!s.empty() && s.top()=='(' && c==')') {
            if (prev=='(') {
                num+=temp;
            }
            s.pop();
            temp/=2;
        }
        else if (!s.empty() && s.top()=='[' && c==']') {
            if (prev=='[') {
                num+=temp;
            }
            s.pop();
            temp/=3;
        }
        else {
            is_invalid=true;
            break;
        }
        prev=c;
    }
    cout << ((!s.empty() || is_invalid) ? 0 : num);

    return 0;
}