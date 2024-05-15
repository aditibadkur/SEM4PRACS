DATA SEGMENT
    STRING1 DB 33H, 6H, 89H, 1H
DATA ENDS

CODE SEGMENT
    ASSUME CS: CODE, DS:DATA
    
    START: MOV AX, DATA
    MOV DS, AX
    
    MOV CH, 04H
    
    UP1: MOV CL, 04H
    LEA SI, STRING1
    
    UP2: MOV AL, [SI]
    MOV BL, [SI+1]
    CMP AL, BL       ; AL-BL (if AL<BL carry is generated)
    JC DOWN          
    MOV DL, [SI+1]   
    XCHG DL, [SI]    ; value[1]=AL -> DL, value[2]=BL -> SI
    MOV [SI+1], DL  
    
    DOWN: INC SI
    DEC CL
    JNZ UP2 
    DEC CH
    JNZ UP1          
    
CODE ENDS
END START