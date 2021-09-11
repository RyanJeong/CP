#include <iostream>
/////
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    int sz_user = id_list.size();
    map<string, int> m;
    for (int i = 0; i<sz_user; ++i) {
        m[id_list[i]]=i;
    }

    vector<vector<int>> v(sz_user);
    vector<int> freq(sz_user);
    vector<vector<bool>> is_used(sz_user,vector<bool>(sz_user));
    for (string str : report) {
        int idx = 0; 
        for (char c : str) {
            if (c==' ') {
                break;
            }
            ++idx;
        }
        string from = str.substr(0,idx);
        string to = str.substr(idx+1,str.size());
        int idx_from = m[from];
        int idx_to = m[to];
        if (is_used[idx_from][idx_to]) {
            continue;
        }
        v[idx_from].push_back(idx_to);
        ++freq[idx_to];
        is_used[idx_from][idx_to]=true;
    }
    
    vector<int> answer(sz_user);
    for (int u = 0; u<sz_user; ++u) {
        if (freq[u]>=k) {
            for (int i = 0; i<sz_user; ++i) {
                for (auto cur : v[i]) {
                    if (u==cur) {
                        ++answer[i];
                    }
                }
            }
        }
    }

    return answer;
}
/////

int main(void)
{
    for (auto i : solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2)) {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3)) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}