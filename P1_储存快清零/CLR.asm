ORG 0000H
LJMP START
       ORG 0030H
START: MOV 30H,#10H
MOV 31H,#11H
MOV 32H,#12H
       MOV 33H,#13H
       MOV 34H,#14H
       MOV 35H,#15H
       MOV 36H,#16H
       MOV 37H,#17H
       MOV 38H,#18H
       MOV 39H,#19H
       MOV R0,#30H
LOOP1: CLR A
MOV @R0,A
INC R0
       CJNE R0,#3AH,LOOP1
       END