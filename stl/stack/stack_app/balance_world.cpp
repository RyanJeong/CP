// https://www.acmicpc.net/problem/4949
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (string str; getline(cin,str); ) {
        if (str==".") {
            break;
        }
        stack<char> bracket;
        bool is_valid = true;
        for (char c : str) {
            if (c=='(') {
                bracket.push(c);
            }
            else if (c=='[') {
                bracket.push(c);
            }
            else if (c==')') {
                if (!bracket.empty() && bracket.top()=='(') {
                    bracket.pop();
                }
                else {
                    is_valid=false;
                    break;
                }
            }
            else if (c==']') {
                if (!bracket.empty() && bracket.top()=='[') {
                    bracket.pop();
                }
                else {
                    is_valid=false;
                    break;
                }
            }
        }
        cout << ((is_valid && bracket.empty()) ? "yes" : "no") << '\n';
    }

    return 0;
}
