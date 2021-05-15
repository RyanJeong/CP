// http://icpc.me/1822
#include <bits/stdc++.h>

using namespace std;

bool is_used[500'002];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a, b;
  
  cin >> a >> b;
  vector<int> v;
  
  while (a--) {
    int temp;

    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  int size = v.size();

  while (b--) {
    int temp;

    cin >> temp;
    auto cur = lower_bound(v.begin(), v.end(), temp);
    
    if (cur != v.end() && *cur == temp) {
      is_used[cur-v.begin()] = true;
      --size;
    }
  }
  cout << size << '\n';
  int v_real_size = v.size();

  for (int i = 0; i < v_real_size; ++i) {
    if (!is_used[i]) {
      cout << v[i] << ' ';
    }
  }

  return 0;
}