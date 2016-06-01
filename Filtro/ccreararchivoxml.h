#ifndef CCREARARCHIVOXML_H
#define CCREARARCHIVOXML_H

#include <QtCore>
#include <QDebug>
#include <QString>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class CCrearArchivoXml
{
public:
    QString mCrea_Mapa_Xml_String(cv::Mat pMatriz,int* pSignificados);
    void mCrea_Mapa_Xml(QString pMapaxmlstring, QString pRuta);
};

#endif // CCREARARCHIVOXML_H
