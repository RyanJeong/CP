#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, h;
    cin>>n>>p>>h;

    for (int i = 0; i<n; i++) {
        int dollar;
        cin>>dollar;

        if (dollar>h) {
            cout << "BBTV: Dollar reached " << dollar << " Oshloobs, A record!\n";
            h=dollar;
            p=dollar;
            continue;
        }

        if (dollar<p) {
            cout << "NTV: Dollar dropped by " << p-dollar << " Oshloobs\n";
        }
        p=dollar;
    }

    return 0;
}