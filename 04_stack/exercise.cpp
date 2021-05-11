#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  stack<int> s;

  s.push(10); // 10
  s.push(20); // 10 20
  s.push(30); // 10 20 30
  cout << s.size() << '\n'; // 3
  if (s.empty()) {
    cout << "Stack is empty!\n";
  } else {
    cout << "Stack is not empty!\n"; // print "Stack is not empty!"
  }
  s.pop(); // 10 20, return type is void
  cout << s.top() << '\n'; // 20
  s.pop(); // 10
  s.pop(); // NULL
  if (s.empty()) {
    cout << "Stack is empty!\n"; // print "Stack not empty!"
  } else {
    cout << "Stack is not empty!\n"; 
  }

  return 0;
}