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

  while (true) {
    int m;
    std::cin >> m;
    if (!m)
      break;

    std::string str;
    std::cin >> str;

    // baaaababababbababbab
    // idx | suffix
    //  0  | baaaababababbababbab
    //  1  |  aaaababababbababbab
    //  2  |   aaababababbababbab
    //  3  |    aababababbababbab
    //  4  |     ababababbababbab
    //  5  |      babababbababbab
    //  6  |       abababbababbab
    //  7  |        bababbababbab
    //  8  |         ababbababbab
    //  9  |          babbababbab
    // 10  |           abbababbab
    // 11  |            bbababbab
    // 12  |             bababbab
    // 13  |              ababbab
    // 14  |               babbab
    // 15  |                abbab
    // 16  |                 bbab
    // 17  |                  bab
    // 18  |                   ab
    // 19  |                    b

    // idx | suffix               | sa | lcp
    //  0  |  aaaababababbababbab |  1 |  0
    //  1  |   aaababababbababbab |  2 |  3
    //  2  |    aababababbababbab |  3 |  2
    //  3  |                   ab | 18 |  1
    //  4  |     ababababbababbab |  4 |  2
    //  5  |       abababbababbab |  6 |  6
    //  6  |              ababbab | 13 |  4
    //  7  |         ababbababbab |  8 |  7
    //  8  |                abbab | 15 |  2
    //  9  |           abbababbab | 10 |  5
    // 10  |                    b | 19 |  0
    // 11  | baaaababababbababbab |  0 |  1
    // 12  |                  bab | 17 |  2
    // 13  |      babababbababbab |  5 |  3
    // 14  |             bababbab | 12 |  5
    // 15  |        bababbababbab |  7 |  8
    // 16  |               babbab | 14 |  3
    // 17  |          babbababbab |  9 |  6
    // 18  |                 bbab | 16 |  1
    // 19  |            bbababbab | 11 |  4
  }
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    int len = str.length();
    str += str;

    auto sa = SuffixArray(str);
    auto lcp = Lcp(sa, str);

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
    str = {str.begin() + res, str.begin() + res + len};
    std::cout << str << '\n';
  }

  return 0;
}
