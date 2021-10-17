// https://www.acmicpc.net/problem/1918
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;

    stack<char> op;
    string res;
    for (char c : str) {
        if (isalpha(c) && isupper(c)) {
            res+=c;
            continue;
        }

        // +, -, *, /, (, )
        switch (c) {
        case '(':
            op.push(c);
            break;
        case '*':
        case '/':
            while (!op.empty() && (op.top()=='*' || op.top()=='/')) {
                res+=op.top();
                op.pop();
            }
            op.push(c);
            break;
        case '+':
        case '-':
        //  while (!op.empty() && (op.top()=='+' || op.top()=='|' || op.top()=='*' || op.top()=='/')) {
            while (!op.empty() && op.top()!='(') {
                res+=op.top();
                op.pop();
            }
            op.push(c);
            break;
        case ')':
            while (!op.empty() && op.top()!='(') {
                res+=op.top();
                op.pop();
            }
            op.pop();
            break;
        default:

            return 1;
        } 
    }

    while (!op.empty()) {
        res+=op.top();
        op.pop();
    }
    cout << res;

    return 0;
}
