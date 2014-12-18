/*
 * include/asm/segment.h
 * Copyright (C) <2014>  <@RKX1209>
 */


#ifndef _ASM_SEGMENT_H
#define _ASM_SEGMENT_H

/*
 * The layout of the per-CPU GDT under Abyon:
 *
 *   0 - null
 *   1 - reserved
 *   2 - reserved
 *   3 - reserved
 *
 *   4 - unused			<==== new cacheline
 *   5 - unused
 *
 *  ------- start of TLS (Thread-Local Storage) segments:
 *
 *   6 - TLS segment #1			[ glibc's TLS segment ]
 *   7 - TLS segment #2			[ Wine's %fs Win32 segment ]
 *   8 - TLS segment #3
 *   9 - reserved
 *  10 - reserved
 *  11 - reserved
 *
 *  ------- start of kernel segments:
 *
 *  12 - kernel code segment		<==== new cacheline
 *  13 - kernel data segment
 *  14 - default user CS
 *  15 - default user DS
 *  16 - TSS
 *  17 - LDT
 *  18 - PNPBIOS support (16->32 gate)
 *  19 - PNPBIOS support
 *  20 - PNPBIOS support
 *  21 - PNPBIOS support
 *  22 - PNPBIOS support
 *  23 - APM BIOS support
 *  24 - APM BIOS support
 *  25 - APM BIOS support 
 *
 *  26 - ESPFIX small SS
 *  27 - unused
 *  28 - unused
 *  29 - unused
 *  30 - unused
 *  31 - TSS for double fault handler
 */

#define GDT_ENTRY_TLS_ENTRIES	3
#define GDT_ENTRY_TLS_MIN	6
#define GDT_ENTRY_TLS_MAX 	(GDT_ENTRY_TLS_MIN + GDT_ENTRY_TLS_ENTRIES - 1)

#define TLS_SIZE (GDT_ENTRY_TLS_ENTRIES * 8)

/* GDT entry (User space) */
#define GDT_ENTRY_DEFAULT_USER_CS	14 //User CS
#define __USER_CS (GDT_ENTRY_DEFAULT_USER_CS * 8 + 3)

#define GDT_ENTRY_DEFAULT_USER_DS	15 //User DS
#define __USER_DS (GDT_ENTRY_DEFAULT_USER_DS * 8 + 3)

/* GDT entry (Kernel space) */
#define GDT_ENTRY_KERNEL_BASE 12

#define GDT_ENTRY_KERNEL_CS (GDT_ENTRY_KERNEL_BASE + 0)//Kernel CS
#define __KERNEL_CS (GDT_ENTRY_KERNEL_CS * 8)

#define GDT_ENTRY_KERNEL_DS (GDT_ENTRY_KERNEL_BASE + 1)//Kernel DS
#define __KERNEL_DS (GDT_ENTRY_KERNEL_DS * 8)

#define GDT_ENTRY_TSS			(GDT_ENTRY_KERNEL_BASE + 4)
#define GDT_ENTRY_LDT			(GDT_ENTRY_KERNEL_BASE + 5)

#define GDT_ENTRY_PNPBIOS_BASE		(GDT_ENTRY_KERNEL_BASE + 6)
#define GDT_ENTRY_APMBIOS_BASE		(GDT_ENTRY_KERNEL_BASE + 11)

#define GDT_ENTRY_ESPFIX_SS		(GDT_ENTRY_KERNEL_BASE + 14)
#define __ESPFIX_SS (GDT_ENTRY_ESPFIX_SS * 8)

#define GDT_ENTRY_DOUBLEFAULT_TSS	31

/* GDT Size */
#define GDT_ENTRIES 32
#define GDT_SIZE (GDT_ENTRIES * 8)

/* Simple GDT entries used in booting process */
#define GDT_ENTRY_BOOT_CS		2
#define __BOOT_CS	(GDT_ENTRY_BOOT_CS * 8)

#define GDT_ENTRY_BOOT_DS		(GDT_ENTRY_BOOT_CS + 1)
#define __BOOT_DS	(GDT_ENTRY_BOOT_DS * 8)

/* IDT Size */
#define IDT_ENTRIES 256

#endif
