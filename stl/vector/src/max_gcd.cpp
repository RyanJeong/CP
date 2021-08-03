// https://www.acmicpc.net/problem/9417
#include <bits/stdc++.h>

using namespace std;

int gcd(int, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cin.ignore(); // consume '\n'
    while (n--) {
        static vector<int> v(101);
        string str;
        getline(cin,str);
        str.push_back('\n'); // dummy
        
        int size = 0;
        int tmp = 0;
        for (char c : str) {
            if (isdigit(c)) {
                tmp = tmp*10+(c-'0');
            } 
            else {
                v[size++]=tmp;
                tmp=0;
            }
        }

        int res = 0;
        for (int i = 0; i<size; ++i) {
            for (int j = i+1; j<size; ++j) {
                res=max(res,gcd(v[i],v[j]));
            }
        }
        cout << res << '\n';
    }

    return 0;
}

int gcd(int a, int b)
{
    
    return ((b==0) ? a : gcd(b,a%b));
}

