#ifndef ADMMATRIZ_H
#define ADMMATRIZ_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class AdmMatriz
{
public:
    AdmMatriz();
    AdmMatriz(cv::Mat pImagen);
    void mCambiar_Color(int pColor, int pI, int pJ);
    void mCambiar_Significado(int pColor, int pSignificado);
    int mGet_Color(int pI, int pJ);
    int *mGet_Significados();
    cv::Mat mGet_Matriz();
private:
    cv::Mat aMatriz;
    int aSignificados[27];
    int aCant_X;
    int aCant_Y;
};

#endif // ADMMATRIZ_H
