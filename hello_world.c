/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>

int main()
{
	const unsigned int DATA_READY_ADDRESS = 0x2000;
	const unsigned int NIOS_READY_ADDRESS = 0x2001;
	const unsigned int MATRIX_DIMENSIONS_ADDRESS = 0x2004; // [n,m]
	const unsigned int MATRIX_BASE_ADDRESS = 0x2000C;

	int *ptrDataReadyValue;
	ptrDataReadyValue = DATA_READY_ADDRESS;
	int *ptrNiosReady;
	ptrNiosReady = NIOS_READY_ADDRESS;

while(1){
	if(*ptrDataReadyValue == 1){
		//exec filter algorithm
		int a = DoSomething();
		if(a == 1){
			*ptrNiosReady = 1;
			printf("Procesamiento de matriz satisfactorio.");
		else{
			printf("Falló procesamiento de matriz.");
		}
	}

}
}
return 0;
}

int DoSomething(){
	printf("1");
	return 1;
}
