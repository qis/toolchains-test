# Vcpkg Test
Tests for custom vcpkg [toolchains](https://github.com/qis/toolchains).

## Linux
Install dependencies.

```cmd
make overlay=/opt/ports triplet=x64-linux-llvm install
```

Run tests.

```cmd
make triplet=x64-linux-llvm && make triplet=x64-linux-llvm run
```

## Windows
Install dependencies.

```cmd
make overlay=C:/Workspace/ports triplet=x64-windows-msvc install
make overlay=C:/Workspace/ports triplet=x64-windows-llvm install
```

Run tests.

```cmd
make triplet=x64-windows-msvc && make triplet=x64-windows-msvc run
make triplet=x64-windows-llvm && make triplet=x64-windows-llvm run
```
