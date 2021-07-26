// https://www.acmicpc.net/problem/19644
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, d, c;
    cin>>l>>r>>d>>c;
    int damage = 0;
    // q 변수는 공격 시점에서 공격을 받는 좀비들 중 가장 멀리 떨어진 좀비의
    // 바로 다음 인덱스(r+1)를 값으로 보관
    // r+1 이후에는 해당 시점에서의 공격이 유효하지 않으므로, 
    // damage에 d를 빼주어야 함
    queue<int> q;
    for (int i = 1; i<=l; ++i) {
        if (!q.empty() && q.front()==i) {
            q.pop();
            damage-=d;
        }
        int hp;
        cin>>hp;
        // 수류탄을 사용해야 하는 경우에는
        // 다른 좀비들을 공격할 수 없으므로,
        // damage+d 부분은 조건을 만족할 때에만
        // 수행해야 함
        if (hp>damage+d) {
            if (c>0) {
                --c;
            }
            else {
                cout << "NO";

                return 0;
            }
        }
        else {
            damage+=d;
            q.push(i+r);
        }
    }
    cout << "YES";

    return 0;
}