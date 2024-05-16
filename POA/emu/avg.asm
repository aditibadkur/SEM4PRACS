DATA SEGMENT
    ARR DB 1H, 2H, 3H, 4H, 5H  
    LEN DW $-ARR
    AVG DW ?
DATA ENDS

CODE SEGMENT
         ASSUME CS:CODE, DS:DATA
         START: MOV AX, DATA
         MOV DS, AX
         
         LEA SI, ARR   
         
         MOV CX, LEN
         MOV AH, 00
         MOV AL, 00
         
         REPEAT: MOV DL, [SI]
         ADD AL, DL
         INC SI
         LOOP REPEAT
         
         MOV CX, LEN
         DIV CL
         MOV AVG, AX    
         
         MOV AH, 4CH
         INT 21H         
         
CODE ENDS
END START
