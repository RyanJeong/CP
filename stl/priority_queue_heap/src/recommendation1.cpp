// https://www.acmicpc.net/problem/21939
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // idx: p
    vector<int> v(100'000+1);
    // {level,problem}
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   less<pair<int, int>>> max_heap;
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> min_heap;
    while (n--) {
        int p, l;
        cin>>p>>l;
        max_heap.push({l,p});
        min_heap.push({l,p});
        v[p]=l;
    }
    
    int m;
    cin>>m;
    while (m--) {
        string str;
        cin>>str;
        if (str=="recommend") {
            int x;
            cin>>x;
            if (x==1) {
                while (max_heap.top().first!=v[max_heap.top().second]) {
                    max_heap.pop();
                }
                cout << max_heap.top().second << '\n';
            }
            else {
                while (min_heap.top().first!=v[min_heap.top().second]) {
                    min_heap.pop();
                }
                cout << min_heap.top().second << '\n';
            }
        }
        else if (str=="add") {
            int p, l;
            cin>>p>>l;
            max_heap.push({l,p});
            min_heap.push({l,p});
            v[p]=l;
        }
        else { // solved 
            int p;
            cin>>p;
            v[p]=0;
        }
    }

    return 0;
}