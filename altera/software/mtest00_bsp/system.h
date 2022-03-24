/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios2e'
 * SOPC Builder design path: ../../nios2e.sopcinfo
 *
 * Generated: Thu Mar 24 22:44:11 KST 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00000820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1a
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x02000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1a
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x02000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00000820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1a
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x02000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1a
#define NIOS2_RESET_ADDR 0x02000000


/*
 * DECODE0 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE0 altera_avalon_pio
#define DECODE0_BASE 0x30000
#define DECODE0_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE0_CAPTURE 0
#define DECODE0_DATA_WIDTH 28
#define DECODE0_DO_TEST_BENCH_WIRING 0
#define DECODE0_DRIVEN_SIM_VALUE 0
#define DECODE0_EDGE_TYPE "NONE"
#define DECODE0_FREQ 50000000
#define DECODE0_HAS_IN 0
#define DECODE0_HAS_OUT 1
#define DECODE0_HAS_TRI 0
#define DECODE0_IRQ -1
#define DECODE0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE0_IRQ_TYPE "NONE"
#define DECODE0_NAME "/dev/DECODE0"
#define DECODE0_RESET_VALUE 0
#define DECODE0_SPAN 16
#define DECODE0_TYPE "altera_avalon_pio"


/*
 * DECODE1 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE1 altera_avalon_pio
#define DECODE1_BASE 0x31000
#define DECODE1_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE1_CAPTURE 0
#define DECODE1_DATA_WIDTH 28
#define DECODE1_DO_TEST_BENCH_WIRING 0
#define DECODE1_DRIVEN_SIM_VALUE 0
#define DECODE1_EDGE_TYPE "NONE"
#define DECODE1_FREQ 50000000
#define DECODE1_HAS_IN 0
#define DECODE1_HAS_OUT 1
#define DECODE1_HAS_TRI 0
#define DECODE1_IRQ -1
#define DECODE1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE1_IRQ_TYPE "NONE"
#define DECODE1_NAME "/dev/DECODE1"
#define DECODE1_RESET_VALUE 0
#define DECODE1_SPAN 16
#define DECODE1_TYPE "altera_avalon_pio"


/*
 * DECODE2 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE2 altera_avalon_pio
#define DECODE2_BASE 0x32000
#define DECODE2_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE2_CAPTURE 0
#define DECODE2_DATA_WIDTH 28
#define DECODE2_DO_TEST_BENCH_WIRING 0
#define DECODE2_DRIVEN_SIM_VALUE 0
#define DECODE2_EDGE_TYPE "NONE"
#define DECODE2_FREQ 50000000
#define DECODE2_HAS_IN 0
#define DECODE2_HAS_OUT 1
#define DECODE2_HAS_TRI 0
#define DECODE2_IRQ -1
#define DECODE2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE2_IRQ_TYPE "NONE"
#define DECODE2_NAME "/dev/DECODE2"
#define DECODE2_RESET_VALUE 0
#define DECODE2_SPAN 16
#define DECODE2_TYPE "altera_avalon_pio"


/*
 * DECODE3 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE3 altera_avalon_pio
#define DECODE3_BASE 0x33000
#define DECODE3_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE3_CAPTURE 0
#define DECODE3_DATA_WIDTH 28
#define DECODE3_DO_TEST_BENCH_WIRING 0
#define DECODE3_DRIVEN_SIM_VALUE 0
#define DECODE3_EDGE_TYPE "NONE"
#define DECODE3_FREQ 50000000
#define DECODE3_HAS_IN 0
#define DECODE3_HAS_OUT 1
#define DECODE3_HAS_TRI 0
#define DECODE3_IRQ -1
#define DECODE3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE3_IRQ_TYPE "NONE"
#define DECODE3_NAME "/dev/DECODE3"
#define DECODE3_RESET_VALUE 0
#define DECODE3_SPAN 16
#define DECODE3_TYPE "altera_avalon_pio"


/*
 * DECODE4 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE4 altera_avalon_pio
#define DECODE4_BASE 0x34000
#define DECODE4_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE4_CAPTURE 0
#define DECODE4_DATA_WIDTH 28
#define DECODE4_DO_TEST_BENCH_WIRING 0
#define DECODE4_DRIVEN_SIM_VALUE 0
#define DECODE4_EDGE_TYPE "NONE"
#define DECODE4_FREQ 50000000
#define DECODE4_HAS_IN 0
#define DECODE4_HAS_OUT 1
#define DECODE4_HAS_TRI 0
#define DECODE4_IRQ -1
#define DECODE4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE4_IRQ_TYPE "NONE"
#define DECODE4_NAME "/dev/DECODE4"
#define DECODE4_RESET_VALUE 0
#define DECODE4_SPAN 16
#define DECODE4_TYPE "altera_avalon_pio"


/*
 * DECODE5 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE5 altera_avalon_pio
#define DECODE5_BASE 0x35000
#define DECODE5_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE5_CAPTURE 0
#define DECODE5_DATA_WIDTH 28
#define DECODE5_DO_TEST_BENCH_WIRING 0
#define DECODE5_DRIVEN_SIM_VALUE 0
#define DECODE5_EDGE_TYPE "NONE"
#define DECODE5_FREQ 50000000
#define DECODE5_HAS_IN 0
#define DECODE5_HAS_OUT 1
#define DECODE5_HAS_TRI 0
#define DECODE5_IRQ -1
#define DECODE5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE5_IRQ_TYPE "NONE"
#define DECODE5_NAME "/dev/DECODE5"
#define DECODE5_RESET_VALUE 0
#define DECODE5_SPAN 16
#define DECODE5_TYPE "altera_avalon_pio"


/*
 * DECODE6 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE6 altera_avalon_pio
#define DECODE6_BASE 0x36000
#define DECODE6_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE6_CAPTURE 0
#define DECODE6_DATA_WIDTH 28
#define DECODE6_DO_TEST_BENCH_WIRING 0
#define DECODE6_DRIVEN_SIM_VALUE 0
#define DECODE6_EDGE_TYPE "NONE"
#define DECODE6_FREQ 50000000
#define DECODE6_HAS_IN 0
#define DECODE6_HAS_OUT 1
#define DECODE6_HAS_TRI 0
#define DECODE6_IRQ -1
#define DECODE6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE6_IRQ_TYPE "NONE"
#define DECODE6_NAME "/dev/DECODE6"
#define DECODE6_RESET_VALUE 0
#define DECODE6_SPAN 16
#define DECODE6_TYPE "altera_avalon_pio"


/*
 * DECODE7 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE7 altera_avalon_pio
#define DECODE7_BASE 0x37000
#define DECODE7_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE7_CAPTURE 0
#define DECODE7_DATA_WIDTH 28
#define DECODE7_DO_TEST_BENCH_WIRING 0
#define DECODE7_DRIVEN_SIM_VALUE 0
#define DECODE7_EDGE_TYPE "NONE"
#define DECODE7_FREQ 50000000
#define DECODE7_HAS_IN 0
#define DECODE7_HAS_OUT 1
#define DECODE7_HAS_TRI 0
#define DECODE7_IRQ -1
#define DECODE7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE7_IRQ_TYPE "NONE"
#define DECODE7_NAME "/dev/DECODE7"
#define DECODE7_RESET_VALUE 0
#define DECODE7_SPAN 16
#define DECODE7_TYPE "altera_avalon_pio"


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_QSYS


/*
 * HEX0 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX0 altera_avalon_pio
#define HEX0_BASE 0x40000
#define HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX0_CAPTURE 0
#define HEX0_DATA_WIDTH 8
#define HEX0_DO_TEST_BENCH_WIRING 0
#define HEX0_DRIVEN_SIM_VALUE 0
#define HEX0_EDGE_TYPE "NONE"
#define HEX0_FREQ 50000000
#define HEX0_HAS_IN 0
#define HEX0_HAS_OUT 1
#define HEX0_HAS_TRI 0
#define HEX0_IRQ -1
#define HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX0_IRQ_TYPE "NONE"
#define HEX0_NAME "/dev/HEX0"
#define HEX0_RESET_VALUE 0
#define HEX0_SPAN 16
#define HEX0_TYPE "altera_avalon_pio"


/*
 * HEX1 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX1 altera_avalon_pio
#define HEX1_BASE 0x41000
#define HEX1_BIT_CLEARING_EDGE_REGISTER 0
#define HEX1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX1_CAPTURE 0
#define HEX1_DATA_WIDTH 8
#define HEX1_DO_TEST_BENCH_WIRING 0
#define HEX1_DRIVEN_SIM_VALUE 0
#define HEX1_EDGE_TYPE "NONE"
#define HEX1_FREQ 50000000
#define HEX1_HAS_IN 0
#define HEX1_HAS_OUT 1
#define HEX1_HAS_TRI 0
#define HEX1_IRQ -1
#define HEX1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX1_IRQ_TYPE "NONE"
#define HEX1_NAME "/dev/HEX1"
#define HEX1_RESET_VALUE 0
#define HEX1_SPAN 16
#define HEX1_TYPE "altera_avalon_pio"


/*
 * HEX2 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX2 altera_avalon_pio
#define HEX2_BASE 0x42000
#define HEX2_BIT_CLEARING_EDGE_REGISTER 0
#define HEX2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX2_CAPTURE 0
#define HEX2_DATA_WIDTH 8
#define HEX2_DO_TEST_BENCH_WIRING 0
#define HEX2_DRIVEN_SIM_VALUE 0
#define HEX2_EDGE_TYPE "NONE"
#define HEX2_FREQ 50000000
#define HEX2_HAS_IN 0
#define HEX2_HAS_OUT 1
#define HEX2_HAS_TRI 0
#define HEX2_IRQ -1
#define HEX2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX2_IRQ_TYPE "NONE"
#define HEX2_NAME "/dev/HEX2"
#define HEX2_RESET_VALUE 0
#define HEX2_SPAN 16
#define HEX2_TYPE "altera_avalon_pio"


/*
 * HEX3 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX3 altera_avalon_pio
#define HEX3_BASE 0x43000
#define HEX3_BIT_CLEARING_EDGE_REGISTER 0
#define HEX3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX3_CAPTURE 0
#define HEX3_DATA_WIDTH 8
#define HEX3_DO_TEST_BENCH_WIRING 0
#define HEX3_DRIVEN_SIM_VALUE 0
#define HEX3_EDGE_TYPE "NONE"
#define HEX3_FREQ 50000000
#define HEX3_HAS_IN 0
#define HEX3_HAS_OUT 1
#define HEX3_HAS_TRI 0
#define HEX3_IRQ -1
#define HEX3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX3_IRQ_TYPE "NONE"
#define HEX3_NAME "/dev/HEX3"
#define HEX3_RESET_VALUE 0
#define HEX3_SPAN 16
#define HEX3_TYPE "altera_avalon_pio"


/*
 * HEX4 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX4 altera_avalon_pio
#define HEX4_BASE 0x44000
#define HEX4_BIT_CLEARING_EDGE_REGISTER 0
#define HEX4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX4_CAPTURE 0
#define HEX4_DATA_WIDTH 8
#define HEX4_DO_TEST_BENCH_WIRING 0
#define HEX4_DRIVEN_SIM_VALUE 0
#define HEX4_EDGE_TYPE "NONE"
#define HEX4_FREQ 50000000
#define HEX4_HAS_IN 0
#define HEX4_HAS_OUT 1
#define HEX4_HAS_TRI 0
#define HEX4_IRQ -1
#define HEX4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX4_IRQ_TYPE "NONE"
#define HEX4_NAME "/dev/HEX4"
#define HEX4_RESET_VALUE 0
#define HEX4_SPAN 16
#define HEX4_TYPE "altera_avalon_pio"


/*
 * HEX5 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX5 altera_avalon_pio
#define HEX5_BASE 0x45000
#define HEX5_BIT_CLEARING_EDGE_REGISTER 0
#define HEX5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX5_CAPTURE 0
#define HEX5_DATA_WIDTH 8
#define HEX5_DO_TEST_BENCH_WIRING 0
#define HEX5_DRIVEN_SIM_VALUE 0
#define HEX5_EDGE_TYPE "NONE"
#define HEX5_FREQ 50000000
#define HEX5_HAS_IN 0
#define HEX5_HAS_OUT 1
#define HEX5_HAS_TRI 0
#define HEX5_IRQ -1
#define HEX5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX5_IRQ_TYPE "NONE"
#define HEX5_NAME "/dev/HEX5"
#define HEX5_RESET_VALUE 0
#define HEX5_SPAN 16
#define HEX5_TYPE "altera_avalon_pio"


/*
 * PERIOD0 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD0 altera_avalon_pio
#define PERIOD0_BASE 0x20000
#define PERIOD0_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD0_CAPTURE 0
#define PERIOD0_DATA_WIDTH 28
#define PERIOD0_DO_TEST_BENCH_WIRING 0
#define PERIOD0_DRIVEN_SIM_VALUE 0
#define PERIOD0_EDGE_TYPE "NONE"
#define PERIOD0_FREQ 50000000
#define PERIOD0_HAS_IN 0
#define PERIOD0_HAS_OUT 1
#define PERIOD0_HAS_TRI 0
#define PERIOD0_IRQ -1
#define PERIOD0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD0_IRQ_TYPE "NONE"
#define PERIOD0_NAME "/dev/PERIOD0"
#define PERIOD0_RESET_VALUE 0
#define PERIOD0_SPAN 16
#define PERIOD0_TYPE "altera_avalon_pio"


/*
 * PERIOD1 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD1 altera_avalon_pio
#define PERIOD1_BASE 0x21000
#define PERIOD1_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD1_CAPTURE 0
#define PERIOD1_DATA_WIDTH 28
#define PERIOD1_DO_TEST_BENCH_WIRING 0
#define PERIOD1_DRIVEN_SIM_VALUE 0
#define PERIOD1_EDGE_TYPE "NONE"
#define PERIOD1_FREQ 50000000
#define PERIOD1_HAS_IN 0
#define PERIOD1_HAS_OUT 1
#define PERIOD1_HAS_TRI 0
#define PERIOD1_IRQ -1
#define PERIOD1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD1_IRQ_TYPE "NONE"
#define PERIOD1_NAME "/dev/PERIOD1"
#define PERIOD1_RESET_VALUE 0
#define PERIOD1_SPAN 16
#define PERIOD1_TYPE "altera_avalon_pio"


/*
 * PERIOD2 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD2 altera_avalon_pio
#define PERIOD2_BASE 0x22000
#define PERIOD2_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD2_CAPTURE 0
#define PERIOD2_DATA_WIDTH 28
#define PERIOD2_DO_TEST_BENCH_WIRING 0
#define PERIOD2_DRIVEN_SIM_VALUE 0
#define PERIOD2_EDGE_TYPE "NONE"
#define PERIOD2_FREQ 50000000
#define PERIOD2_HAS_IN 0
#define PERIOD2_HAS_OUT 1
#define PERIOD2_HAS_TRI 0
#define PERIOD2_IRQ -1
#define PERIOD2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD2_IRQ_TYPE "NONE"
#define PERIOD2_NAME "/dev/PERIOD2"
#define PERIOD2_RESET_VALUE 0
#define PERIOD2_SPAN 16
#define PERIOD2_TYPE "altera_avalon_pio"


/*
 * PERIOD3 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD3 altera_avalon_pio
#define PERIOD3_BASE 0x23000
#define PERIOD3_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD3_CAPTURE 0
#define PERIOD3_DATA_WIDTH 28
#define PERIOD3_DO_TEST_BENCH_WIRING 0
#define PERIOD3_DRIVEN_SIM_VALUE 0
#define PERIOD3_EDGE_TYPE "NONE"
#define PERIOD3_FREQ 50000000
#define PERIOD3_HAS_IN 0
#define PERIOD3_HAS_OUT 1
#define PERIOD3_HAS_TRI 0
#define PERIOD3_IRQ -1
#define PERIOD3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD3_IRQ_TYPE "NONE"
#define PERIOD3_NAME "/dev/PERIOD3"
#define PERIOD3_RESET_VALUE 0
#define PERIOD3_SPAN 16
#define PERIOD3_TYPE "altera_avalon_pio"


/*
 * PERIOD4 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD4 altera_avalon_pio
#define PERIOD4_BASE 0x24000
#define PERIOD4_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD4_CAPTURE 0
#define PERIOD4_DATA_WIDTH 28
#define PERIOD4_DO_TEST_BENCH_WIRING 0
#define PERIOD4_DRIVEN_SIM_VALUE 0
#define PERIOD4_EDGE_TYPE "NONE"
#define PERIOD4_FREQ 50000000
#define PERIOD4_HAS_IN 0
#define PERIOD4_HAS_OUT 1
#define PERIOD4_HAS_TRI 0
#define PERIOD4_IRQ -1
#define PERIOD4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD4_IRQ_TYPE "NONE"
#define PERIOD4_NAME "/dev/PERIOD4"
#define PERIOD4_RESET_VALUE 0
#define PERIOD4_SPAN 16
#define PERIOD4_TYPE "altera_avalon_pio"


/*
 * PERIOD5 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD5 altera_avalon_pio
#define PERIOD5_BASE 0x25000
#define PERIOD5_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD5_CAPTURE 0
#define PERIOD5_DATA_WIDTH 28
#define PERIOD5_DO_TEST_BENCH_WIRING 0
#define PERIOD5_DRIVEN_SIM_VALUE 0
#define PERIOD5_EDGE_TYPE "NONE"
#define PERIOD5_FREQ 50000000
#define PERIOD5_HAS_IN 0
#define PERIOD5_HAS_OUT 1
#define PERIOD5_HAS_TRI 0
#define PERIOD5_IRQ -1
#define PERIOD5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD5_IRQ_TYPE "NONE"
#define PERIOD5_NAME "/dev/PERIOD5"
#define PERIOD5_RESET_VALUE 0
#define PERIOD5_SPAN 16
#define PERIOD5_TYPE "altera_avalon_pio"


/*
 * PERIOD6 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD6 altera_avalon_pio
#define PERIOD6_BASE 0x26000
#define PERIOD6_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD6_CAPTURE 0
#define PERIOD6_DATA_WIDTH 28
#define PERIOD6_DO_TEST_BENCH_WIRING 0
#define PERIOD6_DRIVEN_SIM_VALUE 0
#define PERIOD6_EDGE_TYPE "NONE"
#define PERIOD6_FREQ 50000000
#define PERIOD6_HAS_IN 0
#define PERIOD6_HAS_OUT 1
#define PERIOD6_HAS_TRI 0
#define PERIOD6_IRQ -1
#define PERIOD6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD6_IRQ_TYPE "NONE"
#define PERIOD6_NAME "/dev/PERIOD6"
#define PERIOD6_RESET_VALUE 0
#define PERIOD6_SPAN 16
#define PERIOD6_TYPE "altera_avalon_pio"


/*
 * PERIOD7 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD7 altera_avalon_pio
#define PERIOD7_BASE 0x27000
#define PERIOD7_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD7_CAPTURE 0
#define PERIOD7_DATA_WIDTH 28
#define PERIOD7_DO_TEST_BENCH_WIRING 0
#define PERIOD7_DRIVEN_SIM_VALUE 0
#define PERIOD7_EDGE_TYPE "NONE"
#define PERIOD7_FREQ 50000000
#define PERIOD7_HAS_IN 0
#define PERIOD7_HAS_OUT 1
#define PERIOD7_HAS_TRI 0
#define PERIOD7_IRQ -1
#define PERIOD7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD7_IRQ_TYPE "NONE"
#define PERIOD7_NAME "/dev/PERIOD7"
#define PERIOD7_RESET_VALUE 0
#define PERIOD7_SPAN 16
#define PERIOD7_TYPE "altera_avalon_pio"


/*
 * PUSH configuration
 *
 */

