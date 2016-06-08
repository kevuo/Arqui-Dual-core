/* 
 * File:   filtro.h
 * Author: M. Taylor
 *
 * Created on June 1, 2016, 10:03 AM
 */

#ifndef FILTRO_H
#define	FILTRO_H

#include <api.h>
#include <omp.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

class Filtro
{
public:
    Filtro();
    ~Filtro();
    Filtro(cv::Mat pImagen, int pN, int pM);
    cv::Mat mGet_Matrix();
    void mProcesar_Imagen(int distribution);

private:
    int mMax_5n(int a,int b,int c,int d,int e);
    void mSalt_Filter(int distribution);
    void mConstruir(vector<uchar> *dataTransfer);
    void mReconstruir(vector<uchar>  dataTransfer,int distribution);
    void mTraspuesta();
    void timerStart();
    double timerStop();
    void printMatrix(int **matrix, int N, int M);
    cv::Mat aMatrix1;
    cv::Mat aMatrix2;
    int aN;//filas
    int aM;//columnas
    double startTime;
};

#endif	/* FILTRO_H */

