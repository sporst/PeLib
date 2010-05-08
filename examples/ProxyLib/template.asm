.386
.model flat, stdcall
option casemap:none

include		\masm32\include\windows.inc
include		\masm32\include\kernel32.inc
includelib	\masm32\lib\kernel32.lib

.data
OldDll				db '%OLDDLL%',0
OldDllHandle		dd 0

%NAMESTRING%
%ORDINALSTRING%

.code

DllEntry proc hinst:HINSTANCE, reason:DWORD, reserved1:DWORD
	.IF reason == DLL_PROCESS_ATTACH
		pushad
		call InitializeOldDll
		test eax, eax
		popad
		je @ret
		mov eax, 1
	.ENDIF
@ret:
	ret
DllEntry endp

InitializeOldDll proc
	invoke LoadLibrary, ADDR OldDll
	.IF eax == 0
		ret
	.ENDIF
	
	mov OldDllHandle, eax
	
	mov ebx, OFFSET Ordinals + 4
	.while dword ptr[ebx] != 0
		invoke GetProcAddress, OldDllHandle, dword ptr [ebx]
		mov dword ptr [ebx], eax
		add ebx, 4
	.endw
	
@ret:
	ret

InitializeOldDll endp

%FUNCTIONS%

End DllEntry