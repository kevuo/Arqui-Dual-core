#include "filtro.h"

Filtro::Filtro() {
    aN = 10; //filas
    aM = 10; //columnas
    aMatrix1 = new int*[aN];
    aMatrix2 = new int*[aN];
    for (int i = 0; i < aN; i++) {
        aMatrix1[i] = new int[aM];
        aMatrix2[i] = new int[aM];
    }

    mSalt_Filter();
    mTraspuesta();
    mSalt_Filter();
    mTraspuesta();

    mPrint_Matrix(aMatrix1, aN, aM);
    mPrint_Matrix(aMatrix2, aN, aM);

    for (int i = 0; i < aN; i++) {
        delete [] aMatrix1[i];
        delete [] aMatrix2[i];
    }
    delete [] aMatrix1;
    delete [] aMatrix2;
}

Filtro::Filtro(int** matrix, int N, int M) {
    aN = N; //filas
    aM = M; //columnas
    aMatrix1 = matrix;
    aMatrix2 = new int*[aN];
    for (int i = 0; i < aN; i++) {
        aMatrix2[i] = new int[aM];
    }
}

Filtro::mSet_Matrix(int **Matrix) {
    aMatrix1 = Matrix;
    aMatrix2 = new int*[aN];
    for (int i = 0; i < aN; i++) {
        aMatrix2[i] = new int[aM];
    }
}

Filtro::mGet_Matrix() {
    return aMatrix1;
}

Filtro::mProcesar_Imagen(){
    mSalt_Filter();
    mTraspuesta();
    mSalt_Filter();
    mTraspuesta();
}

Filtro::mPrint_Matrix(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

Filtro::mMax_5n(int a, int b, int c, int d, int e) {
    int max = (a < b) ? b : a;
    max = (max < c) ? c : max;
    max = (max < d) ? d : max;
    return (max < e) ? e : max;
}

Filtro::mSalt_Filter() {
    for (int i = 0; i < aN; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix2[i][j] = mMax_5n(matrix[i][j - 2], aMatrix1[i][j - 1], aMatrix1[i][j], aMatrix1[i][j + 1], aMatrix1[i][j + 2]);
        }
    }
}

Filtro::mTraspuesta() {
    for (int i = 0; i < aN; i++) {
        for (int j = 2; j < aM - 2; j++) {
            aMatrix1[i][j] = aMatrix2[j][i];
        }
    }
}