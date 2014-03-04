@rem Used by the buildbot "buildmsi" step.

cmd /c Tools\buildbot\external-amd64.bat
@rem build release versions of things
call "%VS100COMNTOOLS%vsvars32.bat" x86_amd64

@rem build Python
cmd /c PCbuild\build.bat

@rem build the documentation
bash.exe -c 'cd Doc;make PYTHON=python update htmlhelp'
"%ProgramFiles(x86)%\HTML Help Workshop\hhc.exe" Doc\build\htmlhelp\python276.hhp

@rem build the MSI file
cd PC
nmake /f icons.mak
cd ..\Tools\msi
del *.msi
nmake /f msisupport.mak
%HOST_PYTHON% msi.py
