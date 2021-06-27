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

# [Stack](https://cplusplus.com/reference/stack/stack)
* Restricted Structure
* FIFO (First In First Out)
* `push`의 시간 복잡도는 <b><i>O</i>(1)</b>
* `pop`의 시간 복잡도는 <b><i>O</i>(1)</b>
* `top`의 시간 복잡도는 <b><i>O</i>(1)</b>

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

## 올바른 괄호 쌍 구하기
* 괄호로만 구성된 문자열이 주어졌다면:
1. 여는 괄호는 스택에 `push`
2. 닫는 괄호가 나오면:
    1. 스택이 비어있으면 틀린 괄호 쌍
    2. 스택의 `top` 결과와 닫는 괄호가 대응되지 않으면 틀린 괄호 쌍
    3. 스택의 `top` 결과와 닫는 괄호가 대응되면 `pop`
3. 해당 문자열을 모두 처리한 뒤에 스택에 괄호가 남아있다면 틀린 괄호 쌍이며, 스택이 비어있으면 올바른 괄호 쌍
### 연습문제
* [[BOJ] 괄호의 값](https://www.acmicpc.net/problem/2504)
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
|[이전 - Array](../Array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](../bfs_dfs/)|
|-|-|-|

