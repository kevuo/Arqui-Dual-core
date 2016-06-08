#ifndef API_H
#define API_H

#include "PCIE.h"

extern "C" {
    void DMAWriteMatriz(void* pData, DWORD dwDataSize);
    void DMAReadMatriz(DWORD dwBufSize, void *pBuffer);
    //void DMAWriteDimensiones(void* pData, DWORD dwDataSize);
    void WriteNDimention(DWORD nDimention);
    void WriteMDimention(DWORD mDimention);
    void ReadNiosStatus(DWORD *pdwData);
    void WriteDataReadyStatus(DWORD dwData);
}

class API{
    public:
        API();
        void escribirMatriz(void* pData, unsigned int dwDataSize);
        void leerMatriz(unsigned int dwBufSize, void* pBuffer);
        //void escribirDimensiones(void *pData, unsigned int dwDataSize);
        void escribirNDimension(unsigned int nDimension);
        void escribirMDimension(unsigned int mDimension);
        void obtenerNiosStatus(unsigned int* pdwData);
        void escribirEstadoDatoListo(unsigned int dwData);
};

#endif // API_H
