DATA SEGMENT
    N DB 5   
    fact DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS: CODE, DS: DATA
    
    START: MOV AX, DATA
    MOV DS, AX     
    MOV AH, 00H
    MOV AL, N
    
    REPEAT: DEC N 
    MUL N     
    CMP N, 01     
    JNZ REPEAT 
    
    MOV fact, AL
    
CODE ENDS
END START

    