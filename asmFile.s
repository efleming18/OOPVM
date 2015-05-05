.data     
; start of data space
numA:   .word   12
numB:   .word   24
numC:   .word   0

.text
; start of code space
main:   
        ; Load data
        Read_mem r1, numA
        Read_mem r2, numB

        ;Add numbers together
        Add r3, r1, r2

        ; Store data back
        Write_mem numC, r3

        
        ; stop execution
        Syscall 0