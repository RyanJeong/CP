## 2021
### [문제 1 – 아이디 추천](https://programmers.co.kr/learn/courses/30/lessons/72410)
#### Category: 구현
* 문제의 조건:
    * 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    * 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    * 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    * 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    * 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    * 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.<br>
    만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    * 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

 ```c++
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string tmp;

    // step 1
    for (char c : new_id) {
        tmp.push_back((isalpha(c)) ? tolower(c) : c);
    }
    new_id=tmp;
    tmp.clear();

    // step 2
    for (char c : new_id) {
        if (!isalpha(c) && !isdigit(c) && c!='-' && c!='_' && c!='.') {
            continue;
        }
        tmp.push_back(c);
    }
    new_id=tmp;
    tmp.clear();

    // step 3
    bool is_used = false;
    for (char c : new_id) {
        if (c=='.') {
            if (!is_used) {
                is_used=true;
                tmp.push_back(c);
            }
        } 
        else {
            is_used=false;
            tmp.push_back(c);
        }
    }
    new_id=tmp;
    tmp.clear();

    // step 4
    if (new_id.front()=='.') {
        new_id.erase(new_id.begin());
    }
    if (new_id.back()=='.') {
        new_id.erase(new_id.end()-1);
    }

    // step 5
    if (new_id.empty()) {
        new_id.push_back('a');
    }

    // step 6
    if (new_id.size()>15) { // >=16
        new_id.erase(new_id.begin()+15,new_id.end());
    }
    if (new_id.back()=='.') {
        new_id.erase(new_id.end()-1);
    }

    // step 7
    while (new_id.size()<3) {
        new_id.push_back(new_id.back());
    }

    return new_id;
}
```

### [문제 2 – 메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411)
#### Category: 조합(`next_permutation`, `prev_permutation`)
* 문제 제한 사항:
    * orders 배열의 크기는 2 이상 20 이하입니다.
    * orders 배열의 각 원소는 크기가 2 이상 10 이하인 문자열입니다.
    * 각 문자열은 알파벳 대문자로만 이루어져 있습니다.
    * 각 문자열에는 같은 알파벳이 중복해서 들어있지 않습니다.
    * course 배열의 크기는 1 이상 10 이하입니다.
    * course 배열의 각 원소는 2 이상 10 이하인 자연수가 오름차순으로 정렬되어 있습니다.
    * course 배열에는 같은 값이 중복해서 들어있지 않습니다.
    * 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return 해주세요.
    * 배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬되어야 합니다.
    * 만약 가장 많이 함께 주문된 메뉴 구성이 여러 개라면, 모두 배열에 담아 return 하면 됩니다.
    * orders와 course 매개변수는 return 하는 배열의 길이가 1 이상이 되도록 주어집니다.

###### `next_permutation`
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) 
{
    for (string& order : orders) {
        sort(order.begin(),order.end());
    }

    vector<string> answer;
    for (int n : course) {
        map<string, int> m;
        int max_cnt = 2;
        for (string order : orders) {
            if (n>order.size()) {
                continue;
            }

            // combination
            vector<bool> is_used(order.size(),false); 
            for (int i = 0; i<n; ++i) {
                is_used[i]=true;
            }
            sort(is_used.begin(),is_used.end());
            do {
                string tmp;
                for (int i = 0; i<order.size(); ++i) {
                    if (is_used[i]) {
                        tmp+=order[i];
                    }
                }
                m[tmp]+=1;
                max_cnt=max(max_cnt,m[tmp]);
            } while (next_permutation(is_used.begin(),is_used.end()));
        }
        for (auto cur : m) {
            if (cur.second==max_cnt) {
                answer.push_back(cur.first);
            }
        }
    }
    sort(answer.begin(),answer.end());

    return answer;
}
```
###### `prev_permutation`
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) 
{
    for (string& order : orders) {
        sort(order.begin(),order.end());
    }

    vector<string> answer;
    for (int n : course) {
        map<string, int> m;
        int max_cnt = 2;
        for (string order : orders) {
            if (n>order.size()) {
                continue;
            }

            // combination
            vector<bool> is_used(order.size(),false); 
            for (int i = 0; i<n; ++i) {
                is_used[i]=true;
            }
            do {
                string tmp;
                for (int i = 0; i<order.size(); ++i) {
                    if (is_used[i]) {
                        tmp+=order[i];
                    }
                }
                m[tmp]+=1;
                max_cnt=max(max_cnt,m[tmp]);
            } while (prev_permutation(is_used.begin(),is_used.end()));
        }
        for (auto cur : m) {
            if (cur.second==max_cnt) {
                answer.push_back(cur.first);
            }
        }
    }
    sort(answer.begin(),answer.end());

    return answer;
}
```

