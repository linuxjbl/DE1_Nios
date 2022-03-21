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

unsigned long Period[8];
unsigned long Decode[8];

int pn = 0;
int dn = 0;
int BlinkEnb = 0;
unsigned long blinkco = 0;
char state[3];
int Category = 0;
int Duty[8];
int ChN = 0;

void _wait(loop_count)
int loop_count;
{
	volatile int sum, data;
	sum	= 0;
	for (data = 0; data < loop_count; data++) {
		sum = (data << 8);
	}
  return;
}

int Seg7Enc(int n) {
	int res;
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
	else if(n == 10) res = 0x88; // A
	else if(n == 11) res = 0x83; // b
	else if(n == 12) res = 0xa7; // c
	else if(n == 13) res = 0xa1; // d
	else if(n == 14) res = 0x86; // E
	else if(n == 15) res = 0x8e; // F
	else if(n == 100) res = 0x8b; // h(hundred)
	else if(n == 1000) res = 0x79; // 1.(1k)
	else if(n == 2000) res = 0x24; // 2.(2k)
	else if(n == 5000) res = 0x12; // 5.(5k)
	else if(n == 10000) res = 0x40; // 0.(10k)
	else if(n == 100000) res = 0x0b; // h.(100k)
	else res = 0xff;
	return res;
}

void TurnOffSeg(int n) {
	if(n == 1) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(-1);
	} else if(n == 2) {
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(-1);
	} else {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(-1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(-1);
	}
}

void DispPeriod(int byState) {
	if((byState == 0 && Period[ChN] == 50000000) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(1);
	} else if((byState == 0 && Period[ChN] == 25000000) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(2);
	} else if((byState == 0 && Period[ChN] == 10000000) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(5);
	} else if((byState == 0 && Period[ChN] == 5000000) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 2500000) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 1000000) || (byState == 1 && state[2] == '5')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 500000) || (byState == 1 && state[2] == '6')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 250000) || (byState == 1 && state[2] == '7')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 100000) || (byState == 1 && state[2] == '8')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 50000) || (byState == 1 && state[2] == '9')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(1000);
	} else if((byState == 0 && Period[ChN] == 25000) || (byState == 1 && state[2] == 'a')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(2000);
	} else if((byState == 0 && Period[ChN] == 10000) || (byState == 1 && state[2] == 'b')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(5000);
	} else if((byState == 0 && Period[ChN] == 5000) || (byState == 1 && state[2] == 'c')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 2500) || (byState == 1 && state[2] == 'd')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 1000) || (byState == 1 && state[2] == 'e')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 500) || (byState == 1 && state[2] == 'f')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	} else if((byState == 0 && Period[ChN] == 250) || (byState == 1 && state[2] == 'g')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	} else if((byState == 0 && Period[ChN] == 100) || (byState == 1 && state[2] == 'h')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	}
}

void DispDuty(int byState) {
	if((byState == 0 && Duty[ChN] == 1) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 2) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 3) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(3);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 4) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(4);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 5) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 6) || (byState == 1 && state[2] == '5')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(6);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 7) || (byState == 1 && state[2] == '6')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(7);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 8) || (byState == 1 && state[2] == '7')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(8);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 9) || (byState == 1 && state[2] == '8')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(9);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	}
}

void DispChN(int byState) {
	if((byState == 0 && ChN == 0) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(0);
	} else if((byState == 0 && ChN == 1) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(1);
	} else if((byState == 0 && ChN == 2) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(2);
	} else if((byState == 0 && ChN == 3) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(3);
	} else if((byState == 0 && ChN == 4) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(4);
	} else if((byState == 0 && ChN == 5) || (byState == 1 && state[2] == '5')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(5);
	} else if((byState == 0 && ChN == 6) || (byState == 1 && state[2] == '6')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(6);
	} else if((byState == 0 && ChN == 7) || (byState == 1 && state[2] == '7')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(7);
	} else if((byState == 0 && ChN == 8) || (byState == 1 && state[2] == '8')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(8);
	}
}

