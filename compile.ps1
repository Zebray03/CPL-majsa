# 使用 Windows 下的 VS Code 的同学可以在 PowerShell 终端中运行此脚本来编译 majsa
git add -A
git commit --allow-empty -m "compile"
gcc $(Get-ChildItem -Recurse "./src" -Filter "*.c" | ForEach-Object { $_.FullName }) -std=c17 -lm -march=native -O2 -fno-strict-aliasing -Wall -DONLINE_JUDGE -fdiagnostics-color=always -o majsa