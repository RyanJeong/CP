# 프로그래머스 코딩테스트 연습
## Level 2
* `★`[단체사진 찍기](https://programmers.co.kr/learn/courses/30/lessons/1835) [(소스코드)](./src/1835.cpp) - `find()`, `next_permutation()`
* `　`[카카오 프렌즈 컬러링북](https://programmers.co.kr/learn/courses/30/lessons/1829) [(소스코드)](./src/1829.cpp) - BFS
* `　`[문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057) [(소스코드)](./src/60057.cpp) - 문자열, `to_string()`, `substr()`
* `　`[오픈채팅방](https://programmers.co.kr/learn/courses/30/lessons/42888) [(소스코드)](./src/42888.cpp) - 문자열, 맵
* `★`[[카카오 인턴] 수식 최대화](https://programmers.co.kr/learn/courses/30/lessons/67257) [(소스코드)](./src/67257.cpp) - 문자열, `next_permutation()`
* `★`[메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411) [(소스코드)](./src/72411.cpp) - 문자열, `next_permutation()`, 조합
* `★`[튜플](https://programmers.co.kr/learn/courses/30/lessons/64065) [(소스코드)](./src/64065.cpp) - 문자열, `set`
    * 문제에서 주어진 문자열을 문제 풀이에 적합하게 조작해 푸는 것도 문제 풀이 기술 중 하나
* `　`[거리두기 확인하기](https://programmers.co.kr/learn/courses/30/lessons/81302) [(소스코드)](./src/81302.cpp) - BFS, `fill()`
    ```c++
        vector<int> v1(5);
        fill(v1.begin(),v1.end(),100);
        for (int i : v1) {
            cout << i << ' ';
        }
        cout << '\n'; // 100 100 100 100 100 

        vector<vector<int>> v2(5,vector<int>(5));
        fill(v2.begin(),v2.end(),vector<int>(5,66));
        for (auto i : v2) {
            for (auto j : i) {
                cout << j << ' ';
            }
            cout << '\n';
        }
        /*
        66 66 66 66 66 
        66 66 66 66 66 
        66 66 66 66 66 
        66 66 66 66 66 
        66 66 66 66 66 
        */
    ```
* [괄호 변환](https://programmers.co.kr/learn/courses/30/lessons/60058) - WIP
* [[1차] 뉴스 클러스터링](https://programmers.co.kr/learn/courses/30/lessons/17677) - WIP
* [후보키](https://programmers.co.kr/learn/courses/30/lessons/42890) - WIP
* [순위 검색](https://programmers.co.kr/learn/courses/30/lessons/72412) - WIP
* [[1차] 프렌즈4블록](https://programmers.co.kr/learn/courses/30/lessons/17679) - WIP
* [[1차] 캐시](https://programmers.co.kr/learn/courses/30/lessons/17680) - WIP
* [[3차] 방금그곡](https://programmers.co.kr/learn/courses/30/lessons/17683) - WIP
* [[3차] 압축](https://programmers.co.kr/learn/courses/30/lessons/17684) - WIP
* [[3차] 파일명 정렬](https://programmers.co.kr/learn/courses/30/lessons/17686) - WIP
* [[3차] n진수 게임](https://programmers.co.kr/learn/courses/30/lessons/17687) - WIP