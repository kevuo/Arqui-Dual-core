#ifndef ADMIMAGEN_H
#define ADMIMAGEN_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "string"
using namespace std;

class AdmImagen
{
public:
    AdmImagen();
    AdmImagen(string pFile);
    void mSet_Image(string pFile);
    cv::Mat mGet_Image();
    int mGet_Height();
    int mGet_Width();
    int mGet_Channels();
    int mGet_Pixel_Size();
    void mProcesar_Imagen(int pCant_Div);
    cv::Mat mReconstruir();
    cv::Mat mReconstruir(cv::Mat pMatriz);
    bool mImage_Null();

private:

    void mTile_Filling(int pCant_Div);
    void mGet_Sub_Image(int pWidth, int pHeight);
    void mInterpolation_NN();
    void mInterpolation_Taylor();
    void mInterpreter();
    cv::Mat aImagen;
    bool aImageNull;
    int aHeight;
    int aWidth;
    int aChannels;
    int aPixelSize;
    int aCant_X;
    int aCant_Y;
};

#endif // ADMIMAGEN_H
