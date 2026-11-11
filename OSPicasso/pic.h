/* all rights reserved @picasso Rayne Studios LLC 2026 */

#ifndef PIC_H
#define PIC_H

#include "io.h"

/* Primary  PIC (PIC1) Ports*/
#define PIC_PRIMARY_COMMAND 0x20
#define PIC_PRIMARY_DATA 0x21

/* Secondary PIC (PIC2) Ports */
#define PIC_SECONDARY_COMMAND 0xA0
#define PIC_SECONDARY_DATA 0xA1

/* End-of-Interrupt (EOI) COMMAND */
#define PIC_EOI 0x20

/* Initialization Control Words (ICW) */
#define ICW1_INIT 0x10 /* Required initialization bit */
#define ICW1_ICW4 0x01 /* Indicates ICW4 will be present */
#define ICW4_8086 0x01 /* Operate in 8086/88 mode */

/* Public API */
void pic_remap(uint8_t offset_primary, uint8_t offset_secondary);
void pic_send_eoi(uint8_t irq);
void pic_set_mask(uint8_t irq_line);
void pic_clear_mask(uint8_t irq_line);

#endif