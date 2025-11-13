# Problem-Solving-Lab-Assignment-Submissions

Author: MAYANK DANTRE
Roll: 202401080047
Section: A2- 35

This repository contains C++ solutions organized by topic for lab assignments. Some files are intended to be edited and compiled in Visual Studio Code.

Setup notes to fix IntelliSense (C/C++ extension) and build on Windows
1. Install a C++ compiler (MinGW-w64 or MSYS2 recommended):
	- MSYS2 (recommended): https://www.msys2.org/
	  After installing MSYS2, open the MSYS2 MinGW 64-bit terminal and run:
	  ```powershell
	  pacman -Syu
	  pacman -S mingw-w64-x86_64-toolchain
	  ```
	  Add `C:\msys64\mingw64\bin` to your PATH (System Environment Variables).

	- Or install MinGW-w64 from https://winlibs.com/ and add its `bin` to PATH.

2. Install the C/C++ extension in VS Code (Microsoft). Restart VS Code.

3. Open this workspace in VS Code. If IntelliSense still shows include errors:
	- Open Command Palette (Ctrl+Shift+P) → `C/C++: Edit Configurations (UI)` and set `Compiler path` to your `g++.exe` (for example `C:\msys64\mingw64\bin\g++.exe`).
	- Or edit `.vscode/c_cpp_properties.json` (a sample has been added) and set `compilerPath` to your compiler.

4. Build: use the build task (Ctrl+Shift+B) which runs `g++ -std=c++17 -g ${file} -o ${fileBasenameNoExtension}.exe` on the current file. You can also compile from PowerShell:
```powershell
g++ -std=c++17 -g "path\to\file.cpp" -o "path\to\file.exe"
```

If you prefer MSVC (Visual Studio), configure the C/C++ extension to use MSVC's `cl.exe` as the compiler path.

If IntelliSense errors persist after configuring `compilerPath`, restart VS Code. If you want, I can detect your installed compiler and automatically set `compilerPath` for you — tell me which compiler you have installed or allow me to look for `g++` in PATH.

