BITS 32

section .text

align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)

global start

extern kernel_main

start:
    cli
    call kernel_main
    hlt

section .bss
stack_space: resb 65536 ; 64 KB de pila
