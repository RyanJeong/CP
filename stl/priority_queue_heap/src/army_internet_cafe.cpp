// https://www.acmicpc.net/problem/12764
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	// <from,to>
	vector<pair<int, int>> v(1);
	for (int i = 1; i<=n; ++i) {
		int s, t;
		cin>>s>>t;
		v.push_back({s,t});
	}
	sort(v.begin()+1,v.end()); // 1-based

	priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    set<int> s;
    vector<int> freq;
    for (int i = 1; i<=n; ++i) {
        while (!pq.empty()) {
            if (pq.top().first<=v[i].first) {
                s.insert(pq.top().second);
                pq.pop();
            }    
            else {
                break;
            }
        }
        if (s.empty()) {
            pq.push({v[i].second,freq.size()});
            freq.push_back(1);
        }
        else {
            auto cur = s.begin();
            pq.push({v[i].second,*cur});
            ++freq[*cur];
            s.erase(cur);
        }
    }
    cout << freq.size() << '\n';
    for (int i : freq) {
        cout << i << ' ';
    }

	return 0;
}