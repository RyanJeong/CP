// https://www.acmicpc.net/problem/1991
#include <bits/stdc++.h>

using namespace std;

void preorder(int cur);
void inorder(int cur);
void postorder(int cur);

vector<int> left_child;
vector<int> right_child;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    left_child=vector<int>(n+1);
    right_child=vector<int>(n+1);
    for (int i = 1; i<=n; ++i) {
        char v, lc, rc;
        cin>>v>>lc>>rc;

        v=v-'A'+1;
        if (lc!='.') {
            left_child[v]=lc-'A'+1;
        }
        if (rc!='.') {
            right_child[v]=rc-'A'+1;
        }
    }
    // preorder
    preorder(1);
    cout << '\n';

    // inorder
    inorder(1);
    cout << '\n';

    // postorder
    postorder(1);
    cout << '\n';
    
    return 0;
}

void preorder(int cur)
{
    char c = cur+'A'-1;
    cout << c;
    if (left_child[cur]) {
        preorder(left_child[cur]);
    }
    if (right_child[cur]) {
        preorder(right_child[cur]);
    }

    return;
}

void inorder(int cur)
{
    if (left_child[cur]) {
        inorder(left_child[cur]);
    }
    char c = cur+'A'-1;
    cout << c;
    if (right_child[cur]) {
        inorder(right_child[cur]);
    }

    return;
}

void postorder(int cur)
{
    if (left_child[cur]) {
        postorder(left_child[cur]);
    }
    if (right_child[cur]) {
        postorder(right_child[cur]);
    }
    char c = cur+'A'-1;
    cout << c;

    return;
}
