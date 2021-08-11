#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) 
{
    s.erase(s.begin());
    s.erase(s.end()-1);
    s.push_back(',');
    vector<pair<int, vector<int>>> v;
    bool is_bracket = false;
    int elem = 0;
    int size = 0;
    vector<int> tmp;
    for (char c : s) {
        if (c=='{') {
            is_bracket=true;
        }
        else if (c=='}') {
            is_bracket=false;
        } 
        else if (c==',') {
            ++size;
            tmp.push_back(elem);
            elem=0;
            if (!is_bracket) {
                v.push_back({size,tmp});
                size=0;
                tmp.clear(); 
            }
        }
        else {
            elem=elem*10+c-'0';
        }
    }

    sort(v.begin(),v.end());
    set<int> check_dup;
    vector<int> answer;
    for (auto cur : v) {
        vector<int> tmp = cur.second;

        for (int i : tmp) {
            if (check_dup.find(i)!=check_dup.end()) {
                continue;
            }
            check_dup.insert(i);
            answer.push_back(i);
        }
    }

    return answer;
}