#define ALT_MODULE_CLASS_PUSH altera_avalon_pio
#define PUSH_BASE 0x50000
#define PUSH_BIT_CLEARING_EDGE_REGISTER 0
#define PUSH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSH_CAPTURE 0
#define PUSH_DATA_WIDTH 4
#define PUSH_DO_TEST_BENCH_WIRING 0
#define PUSH_DRIVEN_SIM_VALUE 0
#define PUSH_EDGE_TYPE "NONE"
#define PUSH_FREQ 50000000
#define PUSH_HAS_IN 1
#define PUSH_HAS_OUT 0
#define PUSH_HAS_TRI 0
#define PUSH_IRQ -1
#define PUSH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSH_IRQ_TYPE "NONE"
#define PUSH_NAME "/dev/PUSH"
#define PUSH_RESET_VALUE 0
#define PUSH_SPAN 16
#define PUSH_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x70000
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x70000
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x70000
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios2e"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x70000
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * new_sdram_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_new_sdram_controller_0 altera_avalon_new_sdram_controller
#define NEW_SDRAM_CONTROLLER_0_BASE 0x2000000
#define NEW_SDRAM_CONTROLLER_0_CAS_LATENCY 3
#define NEW_SDRAM_CONTROLLER_0_CONTENTS_INFO
#define NEW_SDRAM_CONTROLLER_0_INIT_NOP_DELAY 0.0
#define NEW_SDRAM_CONTROLLER_0_INIT_REFRESH_COMMANDS 2
#define NEW_SDRAM_CONTROLLER_0_IRQ -1
#define NEW_SDRAM_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NEW_SDRAM_CONTROLLER_0_IS_INITIALIZED 1
#define NEW_SDRAM_CONTROLLER_0_NAME "/dev/new_sdram_controller_0"
#define NEW_SDRAM_CONTROLLER_0_POWERUP_DELAY 100.0
#define NEW_SDRAM_CONTROLLER_0_REFRESH_PERIOD 15.625
#define NEW_SDRAM_CONTROLLER_0_REGISTER_DATA_IN 1
#define NEW_SDRAM_CONTROLLER_0_SDRAM_ADDR_WIDTH 0x17
#define NEW_SDRAM_CONTROLLER_0_SDRAM_BANK_WIDTH 2
#define NEW_SDRAM_CONTROLLER_0_SDRAM_COL_WIDTH 8
#define NEW_SDRAM_CONTROLLER_0_SDRAM_DATA_WIDTH 16
#define NEW_SDRAM_CONTROLLER_0_SDRAM_NUM_BANKS 4
#define NEW_SDRAM_CONTROLLER_0_SDRAM_NUM_CHIPSELECTS 1
#define NEW_SDRAM_CONTROLLER_0_SDRAM_ROW_WIDTH 13
#define NEW_SDRAM_CONTROLLER_0_SHARED_DATA 0
#define NEW_SDRAM_CONTROLLER_0_SIM_MODEL_BASE 0
#define NEW_SDRAM_CONTROLLER_0_SPAN 16777216
#define NEW_SDRAM_CONTROLLER_0_STARVATION_INDICATOR 0
#define NEW_SDRAM_CONTROLLER_0_TRISTATE_BRIDGE_SLAVE ""
#define NEW_SDRAM_CONTROLLER_0_TYPE "altera_avalon_new_sdram_controller"
#define NEW_SDRAM_CONTROLLER_0_T_AC 5.5
#define NEW_SDRAM_CONTROLLER_0_T_MRD 3
#define NEW_SDRAM_CONTROLLER_0_T_RCD 20.0
#define NEW_SDRAM_CONTROLLER_0_T_RFC 70.0
#define NEW_SDRAM_CONTROLLER_0_T_RP 20.0
#define NEW_SDRAM_CONTROLLER_0_T_WR 14.0

#endif /* __SYSTEM_H_ */