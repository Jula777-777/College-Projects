;Program Description: The program asks the user to input three integers and then it subtracts them. The program repeats this process in an infinite loop.
;Author: Justin Dady
;Date: 2/27/2020							

INCLUDE irvine32.inc

.data
	welcomeMessage BYTE "Welcome! This program subtracts integer numbers.", 0Ah, 0Dh, 0
	askForInput BYTE "Please input three integers x, y, and z: ", 0AH, 0Dh, 0
	result DWORD 0d
	resultString BYTE "The result of (x - y - z) is: ", 0
.code
main PROC
infiniteLoop:
	MOV EDX, OFFSET welcomeMessage
	CALL WriteString

	MOV EDX, OFFSET askForInput
	CALL WriteString

	CALL ReadDec
	MOV result, EAX

	MOV ECX, 2d
readInputAndSubtract:
	CALL ReadDec
	SUB result, EAX

	LOOP readInputAndSubtract	

	MOV EDX, OFFSET resultString
	CALL WriteString

	MOV EAX, result
	CALL WriteDec

	CALL Crlf

	CALL WaitMsg
	CALL Clrscr

	JMP infiniteLoop
	
	INVOKE ExitProcess,0
main ENDP

END main