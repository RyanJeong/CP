#include <bits/stdc++.h>

using namespace std;

vector<int> get_fail(string);
vector<int> kmp(string, string);
int gcd(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string p;
    for (int i = 1; i<=n; ++i) {
        char c;
        cin>>c;
        p.push_back(c); 
    }
    string s;
    for (int i = 1; i<=n; ++i) {
        char c;
        cin>>c;
        s.push_back(c); 
    }
    s+=s; // circular
    s.pop_back(); // ABC -> ABCAB

    auto res = kmp(s,p);
    int m = res.size();
    int d = gcd(n,m);    
    cout << m/d << '/' << n/d;

    return 0;
}

vector<int> get_fail(string p)
{
    int n_p = p.size();
    vector<int> fail(n_p);
    for (int i = 1, j = 0; i<n_p; i++) {
        while (j>0 && p[i]!=p[j]) {
            j=fail[j-1];
        }
        if (p[i]==p[j]) {
            fail[i]=j+1;
            ++j;
        }
    }

    return fail;
}

vector<int> kmp(string s, string p)
{
    auto fail = get_fail(p);
    int n_s = (int)s.size();
    int n_p = (int)p.size();

    vector<int> ans;
    for (int i = 0, j = 0; i<n_s; i++) {
        while (j>0 && s[i]!=p[j]) {
            j=fail[j-1];
        }
        if (s[i]==p[j]) {
            if (j==n_p-1){
                ans.push_back(i-n_p+1);
                j=fail[j];
            }
            else {
                j++;
            }
        }
    }

    return ans;
}

int gcd(int a, int b)
{
    
    return ((b==0) ? a : gcd(b,a%b));
}