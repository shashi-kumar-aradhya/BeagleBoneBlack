/*
Bare metal programming example for turning on led USR0
*/
.equ CM_PER_GPIO1_CLKCTRL, 0x44e000AC
.equ GPIO1_OE, 0X4804C134
.equ GPIO1_SETDATAOUT, 0X4804C194

_start:
    mrs r0, cpsr
    bic r0, r0, #0x1F @ clear mode bits
    orr r0, r0, #0x13 @ set SVC mode
    orr r0, r0, #0xC0 @ disable FIQ and IRQ
    msr cpsr, r0    

    bl _main

.loop: b .loop

.globl PUT32
PUT32:
	str r1,[r0]
	bx lr

.globl GET32
GET32:
	ldr r0, [r0]
	bx lr
