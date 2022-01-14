/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>

// iostream
using std::cin;
using std::cout;
using std::getline;

// vector
using std::vector;

int main() {
  CP;

  // v1
  vector<int> v1(3, 5);
  cout << v1.size() << ' ' << v1.capacity() << '\n';  // 3 3
  for (const int& i : v1)
    cout << i << ' ';  // 5 5 5
  cout << '\n';

  v1.push_back(7);
  cout << v1.size() << ' ' << v1.capacity() << '\n';  // 4 6
  for (const int& i : v1)
    cout << i << ' ';  // 5 5 5 7
  cout << '\n';

  // v2
  vector<int> v2(2);
  cout << v2.size() << ' ' << v2.capacity() << '\n';  // 2 2
  for (const int& i : v2)
    cout << i << ' ';  // 0 0
  cout << '\n';

  v2.insert(v2.begin() + 1, 3);
  cout << v2.size() << ' ' << v2.capacity() << '\n';  // 3 4
  for (const int& i : v2)
    cout << i << ' ';  // 0 3 0
  cout << '\n';

  v2.pop_back();
  cout << v2.size() << ' ' << v2.capacity() << '\n';  // 2 4
  for (const int& i : v2)
    cout << i << ' ';  // 0 3
  cout << '\n';

  v2.swap(v1);  // swap between v1 and v2
  for (auto it = v2.begin(); it != v2.end(); ++it)
    cout << *it << ' ';  // 5 5 5 7
  cout << '\n';

  for (auto it = v2.rbegin(); it != v2.rend(); ++it)
    cout << *it << ' ';  // 7 5 5 5
  cout << '\n';

  cout << v2.size() << ' ' << v2.capacity() << '\n';  // 4 6
  v2.clear();
  cout << v2.size() << ' ' << v2.capacity() << '\n';  // 0 6
  for (const int& i : v2)
    cout << i << ' ';  // SKIP
  cout << '\n';

  // v3
  vector<int> v3;
  for (int i = 1; i < 10; ++i) {
    v3.push_back(i);
    cout << "size: " << v3.size() << ", cap.: " << v3.capacity() << '\n';
    /*
      size: 1, cap.: 1
      size: 2, cap.: 2
      size: 3, cap.: 4
      size: 4, cap.: 4
      size: 5, cap.: 8
      size: 6, cap.: 8
      size: 7, cap.: 8
      size: 8, cap.: 8
      size: 9, cap.: 16
    */
  }
  for (int i = 1; i < 10; ++i) {
    v3.pop_back();
    cout << "size: " << v3.size() << ", cap.: " << v3.capacity() << '\n';
    /*
      size: 8, cap.: 16
      size: 7, cap.: 16
      size: 6, cap.: 16
      size: 5, cap.: 16
      size: 4, cap.: 16
      size: 3, cap.: 16
      size: 2, cap.: 16
      size: 1, cap.: 16
      size: 0, cap.: 16
    */
  }

  // v4
  vector<int> v4 = { 1, 2, 4, 8, 16 };
  auto it_begin = v4.begin();
  auto it_end = v4.end();
  cout << v4.size() << ' ' << v4.capacity() << '\n';  // 5 5
  cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  cout << &(*v4.end()) << '\n';    // 0x7ffff727dec4

  // The base iterator refers to the element that is next to
  // the element the `reverse_iterator` is currently pointing to.
  // That is `std::reverse_iterator(it).base()` == `std::next(it)`.

  // v4.erase(v4.end() - 1);
  // Modern style: v4.erase(prev(v4.end()));
  v4.erase((v4.rbegin()).base() - 1);
  cout << v4.size() << ' ' << v4.capacity() << '\n';  // 4 5
  cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  cout << &(*v4.end()) << '\n';    // 0x7ffff727dec0
  for (const int& i : v4)
    cout << i << ' ';  // 1 2 4 8
  cout << '\n';

  v4.erase(v4.begin());
  cout << v4.size() << ' ' << v4.capacity() << '\n';  // 3 5
  cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  cout << &(*v4.end()) << '\n';    // 0x7ffff727debc
  for (const int& i : v4)
    cout << i << ' ';  // 2 4 8
  cout << '\n';

  v4.erase(v4.begin() + 1);
  cout << v4.size() << ' ' << v4.capacity() << '\n';  // 2 5
  cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  cout << &(*v4.end()) << '\n';    // 0x7ffff727deb8
  for (const int& i : v4)
    cout << i << ' ';  // 2 8
  cout << '\n';

  *it_begin = 4;
  for (const int& i : v4)
    cout << i << ' ';  // 4 8
  cout << '\n';
  auto it = v4.erase(it_begin);  // An iterator pointing to the new location of
                                 // the element that `followed the last element`
                                 // erased by the function call.
                                 // it will point to the 8's location
  *it_begin = 16;  // 8 will replace with 16
  for (const int& i : v4)
    cout << i << ' ';  // 16
  cout << '\n';

  return 0;
}
