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

int main() {
  CP;

  // constructing std::vectors
  // constructors used in the same order as described above:

  // an empty vector
  std::vector<int> first;
  // a vector of size 4 with all values as 100
  std::vector<int> second(4, 100);
  // iterating through second
  std::vector<int> third(second.begin(), second.end());
  // use copy constructor
  std::vector<int> fourth(third);

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = { 16, 2, 77, 29 };
  std::vector<int> fifth(myints, myints + sizeof myints / sizeof(int));

  std::cout << "The contents of fifth are: ";
  // The contents of fifth are: 16 2 77 29
  // for (auto it = fifth.begin(); it != fifth.end(); ++it)
  //   std::cout << *it << ' ';
  for (const auto& i : fifth)
    std::cout << i << ' ';
  std::cout << '\n';

  // vector assignment
  std::vector<int> foo(3, 0);
  std::vector<int> bar = foo;
  foo = std::vector<int>();
  // foo's size: 0, foo's cap.: 0
  std::cout << "foo's size: " << foo.size()
       << ", foo's cap.: " << foo.capacity() << '\n';
  // bar's size: 3, bar's cap.: 3
  std::cout << "bar's size: " << bar.size()
       << ", bar's cap.: " << bar.capacity() << '\n';

  return 0;
}
