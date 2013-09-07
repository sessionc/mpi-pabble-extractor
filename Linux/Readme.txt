If you want to execute the application directly, then there is an executable in the archive.

If you want to recompile the program, then
decompress the archive and copy the folder with name 'SessionTypeExtractor' to 
/your LLVM src root/tools/clang/tools 

Then open the terminal and 'cd' to 'SessionTypeExtractor' directory.  Then type make. 

The resulting app is produced in the Debug+Assert folder in the LLVM source root directory.

The execution method is the same as that of windows.
You need to specify the library search path in the LIB_SEARCH_PATH.txt file. Different path names are separated by ';'. At least the C std lib, MPI library path and the directory 'LLVM build root/lib/clang/clangVersionNumber/include'; need to be specified.  