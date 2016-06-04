#ifndef ADMIMAGEN_H
#define ADMIMAGEN_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "string"
#include <filtro.h>
using namespace std;

class AdmImagen
{
public:
    AdmImagen();
    AdmImagen(string pFile);
    void mProcesar_Imagen();
    cv::Mat mReconstruir();
    bool mImage_Null();

private:

    cv::Mat aImagen;
    Filtro aFiltro;
    bool aImageNull;
    int aHeight;
    int aWidth;
    int aChannels;
    void mGet_Sub_Image(int pWidth, int pHeight);
};

#endif // ADMIMAGEN_H
