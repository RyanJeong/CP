// https://www.acmicpc.net/problem/2870
#include <bits/stdc++.h>

using namespace std;

bool cmp(string&, string&);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
    cin>>n;
    
    vector<string> res;
    while (n--) {
        string str;
        cin>>str;

        string tmp;
        for (char& c : str) {
            if (isdigit(c)) {
                tmp+=c;
            }
            else {
                if (tmp.empty()) {
                    continue;
                }
                while (tmp.front()=='0' && tmp.size()>1) {
                    tmp.erase(0,1);
                }
                res.push_back(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty()) {
            while (tmp.front()=='0' && tmp.size()>1) {
                tmp.erase(0,1);
            }
            res.push_back(tmp);
            tmp.clear();
        }
    }
    sort(res.begin(),res.end(),cmp);
    for (string& str : res) {
        cout << str << '\n';
    }

    return 0;
}

bool cmp(string& a, string& b) 
{ 
    if (a.size()!=b.size()) {

        return a.size()<b.size();
    }

    int n = a.size();
    for (int i = 0; i<n; ++i) {
        if (a[i]==b[i]) {
            continue;
        }

        return a[i]<b[i];
    }

    return true;
}
