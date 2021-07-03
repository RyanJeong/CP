//http://icpc.me/5014
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    int arr[f+1]; // 0, 1 ~ f
    memset(arr, -1, sizeof arr);
    vector<int> dx;
    dx.push_back(u);
    dx.push_back(-d);

    queue<int> q;
    arr[s]=0;
    q.push(s);

    bool is_reached = false;
    while (!q.empty() && !is_reached) {
        auto cur = q.front();
        q.pop();

        if (cur==g) {
            is_reached=true;
            break;
        }
        for (int d : dx) {
            int x = cur+d;

            if (x<1 || x>f) {
                continue;
            }
            if (arr[x]!=-1 || arr[x]>=arr[cur]+1) {
                continue;
            }
            arr[x]=arr[cur]+1;
            q.push(x);
        }
    }
    if (is_reached) {
        cout << arr[g];
    }
    else {
        cout << "use the stairs";
    }

    return 0;
}