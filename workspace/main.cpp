#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r, d, c;
    cin>>l>>r>>d>>c;

    int n_zombie = 0;
    int damage = d;
    for (int i = 1; i<=l; ++i) {
        int hp;
        cin>>hp;
        cout << ' ' << hp-damage << '\n';
        if (hp>damage) {
            ++n_zombie;
        }
        if (i<r) {
            damage+=d;
        }
    }

    if (n_zombie>c) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}