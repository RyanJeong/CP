#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int n;
    while (cin>>str>>n) {
        cout << str << ' ' << n << " = ";
        do {
            --n;
            if (!n) {
                break;
            }
        } while (next_permutation(str.begin(),str.end()));
        if (n) {
            cout << "No permutation" << '\n';
        }
        else {
            cout << str << '\n';
        }
    }

    return 0;
}