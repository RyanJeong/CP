# Visual Studio Code 사용과 관련된 자료들:
## [How can I inspect this slice of this array in gdb?](https://stackoverflow.com/questions/17202794/how-can-i-inspect-this-slice-of-this-array-in-gdb)
```c++
    int x[100'000];
```
```text
    // WATCH in VSCode:
    arr[50]@5 // 5 elements from the index 50
```

## [Visual Studio Code - Convert spaces to tabs](https://stackoverflow.com/questions/36814642/visual-studio-code-convert-spaces-to-tabs)
### press `F1` -> type <i>Preferences: Open Settings (JSON)</i>
```text
// The number of spaces a tab is equal to.
"editor.tabSize": 4,

// Insert spaces when pressing Tab.
"editor.insertSpaces": true,

// When opening a file, `editor.tabSize` and `editor.insertSpaces` will be detected based on the file contents.
"editor.detectIndentation": true
```