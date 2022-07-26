.global stop

stop:	
   bl stop 
   
.global reset 

reset:
   ldr sp , =stack_top 
   bl main 
   bl stop 
   
