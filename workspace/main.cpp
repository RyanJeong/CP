// 
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t1, v1, t2, v2;
    cin>>t1>>v1>>t2>>v2;

    do {
        if (t2<0 && v2>=10) {
            cout << "A storm warning for tomorrow! Be careful and stay home if possible!\n";
            break;
        }
        if (t2<t1) {
            cout << "MCHS warns! Low temperature is expected tomorrow.\n";
            break;
        }
        if (v1<v2) {
            cout << "MCHS warns! Strong wind is expected tomorrow.\n";
            break;
        }
        cout << "No message\n";
    } while (0);

    return 0;
}
