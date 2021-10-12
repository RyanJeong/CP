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

        queue<int> q;
        q.push(a);
        vector<int> prev(10'000);
        prev[a]=-1;
        vector<char> path(10'000);
        path[a]=-1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur==b) {
                string str;
                while (prev[cur]!=-1) {
                    str.push_back(path[cur]);
                    cur=prev[cur];
                }
                reverse(str.begin(),str.end());
                cout << str << '\n';
                break;
            }

            int next;
            next=(2*cur)%10'000;
            if (!path[next]) {
                path[next]='D';
                prev[next]=cur;
                q.push(next);
            }
            next=((!cur) ? 9'999 : cur-1);
            if (!path[next]) {
                path[next]='S';
                prev[next]=cur;
                q.push(next);
            }
            next=(cur%1'000)*10+cur/1'000;
            if (!path[next]) {
                path[next]='L';
                prev[next]=cur;
                q.push(next);
            }
            next=(cur%10)*1'000+cur/10;
            if (!path[next]) {
                path[next]='R';
                prev[next]=cur;
                q.push(next);
            }
        }
    }

    return 0;
}