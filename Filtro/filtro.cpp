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
    vector<uchar> dataTransfer;

    uint* dimensions = new uint[2];
    dimensions[0]=aN*distribution/100;
    dimensions[1]=aM;

    // starting timer
    timerStart();

    //construir
    mConstruir(&dataTransfer);
    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        if(id==0) mSalt_Filter(distribution);
        if(id==1){
            //enviar datos
            escribirMatriz(dataTransfer, (aN*distribution/100)+aM);
            escribirDimensiones(dimensions, 2);
            escribirEstadoDatoListo(1);
            //polling
            int status = 0;
            while(*status==0){
                obtenerNiosStatus(status);
            }
            //recibir dato
            leerMatriz((aN*distribution/100)+aM, dataTransfer);
        }
    }

    //reconstruir
    mReconstruir(dataTransfer,distribution);
    mTraspuesta();

    //construir
    mConstruir(&dataTransfer);
    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        if(id==0) {
            mSalt_Filter(distribution);
        }
        if(id==1){
            //enviar datos
            escribirMatriz(dataTransfer, (aN*distribution/100)+aM);
            escribirDimensiones(dimensions, 2);
            escribirEstadoDatoListo(1);
            //polling
            int status = 0;
            while(*status==0){
                obtenerNiosStatus(status);
            }
            //recibir dato
            leerMatriz((aN*distribution/100)+aM, dataTransfer);
        }
    }

    //reconstruir
    mReconstruir(dataTransfer,distribution);
    mTraspuesta();


    // stopping timer
    double elapsedTime = timerStop();
    cout << "Duracion: " << elapsedTime << " seconds" << std::endl;

    delete [] dimensions;
}

int Filtro::mMax_5n(int a, int b, int c, int d, int e) {
    int max = (a < b) ? b : a;
    max = (max < c) ? c : max;
    max = (max < d) ? d : max;
    return (max < e) ? e : max;
}

void Filtro::mConstruir(vector<uchar>* dataTransfer){
    if (aMatrix1.isContinuous()) {
      dataTransfer->assign(aMatrix1.datastart, aMatrix1.dataend);
    } else {
      for (int i = 0; i < aMatrix1.rows; i++) {
        dataTransfer->insert(dataTransfer->end(), aMatrix1.ptr<uchar>(i), aMatrix1.ptr<uchar>(i)+aMatrix1.cols);
      }
    }
}

void Filtro::mReconstruir(vector<uchar> dataTransfer,int distribution){
    for (int i=0; i<aN*distribution/100; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix2.at<uchar>(i,j) = dataTransfer.at(j+i*aN);
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

// Starts timer and resets the elapsed time
void Filtro::timerStart(){
    struct timeval tod;
    gettimeofday(&tod, 0);
    startTime = (double)tod.tv_sec + ((double)tod.tv_usec * 1.0e-6);
}

// Stops the timer and returns the elapsed time
double Filtro::timerStop(){
    struct timeval tod;
    gettimeofday(&tod, 0);
    return ((double)tod.tv_sec + ((double)tod.tv_usec * 1.0e-6)) - startTime;
}

// Prints matrix to standard output
void Filtro::printMatrix(int **matrix, int N, int M){
    int errores = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            bool igual = ((int)matrix[i][j]==(int)aMatrix2 .at<uchar>(j,i));
            if(!igual){
                errores++;
            }
        }
    }
    cout <<"errores: "<<errores<<endl;
}
