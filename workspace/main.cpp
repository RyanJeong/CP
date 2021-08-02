// https://www.acmicpc.net/problem/21944
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
    // {{level,problem},group}
    priority_queue<pair<pair<int, int>, int>, 
                   vector<pair<pair<int, int>, int>>, 
                   less<pair<pair<int, int>, int>>> max_heap;
    priority_queue<pair<pair<int, int>, int>, 
                   vector<pair<pair<int, int>, int>>, 
                   greater<pair<pair<int, int>, int>>> min_heap;
    while (n--) {
        int p, l, g;
        cin>>p>>l>>g;
        max_heap.push({make_pair(l,p),g});
        min_heap.push({make_pair(l,p),g});
        v[p]=l;
    }
    
    int m;
    cin>>m;
    while (m--) {
        string str;
        cin>>str;
        if (str=="recommend") {
            int g, x;
            cin>>g>>x;
            vector<pair<pair<int, int>, int>> tmp;
            if (x==1) {
                while (max_heap.top().second!=g) {
                    tmp.push_back(max_heap.top());
                    max_heap.pop();
                }
                cout << max_heap.top().first.second << '\n';
                while (!tmp.empty()) {
                    max_heap.push(tmp.back());
                    tmp.pop_back();
                }
            }
            else {
                while (min_heap.top().second!=g) {
                    tmp.push_back(min_heap.top());
                    min_heap.pop();
                }
                cout << min_heap.top().first.second << '\n';
                while (!tmp.empty()) {
                    min_heap.push(tmp.back());
                    tmp.pop_back();
                }
            }
        }
        else if (str=="recommend2") {
            int x;
            cin>>x;
            if (x==1) {
                while (max_heap.top().first.first!=v[max_heap.top().first.second]) {
                    max_heap.pop();
                }
                cout << max_heap.top().first.second << '\n';
            }
            else {
                while (min_heap.top().first.first!=v[min_heap.top().first.second]) {
                    min_heap.pop();
                }
                cout << min_heap.top().first.second << '\n';
            }
        }
        else if (str=="recommend3") {
            int x, l;
            cin>>x>>l;
            vector<pair<pair<int, int>, int>> tmp;
            if (x==1) {
                while (min_heap.top().first.first<l) {
                    tmp.push_back(min_heap.top());
                    min_heap.pop();
                }
                cout << ((min_heap.empty()) ? -1 : min_heap.top().first.second) << '\n';
                while (!tmp.empty()) {
                    min_heap.push(tmp.back());
                    tmp.pop_back();
                }
            }
            else {
                while (max_heap.top().first.first>=l) {
                    tmp.push_back(max_heap.top());
                    max_heap.pop();
                }
                cout << ((max_heap.empty()) ? -1 : max_heap.top().first.second) << '\n';
                while (!tmp.empty()) {
                    max_heap.push(tmp.back());
                    tmp.pop_back();
                }
            }
        }
        else if (str=="add") {
            int p, l, g;
            cin>>p>>l>>g;
            max_heap.push({make_pair(l,p),g});
            min_heap.push({make_pair(l,p),g});
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