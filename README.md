# Bakara project

## Resume

## Generate doc
To generate the documentation using doxygen, <a>install</a> it from there website for your plaform.
Then write commands : 
```bash
	cd dirs/to/bakara  
	doxygen
```

## Prerequiste
* A video/graphics card that supports OpenGL.
### Windows
* C++ ms-compiler for Windows
### Linux
* GCC compiler suite.

## Build
### Windows
On windows, write commands :
```batch
	cd C:\Users\username
	git clone https://github.com/anulax/bakara
	git submodule init
	git submodule update
	.\vendor\premake5 vs2022
	dotnet build
	dotnet run
```
Or use visual studio 2022 to build your project.
### Linux
---
On linux (if you don't have premake5, install it with your distro's packet manager). You have two env variable to change build proccess :

| Name        | Value	    |
| ----------- | ----------- |
| autoexec    | 0/1         |
| clearbin    | 0/1         |

Then write commands :
```bash
	cd ~/
	git clone https://github.com/anulax/bakara
	git submodule init
	git submodule update
	(export clearbin=1 autoexec=1)
	./build.sh config=release
```

## Getting started
(to do)