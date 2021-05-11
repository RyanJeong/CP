#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<pair<int, vector<int>>> v;
    vector<int>                    temp;

    string elem   = "";
    int    size   = s.size();

    for (int i = 0; i < size; ++i) {
      if (s[i] == '{') {
        continue;
      }
      if (s[i] == '}') {
        if (s[i-1] == '}') {
          continue;
        }
        temp.push_back(atoi(elem.c_str()));
        elem = "";
        v.push_back({ temp.size(), temp });
        temp.clear();
      } else if (s[i] == ',') {
        if (s[i-1] == '}') {
          continue;
        }
        temp.push_back(atoi(elem.c_str()));
        elem = "";
      } else { // nums
        elem += s[i];
      }
    }
    sort(v.begin(), v.end());
    set<int> remove_dup;

    for (auto cur : v) {
      vector<int> subset = cur.second;

      for (int i : subset) {
        if (remove_dup.find(i) == remove_dup.end()) {
          remove_dup.insert(i);
          answer.push_back(i);
        }
      }
    }

    return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
  vector<int> v(solution(s));
  for (int i : v) {
    cout << i << ' ';
  }

  return 0;
}