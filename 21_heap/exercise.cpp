#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  // https://en.cppreference.com/w/cpp/container/priority_queue 
  // priority_queue<int, vector<int>, greater<int>> -> min heap
  // priority_queue<int> -> max heap
  priority_queue<int, vector<int>, greater<int>> min_heap;
  
  while (n--) {
    int x;

    cin >> x;
    if (!x) {
      if (min_heap.empty()) {
        cout << "0\n";
      } else {
        cout << min_heap.top() << '\n';
        min_heap.pop();
      }
    } else {
      min_heap.push(x);
    }
  }

  return 0;
}