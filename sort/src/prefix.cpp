// http://icpc.me/11656
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;
    int size = str.size();
    vector<string> v;
    for (int i = 0; i<size; ++i) {
        v.push_back(str.substr(i,size));
    }
    sort(v.begin(),v.end());
    for (string s : v) {
        cout << s << '\n';
    }

    return 0;
}