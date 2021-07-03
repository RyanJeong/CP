# Visual Studio Code 사용과 관련된 자료들:
## [How can I inspect this slice of this array in gdb?](https://stackoverflow.com/questions/17202794/how-can-i-inspect-this-slice-of-this-array-in-gdb)
```c++
    int x[100'000];
```
```text
    // WATCH in VSCode:
    arr[50]@5 // 5 elements from the index 50
```