void DispAll() {
	if(state[1] == 'U') { // "RUN"
		DispChN(0); // display by the ChN
		if(Category == 0) {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
			DispPeriod(0); // display by the variable
		} else {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
			DispDuty(0); // display by the variable
		}
	}

	else if(state[1] == 'N') { // "PNx"
		DispChN(1); // display by the state[2]
		if(Category == 0) {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
			DispPeriod(0); // display by the variable
		} else {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
			DispDuty(0); // display by the variable
		}
	}

	else if(state[1] == 'C') { // "xCx"
		DispChN(0); // display by the ChN
		if(state[2] == '0') {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
		} else if(state[2] == '1') {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
		}
		if(Category == 0) DispPeriod(0); // display by the variable
		else DispDuty(0); // display by the variable
	}

	else if(state[1] == 'F') { // "xFx"
		DispChN(0); // display by the ChN
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
		DispPeriod(1); // display by the state
	}

	else if(state[1] == 'd') { // "xdx"
		DispChN(0); // display by the ChN
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
		DispDuty(1); // display by the state
	}

}

int main()
{
	unsigned long reg1, reg1old, reg1tmp, reg2tmp, reg3tmp;
	int i;

	  alt_putstr("Hello from Nios II! JBLee *** \n");

	for(i = 0; i < 8; i++) {
		Period[i] = 50000000;
		Decode[i] = 25000000;
		Duty[i] = 5;
	}
	*(volatile unsigned long *)PERIOD0_BASE = Period[0];
	*(volatile unsigned long *)DECODE0_BASE = Decode[0];
	*(volatile unsigned long *)PERIOD1_BASE = Period[1];
	*(volatile unsigned long *)DECODE1_BASE = Decode[1];
	*(volatile unsigned long *)PERIOD2_BASE = Period[2];
	*(volatile unsigned long *)DECODE2_BASE = Decode[2];
	*(volatile unsigned long *)PERIOD3_BASE = Period[3];
	*(volatile unsigned long *)DECODE3_BASE = Decode[3];
	*(volatile unsigned long *)PERIOD4_BASE = Period[4];
	*(volatile unsigned long *)DECODE4_BASE = Decode[4];
	*(volatile unsigned long *)PERIOD5_BASE = Period[5];
	*(volatile unsigned long *)DECODE5_BASE = Decode[5];
	*(volatile unsigned long *)PERIOD6_BASE = Period[6];
	*(volatile unsigned long *)DECODE6_BASE = Decode[6];
	*(volatile unsigned long *)PERIOD7_BASE = Period[7];
	*(volatile unsigned long *)DECODE7_BASE = Decode[7];

	state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
	DispAll();

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

    	if((reg1 & 0x03) == 0x01) { // button2（選択??ン）が押された
    		if(state[1] == 'N') { // "PNx", Pwm ChN selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '4';
    			} else if(state[2] == '4') {
    				state[2] = '5';
    			} else if(state[2] == '5') {
    				state[2] = '6';
    			} else if(state[2] == '6') {
    				state[2] = '7';
    			} else if(state[2] == '7') {
    				state[2] = '0';
    			}
      		}

    		else if(state[1] == 'C') { // "xCx", Category selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '0';
    			}
    		}

    		else if(state[1] == 'F') { // "xFx", Frequency selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '4';
    			} else if(state[2] == '4') {
    				state[2] = '5';
    			} else if(state[2] == '5') {
    				state[2] = '6';
    			} else if(state[2] == '6') {
    				state[2] = '7';
    			} else if(state[2] == '7') {
    				state[2] = '8';
    			} else if(state[2] == '8') {
    				state[2] = '9';
    			} else if(state[2] == '9') {
    				state[2] = 'a';
    			} else if(state[2] == 'a') {
    				state[2] = 'b';
    			} else if(state[2] == 'b') {
    				state[2] = 'c';
    			} else if(state[2] == 'c') {
    				state[2] = 'd';
    			} else if(state[2] == 'd') {
    				state[2] = 'e';
    			} else if(state[2] == 'e') {
    				state[2] = 'f';
    			} else if(state[2] == 'f') {
    				state[2] = 'g';
    			} else if(state[2] == 'g') {
    				state[2] = 'h';
    			} else if(state[2] == 'h') {
    				state[2] = '0';
    			}
    		}

    		else if(state[1] == 'd') { // "xdx", Frequency selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '4';
    			} else if(state[2] == '4') {
    				state[2] = '5';
    			} else if(state[2] == '5') {
    				state[2] = '6';
    			} else if(state[2] == '6') {
    				state[2] = '7';
    			} else if(state[2] == '7') {
    				state[2] = '8';
    			} else if(state[2] == '8') {
    				state[2] = '0';
    			}
    		}

    		DispAll();
			if(pn == 17) pn = 0;
			else pn++;
    	}

    	if((reg1 & 0x03) == 0x02) { // button1（決定??ン）が押された
    		if(state[1] == 'U') { // "RUN", free-run state
				state[0] = 'P';	state[1] = 'N';
				if(ChN == 0) state[2] = '0';
				else if(ChN == 1) state[2] = '1';
				else if(ChN == 2) state[2] = '2';
				else if(ChN == 3) state[2] = '3';
				else if(ChN == 4) state[2] = '4';
				else if(ChN == 5) state[2] = '5';
				else if(ChN == 6) state[2] = '6';
				else if(ChN == 7) state[2] = '7';
				else if(ChN == 8) state[2] = '8';
      		}

    		else if(state[1] == 'N') { // "PNx", Pwm number selection
    			if(state[2] == '0') ChN = 0;
    			else if(state[2] == '1') ChN = 1;
    			else if(state[2] == '2') ChN = 2;
    			else if(state[2] == '3') ChN = 3;
    			else if(state[2] == '4') ChN = 4;
    			else if(state[2] == '5') ChN = 5;
    			else if(state[2] == '6') ChN = 6;
    			else if(state[2] == '7') ChN = 7;
    			else if(state[2] == '8') ChN = 8;
				state[0] = 48+ChN;
				state[1] = 'C';
    			if(Category == 0) state[2] = '0';
    			else state[2] = '1';
      		}

    		else if(state[1] == 'C') { // "xCx", Category selection
    			if(state[2] == '0') {
    				Category = 0;
    				state[0] = 48+ChN;
    				state[1] = 'F';
    				if(Period[ChN] == 50000000) state[2] = '0';
    				else if(Period[ChN] == 25000000) state[2] = '1';
    				else if(Period[ChN] == 10000000) state[2] = '2';
    				else if(Period[ChN] == 5000000) state[2] = '3';
    				else if(Period[ChN] == 2500000) state[2] = '4';
    				else if(Period[ChN] == 1000000) state[2] = '5';
    				else if(Period[ChN] == 500000) state[2] = '6';
    				else if(Period[ChN] == 250000) state[2] = '7';
    				else if(Period[ChN] == 100000) state[2] = '8';
    				else if(Period[ChN] == 50000) state[2] = '9';
    				else if(Period[ChN] == 25000) state[2] = 'a';
    				else if(Period[ChN] == 10000) state[2] = 'b';
    				else if(Period[ChN] == 5000) state[2] = 'c';
    				else if(Period[ChN] == 2500) state[2] = 'd';
    				else if(Period[ChN] == 1000) state[2] = 'e';
    				else if(Period[ChN] == 500) state[2] = 'f';
    				else if(Period[ChN] == 250) state[2] = 'g';
    				else if(Period[ChN] == 100) state[2] = 'h';
    			} else {
    				Category = 1;
    				state[0] = 48+ChN;
    				state[1] = 'd';
    				if(Duty[ChN] == 1) state[2] = '0';
    				else if(Duty[ChN] == 2) state[2] = '1';
    				else if(Duty[ChN] == 3) state[2] = '2';
    				else if(Duty[ChN] == 4) state[2] = '3';
    				else if(Duty[ChN] == 5) state[2] = '4';
    				else if(Duty[ChN] == 6) state[2] = '5';
    				else if(Duty[ChN] == 7) state[2] = '6';
    				else if(Duty[ChN] == 8) state[2] = '7';
    				else if(Duty[ChN] == 9) state[2] = '8';
    			}
      		}

    		else if(state[1] == 'F') { // "xFx", Category selection
				if(state[2] == '0') {
					Period[ChN] = 50000000; // 1Hz
				} else if(state[2] == '1') {
						Period[ChN] = 25000000; // 2Hz
				} else if(state[2] == '2') {
						Period[ChN] = 10000000; // 5Hz
				} else if(state[2] == '3') {
						Period[ChN] = 5000000; // 10Hz
				} else if(state[2] == '4') {
						Period[ChN] = 2500000; // 20Hz
				} else if(state[2] == '5') {
						Period[ChN] = 1000000; // 50Hz
				} else if(state[2] == '6') {
						Period[ChN] = 500000; // 100Hz
				} else if(state[2] == '7') {
						Period[ChN] = 250000; // 200Hz
				} else if(state[2] == '8') {
						Period[ChN] = 100000; // 500Hz
				} else if(state[2] == '9') {
						Period[ChN] = 50000; // 1kHz
				} else if(state[2] == 'a') {
						Period[ChN] = 25000; // 2kHz
				} else if(state[2] == 'b') {
						Period[ChN] = 10000; // 5kHz
				} else if(state[2] == 'c') {
						Period[ChN] = 5000; // 10kHz
				} else if(state[2] == 'd') {
						Period[ChN] = 2500; // 20kHz
				} else if(state[2] == 'e') {
						Period[ChN] = 1000; // 50kHz
				} else if(state[2] == 'f') {
						Period[ChN] = 500; // 100kHz
				} else if(state[2] == 'g') {
						Period[ChN] = 250; // 200kHz
				} else if(state[2] == 'h') {
						Period[ChN] = 100; // 500kHz
				}
				Decode[ChN] = Period[ChN] * Duty[ChN] / 10;
				if(ChN == 0) {
					*(volatile unsigned long *)PERIOD0_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE0_BASE = Decode[ChN];
				} else if(ChN == 1) {
					*(volatile unsigned long *)PERIOD1_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE1_BASE = Decode[ChN];
				} else if(ChN == 2) {
					*(volatile unsigned long *)PERIOD2_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE2_BASE = Decode[ChN];
				} else if(ChN == 3) {
					*(volatile unsigned long *)PERIOD3_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE3_BASE = Decode[ChN];
				} else if(ChN == 4) {
					*(volatile unsigned long *)PERIOD4_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE4_BASE = Decode[ChN];
				} else if(ChN == 5) {
					*(volatile unsigned long *)PERIOD5_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE5_BASE = Decode[ChN];
				} else if(ChN == 6) {
					*(volatile unsigned long *)PERIOD6_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE6_BASE = Decode[ChN];
				} else if(ChN == 7) {
					*(volatile unsigned long *)PERIOD7_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE7_BASE = Decode[ChN];
				}
				state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
    		}

	    	else if(state[1] == 'd') { // "xdx", Category selection
				if(state[2] == '0') {
					Duty[ChN] = 1;
				} else if(state[2] == '1') {
					Duty[ChN] = 2;
				} else if(state[2] == '2') {
					Duty[ChN] = 3;
				} else if(state[2] == '3') {
					Duty[ChN] = 4;
				} else if(state[2] == '4') {
					Duty[ChN] = 5;
				} else if(state[2] == '5') {
					Duty[ChN] = 6;
				} else if(state[2] == '6') {
					Duty[ChN] = 7;
				} else if(state[2] == '7') {
					Duty[ChN] = 8;
				} else if(state[2] == '8') {
					Duty[ChN] = 9;
				}
				Decode[ChN] = Period[ChN] * Duty[ChN] / 10;
				if(ChN == 0) {
					*(volatile unsigned long *)DECODE0_BASE = Decode[ChN];
				} else if(ChN == 1) {
					*(volatile unsigned long *)DECODE1_BASE = Decode[ChN];
				} else if(ChN == 2) {
					*(volatile unsigned long *)DECODE2_BASE = Decode[ChN];
				} else if(ChN == 3) {
					*(volatile unsigned long *)DECODE3_BASE = Decode[ChN];
				} else if(ChN == 4) {
					*(volatile unsigned long *)DECODE4_BASE = Decode[ChN];
				} else if(ChN == 5) {
					*(volatile unsigned long *)DECODE5_BASE = Decode[ChN];
				} else if(ChN == 6) {
					*(volatile unsigned long *)DECODE6_BASE = Decode[ChN];
				} else if(ChN == 7) {
					*(volatile unsigned long *)DECODE7_BASE = Decode[ChN];
				}
				state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
      		}
    		DispAll();
    	}

    	if(state[1] == 'U') { // "RUN"ステ?トは全部?灯
   			DispAll();
    	} else if(state[1] == 'N') { // "PNx"ステ?トは1個目?滅
        		if(blinkco < 3) {
        			TurnOffSeg(1);
        		} else {
        			DispAll();
        		}
    	} else if(state[1] == 'C') { // "xCx"ステ?トは2個目?滅
    		if(blinkco < 3) {
    			TurnOffSeg(2);
    		} else {
    			DispAll();
    		}
    	} else if(state[1] == 'F' || state[1] == 'd') { // "xFx"ステ?トは3,4個目?滅
    		if(blinkco < 3) {
    			TurnOffSeg(3);
    		} else {
    			DispAll();
    		}
    	}

    	if(blinkco == 9) {
    		blinkco = 0;
    	} else {
    		blinkco++;
    	}

	}

  return 0;
}
