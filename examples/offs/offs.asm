; offs.asm - Win32Asm example program for the PeLib library.
; 
; offs.asm converts between RVA and file offsets using the functionality
; of the PeLib library.
;
; Copyright (c) 2004 Sebastian Porst (webmaster@the-interweb.com)
; All rights reserved.
;
; This software is licensed under the zlib/libpng License.
; For more details see http://www.opensource.org/licenses/zlib-license.php
; or the license information file (license.htm) in the root directory 
; of PeLib.

.386
.model flat, stdcall
option casemap : none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\comdlg32.inc
include \masm32\include\user32.inc
includelib \masm32\lib\comdlg32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib

MainWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

MAXSIZE                              equ  511
FNAME_FIELD                          equ 3000
IMGBASE_FIELD                        equ 3001
RVA_FIELD                            equ 3002
OFFS_FIELD                           equ 3003
SNAME_FIELD                          equ 3004

.data
PeLib                                db 'PeLib',0
PeLib_dll                            db 'PeLib.dll',0
PeLib_dll_offset                     dd 0
PeLib_openFile                       db 'PeLib_openFile',0
PeLib_openFile_offset                dd 0
PeLib_closeFile                      db 'PeLib_closeFile',0
PeLib_closeFile_offset               dd 0
PeFile_peHeader                      db 'PeFile_peHeader',0
PeFile_peHeader_offset               dd 0
PeFile_readMzHeader                  db 'PeFile_readMzHeader',0
PeFile_readMzHeader_offset           dd 0
PeFile_readPeHeader                  db 'PeFile_readPeHeader',0
PeFile_readPeHeader_offset           dd 0
PeHeader_offsetToRva                 db 'PeHeader_offsetToRva',0
PeHeader_offsetToRva_offset          dd 0
PeHeader_rvaToOffset                 db 'PeHeader_rvaToOffset',0
PeHeader_rvaToOffset_offset          dd 0
PeHeader_getImageBase                db 'PeHeader_getImageBase',0
PeHeader_getImageBase_offset         dd 0
PeHeader_getSectionWithOffset        db 'PeHeader_getSectionWithOffset',0
PeHeader_getSectionWithOffset_offset dd 0
PeHeader_getSectionName              db 'PeHeader_getSectionName',0
PeHeader_getSectionName_offset       dd 0
DllFailureMessage                    db 'Loading PeLib.dll failed',0
hInstance                            dd 0
dialogfilter                         db "PE Files",0,"*.exe; *.dll",0,0
hexconv                              db "%08X",0
error                                db 'Error',0
PeFile                               dd 0
PeHeader                             dd 0
empty                                db 0
ofn                                  OPENFILENAME <>

.data?
FilenameBuffer                       db 512 dup(?)
buffer                               db 512 dup(?)


.code
start:
	; Load PeLib.dll and get the addresses of all necessary functions.
	call InitializeDll
	test eax, eax
	je @Failure

	invoke GetModuleHandle,0
	mov hInstance, eax

	; Load and display the main window.
	invoke DialogBoxParam, eax, 100, 0, ADDR MainWndProc, 0
	ret

@Failure:
	; Couldn't load the PeLib.dll library.
	invoke MessageBoxA, 0, ADDR DllFailureMessage, ADDR PeLib, 0
	ret

; htodw from Iczelion
htodw proc uses ebx ecx edi edx esi String:DWORD
;------------------------------------
; Convert hex string into dword value
; Return value in eax
;------------------------------------

LOCAL Result:DWORD

	mov Result, 0
	xor ecx, ecx
	mov edi, String
	invoke lstrlen, String
	mov ebx, 16
	mov esi, eax
	
	.while esi != 0
	mov al, [edi]
	.if al >= "0" && al <= "9"
		sub al, "0"
	.elseif al >= "a" && al <= "f"
		sub al, "a"
		add al, 10
	.else
		sub al, "A"
		add al, 10
	.endif
	movzx eax, al
	mov ecx, esi
	dec ecx
	.while ecx > 0
		mul ebx
		dec ecx
	.endw
	add Result, eax
	inc edi
	dec esi
	.endw
	
	mov eax, Result
	ret
htodw endp

