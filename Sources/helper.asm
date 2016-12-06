.text
.global timerUpdate, timerDoneCheck
/*
 * Check to see if the timer needs to be decremented.
 */
timerUpdate:
	@ r0: Results
	@ r1: CurrentTimerPosition
	@ r2: cycles/second
	PUSH {R1-R7, LR}
	MOV r1, #9
	CMP r1, r0
	BEQ equal
	B notequal
equal:
	MOV r0, #1
	B done
notequal:
	MOV r0, #0
done:
	POP {R1-R7, PC}

timerDoneCheck:
	@ r0: Results
	@ r1: CurrentTimerPosition
	@ r2: cycles/second
	PUSH {R1-R7, LR}
	MOV r1, #0
	CMP r1, r0
	BEQ equal
	B notequal
