#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string a = "ABCDE";
  string b = "VWXYZ";

  if (a < b) {
    cout << "a before b\n";
  } else {
    cout << "a after b\n";
  }
  string c = a.substr(2, 3); 
  cout << c << '\n'; // "CDE"
  string d = "Hello world!";
  cout << d.find("wo") << '\n'; // 6

  return 0;
}