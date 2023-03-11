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

  std::string s, t;
  std::cin >> s >> t;

  // s: ababa
  // t: baba
  // s + t = ababababa
  // -> ababababa
  //     babababa
  //      abababa
  //       bababa
  //        ababa
  //         baba
  //          aba
  //           ba
  //            a
  //  idx |  suffix  | sa | isa | lcp
  // 0    |         a| 8  | 4   | 0
  // 1    |       aba| 6  | 8   | 1
  // 2    |     ababa| 4  | 3   | 3
  // 3    |   abababa| 2  | 7   | 5 <- invalid
  // 4    | ababababa| 0  | 2   | 7 <- invalid
  // 5    |        ba| 7  | 6   | 0
  // 6    |      baba| 5  | 1   | 2
  // 7    |    bababa| 3  | 5   | 4
  // 8    |  babababa| 1  | 0   | 6 <- invalid
  //
  // s + '$' + t = ababa$baba <- ba
  // -> ababa$baba
  //     baba$baba
  //      aba$baba
  //       ba$baba
  //        a$baba
  //         &baba
  //          baba
  //           aba
  //            ba
  //             a
  //  idx |   suffix  | sa | isa | lcp
  // 0    |      $baba| 5  | 5   | 0
  // 1    |          a| 9  | 9   | 0
  // 2    |     a$baba| 4  | 4   | 1
  // 3    |        aba| 7  | 7   | 1
  // 4    |   aba$baba| 2  | 2   | 3
  // 5    | abab$ababa| 0  | 0   | 3
  // 6    |         ba| 8  | 8   | 0
  // 7    |    ba$baba| 3  | 3   | 2
  // 8    |       baba| 6  | 8   | 2
  // 9    |  baba$baba| 1  | 1   | 4
  std::string str = s + '$' + t;  // EOS
  auto sa = SuffixArray(str);
  auto lcp = Lcp(sa, str);

  // counter case: aa bb
  // str: aa&bb
  // -> aa&bb
  //     a&bb
  //      &bb
  //       bb
  //        b
  // idx | suffix | sa | isa | lcp
  // 0   |   &bb  | 2  | 2   | 0
  // 1   |  a&bb  | 1  | 1   | 0
  // 2   | aa&bb  | 0  | 0   | 1  <- invalid
  // 3   |     b  | 4  | 4   | 0
  // 4   |    bb  | 3  | 3   | 1  <- invalid
  // the result should contain both S_n and T_n

  int res = 0;
  int idx = -1;
  for (int i = 1; i < lcp.size(); ++i) {
    if (res >= lcp[i])
      continue;
    // need to consider '$'
    // at least sa[i-1] or sa[i] should be s's prefix
    if ((sa[i-1] > s.length() && sa[i] < s.length()) ||
        (sa[i-1] < s.length() && sa[i] > s.length())) {
      res = lcp[i];
      idx = sa[i];
    }
  }

  str = {str.begin() + idx, str.begin() + idx + res};
  std::cout << res << '\n' << str;

  return 0;
}
