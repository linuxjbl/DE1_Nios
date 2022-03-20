/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include "system.h"



unsigned long Period0 = 50000000;
unsigned long Decode0 = 25000000;
int buttoncount = 0;

void _wait(loop_count) // _wait(700000)궳뽵1뷳
int loop_count;
{
	volatile int sum, data;
	sum	= 0;
	for (data = 0; data < loop_count; data++) {
		sum = (data << 8);
	}
  return;
}

int SevenSegEnc(int n) {
	int res = 0xc0;

	if(n == 0) res = 0xc0;
	else if(n == 1) res = 0xf9;
	else if(n == 2) res = 0xa4;
	else if(n == 3) res = 0xb0;
	else if(n == 4) res = 0x99;
	else if(n == 5) res = 0x92;
	else if(n == 6) res = 0x82;
	else if(n == 7) res = 0xf8;
	else if(n == 8) res = 0x80;
	else if(n == 9) res = 0x98;
	else if(n == 10) res = 0x88;
	else if(n == 11) res = 0x83;
	else if(n == 12) res = 0xa7;
	else if(n == 13) res = 0xa1;
	else if(n == 14) res = 0x86;
	else if(n == 15) res = 0x8e;
	return res;
}

void SetPeriod(int n) {
	if(n == 0) Period0 = 50000000;
	else if(n == 1) Period0 = 40000000;
	else if(n == 2) Period0 = 35000000;
	else if(n == 3) Period0 = 30000000;
	else if(n == 4) Period0 = 25000000;
	else if(n == 5) Period0 = 20000000;
	else if(n == 6) Period0 = 16000000;
	else if(n == 7) Period0 = 13000000;
	else if(n == 8) Period0 = 10000000;
	else if(n == 9) Period0 = 8000000;
	else if(n == 10) Period0 = 6000000;
	else if(n == 11) Period0 = 5000000;
	else if(n == 12) Period0 = 4000000;
	else if(n == 13) Period0 = 3500000;
	else if(n == 14) Period0 = 3000000;
	else if(n == 15) Period0 = 2500000;

	Decode0 = Period0 >> 1;
	*(volatile unsigned long *)PERIOD0_BASE = Period0;
	*(volatile unsigned long *)DECODE0_BASE = Decode0;
}

int main()
{
	unsigned long reg1 = 0;
	unsigned long reg1old, reg1tmp, reg2tmp, reg3tmp;

	*(volatile unsigned long *)PERIOD0_BASE = Period0;
	*(volatile unsigned long *)DECODE0_BASE = Decode0;
	*(volatile unsigned long *)HEX0_BASE = 0xc0;

  alt_putstr("Hello from Nios II!   JBL   ...\n");

	while (1) {
    	reg1old = reg1;
      	reg1tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
      	reg2tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
     	reg3tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
    	reg1 = *(volatile unsigned long *)PUSH_BASE;
    	if(reg1 == reg1tmp && reg1 == reg2tmp && reg1 == reg3tmp) {
    	} else {
    		reg1 = reg1old;
    	}

    	if(reg1 != reg1old) {
    		_wait(200000);
    	}

    	if((reg1 & 0x03) == 0x01) { // button2걁Up??깛걂궕돓궠귢궫
    		if(buttoncount == 15) buttoncount = 0;
    		else buttoncount++;
    	}
    	if((reg1 & 0x03) == 0x02) { // button1걁Down??깛걂궕돓궠귢궫
    		if(buttoncount == 0) buttoncount = 15;
    		else buttoncount--;
    	}
		*(volatile unsigned long *)HEX0_BASE = SevenSegEnc(buttoncount);
		SetPeriod(buttoncount);
	}

  return 0;
}

