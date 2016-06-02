#include "stdio.h"
#include "PCIE.h"

int iniciarPCIeWriteDMA()
{
    printf ("---------- Iniciando el PCIe de la memoria ----------\n");

    void *lib_handle;
    void * pData;
    PCIE_LOCAL_ADDRESS aPCIE;
    PCIE_HANDLE hPCIE;
    DWORD dwDataSize;

    printf ("---------- Cargando el PCIe ----------\n");
    //lib_handle = PCIE_Load();
    if (!lib_handle){
        printf("Carga fallida del PCIe \n");
        return 0;
    }
    printf ("---------- Abriendo el PCIe ----------\n");
   //hPCIE = PCIE_Open(0,0,0);
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


