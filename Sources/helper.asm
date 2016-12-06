.text
.global timerCheck
/*
 * Check to see if the timer needs to be decremented.
 */
timerCheck:
	@ r0: Results
	@ r1: CurrentTimerPosition
	@ r2: cycles/second
	PUSH {R1-R7, LR}
	MOV r2, #9
	CMP r1, r2
	BEQ equal
	B notequal
equal:
	MOV r0, #1
	B done
notequal:
	MOV r0, #0
done:
	POP {R1-R7, PC}
