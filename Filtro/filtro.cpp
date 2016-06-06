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

void Filtro::mProcesar_Imagen(int distribution){
    //memoria de datos para enviar
    unsigned char **dataTransfer;
    dataTransfer = new unsigned char*[aN*distribution/100];
    for (int i=0; i<aN*distribution/100; i++){
        dataTransfer[i] = new unsigned char[aM];
    }

    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        if(id==0) mSalt_Filter(distribution);
        if(id==1){
            //enviar datos
            //polling
        }
    }

    //reconstruir
    mReconstruir(dataTransfer,distribution);
    mTraspuesta();

    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        if(id==0) {
            mSalt_Filter(distribution);
        }
        if(id==1){
            //enviar datos
            //polling
        }
    }

    //reconstruir
    mReconstruir(dataTransfer,distribution);
    mTraspuesta();

    // releasing memory
    for (int i=0; i<aN*distribution/100; i++) {
        delete [] dataTransfer[i];
    }
    delete [] dataTransfer;

}

int Filtro::mMax_5n(int a, int b, int c, int d, int e) {
    int max = (a < b) ? b : a;
    max = (max < c) ? c : max;
    max = (max < d) ? d : max;
    return (max < e) ? e : max;
}

void Filtro::mReconstruir(unsigned char **dataTransfer,int distribution){
    for (int i=0; i<aN*distribution/100; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix2 .at<uchar>(i,j) = dataTransfer[i][j];
        }
    }
}

void Filtro::mSalt_Filter(int distribution) {
    for (int i = (aN*distribution/100); i < aN; i++) {
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
