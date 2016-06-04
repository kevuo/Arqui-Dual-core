#include "filtro.h"

Filtro::Filtro() {}

Filtro::~Filtro(){}

Filtro::Filtro(cv::Mat pImagen, int pN, int pM) {
    aN = pN; //filas
    aM = pM; //columnas
    cv::Mat Matrix1(pN,pM,CV_8UC1);
    cv::Mat Matrix2(pN,pM,CV_8UC1);
    cvtColor(pImagen,Matrix1,CV_RGB2GRAY);
    aMatrix1 = Matrix1;
    aMatrix2 = Matrix2;
}

cv::Mat Filtro::mGet_Matrix() {
    return aMatrix1;
}

void Filtro::mProcesar_Imagen(){
    mSalt_Filter();
    mTraspuesta();
    mSalt_Filter();
    mTraspuesta();
}

int Filtro::mMax_5n(int a, int b, int c, int d, int e) {
    int max = (a < b) ? b : a;
    max = (max < c) ? c : max;
    max = (max < d) ? d : max;
    return (max < e) ? e : max;
}

void Filtro::mSalt_Filter() {
    for (int i = 0; i < aN; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix2 .at<uchar>(i,j) = mMax_5n(
                        aMatrix1 .at<uchar>(i,j-2),
                        aMatrix1 .at<uchar>(i,j-1),
                        aMatrix1 .at<uchar>(i,j),
                        aMatrix1 .at<uchar>(i,j+1),
                        aMatrix1 .at<uchar>(i,j+2));
        }
    }
}

void Filtro::mTraspuesta() {
    for (int i = 0; i < aN; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix1 .at<uchar>(i,j) = aMatrix2 .at<uchar>(j,i);
        }
    }
}
