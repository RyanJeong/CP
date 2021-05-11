#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  queue<int> q;

  q.push(10); // 10
  q.push(20); // 10 20
  q.push(30); // 10 20 30
  cout << q.size() << '\n'; // 3
  if (q.empty()) {
    cout << "Queue is empty!\n";
  } else {
    cout << "Queue is not empty!\n"; // print "Queue is not empty!"
  }
  q.pop();    //   20 30
  q.push(40); //   20 30 40
  cout << q.front() << '\n'; // 20
  cout << q.back() << '\n';  // 40

  return 0;
}