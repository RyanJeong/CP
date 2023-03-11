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
    int len;
    std::string str;
    std::cin >> len >> str;
    str += str;

    auto sa = SuffixArray(str);
    auto lcp = Lcp(sa, str);

    //  e.g. baabaa
    // => str: baabaabaabaa
    // idx | suffix:
    //  0  | baabaabaabaa
    //  1  |  aabaabaabaa
    //  2  |   abaabaabaa
    //  3  |    baabaabaa
    //  4  |     aabaabaa
    //  5  |      abaabaa
    //  6  |       baabaa
    //  7  |        aabaa
    //  8  |         abaa
    //  9  |          baa
    // 10  |           aa
    // 11  |            a
    //
    // idx | suffix       | sa | isa | lcp
    //  0  |            a | 11 | 11  |  0
    //  1  |           aa | 10 |  4  |  1
    //  2  |        aabaa |  7 |  7  |  2
    //  3  |     aabaabaa |  4 | 10  |  5  <<<<
    //  4  |  aabaabaabaa |  1 |  3  |  8  <<<<
    //  5  |         abaa |  8 |  6  |  1
    //  6  |      abaabaa |  5 |  9  |  4
    //  7  |   abaabaabaa |  2 |  2  |  7
    //  8  |          baa |  9 |  5  |  0
    //  9  |       baabaa |  6 |  8  |  3
    // 10  |    baabaabaa |  3 |  1  |  6
    // 11  | baabaabaabaa |  0 |  0  |  9

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
    std::cout << res << '\n';
  }

  return 0;
}
