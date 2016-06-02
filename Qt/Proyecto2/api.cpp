#include "api.h"
#include "iostream"
#include "qfiledialog.h"

API::API(){

}

void API::escribirMatriz(){
   DMAWriteMatriz();
   std::cout << "" << std::endl;
}

void API::leerMatriz(){
    DMAReadMatriz();
    std::cout << ""  << std::endl;
}

void API::escribirDimensiones(){
    DMAWriteDimensiones();
    std::cout << ""  << std::endl;
}

void API::obtenerNiosStatus(){
    ReadNiosStatus();
    std::cout << ""  << std::endl;
}

void API::escribirEstadoDatoListo(){
    WriteDataReadyStatus();
    std::cout << ""  << std::endl;
}


//void API::readDMAMatriz(){
//    hola(8000);
//   std::cout << "La matriz es [][]" << std::endl;
//}
