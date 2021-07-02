// https://www.acmicpc.net/problem/1406
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    list<char> l;
    for (char c : s) {
        l.push_back(c);
    }
    int cnt;
    cin>>cnt;
    cin.ignore(); // consume a '\n'
    auto it = l.end();

    for (int i = 0; i<cnt; ++i) {
        string ops;
        getline(cin,ops);
        switch (ops.front()) {
        case 'L':
            if (it!=l.begin()) {
                --it;
            }
            break;
        case 'D':
            if (it!=l.end()) {
                ++it;
            }
            break;
        case 'B':
            if (it!=l.begin()) {
                it=l.erase(prev(it));
            }
            break;
        case 'P':
            l.insert(it,ops[2]);
            break;
        default:
            break;
        }
    }
    for (char c : l) {
        cout << c;
    }

    return 0;
}