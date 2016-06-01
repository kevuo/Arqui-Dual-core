#include "admimagen.h"

AdmImagen::AdmImagen()
{
    aImageNull=true;
}
AdmImagen::AdmImagen(string pFile)
{
    aImagen= cv::imread(pFile);
    if(aImagen.cols>811){
        this->mGet_Sub_Image(811,aImagen.rows);
    }
    if (aImagen.rows>571){
        this->mGet_Sub_Image(aImagen.cols,571);
    }
    aImageNull=false;
    aWidth= aImagen.cols;
    aHeight= aImagen.rows;
    aChannels= aImagen.channels();

}
void AdmImagen::mSet_Image(string pFile){
    aImagen= cv::imread(pFile);
}
cv::Mat AdmImagen::mGet_Image(){
    return aImagen;
}
int AdmImagen::mGet_Width(){
    return aWidth;
}
int AdmImagen::mGet_Height(){
    return aHeight;
}
int AdmImagen::mGet_Channels(){
    return aChannels;
}
int AdmImagen::mGet_Pixel_Size(){
    return aPixelSize;
}
bool AdmImagen::mImage_Null(){
    return aImageNull;
}
void AdmImagen::mProcesar_Imagen(int pCant_Div){
    this->mTile_Filling(pCant_Div);
    this->mGet_Sub_Image(aCant_X*aPixelSize,aCant_Y*aPixelSize);
    this->mInterpolation_Taylor();
    this->mInterpreter();
}

void AdmImagen::mTile_Filling(int pCant_Div){
    if (aWidth*aHeight < pCant_Div) {aCant_X=aWidth;aCant_Y=aHeight;}

    double aspect = (double)aHeight/aWidth;
    double xf = sqrtf(pCant_Div/aspect);
    double yf = xf*aspect;
    int x = max(1.0, floor(xf));
    int y = max(1.0, floor(yf));
    int x_size = floor((double)aWidth/x);
    int y_size = floor((double)aHeight/y);
    int tileSize = min(x_size, y_size);

    x = floor((double)aWidth/tileSize);
    y = floor((double)aHeight/tileSize);
    if (x*y < pCant_Div)
    {
        if (((x+1)*y < pCant_Div) && (x*(y+1) < pCant_Div))
        {
            x_size = floor((double)aWidth/(x+1));
            y_size = floor((double)aHeight/(y+1));
            tileSize = min(x_size, y_size);
        }
        else
        {
            int test_x = ceil((double)pCant_Div/y);
            int test_y = ceil((double)pCant_Div/x);
            x_size = min(floor((double)aWidth/test_x), floor((double)aHeight/y));
            y_size = min(floor((double)aWidth/x), floor((double)aHeight/test_y));
            tileSize = max(x_size, y_size);
        }
    }
    aCant_X=aWidth/tileSize;
    aCant_Y=aHeight/tileSize;
    aPixelSize=tileSize;
}

void AdmImagen::mGet_Sub_Image(int pWidth, int pHeight){
    aWidth=pWidth;
    aHeight=pHeight;
    cv::Mat imageROI= aImagen(cv::Range(0,pHeight),cv::Range(0,pWidth));
    aImagen=imageROI;
}

void AdmImagen::mInterpolation_NN(){
    cv::Mat Resultado(aCant_Y,aCant_X,CV_8UC3);
    for(int i=0; i*aPixelSize<aHeight;i++){
        for(int j=0; j*aPixelSize<aWidth;j++){
            Resultado.at<cv::Vec3b>(i,j)[0]=aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[0];
            Resultado.at<cv::Vec3b>(i,j)[1]=aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[1];
            Resultado.at<cv::Vec3b>(i,j)[2]=aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[2];
        }
    }
    aImagen=Resultado;
}

void AdmImagen::mInterpolation_Taylor(){
    cv::Mat Resultado(aCant_Y,aCant_X,CV_8UC3);
    for(int i=0; i*aPixelSize<aHeight;i++){
        for(int j=0; j*aPixelSize<aWidth;j++){
            int ColorC1=(aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[0]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize)[0]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize+aPixelSize)[0]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize+aPixelSize)[0]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize/2,j*aPixelSize+aPixelSize/2)[0])/5;
            int ColorC2=(aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[1]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize)[1]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize+aPixelSize)[1]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize+aPixelSize)[1]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize/2,j*aPixelSize+aPixelSize/2)[1])/5;
            int ColorC3=(aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize)[2]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize)[2]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize,j*aPixelSize+aPixelSize)[2]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize,j*aPixelSize+aPixelSize)[2]
                         +aImagen.at<cv::Vec3b>(i*aPixelSize+aPixelSize/2,j*aPixelSize+aPixelSize/2)[2])/5;
            Resultado.at<cv::Vec3b>(i,j)[0]=ColorC1;
            Resultado.at<cv::Vec3b>(i,j)[1]=ColorC2;
            Resultado.at<cv::Vec3b>(i,j)[2]=ColorC3;
        }
    }
    aImagen=Resultado;
}

void AdmImagen::mInterpreter(){
    for(int i=0; i<aCant_Y;i++){
        for(int j=0; j<aCant_X;j++){
            for(int k=0;k<3;k++){
                if(aImagen.at<cv::Vec3b>(i,j)[k]<85){
                    aImagen.at<cv::Vec3b>(i,j)[k]=0;
                }
                if(aImagen.at<cv::Vec3b>(i,j)[k]>=85 && aImagen.at<cv::Vec3b>(i,j)[k]<170){
                    aImagen.at<cv::Vec3b>(i,j)[k]=127;
                }
                if(aImagen.at<cv::Vec3b>(i,j)[k]>=170){
                    aImagen.at<cv::Vec3b>(i,j)[k]=254;
                }
            }
        }
    }
}

cv::Mat AdmImagen::mReconstruir(){
    cv::Mat MatNewImage(aHeight,aWidth,CV_8UC3);
    for(int i=0;i<aHeight;i++){
        for(int j=0;j<aWidth;j++){
            MatNewImage.at<cv::Vec3b>(i,j)[0]=aImagen.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[0];
            MatNewImage.at<cv::Vec3b>(i,j)[1]=aImagen.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[1];
            MatNewImage.at<cv::Vec3b>(i,j)[2]=aImagen.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[2];
        }
    }
    return MatNewImage;
}

cv::Mat AdmImagen::mReconstruir(cv::Mat pMatriz){
    cv::Mat MatNewImage(aHeight,aWidth,CV_8UC3);
    for(int i=0;i<aHeight;i++){
        for(int j=0;j<aWidth;j++){
        MatNewImage.at<cv::Vec3b>(i,j)[0]=(int)(pMatriz.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[0]/9)*127;
        MatNewImage.at<cv::Vec3b>(i,j)[1]=(int)((pMatriz.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[0]%9)/3)*127;
        MatNewImage.at<cv::Vec3b>(i,j)[2]=(int)((pMatriz.at<cv::Vec3b>((int)floor(i/aPixelSize),(int)floor(j/aPixelSize))[0]%9)%3)*127;
        }

    }
    return MatNewImage;
}
