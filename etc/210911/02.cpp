#include <iostream>
///// WIP
// test 1, test 11 (seg. fault)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k) {
    // transform
    string tmp;
    while (n) {
        tmp.push_back(n%k+'0');
        n/=k; 
    }
    reverse(tmp.begin(),tmp.end());

    vector<long long> v;
    long long buf = 0;
    tmp.push_back('0');
    for (char c : tmp) {
        if (c=='0') {
            if (buf>1) {
                v.push_back(buf);
            }
            buf=0;
        }
        else {
            buf=buf*10+c-'0';
        }
    }
    const int lim = 10'000'000;
    sort(v.begin(),v.end());
    vector<bool> is_composition(lim+1);
    for (int i = 2; i*i<=lim; ++i) {
        if (is_composition[i]) {
            continue;
        }
        for (int j = i*i; j<=lim; j+=i) {
            is_composition[j]=true;
        }
    }

    int answer = 0;
    for (auto cur : v) {
        if (cur>lim) {
            bool is_prime = true;
            for (int i = 2; i<=lim; ++i) {
                if (!cur%i) {
                    is_prime=false;
                    break;
                }
            }
            if (is_prime) {
                ++answer;
            }
        }
        else {
            answer+=!is_composition[cur];
        }
    }

    return answer;
}
/////

int main(void)
{
    cout << solution(437674,3) << '\n';
    cout << solution(797161,3) << '\n';
    cout << solution(110011,10) << '\n';

    return 0;
}