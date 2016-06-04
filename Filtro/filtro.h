/* 
 * File:   filtro.h
 * Author: M. Taylor
 *
 * Created on June 1, 2016, 10:03 AM
 */

#ifndef FILTRO_H
#define	FILTRO_H


#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
using namespace std;


class Filtro
{
public:
    Filtro();
    ~Filtro();
    Filtro(cv::Mat pImagen, int pN, int pM);
    cv::Mat mGet_Matrix();
    void mProcesar_Imagen();

private:
    int mMax_5n(int a,int b,int c,int d,int e);
    void mSalt_Filter();
    void mTraspuesta();
    cv::Mat aMatrix1;
    cv::Mat aMatrix2;
    int aN;//filas
    int aM;//columnas
};

#endif	/* FILTRO_H */

