@rem Used by the buildbot "compile" step.
set HOST_PYTHON="%CD%\PCbuild\amd64\python.exe"
cmd /c Tools\buildbot\external-amd64.bat
call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
cmd /c Tools\buildbot\clean-amd64.bat
msbuild /useenv PCbuild\kill_python.vcproj "Release|x64" && PCbuild\amd64\kill_python.exe
msbuild PCbuild\pcbuild.sln "Release|x64"
