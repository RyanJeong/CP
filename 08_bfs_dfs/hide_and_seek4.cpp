// https://icpc.me/13913
#include <bits/stdc++.h>

using namespace std;

int dist[100001];
int num[100001];
int path[100001];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int        n, k;
  queue<int> q;

  cin >> n >> k;
  q.push(n);
  memset(dist, -1, sizeof dist);
  dist[n] = 0;
  num[n]  = 1;
  path[n] = -1;
  while (!q.empty()) {
    int cur = q.front();

    if (cur == k) {
      break;
    }
    q.pop();
    for (int next: { cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > 100000) {
        continue;
      }
      if (dist[next] == -1) { // not visited 
        dist[next] = dist[cur] + 1;
        num[next] += num[cur];
        q.push(next);
        path[next] = cur;
      } else if (dist[next] == dist[cur] + 1) {
        num[next] += num[cur]; // opt. path
      }
    }
  }
  cout << dist[k] << '\n';
  vector<int> v;

  for (v.push_back(k); path[k] != -1; k = path[k]) {
    v.push_back(path[k]);
  }
  reverse(v.begin(), v.begin() + v.size());
  for (int i : v) {
    cout << i << ' ';
  }

  return 0;
}
