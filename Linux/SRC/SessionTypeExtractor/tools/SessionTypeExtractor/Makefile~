##===- projects/sample/tools/sample/Makefile ---------------*- Makefile -*-===##

#
# Indicate where we are relative to the top of the source tree.
#
CLANG_LEVEL := ../../../..

#
# Give the name of the tool.
#
TOOLNAME=SessionTypeExtractor

#
# List libraries that we'll need
# We use LIBS because sample is a dynamic library.
#
LINK_COMPONENTS := all

# No plugins, optimize startup time.
TOOL_NO_EXPORTS = 1

#include $(CLANG_LEVEL)/../../Makefile.config



USEDLIBS = clangFrontend.a clangSerialization.a clangDriver.a \
           clangTooling.a clangParse.a clangSema.a \
           clangStaticAnalyzerFrontend.a clangStaticAnalyzerCheckers.a \
           clangStaticAnalyzerCore.a clangAnalysis.a clangRewriteFrontend.a \
           clangRewriteCore.a clangEdit.a clangAST.a clangLex.a clangBasic.a



include $(CLANG_LEVEL)/Makefile

CXX := clang++
CXXFLAGS+=-std=c++11 -fcxx-exceptions -fexceptions

