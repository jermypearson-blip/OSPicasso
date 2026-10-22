#include "vga.h"

void kernel_main(void) {
    terminal_initialize();

    terminal_setcolor(0x1F); /* White text on Blue background */
    terminal_writestring("================================================================================\n");
    terminal_writestring("                        OSPicasso Kernel v0.2 Online                            \n");
    terminal_writestring("================================================================================\n\n");

    terminal_setcolor(0x0A); /* Light Green on Black */
    terminal_writestring("[OK] Hardware I/O bus initialized (inb/outb).\n");
    terminal_writestring("[OK] Modular VGA driver loaded.\n");
    terminal_writestring("[OK] Hardware text cursor tracking active.\n\n");

    terminal_setcolor(0x0E); /* Yellow on Black */
    terminal_writestring("Kernel initialized successfully. Ready for IDT and interrupts!\n");
}