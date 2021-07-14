// https://www.acmicpc.net/problem/16920
// https://codeforces.com/contest/1105/problem/D
#include <bits/stdc++.h>

using namespace std;

struct Elem {
	int _p;
	int _x;
	int _y;
};

struct Cmp {
	bool operator()(Elem s, Elem t) 
	{

		return s._p>t._p;
	}
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin>>n>>m>>p;
    int movement[10];
    for (int i = 1; i<=p; ++i) {
        cin>>movement[i];
    }
    static char arr[1001][1001];
	static int freq[10];
	priority_queue<Elem, vector<Elem>, Cmp> pq;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
			char c;
			cin>>c;
			if (isdigit(c)) {
				int p = c-'0';
				pq.push({p,i,j});
				++freq[p];
				arr[i][j]=p;
			}
			else {
				arr[i][j]=c;
			}
        }
        cin.ignore();
    }

	while (!pq.empty()) {
		priority_queue<Elem, vector<Elem>, Cmp> temp;
		for (int i = 1; i<=p; ++i) {
			queue<pair<int, int>> q;
			while (!pq.empty()) {
				if (pq.top()._p!=i) {
					break;
				}
				auto cur = pq.top();
				pq.pop();
				q.push({cur._x,cur._y});
			}
			for (int mv = movement[i]; !q.empty() && mv; --mv) {
				int cnt = q.size();
				while (cnt--) {
					auto cur = q.front();
					q.pop();

					for (int d = 0; d<4; ++d) {
						const int dx[] = {1,0,-1,0};
						const int dy[] = {0,-1,0,1};
						int x = cur.first+dx[d];
						int y = cur.second+dy[d];

						if (x<1 || x>n) {
							continue;
						}
						if (y<1 || y>m) {
							continue;
						}
						if (arr[x][y]!='.') {
							continue;
						}
						arr[x][y]=i;
						q.push({x,y});
						++freq[i];
					}
				}
			}
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				temp.push({i,cur.first,cur.second});
			}
		}
		pq=temp;
	}

	for (int i = 1; i<=p; ++i) {
		cout << freq[i] << ' ';
	}

    return 0;
}