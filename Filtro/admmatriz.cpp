#include "admmatriz.h"

AdmMatriz::AdmMatriz(){
}
AdmMatriz::AdmMatriz(cv::Mat pImagen){
    aCant_X=pImagen.cols;
    aCant_Y=pImagen.rows;
    cv::Mat Matriz(aCant_Y,aCant_X,CV_8UC3);
    for(int i=0; i<aCant_Y;i++){
        for(int j=0; j<aCant_X;j++){
            Matriz.at<cv::Vec3b>(i,j)[0]=
                    (pImagen.at<cv::Vec3b>(i,j)[0]/127)*9+
                    (pImagen.at<cv::Vec3b>(i,j)[1]/127)*3+
                    (pImagen.at<cv::Vec3b>(i,j)[2]/127);
        }
    }
    aMatriz=Matriz;
    for(int n=-1;n<26;n++){aSignificados[n+1]=n;}
}

void AdmMatriz::mCambiar_Color(int pColor, int pI, int pJ){
    aMatriz.at<cv::Vec3b>(pI,pJ)[0]=pColor;
}

void AdmMatriz::mCambiar_Significado(int pColor, int pSignificado){
    aSignificados[pColor]= pSignificado;
}

int AdmMatriz::mGet_Color(int pI, int pJ){
    return aMatriz.at<cv::Vec3b>(pI,pJ)[0];
}
int* AdmMatriz::mGet_Significados(){
    return aSignificados;
}
cv::Mat AdmMatriz::mGet_Matriz(){
    return aMatriz;
}
