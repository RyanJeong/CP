# Mathematics
## Index
* [[WIP] Big Integer](#big-integer)
* [[WIP] Lucas's Theorem](#lucas-s-theorem)
* [Modulo](#modulo)
* [Outer Product](#outer-product)
* [Permutation and Combination](#permutation-and-combination)
---

## Big Integer
* `long long` 형의 값 표현 범위를 벗어나는 경우, `string` 형을 사용해 큰 수 계산을 구현하거나, 카라추바 또는 FFT(Fast Fourier Transform)을 사용해야 함
* 추천 문제
    * [조합](https://www.acmicpc.net/problem/2407)
    * [큰 수 곱셈](https://www.acmicpc.net/problem/13277)

### [Top](#index)
---

## Lucas's Theorem

### [Top](#index)
---

## Modulo
* 추천 문제
    * [[BOJ] 곱셈](https://www.acmicpc.net/problem/1629) [(소스코드)](./modulo/src/mul.cpp)
* Given <b>two positive numbers</b> <i>a</i> and <i>n</i>, <i>a</i> modulo <i>n</i> (abbreviated as <i>a</i> <b>mod</b> <i>n</i>) is the remainder of the Euclidean division of <i>a</i> by <i>n</i>, where <i>a</i> is the <b>dividend</b> and <i>n</i> is the <b>divisor</b>. 
* The range of numbers for an integer modulo of <i>n</i> is 0 to <i>n</i> − 1 inclusive (<i>a</i> <b>mod</b> 1 is always 0; <i>a</i> <b>mod</b> 0 is <b>undefined</b>, possibly resulting in <b>a division by zero error</b> in some programming languages).

### Distributive Property
#### Modular Addition 
`(A + B) mod C = (A mod C + B mod C) mod C`
```c++
    int A = 14;
    int B = 17;
    int C = 5;

    // operator precedence
    // * / % -> + -
    cout << (A+B)%C << '\n'; // 1
    cout << (A%C+B%C)%C << '\n'; // 1
```
![modulo](./modulo/img/1.jpg)
><b>(A + B) mod C = (A mod C + B mod C) mod C</b><br><br>
<b>A</b> = C * Q1 + R1 where 0 ≤ R1 < C and Q1 is some integer. <b>A mod C = R1</b><br>
<b>B</b> = C * Q2 + R2 where 0 ≤ R2 < C and Q2 is some integer. <b>B mod C = R2</b><br>
<b>(A + B) = C * (Q1 + Q2) + R1+R2</b><br><br>
<b>LHS</b> = (A + B) mod C<br>
<b>LHS</b> = (C * (Q1 + Q2) + R1+ R2) mod C<br>
We can eliminate the multiples of C when we take the mod C<br>
<b>LHS = (R1 + R2) mod C</b><br><br>
<b>RHS</b> = (A mod C + B mod C) mod C<br>
<b>RHS = (R1 + R2) mod C</b><br><br>
<b>LHS=RHS= (R1 + R2) mod C</b>

#### Modular Subtraction
`(A - B) mod C = (A mod C - B mod C) mod C`
```c++
    int A = 14;
    int B = 11;
    int C = 7;

    // operator precedence
    // * / % -> + -
    cout << (A-B)%C << '\n'; // 3 
    cout << (A%C-B%C)%C << '\n'; // -4
    // a dividend can't be negative
    // A%C: 0
    // B%C: 4
    // A%C-B%C: -4
    // so, add a divisor
    cout << (A%C-B%C+C)%C << '\n'; // 3
```

#### Modular Multiplication
`(A * B) mod C = (A mod C * B mod C) mod C`
```c++
    int A = 4;
    int B = 7;
    int C = 6;

    // operator precedence
    // * / % -> + -
    cout << (A*B)%C << '\n'; // 4
    cout << (A%C*B%C)%C << '\n'; // 4
```

#### ~~Modular Multiplication~~(NOT allow)
<br>

### Fast Modular Exponentiation
`A^2 mod C = (A * A) mod C = ((A mod C) * (A mod C)) mod C`
>7<sup>1</sup> <b>mod</b> 13 = 7<br><br>
7<sup>2</sup> <b>mod</b> 13<br>
= (7<sup>1</sup> * 7<sup>1</sup>) <b>mod</b> 13<br>
= (7<sup>1</sup> <b>mod</b> 13 * 7<sup>1</sup> <b>mod</b> 13) <b>mod</b> 13<br><br>
7<sup>4</sup> <b>mod</b> 13<br>
= (7<sup>2</sup> * 7<sup>2</sup>) <b>mod</b> 13<br>
= (7<sup>2</sup> <b>mod</b> 13 * 7<sup>2</sup> <b>mod</b> 13) <b>mod</b> 13<br><br>
...

#### ex. 10<sup>11</sup> <b>mod</b> 12
```c++
#include <bits/stdc++.h>

using namespace std;

long long pow(long long, long long, long long);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin>>a>>b>>c;
    cout << pow(a,b,c);

    return 0;
}

long long pow(long long a, long long b, long long c)
{
    if (b==1) {

        return a%c;
    }

    long long val = pow(a,b/2,c);
    val = val*val%c;

    return (b&01) ? (val*a%c)%c : val;
}
```

### [Top](#index)
---

## Outer Product
* 추천 문제
    * [[BOJ] CCW](https://www.acmicpc.net/problem/11758) [(소스코드)](./outer-product/src/ccw.cpp)
    * [[BOJ] 다각형의 면적](https://www.acmicpc.net/problem/2166) [(소스코드)](./outer-product/src/polygon.cpp)
    * [[BOJ] 선분 교차 1](https://www.acmicpc.net/problem/17386) [(소스코드)](./outer-product/src/line1.cpp)
    * [[BOJ] 선분 교차 2](https://www.acmicpc.net/problem/17387) [(소스코드)](./outer-product/src/line2.cpp)

### CCW(CounterClockWise)
* 벡터의 외적을 이용하면 평면위에 위치한 세 점의 방향성을 판별할 수 있음
* 두 벡터 <i>u</i>, <i>v</i>가 주어졌을 때, 벡터 <i>u</i>, <i>v</i>가 이루는 각이 <i>θ</i>, 벡터 <i>u</i>, <i>v</i>에 수직인 단위벡터가 <i>n</i>이면 두 벡터의 외적은 아래와 같음:<br>
    ![ccw](./outer-product/img/outer_product.png)
    * <i>θ</i>의 범위가 한정됨에 따라, 계산 결과의 부호는 단위벡터 <i>n</i>에 의해 결정

* 단위벡터 <i>n</i>의 방향 결정
    * 반시계 방향이면 양수, 시계 방향이면 음수

    ![ccw](./outer-product/img/1.png)

* 외적의 행렬 표현을 이용한 계산

    ![ccw](./outer-product/img/2.jpeg)

    * 평면위에 놓인 세 점이므로, <i>u</i><sub>3</sub>와 <i>v</i><sub>3</sub>는 둘 다 0
    * 행렬 표현식의 계산 결과는 <i>u</i><sub>1</sub><i>v</i><sub>2</sub>−<i>u</i><sub>2</sub><i>u</i><sub>1</sub>
    * <b><i>u</i><sub>1</sub><i>v</i><sub>2</sub>−<i>u</i><sub>2</sub><i>u</i><sub>1</sub><b>의 계산 결과가 양수라면 반시계 방향, 음수라면 시계 방향</b>


### 다각형의 면접

![ccw](./outer-product/img/3.png)
![ccw](./outer-product/img/4.png)
---
## Permutation and Combination
### Permutation 

![permutation](./permutation-and-combination/img/permu.png)
```c++
// https://www.acmicpc.net/problem/15654
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nPm
    int n, m;
    cin>>n>>m;
    vector<int> v;

    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    do {
        for (int i = 0; i<m; ++i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        // 1 2 3 4 5 -> 1 2 5 4 3, 1 3 2 4 5 -> 1 3 5 4 2, ...
        reverse(v.begin()+m,v.end());
    } while (next_permutation(v.begin(),v.end()));

    return 0;
}
```

### Combination 

![combination](./permutation-and-combination/img/combi.png)
```c++
// https://www.acmicpc.net/problem/15650
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // nCm
    int n, m;
    cin>>n>>m;
    int arr[8];
    for (int i = 0; i<n; ++i) {
        arr[i]=i+1;
    }
    vector<int> v;

    // next_permutation, 0 0 1 1 => 1 1 0 0
    // prev_permutation, 1 1 0 0 => 0 0 1 1
    for (int i = 0; i<m; ++i) {
        v.push_back(0);
    }
    for (int i = m; i<n; ++i) {
        v.push_back(1);
    }
    do {
        for (int i = 0; i<n; ++i) {
            if (!v[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    } while (next_permutation(v.begin(),v.end()));

    return 0;
}
```

### [Top](#index)
---