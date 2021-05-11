// http://icpc.me/1697
#include <bits/stdc++.h>

using namespace std;

int dist[100001];

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
  while (dist[k] == -1) {
    int cur = q.front();

    q.pop();
    for (int next: { cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > 100000) {
        continue;
      }
      if (dist[next] != -1) {
        continue;
      }
      dist[next] = dist[cur] + 1;
      q.push(next);
    }
  }
  cout << dist[k];

  return 0;
}