// http://icpc.me/5430
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin>>test_case;

    while (test_case--) {
        string s;
        cin>>s;
        int n;
        cin>>n;
        cin.get(); // '\n'
        cin.get(); // '['
        deque<int> dq;

        if (n==0) {
            cin.get(); // ']'
        } 
        else {
            for (int i = 0; i<n; ++i) {
                int temp;
                cin>>temp;

                dq.push_back(temp);
                cin.get(); // i == n - 1 ? ']' : ','
            }
        }
        bool is_reverse = false;
        bool is_error = false;
        for (char c : s) {
            if (c=='R') {
                is_reverse=!is_reverse;
            } 
            else if (c=='D') {
                if (dq.empty()) {
                    is_error=true;
                    cout << "error\n";
                    break;
                } 
                else {
                    (is_reverse) ? dq.pop_back() : dq.pop_front();
                }
            }
        }
        if (!is_error) {
            cout << '[';
            if (dq.empty()) {
                cout << "]\n";
            } 
            else {
                if (is_reverse) {
                    while (!dq.empty()) {
                        cout << dq.back() << ((dq.size()==1) ? ']' : ',');
                        dq.pop_back();
                    }
                } 
                else {
                    while (!dq.empty()) {
                        cout << dq.front() << ((dq.size()==1) ? ']' : ',');
                        dq.pop_front();
                    }
                }
                cout << '\n';
            }
        }
    }

    return 0;
}