#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    pair<int, string> res;
    int max_cnt = -1;
    while (n--) {
        string str;
        cin>>str;
        int a, b;
        cin>>a>>b;

        int cnt = 0;
        while (b>=a) {
            b-=a;
            b+=2;
            ++cnt;
            ++res.first;
        }
        if (max_cnt<cnt) {
            max_cnt=cnt;
            res.second=str;
        }
    }
    cout << res.first << '\n' << res.second;

    return 0;
}