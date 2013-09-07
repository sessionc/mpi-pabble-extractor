The file with name 'LIB_SEARCH_PATH.txt' is used to hold the library search paths. This may include MPI header files, std c library include path or LLVM build root/lib/clang/3.4/include;


The app can be started at console, feeding the argument of file name and optionally number of processes.

For example, 

'SessionTypeExtractor4MPI.exe -src test.c -n 3' will make the application analyse the source code test.c in a configuration where the number of processes is 3.

If multiple source files are referenced by the main file, then they can be analysed by the command 'SessionTypeExtractor4MPI.exe -src "main.c;other1.c;other2.c...;othern.c" -n 3'.
 The file with main function must be placed at the beginning.


