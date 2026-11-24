Quick babel installation guide
------------------------------

If you have the babelpackage already installed:
- go to the folder containing babelpackage.dll
- run "regsvr32 /u babelpackage.dll"
- delete "babelpackage.dll" and "babelservice.tlb"
- install the new babelpackage in the *same* folder

Installing the babelpackage:
- get "babelpackage.dll" and "babelservice.tlb" from either the
  debug or release directory.
- put them together in a folder on your system.
- run "regsvr32 babelpackage.dll"

Disable security settings of VS7
- run "setupsecurity.exe" on your system

Install the babel client SDK:
- copy the "client" directory to your system.
- documentation can be found in "client\doc" on how to get started. 
- if you know what you doing, just open "client\myc\bservice.dsw" 
  and hit "F5" to play with myc.  (or forth :-)
- you might need to build the common library first; just open
  "client\common\common.dsw" and click "build - batch build - build all"
 
