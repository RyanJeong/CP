#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    int n_cmd = cmd.size();
    bool is_deleted[1'000'004] = { 0 };
    stack<pair<list<int>::iterator, int>> s;
    list<int>  l;

    for (int i = 0; i < n; ++i) {
      l.push_back(i);
    }
    list<int>::iterator ptr = l.begin();
    ptr = next(ptr, k);
    for (int i = 0; i < n_cmd; ++i) {
      int  x = 0;
      char c = cmd[i][0];
      int                 temp_x;
      list<int>::iterator temp_ptr;

      if (c == 'U' || c == 'D') {
        int len = cmd[i].size();

        for (int j = 2; j < len; ++j) {
          x = (x * 10) + (cmd[i][j] - '0');
        }
      }
      switch (c) {
      case 'U':
        ptr = prev(ptr, x);
        break;
      case 'D':
        ptr = next(ptr, x);
        break;
      case 'C':
        temp_x             = *ptr;
        is_deleted[temp_x] = true;
        ptr = l.erase(ptr);
        s.push({ ptr, temp_x });
        break;
      case 'Z':
        temp_ptr = s.top().first;
        temp_x   = s.top().second;
        is_deleted[temp_x] = false;
        s.pop();
        l.insert(temp_ptr, temp_x);
        break;
      default:
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      answer += (is_deleted[i] ? 'X' : 'O');
    }

    return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n{8};
  int k{2};
  vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
  cout << solution(8, 2, {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"});
  cout << solution(n, k, cmd) << '\n';

  return 0;
}