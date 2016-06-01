
#include <iostream>
#include <fstream>
using namespace std;

int max5n (int a,int b,int c,int d,int e){
    int max = (a<b)? b:a;
    max = (max<c)? c:max;
    max = (max<d)? d:max;
    return (max<e)? e:max;
}

void saltFilter(int **matrix, int N, int M, int **result) {
    for (int i = 0; i < N; i++) {
        for (int j = 2; j < M-2; j++) {
            result[i][j] = max5n(matrix[i][j-2],matrix[i][j-1],matrix[i][j],matrix[i][j+1],matrix[i][j+2]);
        }
    }
}

void printMatrix(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    int **Matrix, **Temporal;

    N = 10;//filas
    M = 10;//columnas
    Matrix = new int*[N];
    Temporal = new int*[N];
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[M];
        Temporal[i] = new int[M];
    }

    saltFilter (Matrix,5,M,Temporal);
    printMatrix(Matrix, N, M);
    printMatrix(Temporal, N, M);

    for (int i = 0; i < N; i++) {
        delete [] Matrix[i];
        delete [] Temporal[i];
    }
    delete [] Matrix;
    delete [] Temporal;
}


