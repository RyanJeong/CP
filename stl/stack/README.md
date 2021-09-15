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
* 추천 문제
    * [[BOJ] 스택](https://www.acmicpc.net/problem/10828) [(소스코드)](./src/stack.cpp)
    * [[BOJ] 도키도키 간식드리미](https://www.acmicpc.net/problem/12789) [(소스코드)](./src/snack.cpp) - 스택 응용
    * [[BOJ] 오큰수](https://www.acmicpc.net/problem/17298) [(소스코드)](./src/nge.cpp)
    * [[BOJ] EKSPLOZIJA](https://www.acmicpc.net/problem/17298) [(소스코드)](./src/eksplozija.cpp) - 컨테이너를 응용한 스택 구현
---

## [스택(stack)](https://cplusplus.com/reference/stack/stack)
* Restricted Structure
* FIFO (First In First Out)
* `push`의 시간 복잡도는 <b>O(1)</b>
* `pop`의 시간 복잡도는 <b>O(1)</b>
* `top`의 시간 복잡도는 <b>O(1)</b>

### [소스코드](./src/exam.cpp)
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    s.push(10); // { 10 }
    s.push(20); // { 10 20 }
    s.push(30); // { 10 20 30 }
    cout << s.size() << '\n'; // 3
    if (s.empty()) {
        cout << "Stack is empty!\n";
    } 
    else {
        cout << "Stack is not empty!\n"; // print "Stack is not empty!"
    }
    cout << s.top() << '\n'; // 30
    s.pop(); // { 10 20 }, return value is none!
    cout << s.top() << '\n'; // 20
    s.pop(); // { 10 }
    s.pop(); // (empty)
    if (s.empty()) {
        cout << "Stack is empty!\n"; // print "Stack is empty!"
    } 
    else {
        cout << "Stack is not empty!\n"; 
    }

    return 0;
}
```

## 스택 응용: 올바른 괄호 쌍 구하기
* 추천 문제
    * [[BOJ] The Balance of the World](https://www.acmicpc.net/problem/4949) [(소스코드)](./stack_app/balance_world.cpp)

* 괄호로만 구성된 문자열이 주어졌다면:
1. 여는 괄호는 스택에 `push`
2. 닫는 괄호가 나오면:
    1. 스택이 비어있으면 틀린 괄호 쌍
    2. 스택의 `top` 결과와 닫는 괄호가 대응되지 않으면 틀린 괄호 쌍
    3. 스택의 `top` 결과와 닫는 괄호가 대응되면 `pop`
3. 해당 문자열을 모두 처리한 뒤에 스택에 괄호가 남아있다면 틀린 괄호 쌍이며, 스택이 비어있으면 올바른 괄호 쌍

### [소스코드](./stack_app/exam.cpp)
```c++
// http://icpc.me/9012
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    while(n--) {
        string ps;
        cin>>ps;
        bool is_vps = true;
        stack<int> s;

        for (char c : ps) {
            if (c=='(') {
                s.push(c);
            } 
            else {
                if (s.empty()) {
                    is_vps=false;
                    break;
                } 
                else { // ')'
                    if (s.top()!='(') {
                        is_vps=false;
                        break;
                    } 
                    else { // s.top() is '('
                        s.pop();
                    }
                }
            }
        }    
        cout << ((s.empty() && is_vps) ? "YES" : "NO") << '\n';
    }

    return 0;
}
```

### 연습문제
* [[BOJ] 괄호의 값](https://www.acmicpc.net/problem/2504) [(소스코드)](./stack_app/exercise.cpp)
###### Memory: 2,024 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/2504
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 0;
    int temp = 1;
    bool is_invalid = false;
    string str;
    cin>>str;
    stack<char> s;
    char prev;
    for (char c : str) {
        if (c=='(') {
            s.push(c);
            temp*=2;
        }
        else if (c=='[') {
            s.push(c);
            temp*=3;
        }
        else if (!s.empty() && s.top()=='(' && c==')') {
            if (prev=='(') {
                num+=temp;
            }
            s.pop();
            temp/=2;
        }
        else if (!s.empty() && s.top()=='[' && c==']') {
            if (prev=='[') {
                num+=temp;
            }
            s.pop();
            temp/=3;
        }
        else {
            is_invalid=true;
            break;
        }
        prev=c;
    }
    cout << ((!s.empty() || is_invalid) ? 0 : num);

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|
