PUBLIC mul ; export 'mul' to the outside world
RSEG CODE ; this is a relocatable segment containing code

mul: ; entry point to the function
  mov R12,R14 ; utilis� pour incr�menter R12
loop:
  sub #1,R13 ; on teste si on a fait le bon nombre d'it�rations
  jz fin ; si oui, on sort de la fonction
  add R14,R12
  jmp loop
fin:
  ret
  
END