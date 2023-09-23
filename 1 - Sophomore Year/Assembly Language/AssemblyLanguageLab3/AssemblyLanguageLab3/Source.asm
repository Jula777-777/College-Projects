INCLUDE irvine32.inc


.data
	welcomeMessage BYTE "Welcome! This program permutates an array of any size.", 0Ah, 0Dh, 0
	askForArraySize BYTE "Please enter the size of the array: ", 0
	askToInputArray1 BYTE "Please enter the ", 0
	askToInputArray2 BYTE " elements in your array (press enter after each element): ", 0AH, 0Dh, 0
	askToInputPermutation BYTE "Please enter the permutation (press enter after each element): ", 0Ah, 0Dh, 0
	printResult BYTE "The array after permutation is: ", 0Ah, 0Dh, 0
	space BYTE " ", 0
	array DWORD 30 DUP(?)
	permutation DWORD 30 DUP(?)
	arraySize DWORD ?
.code
main PROC
	MOV EDX, OFFSET welcomeMessage
	CALL WriteString

	MOV EDX, OFFSET askForArraySize
	CALL WriteString

	CALL ReadDec
	MOV arraySize, EAX

	MOV EDX, OFFSET askToInputArray1
	CALL WriteString

	MOV EAX, arraySize
	CALL WriteDec

	MOV EDX, OFFSET askToInputArray2
	CALL WriteString

	MOV ECX, arraySize
	MOV ESI, 0
InputArray:
	CALL ReadDec
	MOV array[ESI], EAX
	ADD ESI, TYPE array
	LOOP inputArray

	MOV EDX, OFFSET askToInputPermutation
	CALL WriteString

	MOV ECX, arraySize
	MOV ESI, 0
InputPermutation:
	CALL ReadDec
	MOV permutation[ESI], EAX
	ADD ESI, TYPE permutation
	LOOP inputPermutation


	MOV ECX, arraySize
	SUB ECX, 1
	MOV EBX, 0
	MOV EBP, 0
OuterLoop:
	MOV EAX, permutation[EBX]
	MOV EDI, array[EAX * TYPE array]
	XCHG array[EBX], EDI
	MOV array[EAX * TYPE array], EDI
	PUSH ECX
	MOV ECX, arraySize
	SUB ECX, 1
	SUB ECX, EBP
	MOV EDX, EBX
	ADD EDX, TYPE array
	JMP InnerLoop
InnerLoop:
	CMP EBP, permutation[EDX]
	JE IfStatement
	ADD EDX, TYPE permutation
	LOOP InnerLoop
	JMP RestartLoop
IfStatement:
	MOV ESI, permutation[EDX]
	XCHG permutation[EBX], ESI
	MOV permutation[EDX], ESI
	JMP RestartLoop
RestartLoop:
	POP ECX
	ADD EBX, TYPE array
	INC EBP
	LOOP OuterLoop


	MOV EDX, OFFSET printResult
	CALL WriteString
	
	MOV ECX, arraySize
	MOV ESI, 0
printArray:
	MOV EAX, array[ESI]
	CALL WriteDec
	MOV EDX, OFFSET space
	CALL WriteString
	ADD ESI, TYPE array
	LOOP printArray

	INVOKE ExitProcess,0

main ENDP

END main