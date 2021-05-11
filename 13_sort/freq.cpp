// http://icpc.me/2910
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c;

  cin >> n >> c;
  int freq[1'002]  = { 0 }; // 0, 1 ~ 1,000, OOB
  int order[1'002] = { 0 }; // 0, 1 ~ 1,000, OOB
  int size         = 0;
  
  for (int i = 0; i < n; ++i) {
    int temp;

    cin >> temp;
    int index = 0;

    for (int i = 1; i <= size; ++i) {
      if (order[i] == temp) {
        index = i;
        break;
      }
    }
    if (!index) {
      order[++size] = temp;
      ++freq[size];
    } else {
      ++freq[index];
    }
  }
  int max_freq = 0;

  for (int i = 1; i <= size; ++i) {
    max_freq = max(max_freq, freq[i]);
  }
  for (int max = max_freq; max > 0; --max) {
    for (int i = 1; i <= size; ++i) {
      if (freq[i] == max) {
        int value = order[i];

        while (freq[i]--) {
          cout << value << ' ';
        }
      }
    }
  }

  return 0;
}