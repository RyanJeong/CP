#include <iostream>
///// WIP
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apeach;
vector<int> ryan;
vector<vector<int>> buf;
int score = 0;

void bt(int n)
{
    int s_ryan = 0;
    int s_apeach = 0;
    for (int i = 0; i<=10; ++i) {
        if (ryan[i]>apeach[i]) {
            if (ryan[i]) {
                s_ryan+=10-i;
            }
        }    
        else {
            if (apeach[i]) {
                s_apeach+=10-i;
            }
        }
    }
    if (s_ryan+10*n<score) {

        return;
    }
    if (!n && s_ryan>s_apeach && s_ryan>=score) {
        if (s_ryan>score) {
            buf.clear();
        }
        buf.push_back(ryan);
        score=s_ryan;

        return;
    }
    for (int i = 0; i<=10; ++i) {
        if (ryan[i]>apeach[i]) {
            continue;
        }
        ++ryan[i];
        bt(n-1);
        --ryan[i];
    }

    return;
}

vector<int> solution(int n, vector<int> info) 
{
    apeach=info;
    ryan=vector<int>(11);
    bt(n);

    vector<int> answer = {-1};
    if (buf.size()) {
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i<buf.size(); ++i) {
            auto& cur = buf[i];
            for (int j = 10; j>=0; --j) {
                if (cur[j]) {
                    v.push_back({make_pair(j,cur[j]),i});
                    break;
                }
            }
        }
        sort(v.begin(),v.end(),greater<pair<pair<int, int>, int>>());
        /*
for (auto cur : v) {
    cout << cur.first.first << ' ' << cur.first.second << ' ' << cur.second << '\n';
}
*/
        answer=buf[v.front().second];
    }
    
    return answer;
}
/////

int main(void)
{
    /*
    for (auto cur : solution(1, {1,0,0,0,0,0,0,0,0,0,0})) {
        cout << cur << ' ';
    }
    cout << '\n';
    for (auto cur : solution(5, {2,1,1,1,0,0,0,0,0,0,0})) {
        cout << cur << ' ';
    }
    cout << '\n';
    */
    for (auto cur : solution(	9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1})) {
        cout << cur << ' ';
    }
    cout << '\n';


    return 0;
}