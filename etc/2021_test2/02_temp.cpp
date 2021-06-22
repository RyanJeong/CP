#include <bits/stdc++.h>
//https://www.mathsisfun.com/calculator-precision.html

using namespace std;

string b2s(string b) 
{
    // erase postfix zeros
    for (int i = b.size()-1; b[i]=='0'; --i) {
        b.erase(i,1);
    }

    // bin to floating point
    int i = 0;
    long long i_val = 0.0;
    while (isdigit(b[i])) {
        i_val=i_val*2+(b[i++]-'0');
    }
    int cnt = 0;
    double f_val = 0.0; // IEEE 1 11 '52'
    if (b[i]=='.') {
        ++i;
        for (double w = 2.0; isdigit(b[i]); w*=2.0) {
            f_val+=(b[i++]-'0')/w;
            ++cnt;
        }
    }
    
    // floating point to str
    // 2^52 = 52log2, max len: 16 + '\0'
    char i_arr[17];
    memset(i_arr,0,sizeof i_arr);
    snprintf(i_arr,sizeof i_arr,"%lld",i_val);
    string i_res(i_arr);
    char f_arr[55]; // '0', '.', ...(52), '\0';
    memset(f_arr,0,sizeof f_arr);
    snprintf(f_arr,sizeof f_arr,"%.*f",cnt,f_val);
    string f_res(f_arr+2); // ignore '0', '.'

    return i_res+'.'+f_res;
}

int main()
{
    string result = b2s(""
    "101"
    "."
    "10"
    );

    cout << result << '\n';

    return 0;
}