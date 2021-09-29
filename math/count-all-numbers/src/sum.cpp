// https://www.acmicpc.net/problem/1081
#include <bits/stdc++.h>

using namespace std;

vector<long long> get_freq(long long n);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, u;
    cin>>l>>u;
    vector<long long> freq_l = get_freq(l-1);
    vector<long long> freq_u = get_freq(u);
    
    long long res = 0;
    for (int i = 0; i<10; ++i) {
        res+=(freq_u[i]-freq_l[i])*i;
    }
    cout << res;

    return 0;
}

vector<long long> get_freq(long long end)
{
    static const int base = 10;
    long long start = 1;
    long long pos = 1;

    vector<long long> freq(base);
    while (start<=end) {
        while (start%base!=0 && start<=end) {
            int n = start;
            while (n>0) {
                freq[n%base]+=pos;
                n/=base;
            }
            ++start;
        }
        if (start>end) {
            break;
        }
        while (end%base!=9 && start<=end) {
            int n = end;
            while (n>0) {
                freq[n%base]+=pos;
                n/=base;
            }
            --end;
        }

        start/=base;
        end/=base;
        long long cnt = end-start+1;
        for (int i = 0; i<base; ++i) {
            freq[i]+=cnt*pos;
        }
        pos*=10;
    }

    return freq;
}
