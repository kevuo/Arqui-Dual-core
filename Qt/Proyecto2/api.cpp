#include "api.h"
#include "iostream"
#include "qfiledialog.h"

API::API(){

}

void API::inicio(){
    iniciarPCIe();
    std::cout << ""  << std::endl;
}





void API::writeDMAMatriz(int total){
    std::cout << ""  << std::endl;
}

void API::readDMAMatriz(){
    hola(8000);
    std::cout << "La matriz es [][]" << std::endl;
}
