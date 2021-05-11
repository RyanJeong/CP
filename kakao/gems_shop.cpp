#include <bits/stdc++.h>

using namespace std;

int arr[100'005];
int is_used[100'005];

vector<int> solution(vector<string> gems) 
{
  vector<int> answer;
  set<string> remove_dup;
  map<string, int> m;

  for (string s : gems) {
    remove_dup.insert(s);
  }
  int index = 0;

  for (string s : remove_dup) {
    m.insert( {s, index++} );
  }
  int size  = gems.size();
  
  for (int i = 1; i <= size; ++i) {
    arr[i] = m[gems[i-1]];
  }
  int low   = 1;
  int high  = 1;
  int m_len = m.size();

  vector<pair<int, pair<int, int>>> v;

  ++size; // [ ... )
  while (high <= size) {
    bool is_true = true;

    for (int i = 0; i < m_len; ++i) {
      if (!is_used[i]) {
        is_true = false;
        break;
      }
    }
    if (is_true) {
      if (is_used[arr[low]] == 1) {
        v.push_back({ high - low, { low, high - 1 } });
      }
      --is_used[arr[low]];
      ++low;
    } else {
      ++is_used[arr[high]];
      ++high;
    }
  }
  sort(v.begin(), v.end());
  answer.push_back(v[0].second.first);
  answer.push_back(v[0].second.second);

  return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
  vector<int> answer(solution(gems));
  
  for (int i : answer) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}