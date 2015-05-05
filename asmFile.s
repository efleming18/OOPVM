.data     
; start of data space
numA:     .word 12
numB:     .word 24

.text
; start of code space
main:   
        ; r1 is the loop counter.  Fill it with the number of data words in the vector.
        daddi r2, r0, veclength  ; r2 points to the vector length data.
        ld r1, 0(r2)            ; load the vector length into r1.

        ;Load XOR constant into R24
        daddi r2, r0, convertConstant
        ld r24, 0(r2)

        ;Load address of vectorA into r2
        daddi r2, r0, vectorAdata

        ;Load address of vectorB into r3
        daddi r3, r0, vectorBdata

        ;Using r16 as sum register. Set it to zero
        dadd r16, r0, r0

        ; stop execution.
        syscall 0