ENTRY(_start)

SECTIONS
{
    /* Many x86 bootloaders load kernels at 1 MB in RAM */
    . = 1M;

    /* First: put the multiboot header and startup assembly code */
    .text : {
        *(.multiboot)
        *(.text)
    }

    /* Second: put read-only data */
    .rodata : {
        *(.rodata)
    }

    /* Third: put our reserved stack space */
    .bss : {
        *(.bss)
    }
}