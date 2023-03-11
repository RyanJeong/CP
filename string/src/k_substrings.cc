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

  /* example: banana
  |Index|Suffix Array|LCP|
  |-----|------------|---|
  |0    |5(`a`)      | 0 | => a
  |1    |3(`ana`)    | 1 | => 'a'n, 'a'na
  |2    |1(`anana`)  | 3 | => 'ana'n, 'ana'na
  |3    |0(`banana`) | 0 | => b, ba, ban, bana, banan, banana
  |4    |4(`na`)     | 0 | => n, na
  |5    |2(`nana`)   | 2 | => 'na'n, 'na'na
  */
  auto sa = SuffixArray(str);
  auto lcp = Lcp(sa, str);

  // worst case:
  // n = 6 => 6 + 5 + 4 + 3 + 2 + 1
  // n = 90,000 => (90,000 * 90,001) / 2
  std::vector<int> cnt(str.length());
  std::vector<int64_t> sum(str.length());
  for (int i = 0; i < cnt.size(); ++i) {
    cnt[i] = str.length() - sa[i] - lcp[i];
    if (i == 0) {
      sum[i] = cnt[i];
      continue;
    }
    sum[i] = sum[i-1] + cnt[i];
  }

  // idx:  0  1  2  3  4  5
  // sum:  1  3  5 11 13 15
  // if n = 2 then
  // `lower_upper` will point to position 1
  //
  // the string is banana so we need to split from it:
  //     v(idx: 3)
  // `banana`.substr(sa[1], ...)
  // and also the input value(n) is 2 so we need to print `an`:
  // `banana`.substr(sa[1], n - sa[0] + lcp[1])
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    auto idx = std::lower_bound(sum.begin(), sum.end(), n) - sum.begin();
    if (idx == sum.size()) {
      std::cout << "-1\n";
      continue;
    }

    std::string res{str.substr(sa[idx], n - (idx ? sum[idx-1] : 0) + lcp[idx])};
    std::cout << res << '\n';
  }

  return 0;
}
