# Vcpkg Test
Tests for custom vcpkg [toolchains](https://github.com/qis/toolchains).

```sh
make install
make
make run
```

Search for errors, warnings and incorrect library usage in build logs.

```sh
grep -E 'x64-linux-llvm[\\\/]lib[\\\/]' build/x64-linux-llvm-debug.log
grep -E 'x64-linux-llvm[\\\/]debug[\\\/]' build/x64-linux-llvm-release.log
grep -E 'x64-windows-msvc[\\\/]lib[\\\/]' build/x64-windows-msvc-debug.log
grep -E 'x64-windows-msvc[\\\/]debug[\\\/]' build/x64-windows-msvc-release.log
grep -E 'x64-windows-llvm[\\\/]lib[\\\/]' build/x64-windows-llvm-debug.log
grep -E 'x64-windows-llvm[\\\/]debug[\\\/]' build/x64-windows-llvm-release.log
grep -E '(warning|error)' build/*.log
```
