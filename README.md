
### 1.C++11例程。
在Linux编译这些例程的命令:
$ make -f Makefile.linux
需要注意的是你的编译器必须支持C++11标准。例如:
clang++ -std=c++11 sourcefile.cc -o sourcefile 
或者
g++ -std=c++11 sourcefile.cc -o sourcefile 

