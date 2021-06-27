#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // constructors used in the same order as described above:
    vector<int> first;                              // empty vector of ints
    vector<int> second(4,100);                      // four ints with value 100
    vector<int> third(second.begin(),second.end()); // iterating through second
    vector<int> fourth(third);                      // a copy of third
  
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> fifth(myints, myints+sizeof myints/sizeof(int));
  
    cout << "The contents of fifth are:";
    for (auto it = fifth.begin(); it != fifth.end(); ++it) {
        // The contents of fifth are: 16 2 77 29
        cout << ' ' << *it;
    }
    cout << '\n';

    vector<int> foo(3,0);
    vector<int> bar=foo;
    foo=vector<int>();
    // foo's size: 0, foo's cap.: 0
    cout << "foo's size: " << foo.size() << ", foo's cap.: " << foo.capacity() << '\n';
    // bar's size: 3, bar's cap.: 3
    cout << "bar's size: " << bar.size() << ", bar's cap.: " << bar.capacity() << '\n';
  
    return 0;
}