// http://icpc.me/9012
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    while(n--) {
        string ps;
        cin>>ps;
        bool is_vps = true;
        stack<int> s;

        for (char c : ps) {
            if (c=='(') {
                s.push(c);
            } 
            else {
                if (s.empty()) {
                    is_vps=false;
                    break;
                } 
                else { // ')'
                    if (s.top()!='(') {
                        is_vps=false;
                        break;
                    } 
                    else { // s.top() is '('
                        s.pop();
                    }
                }
            }
        }    
        cout << ((s.empty() && is_vps) ? "YES" : "NO") << '\n';
    }

    return 0;
}