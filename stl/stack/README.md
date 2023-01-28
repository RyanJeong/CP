* [STL - Container Classes:](/stl/)
  * Sequence Container
    * [Vector](/stl/vector/)
    * [List](/stl/list/)
    * [Double-ended Queue(Deque)](/stl/deque/)
  * Container Adaptor
    * [Stack](/stl/stack/)
    * [Queue](/stl/queue/)
    * [Priority Queue](/stl/priority_queue_heap/)
  * Associative Container
    * [Set](/stl/set/)
    * [Map](/stl/map/)

# Stack
* 추천 문제 - 스택
  * [[BOJ] 스택](https://www.acmicpc.net/problem/10828) [(소스코드)](./src/stack.cc)
  * [[BOJ] 도키도키 간식드리미](https://www.acmicpc.net/problem/12789) [(소스코드)](./src/snack.cc) - 스택 응용 1
  * [[BOJ] 단어 뒤집기 2](https://www.acmicpc.net/problem/17413) [(소스코드)](./src/word2.cc) - 스택 응용 2
  * [[BOJ] 오큰수](https://www.acmicpc.net/problem/17298) [(소스코드)](./src/nge.cc)
  * [[BOJ] EKSPLOZIJA](https://www.acmicpc.net/problem/17298) [(소스코드)](./src/eksplozija.cc) - 컨테이너를 응용한 스택 구현
  * [[BOJ] 후위 표기식](https://www.acmicpc.net/problem/1918) [(소스코드)](./src/postfix.cc) - 스택을 이용한 후위 표기식 구현

* 추천 문제 - 스택 응용
  * [[BOJ] The Balance of the World](https://www.acmicpc.net/problem/4949) [(소스코드)](./stack_app/balance_world.cc) - 스택을 이용한 괄호 찾기 문제

---

## [스택(stack)](https://cplusplus.com/reference/stack/stack)
* Restricted Structure
* FIFO (First In First Out)
* `push`의 시간 복잡도는 <b>O(1)</b>
* `pop`의 시간 복잡도는 <b>O(1)</b>
* `top`의 시간 복잡도는 <b>O(1)</b>

### [소스코드](./src/exam.cc)
```c++
#include <iostream>
#include <stack>

int main() {
  std::stack<int> s;
  s.push(10);  // { 10 }
  s.push(20);  // { 10 20 }
  s.push(30);  // { 10 20 30 }
  std::cout << s.size() << '\n';  // 3
  if (s.empty())
    std::cout << "stack is empty!\n";
  else
    std::cout << "stack is not empty!\n";  // stack is not empty!
  std::cout << s.top() << '\n';  // 30
  s.pop();  // { 10 20 }, return value is none!
  std::cout << s.top() << '\n';  // 20
  s.pop();  // { 10 }
  s.pop();  // (empty)
  if (s.empty())
    std::cout << "stack is empty!\n";  // stack is empty!
  else
    std::cout << "stack is not empty!\n";

  return 0;
}

```

## 스택 응용: 올바른 괄호 쌍 구하기
* 괄호로만 구성된 문자열이 주어졌다면:
1. 여는 괄호는 스택에 `push`
2. 닫는 괄호가 나오면:
   1. 스택이 비어있으면 틀린 괄호 쌍
   2. 스택의 `top` 결과와 닫는 괄호가 대응되지 않으면 틀린 괄호 쌍
   3. 스택의 `top` 결과와 닫는 괄호가 대응되면 `pop`
3. 해당 문자열을 모두 처리한 뒤에 스택에 괄호가 남아있다면 틀린 괄호 쌍이며, 스택이 비어있으면 올바른 괄호 쌍

### 연습문제
* [[BOJ] Parenthesis](https://www.acmicpc.net/problem/9012) [(소스코드)](./stack_app/exam.cc)
```c++
#include <iostream>
#include <string>
#include <stack>

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    std::string ps;
    std::cin >> ps;
    bool is_vps = true;
    std::stack<int> s;
    for (const char& c : ps) {
      if (c == '(') {
        s.push(c);
      } else {
        if (s.empty()) {
          is_vps = false;
          break;
        } else {
          if (s.top() != '(') {
            is_vps = false;
            break;
          } else {
            s.pop();
          }
        }
      }
    }
    std::cout << ((s.empty() && is_vps) ? "YES" : "NO") << '\n';
  }

  return 0;
}

```

### 연습문제
* [[BOJ] 괄호의 값](https://www.acmicpc.net/problem/2504) [(소스코드)](./stack_app/exercise.cc)
```c++
#include <iostream>
#include <string>
#include <stack>

int main() {
  std::string str;
  std::cin >> str;
  bool is_valid = true;
  std::stack<char> s;
  int value = 1;
  int total_value = 0;
  char prev;
  for (const char& c : str) {
    if (c == '(' || c == '[') {
      s.push(c);
      value *= ((c == '(') ? 2 : 3);
    } else if (!s.empty() && s.top() == '(' && c == ')') {
      if (prev == '(')
        total_value += value;
      s.pop();
      value /= 2;
    } else if (!s.empty() && s.top() == '[' && c == ']') {
      if (prev == '[')
        total_value += value;
      s.pop();
      value /= 3;
    } else {
      is_valid = false;
      break;
    }
    prev = c;
  }
  std::cout << ((!s.empty() || !is_valid) ? 0 : total_value);

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|
