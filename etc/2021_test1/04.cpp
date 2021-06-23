#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1'005];
int                    dist[1'005];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
  int answer;

  memset(adj, 2e9, sizeof adj);
  for (auto v : roads) {
    int x, y, dist;

    x    = v[0];
    y    = v[1];
    dist = v[2];
    adj[x].push_back({ y, dist });
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[start] = 0;
  pq.push({ dist[start], start });
  while (!pq.empty()) {
    auto cur = pq.top();

    pq.pop();
    int d = cur.first;
    int i = cur.second;

    if (dist[i] != d) {
      continue;
    }
    for (auto next : adj[i]) {
      int cost = next.first;
      int nidx = next.second;
      if (dist[nidx] > d + cost) {
        dist[nidx] = d + cost;
        pq.push({ dist[nidx], nidx });
      }
    }
  }
  for (int i = 1; i <= end; ++i) {
    if (dist[i] == 2e9) {
      cout << "INF" << ' ';
    } else {
      cout << dist[i] << ' ';
    }
  }

  return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout << solution(3, 1, 3, {{1, 2, 2}, {3, 2, 3}}, {2});

  return 0;
}