// https://www.acmicpc.net/problem/5397
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l;
    cin>>l;
    while (l--) {
        string str;
        cin>>str;
        list<char> l;
        auto it = l.begin();
        for (char c : str) {
            switch (c) {
            case '-':
                if (it!=l.begin()) {
                    it=l.erase(prev(it));
                }
                break;
            case '<':
                if (it!=l.begin()) {
                    --it;
                }
                break;
            case '>':
                if (it!=l.end()) {
                    ++it;
                }
                break;
            default:
                l.insert(it,c);
                break;
            }
        }
        for (char c : l) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}