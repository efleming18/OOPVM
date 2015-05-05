
.data     ; start of data space
veclength:     .word 12  ; number of elements in vector

;Test data 1 dotprod = 12
;vectorAdata:   .word  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
;vectorBdata:   .word  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

;Test data 2 (Given data) dotprod = 22899
;vectorAdata:   .word  10,  5, -1, 0,   3, -257,  7,  8,  9, 0, -30, -55  ; first vector
;vectorBdata:   .word -4, 200,  3, 6, 100,  -88, 55, 31, -3, 0,  15,  22  ; second vector

;Test data 3 dotprod = -12
;vectorAdata:   .word  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
;vectorBdata:   .word  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1

;Test data 4 dotprod = -22953
vectorAdata:   .word  10,  5, -1, 0,   3, 257,  7,  8,  9, 0, -30, -55  ; first vector
vectorBdata:   .word -4, -200,  -3, -6, -100,  -88, -55, -31, -3, 0,  -15,  -22  ; second vector
        
;printfstring for positive dot product
printfstringPos:  .asciiz "The dot-product of A and B is %d.\n\n"
        
;printfstring for negative dot product
printfstringNeg:  .asciiz "The dot-product of A and B is -%d.\n\n"

printfparams:  .space  8     ; space to store the address of the printfstring
dotproduct:    .word 0       ; space to store final answer to be printed

convertConstant: .word 0xFFFFFFFFFFFFFFFF ;Constant to be used with XOR and negative dot products.

               .text     ; start of code space
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

loop:
        ;loop performs the following:
        ;1) Fetch next data to be multipled together from the vectors
        ;2) Multiply the data from the two vectors, storing results in r15
        ;3) Add result to r16, and store in r16. (r16 initialized to 0)
        ;4) Calculate address for the next memory location within vectors for new data
        ;5) Decrement counter, branching back to loop if r1 != 0

        ;Load r4 with data pointed at address in r2
        ld r4, 0(r2)

        ;Load r5 with data pointed at address in r3
        ld r5, 0(r3)

        ;Multiply data in r4 and r5, move lower 64-bit data to r15
        dmult r4, r5
        mflo r15

        ;Add r15 to r16, storing result r16
        dadd r16, r15, r16

        ;Add 8 to r2 to get next number in vector A
        daddi r2, r2, 8

        ;Add 8 to r3 to get next number in vector B
        daddi r3, r3, 8

        ;Decrement length counter
        daddi r1, r1, -1

        ;Branch to loop if r1 != 0
        BNE r1, r0, loop

        ;Set r25 to 1 if r16 <0
        slti r25, r16, 0

        BNE r25, r0, convertToNegative

        B over

convertToNegative:

        ;Convert negative value to positive value using XOR and adding 1.
        XOR r16, r16, r24
        daddi r16, r16, 1

over:   
        ; save result to designated spot in memory, assuming your code put result in r16.
        sd r16, dotproduct(r0)

        BEQZ r25, printPos

printNeg:
        ;Print negative value
        daddi r5, r0, printfstringNeg  ; r5 now holds address of string to print
        sd r5, printfparams(r0)     ; put address first in parameters section
        daddi r14, r0, printfparams ; syscall 5 expects address of parameters in r14.
        syscall 5

        ;Time to exit
        B end

        ; this code prints the result.  Before making system call syscall 5,
        ; r14 must have the address of the parameters for the printf function.
        ; at that address, the first thing is a pointer to the ascii string; 
        ; after that comes data for any parameters for the printf.
printPos:
        daddi r5, r0, printfstringPos  ; r5 now holds address of string to print
        sd r5, printfparams(r0)     ; put address first in parameters section
        daddi r14, r0, printfparams ; syscall 5 expects address of parameters in r14.
        syscall 5

end:
        ; stop execution.
        syscall 0