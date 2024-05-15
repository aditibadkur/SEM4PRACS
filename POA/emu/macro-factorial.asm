factorial MACRO N
    REPEAT: DEC N
    MUL N
    CMP N, 01H
    JNZ REPEAT
ENDM

DATA SEGMENT 
    N DB 5
    fact DB ?
DATA ENDS     

STACK SEGMENT
    DW 128 dup(0)
STACK ENDS

CODE SEGMENT
    START: MOV AX, DATA
    MOV DS, AX
    
    MOV AL, N
    factorial N
       
    MOV fact, AL  
         
CODE ENDS
END START

