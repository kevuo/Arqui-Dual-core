/*
 * NiosRoutine.c
 *
 *  Created on: 05/06/2016
 *      Author: Kevin
 */


#include <stdio.h>

// Return a pointer to the max value from the given pointer parameters
unsigned char * mMax(unsigned char *a,  unsigned char *b,  unsigned char *c,  unsigned char *d,  unsigned char *e) {
	unsigned char *max;
    *max = (*a < *b) ? *b : *a;
    *max = (*max < *c) ? *c : *max;
    *max = (*max < *d) ? *d : *max;
    return (*max < *e) ? *e : *max;
}


//Main routine
int main()
{
	const unsigned int DATA_READY_ADDRESS = 0x2000
	const unsigned int NIOS_READY_ADDRESS = 0x2001;
	const unsigned int MATRIX_DIMENSIONS_ADDRESS = 0x2004; // [n,m]
	const unsigned int BASE_MATRIX_ADDRESS = 0x200C;
	const unsigned int RESULT_MATRIX_ADDRESS =0x4000000;

	int *ptrDataReadyValue, *ptrNiosReady, *ptrN, *ptrM;
	char *ptrBaseMatrix, *ptrResultMatrix;
	ptrDataReadyValue = DATA_READY_ADDRESS;
	ptrNiosReady = NIOS_READY_ADDRESS;
	ptrN = MATRIX_DIMENSIONS_ADDRESS;
	ptrM = MATRIX_DIMENSIONS_ADDRESS+0x4;
	ptrMatrix=BASE_MATRIX_ADDRESS;
	ptrResultMatrix=RESULT_MATRIX_ADDRESS;

//Polling to flag written by Atom Processor. 
while(1){
	//If Flag is 1, Nios is ready to begin filtering process.
	if(*ptrDataReadyValue == 1){
		//exec filter algorithm
		int *a = ProcessImage(*ptrMatrix, *ptrN, *ptrM);
		if(*a == 1){
			*ptrDataReadyValue=0;
			*ptrNiosReady = 1;
			printf("Procesamiento de matriz satisfactorio.");
		}else{
			printf("Falla procesamiento de matriz.");
		}
	}

}
return 0;
}

void debugRoutine(){
	unsigned char *pMatrix, p;                  //Create buffer to store result matrix
	pResultMatrix=RESULT_MATRIX_ADDRESS;           //Assign buffer address
}


//Debug purpose
void printMatrix(unsigned char *ptrMatrix, int *pN, int *pM){

	int i;
	for(i = 0; i < *pN; i=i+1) {
		int j;
    	for(j = 0; j < *pM; j=j+1) {
     	   printf("%d ", *ptrMatrix);
     	   ptrMatrix=ptrMatrix+1;
    	}
   		 printf("\n");
   		 //*ptrMatrix++;
	}
}

//Max Filter
int ProcessImage(unsigned char *pMatrix, int *pN, int *pM) {
	unsigned char *pResultMatrix;                  //Create buffer to store result matrix
	pResultMatrix=RESULT_MATRIX_ADDRESS;           //Assign buffer address
	int i;
    for (i=0; i < *pN; i=i+1) {

    	//Copy 2 first elements from a row to the resultMatrix
    	*pResultMatrix=*ptrMatrix;
    	ptrMatrix++;
    	ptrResultMatrix++;
    	*pResultMatrix=*ptrMatrix;
    	ptrMatrix++;
    	ptrResultMatrix++;

    	int j;
        for (j = 2; j < *pM - 2; j=j+1) {
          	*pResultMatrix=mMax(pMatrix-0x2,pMatrix-0x1,pMatrix,pMatrix+0x1,pMatrix+0x2);
             pMatrix++;
             pResultMatrix++;
        }
        //Copy 2 first elements from a row to the resultMatrix
    	*pResultMatrix=*ptrMatrix;
    	ptrMatrix++;
    	ptrResultMatrix++;
    	*pResultMatrix=*ptrMatrix;
    	ptrMatrix++;
    	ptrResultMatrix++;
    }
    printMatrix(BASE_MATRIX_ADDRESS,*pN,*pM);
    printMatrix(RESULT_MATRIX_ADDRESS, *pN, *pM);
    return 1;
}




