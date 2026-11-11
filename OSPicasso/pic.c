/* All rights reserved @picasso Rayne Studios LLC 2026 */

#include "pic.h"

void pic_remap(uint8_t offset_primary, uint8_t offset_secondary)
{
    /* 1. Save existing interrupt masks */
    uint8_t mask_primary = inb(PIC_PRIMARY_DATA);
    uint8_t mask_secondary = inb(PIC_SECONDARY_DATA);

    /* 2. Start initialization sequence in cascade mode (ICW1) */
    outb(PIC_PRIMARY_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC_SECONDARY_COMMAND, ICW1_INIT | ICW1_ICW4);
    
    /* 3. ICW2: Set Vector offsets (0x20 for Primary, 0x28 for Secondary) */
    outb(PIC_PRIMARY_DATA, offset_primary);
    outb(PIC_SECONDARY_DATA, offset_secondary);

    /* 4. ICW3: Tell Primary PIC that Secondary is at IRQ2 (0000 0100b = 0x04) */
    outb(PIC_PRIMARY_DATA, 0x04);
    /* Tell Secondary PIC its cascade identity is IRQ2 (0000 0010b = 0x02)*/
    outb(PIC_SECONDARY_DATA, 0x02);

    /* 5. ICW4: Set 8086/88 microprocessor mode*/
    outb(PIC_PRIMARY_DATA, ICW4_8086);
    outb(PIC_SECONDARY_DATA, ICW4_8086);

    /* 6. Restore preserved masks */
    outb(PIC_PRIMARY_DATA, mask_primary);
    outb(PIC_SECONDARY_DATA, mask_secondary);
}

void pic_send_eoi(uint8_t irq)
{
    /* If the interrupt came from the secondary PIC (IRQ 8-15), notify it first */
    if (irq >= 8)
    {
        outb(PIC_SECONDARY_COMMAND, PIC_EOI);
    }
    /* Always notify the primary PIC */
    outb(PIC_PRIMARY_COMMAND, PIC_EOI);
}