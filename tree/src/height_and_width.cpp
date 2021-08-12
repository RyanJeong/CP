// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> left_child;
vector<int> right_child;
vector<pair<int, int>> rc; // row(depth), col

void inorder(int cur);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    parent=vector<int>(n+1);
    left_child=vector<int>(n+1);
    right_child=vector<int>(n+1);
    rc=vector<pair<int, int>>(n+1);
    for (int i = 1; i<=n; ++i) {
        int u, lc, rc;
        cin>>u>>lc>>rc;
        if (lc!=-1) {
            parent[lc]=u;
            left_child[u]=lc;
        }
        if (rc!=-1) {
            parent[rc]=u;
            right_child[u]=rc;
        }
    }

    int root;
    for (int i = 1; i<=n; ++i) {
        if (!parent[i]) {
            root=i;
            break;
        }
    }

    rc[root].first=1;
    inorder(root); // get cols and depths
    sort(rc.begin()+1,rc.end()); // 1-based
    int lv = 0;
    int wid = 0;
    int max_depth = rc.back().first;
    for (int i = 1; i<=max_depth; ++i) {
        int low = lower_bound(rc.begin(),rc.end(),pair<int, int>{i,0})-rc.begin();
        int high = upper_bound(rc.begin(),rc.end(),pair<int, int>{i,n})-rc.begin()-1;
        int gap = rc[high].second-rc[low].second+1;
        if (i>lv && gap>wid) {
            lv=i;
            wid=gap;
        }
    }
    cout << lv << ' ' << wid;

    return 0;
}

void inorder(int cur)
{
    static int idx = 1;

    if (left_child[cur]) {
        rc[left_child[cur]].first=rc[cur].first+1;
        inorder(left_child[cur]);
    }
    rc[cur].second=idx++;
    if (right_child[cur]) {
        rc[right_child[cur]].first=rc[cur].first+1;
        inorder(right_child[cur]);
    }

    return;
}
