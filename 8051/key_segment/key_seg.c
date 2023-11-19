ORG 0000H
	
MOV DPTR,#look_up_table 

MOV A,#0FFh

MOV P1,#00000000B 

reverse:MOV P3,#0FFh 
     CLR P3.0 
     JB P3.4,next_find_1  
     MOV A,#0D  
     ACALL disp_000  
next_find_1:JB P3.5,next_find_2 
      MOV A,#1D
      ACALL disp_000
next_find_2:JB P3.6,next_find_3
      MOV A,#2D
      ACALL disp_000
next_find_3:JB P3.7,next_find_4
      MOV A,#3D
      ACALL disp_000
next_find_4:SETB P3.0
      CLR P3.1
      JB P3.4,next_find_5
      MOV A,#4D
      ACALL disp_000
next_find_5:JB P3.5,next_find_6
      MOV A,#5D
      ACALL disp_000
next_find_6:JB P3.6,next_find_7
      MOV A,#6D
      ACALL disp_000
next_find_7:JB P3.7,next_find_8
      MOV A,#7D
      ACALL disp_000
next_find_8:SETB P3.1
      CLR P3.2
      JB P3.4,NEXT9
      MOV A,#8D
      ACALL disp_000
NEXT9:JB P3.5,next_find_10
      MOV A,#9D
      ACALL disp_000
next_find_10:JB P3.6,next_find_11
       MOV A,#10D
       ACALL disp_000
next_find_11:JB P3.7,next_find_12
       MOV A,#11D
       ACALL disp_000
next_find_12:SETB P3.2
       CLR P3.3
       JB P3.4,next_find_13
       MOV A,#12D
       ACALL disp_000
next_find_13:JB P3.5,next_find_14
       MOV A,#13D
       ACALL disp_000
next_find_14:JB P3.6,next_find_15
       MOV A,#14D
       ACALL disp_000
next_find_15:JB P3.7,reverse
       MOV A,#15D
       ACALL disp_000
       LJMP reverse

disp_000:MOVC A,@A+DPTR 
        MOV P1,A       
        RET

look_up_table: 
     
     DB 11100000B
     DB 11111110B
     DB 11110110B
     DB 10011100B
     DB 01100110B
     DB 10110110B
     DB 10111110B
     DB 00111110B
     DB 01100000B 
     DB 11011010B
     DB 11110010B
     DB 11101110B
     DB 10011110B
     DB 11111100B
     DB 10001110B
     DB 01111010B
     END