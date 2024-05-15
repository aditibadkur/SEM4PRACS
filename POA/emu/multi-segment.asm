DATA SEGMENT 
    SEG1 DB 3, 4, 5
    LEN DW $-SEG1
DATA ENDS 

EXTRA SEGMENT
    SEG2 DB ?
EXTRA ENDS

CODE SEGMENT
    ASSUME CS: CODE, DS: DATA
    
    START: MOV AX, DATA
    MOV DS, AX
    
    MOV AX, EXTRA
    MOV ES, AX         
    
    LEA SI, SEG1
    LEA DI, SEG2    
      
    MOV CX, LEN
    REPEAT: MOV AL, DS:[SI]
    MOV ES:[DI], AL   
    
    INC SI
    INC DI
    LOOP REPEAT  
    INT 3
    
CODE ENDS
END START
    
    