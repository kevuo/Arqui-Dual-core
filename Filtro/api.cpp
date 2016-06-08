#include "api.h"
#include "iostream"
#include "qfiledialog.h"

API::API(){

}

void API::escribirMatriz(void* pData, unsigned int dwDataSize){
   DMAWriteMatriz(pData, dwDataSize);
   std::cout << "" << std::endl;
}

void* API::leerMatriz(unsigned int dwBufSize, void* pBuffer){
    return DMAReadMatriz(dwBufSize, pBuffer);
    std::cout << ""  << std::endl;
}

void API::escribirDimensiones(void* pData, unsigned int dwDataSize){
    DMAWriteDimensiones(pData, dwDataSize);
    std::cout << ""  << std::endl;
}

unsigned char* API::obtenerNiosStatus(unsigned char* pdwData){
    return ReadNiosStatus(pdwData);
    std::cout << ""  << std::endl;
}

void API::escribirEstadoDatoListo(unsigned int dwData){
    WriteDataReadyStatus(dwData);
    std::cout << ""  << std::endl;
}


//void API::readDMAMatriz(){
//    hola(8000);
//   std::cout << "La matriz es [][]" << std::endl;
//}
