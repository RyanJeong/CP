// http://icpc.me/10844
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double d = 0.9999999999999997779553950749686919152736663818359375;
    char arr[1000];
    sprintf(arr, "%52.52f", d);
    cout << arr << '\n';
    d = 1234.56;
    sprintf(arr, "%52.52f", d);
    cout << arr;

    return 0;
}