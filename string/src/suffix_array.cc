/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

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

  // str       : banana
  // sa        :  0   1   2   3   4   5
  // group_id  : 'b' 'a' 'n' 'a' 'n' 'a'   0   0   0   0   0   0
  // * group_id is initialized to an alphabet only at first and then to a
  //   number between 0 and (strlen - 1).
  for (int d = 1; d < kStrLen; d <<= 1) {
    static std::vector<int> cnt(kCntLen), idx(kStrLen);
    // comparison at `i + d` position
    // if d = 1 then
    //  V
    // banana
    // anana
    // nana
    // ana
    // na
    // a
    //
    // cnt: 1(0x00) ... 3('a', 0x61) ... 2('n'0x6e) ...
    //   => 1(0x00) 1 ... 1 4(0x61) 4 ... 4 6(0x6e) 6 ...
    // idx: 5 0 2 4 1 3
    for (int i = 0; i < kCntLen; ++i)
      cnt[i] = 0;
    for (int i = 0; i < kStrLen; ++i)
      cnt[group_id[i+d]]++;
    for (int i = 1; i < kCntLen; ++i)
      cnt[i] += cnt[i-1];
    for (int i = kStrLen - 1; ~i; --i)
      idx[--cnt[group_id[i+d]]] = i;

    // comparison at `i` position
    // V
    // banana
    // anana
    // nana
    // ana
    // na
    // a
    //
    // cnt: 0(0x00) ... 3('a', 0x61) 1('b', 0x62), ... 2('n', 0x6e) ...
    //   => 0(0x00) ... 0 3(0x61) 4(0x62) 4 ... 4 6(0x6e) 6 ...
    // sa: 5 1 3 0 2 4
    for (int i = 0; i < kCntLen; ++i)
      cnt[i] = 0;
    for (int i = 0; i < kStrLen; ++i)
      cnt[group_id[i]]++;
    for (int i = 1; i < kCntLen; ++i)
      cnt[i] += cnt[i-1];
    for (int i = kStrLen - 1; ~i; --i)
      sa[--cnt[group_id[idx[i]]]] = idx[i];

    // temp: 3 2 4 2 4 1
    // group_id will be replaced with temp
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

    // if every suffix has a unique id:
    if (group_id[sa[kStrLen-1]] == kStrLen)
      break;
  }

  return sa;
}
