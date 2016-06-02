#include "stdio.h"
#include "PCIE.h"

void DMAWriteMatriz(){
    printf ("---------- Iniciando la escritura de la matriz por DMA ----------\n");

    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAddress = 0x200c;
    void *pData;
    DWORD dwDataSize;
    void *lib_handle;

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
        if (!PCIE_DmaWrite(hPCIE, LocalAddress, pData, dwDataSize)){
            printf("Fallo en la escritura de la matriz\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;
}

void DMAReadMatriz(){
    printf ("---------- Iniciando la lectura de la matriz por DMA ----------\n");

    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAddress;
    void *pBuffer;
    DWORD dwBufSize;
    void *lib_handle;

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
        if (!PCIE_DmaRead(hPCIE, LocalAddress, pBuffer, dwBufSize)){
            printf("Fallo en la lectura  de la matriz\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;
}

void DMAWriteDimensiones(){
    printf ("---------- Iniciando la escritura de las dimensiones ----------\n");
    void *lib_handle;
    PCIE_HANDLE hPCIE;
    PCIE_LOCAL_ADDRESS LocalAdress;
    void *pData;
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
        if (!PCIE_DmaWrite(hPCIE, LocalAdress, pData, dwDataSize)){
            printf("Fallo en la escritura  de las dimensiones\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;
}

void ReadNiosStatus(){
    printf ("---------- Iniciando la lectura del estado del NIOS ----------\n");
    void *lib_handle;
    PCIE_HANDLE hPCIE;
    PCIE_BAR PcieBar;
    PCIE_ADDRESS PcieAddress;
    unsigned char *pdwData;

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
        if (!PCIE_Read8(hPCIE, PcieBar, PcieAddress, pdwData)){
            printf("Fallo en la lectura del estado del NIOS\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;
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
            printf("Fallo en la escritura  del dato listo\n");
        printf ("---------- Cerrando el PCIe ----------\n");
        PCIE_Close(hPCIE);
        }
    }
    return 0;
}
