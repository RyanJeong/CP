#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  deque<int> dq;

  dq.push_back(10);  // 10
  dq.push_back(40);  // 10 40
  dq.push_front(50); // 50 10 40
  cout << dq.size() << '\n';  //  3
  cout << dq.front() << '\n'; // 50
  cout << dq.back() << '\n';  // 40
  if (dq.empty()) {
    cout << "Deque is empty!\n";
  } else {
    cout << "Deque is not empty!\n"; // print "Deque is not empty!"
  }
  dq.pop_front();   // 10 40
  dq.push_back(60); // 10 40 60
  dq.pop_back();    // 10 40
  cout << dq.front() << '\n'; // 10
  cout << dq.back() << '\n';  // 40
  for (int i : dq) {
    cout << i << ' '; // 10 40
  }
  cout << '\n';

  return 0;
}