// https://www.acmicpc.net/problemv/1283
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<bool> is_used(26);
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<string>> v(n);

    for (int i = 0; i<n; ++i) {
        string tmp;
        getline(cin,tmp,'\n');

        stringstream ss(tmp);
        while (getline(ss,tmp,' ')) {
            v[i].push_back(tmp);
        }

        // process
        bool is_failed = true;
        for (string& str : v[i]) {
            char c = str.front();
            int idx = tolower(c)-'a';
            if (is_used[idx]) {
                continue;
            }
            is_used[idx]=true;
            str.insert(str.begin(),'[');
            str.insert(str.begin()+2,']');
            is_failed=false;
            break;
        }
        if (!is_failed) {
            continue;
        }
        for (string& str : v[i]) {
            for (auto it = str.begin(); it!=str.end(); ++it) {
                int idx = tolower(*it)-'a';
                if (is_used[idx]) {
                    continue;
                }
                is_used[idx]=true;
                str.insert(it,'[');
                str.insert(it+2,']');
                is_failed=false;
                break;
            }
            if (!is_failed) {
                break;
            }
        }
    }
    for (int i = 0; i<n; ++i) {
        for (string& str : v[i]) {
            cout << str << ' ';
        }
        cout << '\n';
    }

    return 0;
}
