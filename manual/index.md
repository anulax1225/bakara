\mainpage Bakara Manual

## Build
On windows, make sure you have ms-compiler for C++.<br>
Then write commands :
```bash
	git clone https://github.com/anulax/bakara
	git submodule init
	git submodule update
	.\vendor\premake5 vs2022
	dotnet build
	dotnet run
```
Or use vs2022 to build your project.

---
On linux (if you don't have premake5, install it with your distro's packet manager). You have two env variable to change build proccess :

| Name        | Value	    |
| ----------- | ----------- |
| autoexec    | 0/1         |
| clearbin    | 0/1         |

Then write commands :

```bash
	git clone https://github.com/anulax/bakara
	git submodule init
	git submodule update
	(export clearbin=1 autoexec=1)
	./build.sh config=release
```
---
## Tuto
(to do)
