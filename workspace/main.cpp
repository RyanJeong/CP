#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long k) 
{
    vector<int> answer;
    for (int i = 1; i<=n; ++i) {
        answer.push_back(i);
    }
    int cnt=1;
    do {
        if (cnt++==k) {
            break;
        }
    } while (next_permutation(answer.begin(),answer.end()));
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i : solution(3,5)) {
        cout << i << ' ';
    } // 4 5

    return 0;
}