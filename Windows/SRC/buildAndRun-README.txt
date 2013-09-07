If you want to compile the windows app from source code, then you need visual studio 2012 and LLVM installed on your machine. It is suggested that LLVM should be built using debug mode. The include paths are LLVM and clang's include folder. The linker's input path is: LLVM's build path/lib/Debug/*.lib

