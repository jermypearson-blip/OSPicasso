// All Rights Reserved at Picasso Rayne Studios LLC 2026.

#include "vga.h"

void clear_screen() {
    volatile char *screen = (volatile char *)0xB8000;
    
    for (int i = 0; i < 4000; i += 2) {
        screen[i] = ' ';      // 🔤 Blank space character
        screen[i + 1] = 0x07; // 🎨 Light grey text on black background
    }
}

void kernel_main() {
    clear_screen();
    volatile char *screen = (volatile char *)0xB8000;
    const char *msg = "Hello";
    int i = 0;

    while (*msg != '\0') {
        screen[i] = *msg;      // Write character 🔤
        screen[i + 1] = 0x06;  // Write color 🎨

        msg++;                 // Next letter in "Hello"
        i += 2;                // Jump past character + color in screen
    }

    while (1) {}               // Halt here
}
