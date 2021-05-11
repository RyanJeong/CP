// http://icpc.me/1406

#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  cin >> s;
  list<char> l;

  for (char c : s) {
    l.push_back(c);
  }
  list<char>::iterator ptr = l.end();
  int cnt;

  cin >> cnt;
  cin.get(); // '\n'
  for (int i = 0; i < cnt; ++i) {
    string ops;
    char   op;

    getline(cin, ops);
    op = ops[0];
    switch (op) {
      case 'L':
        if (ptr != l.begin()) {
          --ptr;
        }
        break;
      case 'D':
        if (ptr != l.end()) {
          ++ptr;
        }
        break;
      case 'B':
        if (ptr != l.begin()) {
          --ptr;
          ptr = l.erase(ptr);
        }
        break;
      case 'P':
        l.insert(ptr, ops[2]);
        break;
      default:
        break;
    }
  }
  for (char c : l) {
    cout << c;
  }

  return 0;
}