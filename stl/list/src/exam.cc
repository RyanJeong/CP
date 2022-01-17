/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <list>

// iostream
using std::cin;
using std::cout;

// list
using std::list;

int main() {
  CP;

  // In C++, an iterator is any object that, pointing to some element in a
  // range of elements(such as an array or a container), has the ability to
  // iterate through the elements of that range using a set of operators
  // (at least, the increment (++) and dereference (*) operators).
  list<int> l = { 1, 2 };  // 1 -> 2
  list<int>::iterator p = l.begin();  // p points to '1'

  l.push_front(10);    // { 10, 1, 2 }
  cout << *p << '\n';  // 1

  l.push_back(5);  // { 10, 1, 2, 5 };
  l.insert(p, 6);  // { 10, 6, 1, 2, 5 }, insert where p is pointing
                   // p still points to '1'
  ++p;  // now p points from '1' to '2'

  // function erase() returns an iterator pointing to the element in the list
  // container which followed the last element erased from the list container.
  p = l.erase(p);  // erase where p is pointing (2 will removed)
                   // now p points to '5'
  cout << *p << '\n';  // 5
  p = l.end();  // now p points to the element after '5' that we don't know
                // what the value is.
  cout << *p << '\n';  // ??

  // range-based for loop
  for (const int& i : l)
    cout << i << ' ';  // 10 6 1 5
  cout << '\n';
  // usage function begin() and end()
  for (auto ptr = l.begin(); ptr != l.end(); ++ptr)
    cout << *ptr << ' ';  // 10 6 1 5
  cout << '\n';

  return 0;
}
