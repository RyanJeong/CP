// Terminal focus and roll back
/* Ctrl + Shift + P -> Preferences: Open Keyboard Shortcuts (JSON)
// Place your key bindings in this file to override the defaults
[
  {
    "key": "Ctrl+;",
    "command": "terminal.focus",
    "when": "editorFocus"
  },
  {
    "key": "Ctrl+;",
    "command": "workbench.action.focusActiveEditorGroup",
    "when": "terminalFocus"
  }
]
*/
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	// Fast I/O for CP
    ios::sync_with_stdio(false); // off the syncronization of all
                                 // the C++ standard streams with
                                 // their corresponding standard
                                 // C streams
    cin.tie(NULL); // disable the flushing of cout 
                   // before cin accepts an input


    cout << "Hello World!\n";

    // Overflow
    // for (char c = 0; c < 128; ++c) { ... } -> loop!
    for (int i = 0; i<128; ++i);

    // for better readability
    long long ll = 1'000'000; // 1000000
    cout << ll << '\n';

    double a = 0.1+0.1+0.1;
    double b = 0.3;

    // MUST be careful about comparing floating-point values
    // if (a == b) 
    if (abs(a-b)<1e-12) {
        cout <<"same!\n";
    }

    // 'overflowing' the 'stack'
    // int arr[1024][1024];

    // How to solve:
    // 1. Static declaration
    // 2. External definition
    static int arr[1024][1024];

    // Init. of array
    memset(arr,0,sizeof arr);

    vector<int> v1(3,5); // { 5, 5, 5 };

    cout << v1.size() << '\n'; // 5, the return type of size() is 'unsigned'
    v1.push_back(4); // { 5, 5, 5, 4 }
    for (int v : v1)
        cout << v << ' ';
    cout << '\n';
    //---------------------------------------------
    vector<int> v2(2); // { 0, 0 }

    v2.insert(v2.begin() + 1, 4); // { 0, 4, 0 }
    for (int v : v2) {
        cout << v << ' ';
    }
    cout << '\n';
    //---------------------------------------------
    vector<int> v3 = {1,2,3,4}; // { 1, 2, 3, 4 }

    v3.erase(v3.begin()+2); // { 1, 2, 4 }
    for (int v : v3) {
        cout << v << ' ';
    }
    cout << '\n';
    //---------------------------------------------
    vector<int> v4; // { }

    v4 = v3; // { 1, 2, 4 }
    for (int v : v4) {
        cout << v << ' ';
    }
    cout << '\n';
    v4.pop_back(); // { 1, 2 };
    for (int v : v4) {
        cout << v << ' ';
    }
    cout << '\n';
    v4.clear(); // { }
    //---------------------------------------------

    int    input1;
    string str1;
    
    cin >> str1;
    cin >> input1; // OK;
    
    cin >> input1;
    cin >> str1;   // OK;

    cin >> input1;
    getline(cin,str1); // not expected.

    cin >> input1;
    cin.get();          //'\n'
    getline(cin,str1); // OK;

    /* 
    input: "ASDF DDF"
      1. cin >> str1;       -> str = "ASDF"
      2. getline(cin, str1) -> str1 = "ASDF DDF"
    */

    return 0;
}