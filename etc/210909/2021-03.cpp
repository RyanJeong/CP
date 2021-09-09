#include <iostream>
///////////

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

///////////
int main(void)
{
    for (int i : solution(
        {
            "java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50"
        }, 
        {
            "java and backend and junior and pizza 100",
            "python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250",
            "- and backend and senior and - 150",
            "- and - and - and chicken 100",
            "- and - and - and - 150"
        })) {
        cout << i << ' ' ;
    }

    return 0;
}