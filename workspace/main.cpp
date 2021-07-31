/*
성질 1. 두 수 A, B의 공약수들은 GCD(A, B)의 모든 약수들이다.

성질 2. 두 수 A, B의 공배수들은 LCM(A, B)의 모든 배수들이다.

성질 3. A × B = GCD(A, B) × LCM(A, B) 
-> A X B ÷ GCD(A, B) = LCM(A, B);
성질 4. GCD(n, n+1) = 1
*/

#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    vector<int> v;
    int sign = 1;
    int tmp = 0;
    s.push_back(' ');
    for (char c : s) {
        if (c=='-') {
            sign=-1;
        }
        else if (c>='0' && c<='9') {
            tmp=tmp*10+c-'0';
        }
        else { // ' '
            v.push_back(sign*tmp);
            sign=1;
            tmp=0;
        } 
    }
    sort(v.begin(),v.end());
    string answer = "";
    string buf;
    int min = v.front();
    if (min<0) {
        min*=-1;
    }
    while (min) {
        buf.push_back(min%10+'0');
        min/=10;
    }
    if (v.front()<0) {
        buf.push_back('-');
    }
    reverse(buf.begin(),buf.end());
    answer+=buf;
    answer.push_back(' ');
    buf="";
    int max = v.back();
    if (max<0) {
        max*=-1;
    }
    while (max) {
        buf.push_back(max%10+'0');
        max/=10;
    }
    if (v.back()<0) {
        buf.push_back('-');
    }
    reverse(buf.begin(),buf.end());
    answer+=buf;
    
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "1 2 3 4";
    cout << solution(s);
    s="-1 -2 -3 -4";
    cout << solution(s);

    return 0;
}