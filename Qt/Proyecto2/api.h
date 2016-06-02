#ifndef API_H
#define API_H

extern "C" {
    void DMAWriteMatriz();
    void DMAReadMatriz();
    void DMAWriteDimensiones();
    void ReadNiosStatus();
    void WriteDataReadyStatus();
    //int hola(int zumbi);
}

class API{
    public:
        API();
        void escribirMatriz();
        void leerMatriz();
        void escribirDimensiones();
        void obtenerNiosStatus();
        void escribirEstadoDatoListo();
};

#endif // API_H
