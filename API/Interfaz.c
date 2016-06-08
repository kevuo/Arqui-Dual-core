#include "stdio.h"
#include "PCIE.h"

void DMAWriteMatriz(void* pData, DWORD dwDataSize){
    printf ("---------- Iniciando la escritura de la matriz por DMA ----------\n");

    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAddress = 0x200C;
    void *lib_handle;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
    }
    printf ("---------- Abriendo el PCIe ----------\n");
    hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
    }else{
        if (!PCIE_DmaWrite(hPCIE, LocalAddress, pData, dwDataSize)){
            printf("Fallo en la escritura de la matriz\n");
        }
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
    }
}

void DMAReadMatriz(DWORD dwBufSize, void *pBuffer){
    printf ("---------- Iniciando la lectura de la matriz por DMA ----------\n");

    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAddress = 0x4000000;    
    void *lib_handle;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
    }
    printf ("---------- Abriendo el PCIe ----------\n");
    hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
    }else{
        if (!PCIE_DmaRead(hPCIE, LocalAddress, pBuffer, dwBufSize)){
            printf("Fallo en la lectura  de la matriz\n");
        }
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
    }
}

void DMAWriteDimensiones(void* pData, DWORD dwDataSize){
    printf ("---------- Iniciando la escritura de las dimensiones ----------\n");

    void *lib_handle;
    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAdress = 0x2004;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
    }
    printf ("---------- Abriendo el PCIe ----------\n");
    hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
    }else{
        if (!PCIE_DmaWrite(hPCIE, LocalAdress, pData, dwDataSize)){
            printf("Fallo en la escritura  de las dimensiones\n");
        }
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
    }
}

void ReadNiosStatus(unsigned char* pdwData){
    printf ("---------- Iniciando la lectura del estado del NIOS ----------\n");
    void *lib_handle;
    PCIE_HANDLE hPCIE;
    PCIE_BAR PcieBar = PCIE_BAR0;
    PCIE_ADDRESS PcieAddress = 0x2001;

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
    }else{
        if (!PCIE_Read8(hPCIE, PcieBar, PcieAddress, pdwData)){
            printf("Fallo en la lectura del estado del NIOS\n");
        }
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
    }
}

void WriteDataReadyStatus(DWORD dwData){
    printf ("---------- Iniciando la escritura del dato listo ----------\n");
    void *lib_handle;
    PCIE_BAR PcieBar = PCIE_BAR0;
    PCIE_HANDLE hPCIE;
    PCIE_ADDRESS PcieAddress = 0x2000;
    //DWORD dwData = 1;

    printf ("---------- Cargando el PCIe ----------\n");
    lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
    }
    printf ("---------- Abriendo el PCIe ----------\n");
    hPCIE = PCIE_Open(0,0,0);
    if(!hPCIE){
        printf("Apertura fallida del PCIe \n");
    }else{
        if (!PCIE_Write8(hPCIE, PcieBar, PcieAddress, dwData)){
            printf("Fallo en la escritura  del dato listo\n");
        }
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
    }
}
