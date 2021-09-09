// next_permutation
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