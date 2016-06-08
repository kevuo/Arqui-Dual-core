#ifndef API_H
#define API_H

#include "PCIE.h"

extern "C" {
    void DMAWriteMatriz(void* pData, DWORD dwDataSize);
    void DMAReadMatriz(DWORD dwBufSize, void *pBuffer);
    void DMAWriteDimensiones(void* pData, DWORD dwDataSize);
    void ReadNiosStatus(unsigned char* pdwData);
    void WriteDataReadyStatus(DWORD dwData);
    //int hola(int zumbi);
}

class API{
    public:
        API();
        void escribirMatriz(void* pData, unsigned int dwDataSize);
        void leerMatriz(unsigned int dwBufSize, void* pBuffer);
        void escribirDimensiones(void *pData, unsigned int dwDataSize);
        void obtenerNiosStatus(unsigned char* pdwData);
        void escribirEstadoDatoListo(unsigned int dwData);
};

#endif // API_H
