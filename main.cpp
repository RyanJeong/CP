#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    priority_queue<int> pq;
    for (int i = 0; i<10; ++i) {
        pq.push(rand()%100);
    }
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
        /*
            93
            92
            86
            86
            83
            77
            49
            35
            21
            15
        */
    }

    return 0;
}