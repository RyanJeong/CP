// https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sec = 359999;
    string answer = "";
    for (int i = 1; i<=3; ++i) {
        int tmp = sec%((i==3) ? 100 : 60);
        sec/=((i==3) ? 100 : 60);
        answer.push_back(tmp%10+'0');
        tmp/=10;
        answer.push_back(tmp%10+'0');
        if (i!=3) {
            answer.push_back(':');
        }
    }
    reverse(answer.begin(),answer.end());
    cout << answer;

    return 0;
}