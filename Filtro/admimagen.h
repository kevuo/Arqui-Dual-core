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
    void mProcesar_Imagen();
    cv::Mat mReconstruir();
    cv::Mat mReconstruir(cv::Mat pMatriz);
    bool mImage_Null();

private:

    cv::Mat aImagen;
    int** aMatrix;
    bool aImageNull;
    int aHeight;
    int aWidth;
    int aChannels;
    int aPixelSize;
    int aCant_X;
    int aCant_Y;
};

#endif // ADMIMAGEN_H