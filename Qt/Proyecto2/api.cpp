#include "api.h"
#include "iostream"
#include "qfiledialog.h"

API::API(){

}

void API::escribirMatriz(PCIE_LOCAL_ADDRESS LocalAddress, void* pData, DWORD dwDataSize){
   DMAWriteMatriz(LocalAddress, pData, dwDataSize);
   std::cout << "" << std::endl;
}

void API::leerMatriz(PCIE_LOCAL_ADDRESS LocalAddress, DWORD dwBufSize){
    DMAReadMatriz(LocalAddress, dwBufSize);
    std::cout << ""  << std::endl;
}

void API::escribirDimensiones(PCIE_LOCAL_ADDRESS LocalAdress, void* pData, DWORD dwDataSize){
    DMAWriteDimensiones(LocalAdress, pData, dwDataSize);
    std::cout << ""  << std::endl;
}

void API::obtenerNiosStatus(PCIE_ADDRESS PcieAddress){
    ReadNiosStatus(PcieAddress);
    std::cout << ""  << std::endl;
}

void API::escribirEstadoDatoListo(PCIE_ADDRESS PcieAddress, DWORD dwData){
    WriteDataReadyStatus(PcieAddress, dwData);
    std::cout << ""  << std::endl;
}


//void API::readDMAMatriz(){
//    hola(8000);
//   std::cout << "La matriz es [][]" << std::endl;
//}
