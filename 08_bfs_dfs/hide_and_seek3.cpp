// https://icpc.me/13549
#include <bits/stdc++.h>

using namespace std;

int dist[100001];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int         n, k;
  deque<int>  dq;

  cin >> n >> k;
  dq.push_back(n);
  memset(dist, -1, sizeof dist);
  dist[n] = 0;
  //while (!dq.empty()) {
  while (dist[k] == -1) {
    int cur = dq.front();
    dq.pop_front();
    for (int next: { cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > 100000) {
        continue;
      }
      if (dist[next] != -1) {
        continue;
      }
      if (next == cur * 2) {
        dist[next] = dist[cur];
        dq.push_front(next);
      } else {
        dist[next] = dist[cur] + 1;
        dq.push_back(next);
      }
    }
  }
  cout << dist[k];

  return 0;
}
