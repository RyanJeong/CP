# [WIP] String
* 추천 문제 - 문자열
    * [[BOJ] IOIOI (IOIOI)](https://www.acmicpc.net/problem/5525) [(소스코드)](./src/ioioi.cc) - 문자열 구현
    * [[BOJ] Mirror, Mirror](https://www.acmicpc.net/problem/4740) [(소스코드)](./src/mirror.cpp) - `getline()`
    * [[BOJ] IZBORNIK](https://www.acmicpc.net/problem/1283) [(소스코드)](./src/izbornik.cpp) - `getline()`, `stringstream` 사용 방법
---

* 추천 문제 - KMP
    * [[BOJ] 카멜레온 부분 문자열](https://www.acmicpc.net/problem/13506) [(소스코드)](./src/chameleon.cc) - `fail` 함수의 동작을 이해할 수 있는 문제
    * [[BOJ] Editor](https://www.acmicpc.net/problem/1701) [(소스코드)](./src/editor.cpp) - KMP `fail`함수를 사용하는 문제 1
    * [[BOJ] Power Strings](https://www.acmicpc.net/problem/4354) [(소스코드)](./src/power_string.cpp) - KMP `fail`함수를 사용하는 문제 2
    * [[BOJ] 찾기](https://www.acmicpc.net/problem/1786) [(소스코드)](./src/kmp.cpp) - KMP 알고리즘 문제

---

## 문자열
* A string can be considered to be a vector of character values. Just as the subscript operator is used to obtain individual elements within a vector, in the same manner the subscript operator is used to access individual characters within strings. In addition, there are many high level operations specific to the string data type.

## [KMP](http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html)
* 대상 문자열(`s`)로부터 패턴 문자열(`p`)의 포함 여부를 구하고자 할 때, `p`의 실패함수(`fail` or `pi`)를 구한 뒤, 이를 `s`에 적용
* 무식한 방법으로 `s`에 `p`의 포함 여부를 구하고자 할 때, `s`의 길이가 `n`, `p`의 길이가 `m`이라면 시간복잡도는 <b>O(<i>nm</i>)</b>
* KMP(Knuth-Morris-Pratt) 알고리즘을 적용하면 시간복잡도는 <b>O(<i>n</i>+<i>m</i>)</b>

### 실패함수(failure function)

![kmp](./img/kmp.png)
  * 실패함수는 패턴 문자열의 `i`번 인덱스가 `0`번 인덱스를 기준으로 몇 번째까지 일치하고, 다음에 확인해야 할 인덱스를 가리킴
  * `fail[4] = 3`이라고 한다면, `0-2`번 부분 문자열과는 일치하며, `3`번 인덱스에 있는 문자와 비교해야 함을 나타냄:
    * `pattern[2~4] == pattern[0~2]`

### KMP 구현 코드
```cpp
#include <string>
#include <vector>

// string
using std::string;

// vector
using std::vector;

template <typename T>
vector<int> GetFail(const T& pattern);
template <typename T>
vector<int> Kmp(const T& str, const T& pattern);

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      // idx    : 0 1 2 3 4 5 6
      // pattern: B A B A B A A
      // fail   : 0 0 1 2 3 4 ?
      // ----------------------
      // i = 6, j = 4
      // loop: j > 0 && p[i] != p[j]
      //  if i = 6, j = 4
      //   then j = fail[j-1];
      //   now j = 2
      //  if i = 6, j = 2
      //   then j = fail[j-1];
      //   now j = 0
      //  j is 0, so escape the loop
      // end
      j = fail[j-1];
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}

template <typename T>
vector<int> Kmp(const T& s, const T& p) {
  vector<int> fail = GetFail(p);
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j])
      j = fail[j-1];
    if (s[i] == p[j]) {
      if (j == p.size() - 1) {
        // ABC    => j = 0;
        // ABCABC => j = 3;
        ans.push_back(i - p.size() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

```

### 연습문제
* [[BOJ] 부분 문자열](https://www.acmicpc.net/problem/16916) [(소스코드)](./src/kmp_exam.cc)
###### Memory: 11,476 KB, Time: 20 ms
```c++
#include <iostream>
#include <string>
#include <vector>

// iostream
using std::cin;
using std::cout;
using std::getline;

// string
using std::string;

// vector
using std::vector;

template <typename T>
vector<int> GetFail(const T& pattern);
template <typename T>
vector<int> Kmp(const T& str, const T& pattern);

int main() {
  string s;
  getline(cin, s);
  string p;
  getline(cin, p);

  auto res = Kmp(s, p);
  cout << (!res.empty());

  return 0;
}

template <typename T>
vector<int> GetFail(const T& p) {
  vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];  // restore the idx
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}

template <typename T>
vector<int> Kmp(const T& s, const T& p) {
  vector<int> fail = GetFail(p);
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j])
      j = fail[j-1];
    if (s[i] == p[j]) {
      if (j == p.size() - 1) {
        ans.push_back(i - p.size() + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

```


## Trie - WIP

### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - Dijkstra](/dijkstra/)|[목록](https://github.com/RyanJeong/CP#index)|다음 - 없음|
|-|-|-|

