#ifndef API_H
#define API_H

extern "C" {
    int iniciarPCIe();
    int hola(int zumbi);
}

class API{
    public:
        API();
        void inicio();
        void writeDMAMatriz(int total);
        void readDMAMatriz();
        void writeDMASize(int total);
        void writeStatus(int status);
        void readStatus();
};

#endif // API_H
