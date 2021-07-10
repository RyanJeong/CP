// http://icpc.me/1920
// binary_search(start_pointer, end_pointer, element)
// If the Element is present in the structure, function return true. Else, it will return false.
/*
template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp)
{
    first = std::lower_bound(first, last, value, comp);
    return (!(first == last) && !(comp(value, *first)));
}
*/

#include <bits/stdc++.h>

using namespace std;

int a[100'005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>a[i];
    }
    int m;
    cin>>m;

    sort(a,a+n);
    while (m--) {
        int t;
        cin>>t;

        cout << binary_search(a,a+n,t) << '\n';
    }

    return 0;
}