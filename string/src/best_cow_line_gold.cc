/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// WIP

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

  // kStrLen + kStrLen => d will check 2*d size
  std::vector<int> sa(kStrLen), group_id(kStrLen + kStrLen);
  for (int i = 0; i < kStrLen; ++i) {
    sa[i] = i;
    group_id[i] = str[i];
  }

  for (int d = 1; d < kStrLen; d <<= 1) {
    static std::vector<int> cnt(kCntLen), idx(kStrLen);

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

    static std::vector<int> temp(kStrLen + kStrLen);
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

int main() {
  CP;

  int n;
  std::cin >> n;
  std::string str;
  str.resize(n);
  for (int i = 0; i < n; ++i)
    std::cin >> str[i];

  // str = ACDBCB
  // => ACDBCBBCBDCA (str + {str.rbegin(), str.rend()}
  // idx | suffix
  //  0  | ACDBCBBCBDCA
  //  1  |  CDBCBBCBDCA
  //  2  |   DBCBBCBDCA
  //  3  |    BCBBCBDCA
  //  4  |     CBBCBDCA
  //  5  |      BBCBDCA
  //  6  |       BCBDCA
  //  7  |        CBDCA
  //  8  |         BDCA
  //  9  |          DCA
  // 10  |           CA
  // 11  |            A
  //
  // idx | suffix       | sa
  //   0 |            A | 11
  //   1 | ACDBCBBCBDCA |  0
  //   2 |      BBCBDCA |  5
  //   3 |    BCBBCBDCA |  3
  //   4 |       BCBDCA |  6
  //   5 |         BDCA |  8
  //   6 |           CA | 10
  //   7 |     CBBCBDCA |  4
  //   8 |        CBDCA |  7
  //   9 |  CDBCBBCBDCA |  1
  //  10 |   DBCBBCBDCA |  2
  //  11 |          DCA |  9
  // If SA is calculated for the str(2n), it is possible to calculate the
  // smaller of the first and last letter of n suffixes

  str += std::string{str.rbegin(), str.rend()};
  auto sa = SuffixArray(str);

  int head = 0, tail = n - 1;
  for (int i = 0; i < n; ++i) {
    std::cout << sa[head] << ' ' << sa[str.length()-tail-1] << '\n';
    if (sa[head] < sa[str.length()-tail-1])
      std::cout << str[head++];
    else
      std::cout << str[tail--];
    if (i == 79)
      break;
  }

  return 0;
}
