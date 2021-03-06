// http://icpc.me/1431
#include <bits/stdc++.h>

using namespace std;

bool cmp(string, string);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<string> str;
    for (int i = 0; i<n; ++i) {
        string temp;
        cin>>temp;

        str.push_back(temp);
    }

    sort(str.begin(),str.end(),cmp);
    for (string s : str) {
        cout << s << '\n';
    }

    return 0;
}

bool cmp(string a, string b)
{
    if (a.length()!=b.length()) {
        
        // Ascending
        return a.length()<b.length();
    }

    int sum_a = 0;

    for (unsigned i = 0; i<a.length(); ++i) {
        if (isdigit(a[i])) {
            sum_a+=a[i]-'0';
        }
    }
    int sum_b = 0;

    for (unsigned i = 0; i<b.length(); ++i) {
        if (isdigit(b[i])) {
            sum_b+=b[i]-'0';
        }
    }
    if (sum_a!=sum_b) {

        // Ascending
        return sum_a<sum_b;
    }

    // Ascending
    return a<b; // a[0] < b[0], a[1] < b[1], ...
}