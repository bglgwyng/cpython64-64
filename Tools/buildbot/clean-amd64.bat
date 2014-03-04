@rem Used by the buildbot "clean" step.
call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
@echo Deleting .pyc/.pyo files ...
del /s Lib\*.pyc Lib\*.pyo
@echo Deleting test leftovers ...
rmdir /s /q build
cd PCbuild
msbuild /clean pcbuild.sln "Release|x64"
msbuild /clean pcbuild.sln "Debug|x64"
cd ..
