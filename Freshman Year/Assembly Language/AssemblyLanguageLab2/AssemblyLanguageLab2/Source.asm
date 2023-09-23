;Program Description: Encrypts and decrypts a user-inputted message using a user-inputted encryption key and displays the original, encrypted, and decrypted versions of the message
;Author: Justin Dady
;Date: 3/31/2020

INCLUDE irvine32.inc



maxCharacters = 30

.data
	welcomeMessage BYTE "Welcome! This program encrypts and decrypts a message that you enter.", 0Ah, 0Dh, 0
	askForUserMessage BYTE "Enter a message that you would like to encrypt that consists of 30 or less characters: ", 0Ah, 0Dh, 0
	askForKey BYTE "Enter the key that contains 30 or characters less that you would like to use to encrypt your message: ", 0Ah, 0Dh, 0
	userMessage BYTE maxCharacters + 1 DUP (0)
	userKey BYTE maxCharacters + 1 DUP (0)
	messageSize DWORD ?
	keySize DWORD ?
	printMessage BYTE "Your message is: ", 0
	printEncryptedMessage BYTE "Your encrypted message is: ", 0
	printDecryptedMessage BYTE "Your decrypted message is: ", 0
	blankLine BYTE 0Dh, 0AH, 0
.code

Encrypt PROTO

main PROC
	MOV EDX, OFFSET welcomeMessage
	CALL WriteString

	MOV EDX, OFFSET askForUserMessage
	CALL WriteString

	MOV ECX, maxCharacters 

	MOV EDX, OFFSET userMessage
	CALL ReadString

	MOV messageSize, EAX

	MOV EDX, OFFSET askForKey
	CALL WriteString

	MOV ECX, maxCharacters

	MOV EDX, OFFSET userKey
	CALL ReadString

	MOV keySize, EAX

	MOV EDX, OFFSET printMessage
	CALL WriteString

	MOV EDX, OFFSET userMessage
	CALL WriteString

	MOV EDX, OFFSET blankLine
	CALL WriteString

	CALL Encrypt

	MOV EDX, OFFSET printEncryptedMessage
	CALL WriteString

	MOV EDX, OFFSET userMessage
	CALL WriteString

	MOV EDX, OFFSET blankLine
	CALL WriteString

	CALL Encrypt

	MOV EDX, OFFSET printDecryptedMessage
	CALL WriteString

	MOV EDX, OFFSET userMessage
	Call WriteString

	MOV EDX, OFFSET blankLine
	CALL WriteString

	INVOKE ExitProcess,0

main ENDP

;-------------------------------------------------------------
Encrypt PROC
; Encrypts/decrypts a message using an encryption key
; Receives: userMessage and userKey as string variables 
;			messageSize and keySize as DWORD unsigned ints
; Returns: An encrypted or decrypted version of userMessage
;-------------------------------------------------------------
	MOV ECX, messageSize
	MOV ESI, 0
	MOV EDI, 0
L1:
	MOV AL, userKey[EDI]
	XOR userMessage[ESI], AL
	INC ESI
	INC EDI
	CMP EDI, keySize
	JE ResetEDI
	LOOP L1
	JMP Quit

ResetEDI:
	MOV EDI, 0
	LOOP L1
Quit: 
	ret

Encrypt ENDP

END main

