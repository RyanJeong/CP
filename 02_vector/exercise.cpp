#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  vector<double> temps;

  for (double temp; cin >> temp; temps.push_back(temp)) {
    ;
  }
  int    above_mid = temps.size() / 2;
  double sum = 0;

  for (double x : temps) {
    sum += x;
  }
  cout << "Average temperature: " << sum / temps.size() << '\n';
  sort(temps.begin(), temps.end());
  cout << "Median temperature: ";
  if (temps.size() % 2 == 0) {
    cout << (temps[above_mid] + temps[above_mid-1]) / 2;
  } else {
    cout << temps[above_mid];
  }
  cout << '\n';

  return 0;
}