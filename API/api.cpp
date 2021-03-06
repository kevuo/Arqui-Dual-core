#include "api.h"
#include "iostream"
#include "qfiledialog.h"

API::API(){

}

void API::escribirMatriz(void* pData, unsigned int dwDataSize){
   DMAWriteMatriz(pData, dwDataSize);
   std::cout << "" << std::endl;
}

void API::leerMatriz(unsigned int dwBufSize, void* pBuffer){
    DMAReadMatriz(dwBufSize, pBuffer);
    std::cout << ""  << std::endl;
}

/*
void API::escribirDimensiones(void* pData, unsigned int dwDataSize){
    DMAWriteDimensiones(pData, dwDataSize);
    std::cout << ""  << std::endl;
}*/

void APi::escribirNDimension(unsigned int nDimension){
    WriteNDimention(nDimension);
    std::cout << ""  << std::endl;
}

void APi::escribirMDimension(unsigned int mDimension){
    WriteMDimention(mDimension);
    std::cout << ""  << std::endl;
}

void API::obtenerNiosStatus(unsigned int* pdwData){
    ReadNiosStatus(pdwData);
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