### [문제 3 – 순위 검색](https://programmers.co.kr/learn/courses/30/lessons/72412)
#### Category: 구현, 조합, `stringstream`
> [조건]을 만족하는 사람 중 코딩테스트 점수를 X점 이상 받은 사람은 모두 몇 명인가?

* [조건]은 "개발언어 and 직군 and 경력 and 소울푸드" 형식의 문자열입니다.
* 언어는 cpp, java, python, - 중 하나입니다.
* 직군은 backend, frontend, - 중 하나입니다.
* 경력은 junior, senior, - 중 하나입니다.
* 소울푸드는 chicken, pizza, - 중 하나입니다.
* '-' 표시는 해당 조건을 고려하지 않겠다는 의미입니다.
* X는 코딩테스트 점수를 의미하며 조건을 만족하는 사람 중 X점 이상 받은 사람은 모두 몇 명인 지를 의미합니다.
* 각 단어는 공백문자(스페이스 바) 하나로 구분되어 있습니다.
* 예를 들면, "cpp and - and senior and pizza 500"은 "cpp로 코딩테스트를 봤으며, 경력은 senior 이면서 소울푸드로 pizza를 선택한 지원자 중 코딩테스트 점수를 500점 이상 받은 사람은 모두 몇 명인가?"를 의미합니다.

###### prev_permutation 사용
```cpp
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) 
{
    map<string, vector<int>> m;
    for (string& str : info) {
        stringstream ss(str);
        vector<string> v(4);
        int score;
        ss>>v[0]>>v[1]>>v[2]>>v[3]>>score;

        // combination
        // lan. dev. career food | score
        //  -   dev. career food | score
        //  -    -   career food | score
        // ... 
        for (int i = 0; i<=4; ++i) {
            vector<bool> is_used(4); // used v[]
            for (int j = 0; j<i; ++j) {
                is_used[j]=true;
            }
            do {
                string tmp;
                for (int j = 0; j<4; ++j) {
                    if (is_used[j]) {
                        tmp+=v[j];
                    }
                    else {
                        tmp.push_back('-');
                    }
                }
                m[tmp].push_back(score);
            } while (prev_permutation(is_used.begin(),is_used.end()));
        }
    }

    // sort
    for (auto& cur : m) {
        sort(cur.second.begin(),cur.second.end());
    }

    // query
    vector<int> answer;
    for (string& str : query) {
        stringstream ss(str);
        string map_key;
        // "java and backend and junior and pizza | 100"
        for (int i = 0; i<7; ++i) {
            string tmp;
            ss>>tmp;
            if (i&1) {
                continue;
            }
            map_key+=tmp; 
        }
        int score;
        ss>>score;

        vector<int> map_values(m[map_key]);
        int idx = lower_bound(map_values.begin(),map_values.end(),score)-map_values.begin();
        answer.push_back(map_values.size()-idx);
    }

    return answer;
}
```

### [문제 4 – 합승 택시 요금](https://programmers.co.kr/learn/courses/30/lessons/72413)
#### Category: 그래프, 플로이드-워셜
* 다익스트라는 시작 정점으로부터 나머지 정점으로의 최단거리 계산 시 사용
* <b>플로이드-워셜은 주어진 모든 정점 사이의 최단경로 계산 시 사용</b>
    * 시작점과 두 도착점이 주어졌기 때문에, 다익스트라가 아닌 플로이드-워셜을 사용해 정점 간 거리 계산을 수행해야 함

* 아래 수식으로 문제를 해결하면 됨:
    * `d[i][j]`: <i>i</i>에서 <i>j</i>까지 갈 때의 최소 비용
    `min(d[s][c]+d[c][a]+d[c][b])`

---