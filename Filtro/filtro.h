/* 
 * File:   filtro.h
 * Author: M. Taylor
 *
 * Created on June 1, 2016, 10:03 AM
 */

#ifndef FILTRO_H
#define	FILTRO_H

#include <iostream>
#include <fstream>
using namespace std;


class Filtro
{
public:
    Filtro();
    Filtro(int **Matrix, int N, int M);
    void mSet_Matrix(int **Matrix);
    int** mGet_Matrix();
    void mProcesar_Imagen();
    bool mImage_Null();
    void mPrint_Matrix(int **matrix, int N, int M);

private:
    int mMax_5n(int a,int b,int c,int d,int e);
    void mSalt_Filter();
    void mTraspuesta();
    int** aMatrix1;
    int** aMatrix2;
    int aN;//filas
    int aM;//columnas
};

#endif	/* FILTRO_H */

