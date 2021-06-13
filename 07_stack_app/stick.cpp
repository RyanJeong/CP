// http://icpc.me/10799
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 0;
    int cnt = 0;
    bool is_cut = true;
    string str;
    cin >> str;

    for (char c : str) {
        if (c=='(') {
            ++cnt;
            is_cut = false;
        } 
        else if (c==')') {
            --cnt;
            if (is_cut) {
                num+=1;
            } 
            else {
                num+=cnt;
                is_cut=true;
            }
        }
    }  
    cout << num;

    return 0;
}