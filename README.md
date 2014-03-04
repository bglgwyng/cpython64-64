# CPython64/64


## Introduction

This is CPython64/64, which according to PyPy's Windows documentation, is an
implementation of CPython that has `sys.maxint == sys.maxsize == 2 ** 63 - 1`
even on Win64. This implementation is made by running several phases of `sed`
on the vanilla codebase of CPython 2.7.6, then hand-tuned to fix compilation
errors, format string inconsistencies, test case failures and the like. It can
pass almost all of CPython test suite, but the remaining failures are minor
enough that they do not affect running PyPy.

Original README file can be found at `README.original`.


## Building

Since CPython64/64 is only meant to help porting PyPy to Win64, only 64-bit
Windows is supported. It is known to build under Visual Studio 2010's 64-bit
toolchain, and likely VS2008 as well (not tested). The build procedure is the
same as vanilla CPython's.


## Progress

CPython64/64 currently can pass a major portion of tests, the only remaining
ones are:

    test_ctypes test_distutils test_import test_macpath
    test_multiprocessing test_ntpath test_posixpath

Of these failing tests, the three path-related tests also fail on regular
CPython with mysterious encoding errors; `test_import` fails due to some UNC
path handling error. Finally, `test_ctypes` and `test_distutils` failures are
somewhat expected but unrelated to PyPy.

So far, CPython64/64 can run PyPy, but translation has not been attempted yet.
Now anyone willing to contribute to PyPy on Win64 can step up and move on!


<!-- vim:set ai et ts=4 sw=4 sts=4 fenc=utf-8: -->
