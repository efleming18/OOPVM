; Put data in registers
; Set r1 to 12
Addi r1, r0, 0x0000000C
; Set r2 to 24
Add r2, r1, r1
; Multiply r2 by 2, r3 should be 48
Multi r3, r2, 0x00000002
; Store data to memory
Write_mem numC, r3      
; stop execution
Syscall 0