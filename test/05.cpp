#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links) 
{
  map<int, pair<int, int>> tree;
  int answer = 0;
  int size   = num.size();

  for (int i = 0; i < size; ++i) {
    int left, right;

    left  = (links[i][0] == -1 ? -1 : num[links[i][0]]);
    right = (links[i][1] == -1 ? -1 : num[links[i][1]]);
    tree[num[i]] = { left, right };
  }

  return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout << solution(3, {12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1}, {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {8, 5}, {2, 10}, {3, 0}, {6, 1}, {11, -1}, {7, 4}, {-1, -1}, {-1, -1}});

  return 0;
}