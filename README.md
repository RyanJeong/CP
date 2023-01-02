# CP
Resources for competitive programming

[![profile](http://mazassumnida.wtf/api/v2/generate_badge?boj=msjeong)](https://www.acmicpc.net/user/msjeong)

* Programming Contest Sites:
	* [Baekjoon Online Judge](https://www.acmicpc.net/)
		* Handle: [msjeong](https://www.acmicpc.net/user/msjeong)
	* [Codeforces](https://codeforces.com/)
		* Handle: [msjeong](https://codeforces.com/profile/msjeong)
	* [AtCoder](https://atcoder.jp/)
		* Handle: [msjeong](https://atcoder.jp/users/msjeong)
	* [HackerRank](https://www.hackerrank.com/dashboard/)
    * [프로그래머스](https://programmers.co.kr/)

## Algorithm
* [Intro.](/intro/)
* [Array](/array/)
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
* [BFS & DFS](/bfs_dfs/)
* [Recursion](/recursion/)
* [Dynamic Programming](/dp/)
* [LIS & LCS](/lis_lcs/)
* [Greedy](/greedy/)
* [Sort](/sort/)
* [Binary Search](/binary_search/)
* [Two Pointer](/two_pointer/)
* [Graph](/graph/)
* [Tree](/tree/)
* [Topological Sort](/topological_sort/)
* [Disjoint-set](/disjoint-set/)
* [Minimum Spanning Tree](/mst/)
* [Floyd-Warshall](/floyd-warshall/)
* [Dijkstra](/dijkstra/)
* [String](/string/)
* [Convex Hull](/convex-hull/)
---
* [Fast IO](./fastio/)
* [Library](/library/)
* [Mathematics](/math/)
* [Simulation](/simulation/)
---

## 추천 문제집
* [[Programmers] 코딩테스트 고득점 Kit](https://programmers.co.kr/learn/challenges?tab=algorithm_practice_kit)
* [[BOJ] 단계별로 풀어보기](https://www.acmicpc.net/step)
* [[BOJ] jinhan814의 공개 문제집](https://www.acmicpc.net/workbook/by/jinhan814)
* [[BOJ] BaaaaaaaaaaarkingDog의 공개 문제집](https://www.acmicpc.net/workbook/by/BaaaaaaaaaaarkingDog)
* [[BOJ] 프로그래밍 콘테스트 챌린징 책에 나오는 문제들](https://www.acmicpc.net/workbook/view/4912)
* [[BOJ] rkm0959의 공개 문제집](https://www.acmicpc.net/workbook/by/rkm0959)
* [[BOJ] code.plus](https://www.acmicpc.net/workbook/codeplus)
* [[BOJ] 한국정보올림피아드](https://www.acmicpc.net/category/55)
    * [한국정보올림피아드](https://koi.or.kr/)
* [[BOJ] Japanese Olympiad in Informatics](https://www.acmicpc.net/category/100)
    * [JOI過去問 - 情報オリンピック日本委員会](https://www.ioi-jp.org/problem_archive.php)

## 사소한 팁
* `std::ios::sync_with_stdio(false); std::cin.tie(NULL);`
  * 입력이 많은 CP 문제에서 사용할 수 있는 최적화
  * `std::ios::sync_with_stdio(false)` 명령을 통해 C 스트림과 C++ 스트림의 버퍼 동기화를 해제(동기화는 비용이 발생하므로 이를 해제하는 것이 좋으며, 대부분 CP 플랫폼은 싱글 스레드를 사용하므로 해제해도 무방)
  * `std::cin.tie(NULL)` 명령을 통해 `std::cin`의 입력 스트림과 `std::cout`의 출력 스트림의 연결을 해제한다. 스트림을 해제하는 이유는 두 스트림이 기본적으로 연결되어 있어 `std::cin` 명령을 통해 입력을 받으면 출력 스트림의 버퍼를 flush 한다. flush는 비용이 발생하므로, `std::cin.tie(NULL)` 명령을 사용해 두 스트림 간 연결을 해제하면 출력 스트림의 flush를 방지할 수 있다.
  > the `cout` is tied to the `cin` object, which means every time we want to input data through the `cin` object, the `cout` object is flushed (emptied)
* `std::endl` vs. `'\n'`
  * `std::endl`은 매번 flush 연산을 하므로 비용이 발생하지만, `'\n'`은 flush 연산을 하지 않아 출력이 많은 문제에서는 `'\n'`을 사용한 넋이 비용적으로 효율적임
* 재귀함수 내 상대적으로 비용이 큰 지역변수는 `static`을 사용해 최초 한 번 생성을 보장하거나 재귀함수에서만 접근 가능한 위치에 변수를 선언하는 것이 비용적으로 효율적임
* [알고리즘 문제 해결 전략](https://book.algospot.com/index.html)
    * [4.6 수행 시간 어림짐작하기](https://book.algospot.com/estimation.html)
        > 입력의 크기를 시간 복잡도에 대입해서 얻은 반복문 수행 횟수에 대해, 1초 당 반복문 수행 횟수가 1억(10<sup>8</sup>)을 넘어가면 시간 제한을 초과할 가능성이 있다.

## 유용한 사이트
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [cppreference.com](https://en.cppreference.com/w/)
* [cplusplus.com - The C++ Resources Network](https://cplusplus.com/)
* [Standard C++](https://isocpp.org/)
* [Bjarne Stroustrup's Homepage](https://www.stroustrup.com/)
* [mathURL](http://mathurl.com/)
* [Alphabetize Your Lists  - WordCounter.net](https://wordcounter.net/alphabetize)
