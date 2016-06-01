#ifndef ADMXML_H
#define ADMXML_H
#include <ccreararchivoxml.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <iostream>
class AdmXML
{
public:
    AdmXML();
    void mCrear_XML(QString pRuta, cv::Mat pMatriz, int* pSignificados);
private:
    CCrearArchivoXml aCrearXML;
};

#endif // ADMXML_H
