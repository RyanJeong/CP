// http://icpc.me/2504
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str;

  cin >> str;
  int         num, temp;
  stack<char> s;
  stack<int>  val;
  bool        is_error;

  num      = 0;
  temp     = 1;
  is_error = false;
  for (unsigned i = 0; i < str.length(); ++i) {
    if (str[i] == '(') {
      temp *= 2;
      s.push('(');
    } else if (str[i] == '[') {
      temp *= 3;
      s.push('[');
    } else if (!s.empty() && s.top() == '(' && str[i] == ')') {
      if (str[i-1] == '(') {
        num += temp;
      }  
      temp /= 2;
      s.pop();
    } else if (!s.empty() && s.top() == '[' && str[i] == ']') {
      if (str[i-1] == '[') {
        num += temp;
      }  
      temp /= 3;
      s.pop();
    } else {
      is_error = true;
      break;
    }
  }
  cout << (!s.empty() || is_error ? 0 : num);

  return 0;
}