#include "stdio.h"
#include "PCIE.h"

void DMAWriteMatriz(){
    printf ("---------- Iniciando el PCIe Write de la memoria ----------\n");

    void *lib_handle;
    void * pData;
    PCIE_LOCAL_ADDRESS aPCIE = 0x200c;
    PCIE_HANDLE hPCIE;
    DWORD dwDataSize;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
        return 0;
    }
    printf ("---------- Abriendo el PCIe ----------\n");
   hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
        return 0;
    }else{
        //if (!PCIE_DmaWrite(hPCIE, aPCIE, pData, dwDataSize)){
            printf("Fallo en la escritura DMA\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        //PCIE_Close(hPCIE);
        //}
    }
    return 0;
}

void DMAReadMatriz(){
    printf("Iniciando lectura de matriz por DMA");
}

void DMAWriteDimensiones(){
    printf("Iniciando la escritura de las dimensiones");
}

void ReadNiosStatus(){
    printf("Iniciando la lectura del estado");
}

void WriteDataReadyStatus(){
    printf ("---------- Iniciando la escritura del dato listo ----------\n");
    void *lib_handle;
    PCIE_BAR PcieBar = PCIE_BAR0;
    PCIE_ADDRESS PcieAddress = 0x2000;
    PCIE_HANDLE hPCIE;
    DWORD dwData = 1;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
        return 0;
    }
    printf ("---------- Abriendo el PCIe ----------\n");
    hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
        return 0;
    }else{
        if (!PCIE_Write8(hPCIE, PcieBar, PcieAddress, dwData)){
            printf("Fallo en la escritura  del readyStatus\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;

}
