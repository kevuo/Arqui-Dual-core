#ifndef API_H
#define API_H

#include "PCIE.h"

extern "C" {
    void  DMAWriteMatriz(PCIE_LOCAL_ADDRESS LocalAddress, void* pData, DWORD dwDataSize);
    void* DMAReadMatriz(PCIE_LOCAL_ADDRESS LocalAddress, DWORD dwBufSize);
    void  DMAWriteDimensiones(PCIE_LOCAL_ADDRESS LocalAdress, void* pData, DWORD dwDataSize);
    unsigned char* ReadNiosStatus(PCIE_ADDRESS PcieAddress);
    void WriteDataReadyStatus(PCIE_ADDRESS PcieAddress, DWORD dwData);
    //int hola(int zumbi);
}

class API{
    public:
        API();
        void escribirMatriz();
        void leerMatriz();
        void escribirDimensiones();
        void obtenerNiosStatus();
        void escribirEstadoDatoListo();
};

#endif // API_H
