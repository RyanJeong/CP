#  Array
* 메모리 상에 요소(element)를 연속적으로 배치한 자료구조
* 추천 문제
    * [[BOJ] 알파벳 개수](https://www.acmicpc.net/problem/10808) [(소스코드)](./src/count_char.cpp)

## 배열 선언
* 배열 선언식이 T <i>name</i>[SIZE]라면, 해당 배열의 필요한 메모리 크기는 `sizeof(T)*SIZE`

```c++
    int arr[100]; // sizeof(int)*100 => 4*100, 400 bytes on a memory
```
<br>

## 배열 특징
* 배열의 요소 접근 시 시간복잡도는 <b>O(1)</b>
* 배열의 요소 수정 시 시간복잡도는 <b>O(1)</b>
* 배열은 연속된 메모리 공간을 사용하므로 캐시 지역성(cache locality) 증가에 따른 캐시 적중률(cache hit rate)가 높음
* 추가적인 메모리가 발생하지 않음
* 배열은 연속된 메모리 공간을 사용하므로 메모리 단편화(memory fragmentation)에 따른 할당 제약이 있을 수 있음

## 배열 연산
### 배열 요소의 개수가 <i>n</i>이라고 가정했을 때:
* 배열의 요소 접근 시 시간복잡도는 <b>O(1)</b>
* 배열의 마지막 요소 뒤에 새로운 요소 추가 시 시간복잡도는 <b>O(1)</b>
* 배열의 마지막 요소 제거 시 시간복잡도는 <b>O(1)</b>
* 배열의 마지막 요소가 아닌 요소 뒤에 새로운 요소 추가 시 시간복잡도는 <b>O(<i>n</i>)</b>
* 배열의 마지막 요소가 아닌 요소 제거 시 시간복잡도는 <b>O(<i>n</i>)</b>

### [소스코드](./src/example.cpp)
```c++
#include <bits/stdc++.h>

using namespace std;

int insert(int[], const int, int&, int, int);
int erase(int[], const int, int&, int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int cap = 10;
    // An array that can store only positive numbers;
    int arr[cap] = { 1, 2, 4, 8, 16, 32 };
    int len = 0;
    for (int i = 0; i<cap; ++i) {
        if (arr[i]) {
            ++len;
        }
    }
    cout << "capacity: " << cap << ", length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 1 2 4 8 16 32

    // 1. insert
    insert(arr,cap,len,0,50);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 1 2 4 8 16 32
    insert(arr,cap,len,len,60);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 1 2 4 8 16 32 60

    // 2. erase
    erase(arr,cap,len,1);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 2 4 8 16 32 60
    erase(arr,cap,len,len);
    cout << "capacity: " << cap << ",length: " << len << '\n';
    for (int i = 0; i<len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    // 50 2 4 8 16 32

    return 0;
}

int insert(int arr[],const int cap,int& len,int idx,int val)
{
    if (len==cap) {
        
        return 0;
    }
    if (idx>len) {

        return 0;
    }
    for (int i = len; i>idx; --i) {
        arr[i]=arr[i-1];
    }
    arr[idx]=val;
    ++len;

    return val;
}

int erase(int arr[],const int cap,int& len,int idx)
{
    if (len==0) {

        return 0;
    }
    if (idx>len) {

        return 0;
    }
    --len;
    int val = arr[idx];
    for (int i = idx; i<len; ++i) {
        arr[i]=arr[i+1];
    }

    return val;
}
```
---
|[이전 - Template](/template/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - STL - Container Classes:](/stl/)|
|-|-|-|



