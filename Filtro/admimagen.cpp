#include "admimagen.h"

AdmImagen::AdmImagen()
{
    aImageNull=true;
}
AdmImagen::AdmImagen(string pFile)
{
    aImagen= cv::imread(pFile);
    aWidth= aImagen.cols;
    aHeight= aImagen.rows;
    if(aWidth>aHeight){
        this->mGet_Sub_Image(aHeight,aHeight);
    }
    else{
        this->mGet_Sub_Image(aWidth,aWidth);
    }
    aWidth= aImagen.cols;
    aHeight= aImagen.rows;
    aImageNull=false;
    aChannels= aImagen.channels();
    this->aFiltro = Filtro(aImagen,aWidth,aHeight);
}

bool AdmImagen::mImage_Null(){
    return aImageNull;
}

void AdmImagen::mProcesar_Imagen(int distribution){
    this->aFiltro.mProcesar_Imagen(distribution);
}

cv::Mat AdmImagen::mReconstruir(){
    return this->aFiltro.mGet_Matrix();
}

void AdmImagen::mGet_Sub_Image(int pWidth, int pHeight){
    aWidth=pWidth;
    aHeight=pHeight;
    cv::Mat imageROI= aImagen(cv::Range(0,pHeight),cv::Range(0,pWidth));
    aImagen=imageROI;
}
