// http://icpc.me/1021
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int        n, m, count;
  deque<int> dq;

  count = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    dq.push_back(i);
  }
  while (m--) {
    unsigned int index;
    int          num;
    
    cin >> num;
    for (unsigned int i = 0; i < dq.size(); ++i) {
      if (num == dq[i]) {
        index = i;
        break;
      }
    }
    if (index < dq.size() - index) {
      while (1) {
        if (num == dq.front()) {
          dq.pop_front();
          break;
        } else {
          ++count;
          dq.push_back(dq.front());
          dq.pop_front();
        }
      }
    } else {
      while (1) {
        if (num == dq.front()) {
          dq.pop_front();
          break;
        } else {
          ++count;
          dq.push_front(dq.back());
          dq.pop_back();
        }
      }
    }
  }
  cout << count;

  return 0;
}