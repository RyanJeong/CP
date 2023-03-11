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

  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    int len = str.length();
    str += str;

    auto sa = SuffixArray(str);
    auto lcp = Lcp(sa, str);

    // e.g. iiijjijiiij
    // => str: iiijjijiiijiiijjijiiij(n=22)
    // idx | suffix
    //  0  | iiijjijiiijiiijjijiiij
    //  1  | iijjijiiijiiijjijiiij
    //  2  | ijjijiiijiiijjijiiij
    //  3  | jjijiiijiiijjijiiij
    //  4  | jijiiijiiijjijiiij
    //  5  | ijiiijiiijjijiiij
    //  6  | jiiijiiijjijiiij
    //  7  | iiijiiijjijiiij
    //  8  | iijiiijjijiiij
    //  9  | ijiiijjijiiij
    // 10  | jiiijjijiiij
    // 11  | iiijjijiiij
    // 12  | iijjijiiij
    // 13  | ijjijiiij
    // 14  | jjijiiij
    // 15  | jijiiij
    // 16  | ijiiij
    // 17  | jiiij
    // 18  | iiij
    // 19  | iij
    // 20  | ij
    // 21  | j

    // idx | suffix                 | sa | lcp
    //   0 | iiij                   | 18 |  0
    //   1 | iiijiiijjijiiij        |  7 |  4
    //   2 | iiijjijiiij            | 11 |  4
    //   3 | iiijjijiiijiiijjijiiij |  0 | 11
    //   4 | iij                    | 19 |  2
    //   5 | iijiiijjijiiij         |  8 |  3
    // ...

    int res = str.length();
    for (int i = 1; i < lcp.size(); ++i) {
      if (sa[i] >= len) {  // the real length: 0~n-1
        if (res == str.length())
          continue;
        break;
      }
      res = std::min(res, sa[i]);
      if (lcp[i] > lcp[i+1])
        break;
    }
    std::cout << res + 1 << '\n';  // 1-based
  }

  return 0;
}
