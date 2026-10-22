; Multiboot header constants
MBALIGN  equ 1 << 0            ; align loaded modules on page boundaries
MEMINFO  equ 1 << 1            ; provide memory map
MBFLAGS  equ MBALIGN | MEMINFO ; multiboot flags
MAGIC    equ 0x1BADB002        ; magic number allowing bootloader to find the header
CHECKSUM equ -(MAGIC + MBFLAGS); checksum to verify multiboot header

section .multiboot
align 4
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM

section .text
global _start
extern kernel_main

_start:
    ; 1. Point the CPU stack pointer register to our reserved memory
    mov esp, stack_top

    ; 2. Jump into our C function
    call kernel_main

    ; 3. If kernel_main ever returns, stop the CPU safely
    cli
.hang:
    hlt
    jmp .hang

section .bss
stack_bottom:
    resb 16384    ; 16 KB of scratchpad RAM
stack_top: