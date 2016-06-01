#ifndef API_H
#define API_H


class API{
    public:
        API();
        void writeDMAMatriz(int total);
        void readDMAMatriz();
        void writeDMASize(int total);
        void writeStatus(int status);
        void readStatus();
};

#endif // API_H
