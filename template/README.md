# Template for CP

## Basic skills for CP
### Prevent Overflow
```c++
    for (char c = 0; c<128; ++c) { ... } // Overflow!
    for (int i = 0; i<128; ++i) { ... }  // OK!

    // We accept on exception;
    // you may ignore the signed/unsigned warning
    // for this:
    vector v;
    for (int i = 0; i<v.size(); ++i) // Warning!
```
#### On a normal PC, `i<v.size()` warns of a problem that <b>only happens if a vector has more than 2<sup>31</sup> elements</b>.
<br>

### Improve readability of large numbers
```c++
    long long ll_1 = 1000000; // 1,000,000
    long long ll_2 = 1'000'000; // This case is more better!
```
<br>

### How to compare two double values
#### This code, it looks like it will print `same!`, but it actually prints 'NOT same!'. [Why?](https://www.cs.technion.ac.il/users/yechiel/c++-faq/floating-point-arith.html)
```c++
    double a = 0.1+0.1+0.1;
    double b = 0.3;

    if (a==b) {
        cout << "same!\n";
    }
    else {
        cout << "NOT same!\n";
    }
```
> Floating point math is not exact. Simple values like 0.1 cannot be precisely represented using binary floating point numbers, and the limited precision of floating point numbers means that slight changes in the order of operations or the precision of intermediates can change the result. That means that comparing two floats to see if they are equal is usually not what you want (GCC even has a warning for this: `warning: comparing floating point with == or != is unsafe`). 

#### Epsilon comparisons can solve the problem.
```c++
    // `epsilon zero` is approximately 8.854e-12
    if (abs(a-b)<1e-12) {
        cout << "same!\n";
    }
```

### Overflowing the stack memory
#### Most systems use a stack of around 1MB.
```c++
int main(void)
{
    // 4 bytes X 1,024 X 1,024
    // approximately 4MB, OverfloW!
    int arr[1024][1024]; // error!
}
```
#### To avoid stack overflow error, you can use global variable or static variable as below.
```c++
int arr1[1024][1024]; // OK!
int main(void)
{
    static int arr2[1024][1024] // OK!
    return 0;
}
```

### Using `memset` for array initialization
#### `void* memset(void* ptr, int value, size_t num);`
##### Sets the first <i>num</i> bytes of the block of memory pointed by <i>ptr</i> to the specified <i>value</i> (interpreted as an `unsigned char`).
```c++
    int arr[100][100];

    // case 1. initialize array to 0
    // Value 0 in memset is represented in binary as 0000 0000
    memset(arr,0,sizeof arr);

    // case 2. initialize array to -1
    // Value -1 in memset is represented in binary as 1111 1111
    memset(arr,-1,sizeof arr);
    // Within every element of the array 
    // is a value of 1111 1111 1111 1111 1111 1111 1111 1111
    // That value is represented in int type as -1

    // else
    int size_i = sizeof arr/sizeof arr[0];
    int size_j = sizeof arr[0]/sizeof(int);
    for (int i = 0; i<size_i; ++i) {
        for (int j = 0; j<size_j; ++j) {
            arr[i][j] = 100;
        }
    }
```

### `cin` and `getline`
```c++
    // input: ABC DEF GHI
    string s1, s2;
    cin>>s1;
    getline(cin,s2);
    cout << s1 << '\n' << s2;
    // s1: ABC
    // s2:  DEF GHI
```
#### input buffer: `A` `B` `C` `⠀` `D` `E` `F` `⠀` `G` `H` `I`
<br>

#### `cin` will skip any leading whitespace (tab spaces, carriage returns and blank spaces), then start reading when it comes to the first non-whitespace character and then stop reading when it comes to the next whitespace. 
#### input buffer after call `cin`: `⠀` `D` `E` `F` `⠀` `G` `H` `I`
#### Trailing whitespace left in the input stream, so `getline` extracts characters from <i>input stream</i>, which includes the whitespace.
#### input buffer after call `getline`: `(empty)`
<br>

#### In general, if you want to immediately throw away the whitespace that follows using `cin` to not mess things up when you later use `getline`, then use `cin.ignore()` immediately after a `cin` to discard the next value.
```c++
/*
cin.ignore() // skip a single character

cin.ignore(n, c) where n is an integer and c is a character. 
In this form, characters are skipped until the number skipped 
is equal to n or until the character c is encountered, 
whichever comes first. If the character c is encountered, it 
itself is not skipped. It just triggers the skipping to stop.
*/

    // input: ABC DEF GHI
    string s1, s2;
    cin>>s1;
    cin.ignore();
    getline(cin,s2);
    cout << s1 << '\n' << s2;
    // s1: ABC
    // s2: DEF GHI
```
<br>

---
## Basic form for CP
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
```
### Fast I/O for CP
#### `ios::sync_with_stdio(false);`
##### off the syncronization of all the C++ standard streams with their corresponding standard C streams
<br>

#### `cin.tie(NULL)`
##### disable the flushing of `cout` before `cin` accepts an input
---
## Visual Studio Code Settings
### <i>tasks.json</i>
#### select <i>C/C++: g++ build active file</i> after select <i>Terminal -> Configure Default Build Task...</i>
```text
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "C/C++: g++ build active file",
      "command": "/usr/bin/g++",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}",
        "-std=c++14",
        "-Wall"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "compiler: /usr/bin/g++"
    }
  ]
}
```
<br>

### <i>launch.json</i> for using GDB
#### select <i>Run -> Add configuration...</i>
```text
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Launch",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "/usr/bin/gdb",
      "preLaunchTask": "C/C++: g++ build active file",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ]
    }
  ]
}
```
<br>

### Terminal focus and roll back
#### press `Ctrl + Shift + P` -> select <i>Preferences: Open Keyboard Shortcuts (JSON)</i> 
```text
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
```
<br>

### Disable auto-insert pair brackets
#### press `Ctrl + ,` -> type `Auto Closing Brackets` in `Search settings`
```text
Editor: Auto Closing Brackets
Controls whether the editor should automatically close brackets after the user adds an opening bracket.
: never
```

---
|이전 - 없음|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Array](/array/)|
|-|-|-|