; This procedure is called after a file was selected from the OpenFile dialog.
LoadFile proc hWin:DWORD
	cmp PeFile, 0
	je @NoFile

	; If a file is currently open it needs to be closed first.
	; Actually it's only recommended to close it, the other option is a memory leak though.
	push PeFile
	call PeLib_closeFile_offset
	add esp, 4
	
	@NoFile:

	; Open the new file
	push OFFSET FilenameBuffer
	call PeLib_openFile_offset
	add esp, 4
	mov PeFile, eax
	
	; Read the file's MZ header.
	push PeFile
	call PeFile_readMzHeader_offset
	add esp, 4
	
	; It would be great (and recommended) to check if the MZ header is valid by calling the
	; appropriate PeLib functions here. It's not critical though, that's why I decided against it.
	
	; Read the file's PE header.
	push PeFile
	call PeFile_readPeHeader_offset
	add esp, 4
	
	; It would be great (and recommended) to check if the PE header is valid by calling the
	; appropriate PeLib functions here. It's not critical though, that's why I decided against it.

	; Get a pointer to the file's PE header.
	push PeFile
	call PeFile_peHeader_offset
	mov PeHeader, eax
	add esp, 4
	
	; Write the filename to the appropriate text field.
	invoke SetDlgItemTextA, hWin, FNAME_FIELD, ADDR FilenameBuffer

	; Get the file's ImageBase.
	push PeHeader
	call PeHeader_getImageBase_offset
	add esp, 4
	
	; Write the image base to the appropriate text field.
	invoke wsprintfA, ADDR buffer, ADDR hexconv, eax
	invoke SetDlgItemTextA, hWin, IMGBASE_FIELD, ADDR buffer
	ret
LoadFile endp

ConvertOffset proc offs:DWORD, conversion:DWORD
	push offs
	push PeHeader
	.IF conversion == 0 ; RVA => File offset
		call PeHeader_rvaToOffset_offset
	.ELSE ; File offset => RVA
		call PeHeader_offsetToRva_offset
	.ENDIF
	add esp, 8
	ret
ConvertOffset endp

GetOffset proc hWin:DWORD, hwnd:DWORD, buff:DWORD
	invoke GetDlgItemTextA, hWin, hwnd, buff, 9
	invoke htodw, buff
	ret
GetOffset endp

GetSection proc offs:DWORD, buff:DWORD
	push offs
	push PeHeader
	call PeHeader_getSectionWithOffset_offset
	add esp, 8
	
	; A return value of 0xFFFF means it's outside of any section. That means it's an offset in the header
	; because if it's not an offset from any section or the header the above call to rvaToOffset would
	; have returned -1. Note again: The return value of -1 from getSectionWithOffset once again only
	; indicates an error with a certainty of 99.9999999% (or something). A return value of 0xFFFF (= -1)
	; could also mean the offset is in the 65535th section of the file. It is however rare enough to find
	; a file with more than 12-15 sections, I am not even sure if a file with 65535 sections is even
	; accepted by the PE loader.
	cmp ax, -1
	je @OffsetToRvaNoSection

	; Get the name of the section.
	push 9 ; Buffer size. The buffer is actually larger than that but section names are max 8 bytes long.
	push buff
	push eax
	push PeHeader
	call PeHeader_getSectionName_offset
	add esp, 16
	ret

@OffsetToRvaNoSection:
	mov eax, -1
	ret
GetSection endp

