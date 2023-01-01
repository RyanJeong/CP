/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>

int Insert(int arr[], const int& cap, int* len, const int& idx, const int& val);
int Erase(int arr[], const int& cap, int* len, const int& idx);

int main() {
  CP;

  const int kCap = 10;
  // An array that can store only positive numbers;
  int arr[kCap] = {1, 2, 4, 8, 16, 32};
  int len = 0;
  for (int i = 0; i < kCap; ++i) {
    if (arr[i])
      ++len;
  }
  std::cout << "capacity: " << kCap << ",length: " << len << '\n';
  for (int i = 0; i < len; ++i)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
  // 1 2 4 8 16 32

  // insert
  Insert(arr, kCap, &len, 0, 50);
  std::cout << "capacity: " << kCap << ",length: " << len << '\n';
  for (int i = 0; i < len; ++i)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
  // 50 1 2 4 8 16 32
  Insert(arr, kCap, &len, len, 60);
  std::cout << "capacity: " << kCap << ",length: " << len << '\n';
  for (int i = 0; i < len; ++i)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
  // 50 1 2 4 8 16 32 60

  // erase
  Erase(arr, kCap, &len, 1);
  std::cout << "capacity: " << kCap << ",length: " << len << '\n';
  for (int i = 0; i < len; ++i)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
  // 50 2 4 8 16 32 60
  Erase(arr, kCap, &len, len);
  std::cout << "capacity: " << kCap << ",length: " << len << '\n';
  for (int i = 0; i < len; ++i)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
  // 50 2 4 8 16 32

  return 0;
}

int Insert(int arr[], const int& cap, int* len, const int& idx,
    const int& val) {
  if (*len == cap)
    return 0;
  if (idx > *len)
    return 0;

  for (int i = *len; i > idx; --i)
    arr[i] = arr[i-1];
  arr[idx] = val;
  ++(*len);

  return val;
}

int Erase(int arr[], const int& cap, int* len, const int& idx) {
  if (*len == 0)
    return 0;
  if (idx > *len)
    return 0;

  --(*len);
  int val = arr[idx];
  for (int i = idx; i < *len; ++i)
    arr[i] = arr[i+1];

  return val;
}
