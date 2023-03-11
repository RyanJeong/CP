/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> SuffixArray(const std::string& str) {
  const size_t kStrLen = str.length();
  // kCntLen: maximum ASCII code value could consist of a string or the kStrLen
  const size_t kCntLen = std::max(static_cast<size_t>(256), kStrLen);

  std::vector<int> cnt(kCntLen), idx(kStrLen);
  std::vector<int> temp(kStrLen + kStrLen);

  // kStrLen + kStrLen => d will check 2*d size
  std::vector<int> sa(kStrLen), group_id(kStrLen + kStrLen);
  for (int i = 0; i < kStrLen; ++i) {
    sa[i] = i;
    group_id[i] = str[i];
  }

  for (int d = 1; d < kStrLen; d <<= 1) {
    for (int i = 0; i < kCntLen; ++i)
      cnt[i] = 0;
    for (int i = 0; i < kStrLen; ++i)
      cnt[group_id[i+d]]++;
    for (int i = 1; i < kCntLen; ++i)
      cnt[i] += cnt[i-1];
    for (int i = kStrLen - 1; ~i; --i)
      idx[--cnt[group_id[i+d]]] = i;

    for (int i = 0; i < kCntLen; ++i)
      cnt[i] = 0;
    for (int i = 0; i < kStrLen; ++i)
      cnt[group_id[i]]++;
    for (int i = 1; i < kCntLen; ++i)
      cnt[i] += cnt[i-1];
    for (int i = kStrLen - 1; ~i; --i)
      sa[--cnt[group_id[idx[i]]]] = idx[i];

    temp[sa[0]] = 1;
    for (int i = 1; i < kStrLen; ++i) {
      temp[sa[i]] = temp[sa[i-1]];
      if (group_id[sa[i-1]] < group_id[sa[i]] ||
          (group_id[sa[i-1]] == group_id[sa[i]] &&
          group_id[sa[i-1]+d] < group_id[sa[i]+d]))
        ++temp[sa[i]];
    }
    group_id = temp;

    if (group_id[sa[kStrLen-1]] == kStrLen)
      break;
  }

  return sa;
}

std::vector<int> Lcp(const std::vector<int>& sa, const std::string& str) {
  const size_t kStrLen = str.length();
  std::vector<int> lcp(kStrLen), isa(kStrLen);

  for (int i = 0; i < kStrLen; ++i)
    isa[sa[i]] = i;

  int k = 0;  // offset
  for (int i = 0; i < kStrLen; ++i) {
    if (!isa[i])
      continue;

    for (int j = sa[isa[i]-1]; str[i+k] == str[j+k]; ++k) {}
    lcp[isa[i]] = (k ? k-- : 0);
  }

  return lcp;
}

int main() {
  CP;

  std::string str;
  std::cin >> str;

  auto sa = SuffixArray(str);
  auto lcp = Lcp(sa, str);

  // e.g. str = ababc
  //         -> ababc
  //             babc
  //              abc
  //               bc
  //                c
  //
  // idx | suffix | sa | isa | lcp
  // 0   | ababc  | 0  | 0   | 0
  // 1   |   abc  | 2  | 2   | 2
  // 2   |  babc  | 1  | 1   | 0
  // 3   |    bc  | 3  | 3   | 1
  // 4   |     c  | 4  | 4   | 0

  // ababc -> {'a', 'ab', 'aba', 'abab', 'ababc'} => 5
  //   abc -> {'a', 'ab', 'abc'}                  => 3('a', 'ab' are dup.)
  //  babc -> {'b', 'ba', 'bab', 'babc'}          => 4
  //    bc -> {'b', 'bc'}                         => 2('b' is dup.)
  //     c -> {'c'}                               => 1
  // => str.length() - sa(num. of prefix) - lcp(dup.)

  int64_t res = str.length() - sa[0];
  for (int i = 1; i < str.length(); ++i)
    res += str.length() - sa[i] - lcp[i];
  std::cout << res;

  return 0;
}
