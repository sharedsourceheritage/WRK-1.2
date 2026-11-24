
TextInterpreterps.dll: dlldata.obj TextInterpreter_p.obj TextInterpreter_i.obj
	link /dll /out:TextInterpreterps.dll /def:TextInterpreterps.def /entry:DllMain dlldata.obj TextInterpreter_p.obj TextInterpreter_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TextInterpreterps.dll
	@del TextInterpreterps.lib
	@del TextInterpreterps.exp
	@del dlldata.obj
	@del TextInterpreter_p.obj
	@del TextInterpreter_i.obj
