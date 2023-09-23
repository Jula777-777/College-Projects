;Author: Justin Dady
;Date: 4/23/2020						

INCLUDE irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

maxCharacters = 30

.data
	welcomeMessage BYTE "Welcome! This program determines whether a string that you enter is a valid hexadecimal constant in MASM syntax.", 0Ah, 0Dh, 0
	askForInput BYTE "Enter your string:", 0Ah, 0Dh, 0
	userInput BYTE maxCharacters + 1 DUP(0)
	validMessage BYTE "Valid Hexadecimal Constant", 0Ah, 0Dh, 0
	invalidMessage BYTE "Invalid Hexadecimal Constant", 0Ah, 0Dh, 0

.code

main PROC

	MOV EDX, OFFSET welcomeMessage
	CALL WriteString

	MOV EDX, OFFSET askForInput
	CALL WriteString

	MOV ECX, maxCharacters
		
	MOV EDX, OFFSET userInput
	CALL ReadString

	MOV ESI, 0
	MOV EAX, 0

StateA:
	MOV AL, userInput[ESI]

	CALL IsDigit
	JZ StateB

	JMP Invalid

StateB:
	INC ESI
	MOV AL, userInput[ESI]

	CALL IsDigit
	JZ StateB

	CMP AL, "A"
	JE StateB

	CMP Al, "B"
	JE StateB

	CMP AL, "C"
	JE StateB

	CMP AL, "D"
	JE StateB

	CMP AL, "E"
	JE StateB

	CMP AL, "F"
	JE StateB

	CMP AL, "h"
	JE StateC

	JMP Invalid

StateC:
	INC ESI
	MOV AL, userInput[ESI]

	CMP AL, 0
	JE Valid

	JMP Invalid

Invalid:
	MOV EDX, OFFSET invalidMessage
	CALL WriteString

	JMP Quit

Valid:
	MOV EDX, OFFSET validMessage
	CALL WriteString

Quit:
	INVOKE ExitProcess,0

main ENDP

END main