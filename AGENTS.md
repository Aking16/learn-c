# learn-c

Small collection of standalone C practice programs. No build system, no tests, no lint/format config.

## Layout

- Each subdirectory (`vars/`, `scanf/`, ...) is an independent program with its own `main.c`.
- Programs do not share code. Do not add a shared build unless asked.
- Build artifacts (`.exe`) sit next to the source and are gitignored.

## Build and run

Compiler is MinGW GCC. The VS Code task uses `C:\MinGW\bin\gcc.exe`; plain `gcc` also works on PATH.

```powershell
gcc -std=c11 -Wall -Wextra -o main.exe main.c
.\main.exe
```

The default VS Code build task compiles the active file to `<same-name>.exe` in the same directory.

## Gotchas

- Most programs read stdin with `scanf`; running them without piped input blocks waiting for input.
- There are no tests. Verify by compiling with `-Wall -Wextra` and running with sample input.
- Windows/PowerShell environment: use `.\\main.exe`, not `./main.exe`.

## Config

- `../opencode.json` configures the `iranrouter` provider; it applies to the whole `learn-c` tree.
- `../.env` holds `IRANROUTER_API_KEY` and is gitignored. Never print or commit it.
