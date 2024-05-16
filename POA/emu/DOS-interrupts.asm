DATA SEGMENT
    MSG DW "Enter a character:$"
DATA ENDS    

CODE SEGMENT
    ASSUME CS: CODE, DS: DATA
    START: MOV AX, DATA
    MOV DS, AX  
    
    LEA SI, MSG
    
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H     
    
    MOV DL, AL
    
    MOV AH, 02H
    INT 21H
    
    MOV AH, 4CH
    INT 21H
    
CODE ENDS
END START