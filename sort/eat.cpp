// http://icpc.me/7795
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
        int a, b;
        cin>>a>>b;

        vector<int> v_a;
        for (int i = 0; i<a; ++i) {
            int temp;
            cin>>temp;

            v_a.push_back(temp);
        }

        vector<int> v_b;
        for (int i = 0; i<b; ++i) {
            int temp;
            cin>>temp;

            v_b.push_back(temp);
        }

        sort(v_a.begin(),v_a.end());
        sort(v_b.begin(),v_b.end());

        int num = 0;
        while (!v_a.empty() && !v_b.empty()) {
            if (v_a.back()>v_b.back()) {
                num+=v_b.size();
                v_a.pop_back();
            } else {
                v_b.pop_back();
            }
        }
        cout << num << '\n';
    }

    return 0;
}