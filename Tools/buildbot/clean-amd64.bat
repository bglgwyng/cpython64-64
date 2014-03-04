@rem Used by the buildbot "clean" step.
call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
@echo Deleting .pyc/.pyo files ...
del /s Lib\*.pyc Lib\*.pyo
@echo Deleting test leftovers ...
rmdir /s /q build
cd PCbuild
msbuild pcbuild.sln /t:Clean /p:Configuration=Release;Machine=x64
msbuild pcbuild.sln /t:Clean /p:Configuration=Debug;Machine=x64
cd ..