; Message loop of the main window.
MainWndProc proc uses ebx hWin:DWORD, uMsg: DWORD, wParam: DWORD, lParam: DWORD
	; Terminate the process if the window is being closed.
	.IF uMsg == WM_CLOSE
		invoke ExitProcess, 0
		mov eax, 1
		ret

	; Handle the user input.
	.ELSEIF uMsg == WM_COMMAND
		mov eax, wParam
		.IF lParam == 0 ; Menu input
			call ChooseFile
		 	.IF eax != 0
		 		invoke LoadFile, hWin
		 	.ENDIF
		.ELSEIF (ax == RVA_FIELD)
			shr eax, 16
			.IF ax == EN_CHANGE && PeHeader != 0 ; RVA was changed.
				invoke GetFocus
				push eax
				invoke GetDlgItem, hWin, RVA_FIELD
				pop ebx
				.IF eax == ebx
					invoke GetOffset, hWin, RVA_FIELD, ADDR buffer
					invoke ConvertOffset, eax, 0
					.IF eax != -1
						push eax

						invoke wsprintfA, ADDR buffer, ADDR hexconv, eax
						invoke SetDlgItemTextA, hWin, OFFS_FIELD, ADDR buffer
						
						pop eax
						invoke GetSection, eax, ADDR buffer
						.IF eax != -1
							invoke SetDlgItemTextA, hWin, SNAME_FIELD, ADDR buffer
						.ELSEIF
							invoke SetDlgItemTextA, hWin, SNAME_FIELD, ADDR empty
						.ENDIF
						
					.ENDIF
				.ENDIF
			.ENDIF
		.ELSEIF (ax == OFFS_FIELD)
			shr eax, 16
			.IF ax == EN_CHANGE && PeHeader != 0 ; Offset was changed.
				invoke GetFocus
				push eax
				invoke GetDlgItem, hWin, OFFS_FIELD
				pop ebx
				.IF eax == ebx
					invoke GetOffset, hWin, OFFS_FIELD, ADDR buffer
                              push eax
					invoke ConvertOffset, eax, 1
					.IF eax != -1
						invoke wsprintfA, ADDR buffer, ADDR hexconv, eax
						invoke SetDlgItemTextA, hWin, RVA_FIELD, ADDR buffer

                                    pop eax
						invoke GetSection, eax, ADDR buffer
						.IF eax != -1
							invoke SetDlgItemTextA, hWin, SNAME_FIELD, ADDR buffer
						.ELSEIF
							invoke SetDlgItemTextA, hWin, SNAME_FIELD, ADDR empty
						.ENDIF
                              .ELSEIF
                                    pop eax
					.ENDIF
				.ENDIF
		 	.ENDIF
		.ENDIF
		mov eax, 1
	.ENDIF
	xor eax,	eax
	ret
MainWndProc endp

; Let the user choose a file.
ChooseFile proc
	mov ofn.lStructSize,SIZEOF ofn 
	push hInstance 
	pop ofn.hInstance
	mov ofn.lpstrFilter, OFFSET dialogfilter
	mov ofn.lpstrFile, OFFSET FilenameBuffer 
	mov ofn.nMaxFile,MAXSIZE
	mov ofn.Flags, OFN_FILEMUSTEXIST or \
		OFN_PATHMUSTEXIST or OFN_LONGNAMES or\
		OFN_EXPLORER or OFN_HIDEREADONLY
	invoke GetOpenFileName, ADDR ofn
ret
ChooseFile endp

; Initialize the PeLib DLL and all necessary functions. Returns 0 if an error occured, otherwise 1.
InitializeDll proc
	invoke LoadLibrary, ADDR PeLib_dll
	test eax,	eax
	je @DllFailure

	mov PeLib_dll_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeLib_openFile
	test eax,	eax
	je @DllFailure
	mov PeLib_openFile_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeLib_closeFile
	test eax,	eax
	je @DllFailure
	mov PeLib_closeFile_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeFile_readMzHeader
	test eax,	eax
	je @DllFailure
	mov PeFile_readMzHeader_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeFile_readPeHeader
	test eax,	eax
	je @DllFailure
	mov PeFile_readPeHeader_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeHeader_offsetToRva
	test eax,	eax
	je @DllFailure
	mov PeHeader_offsetToRva_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeHeader_rvaToOffset
	test eax,	eax
	je @DllFailure
	mov PeHeader_rvaToOffset_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeHeader_getImageBase
	test eax,	eax
	je @DllFailure
	mov PeHeader_getImageBase_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeHeader_getSectionWithOffset
	test eax,	eax
	je @DllFailure
	mov PeHeader_getSectionWithOffset_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeHeader_getSectionName
	test eax,	eax
	je @DllFailure
	mov PeHeader_getSectionName_offset, eax

	invoke GetProcAddress, PeLib_dll_offset, ADDR PeFile_peHeader
	test eax,	eax
	je @DllFailure
	mov PeFile_peHeader_offset, eax

	mov eax,	1
	ret

@DllFailure:
	xor eax,	eax
	ret
InitializeDll endp
	
ret
end start