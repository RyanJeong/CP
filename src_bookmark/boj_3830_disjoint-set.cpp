// https://www.acmicpc.net/problem/3830
/* ex.
input: 
4 4
! 1 2 100
! 2 3 100
! 4 3 150
? 1 2 0 0

output:
100

input: 
7 9
! 1 2 100
! 2 3 100
! 4 3 150
! 6 7 50
! 5 6 50
! 5 4 10
? 5 3
? 5 7
? 1 5
0 0

output: 
160
100
40
*/
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int, int);

vector<int> parent;
vector<long long> diff;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, m;
        cin>>n>>m;
        if (!n && !m) {
            break;
        }
        parent=vector<int>(n+1,0);
        for (int i = 1; i<=n; ++i) {
            parent[i]=i;
        }
		diff=vector<long long>(n+1,0);
        for (int i = 1; i<=m; ++i) {
			char op;
			cin>>op;
			int a, b;
			cin>>a>>b;
			if (op=='!') {
				int w;
				cin>>w;
				merge(a,b,w);
			}
			else { // op=='?'
				if (find(a)!=find(b)) {
					cout << "UNKNOWN\n";
				}
				else {
					cout << diff[b]-diff[a] << '\n';
				}
			}
        }
    }

    return 0;
}

int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }
	int p = find(parent[u]);
	// refresh diff. between root and u
	diff[u]+=diff[parent[u]];

	return parent[u]=p;
}

void merge(int u, int v, int w)
{
	int root_u = find(u);
	int root_v = find(v);
	if (root_u==root_v) {

		return;
	}
	// 기존 루트는 새로운 루트를 계산하는 데 사용됨
	// 이전에 등록된 노드들은 root_v를 기준으로 계산을 해왔기 때문에,
	// 새로운 노드(root_u)를 기준으로 무게 계산을 새로 해야 함
	// 따라서 이전에 사용했던 값 (diff[v])를 제거하고, 
	// 새로운 값 (diff[u]+w)을 더함 
	// 후에, root_v의 새로운 노드는 root_u로 변경되고,
	// 각 노드에 대한 무게 계산 요청이 들어오면
	// find 함수에 의해 해당 노드에 대한 무게를 새로 계산함
	diff[root_v]=-diff[v]+diff[u]+w;
	parent[root_v]=root_u;

    return;
}
