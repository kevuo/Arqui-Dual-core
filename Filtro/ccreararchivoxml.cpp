#include "ccreararchivoxml.h"




/*
*
mCrea_Mapa_Xml_String
Autor: Michael Varela
Resumen: Se encarga de crear un QString que contiene la estructura de mapa.xml, para ello
se utiliza informacion de la matriz que contiene los datos del mapa, para asi ir generando
el mapa.xml completo.
Entradas: no entradas.
Salidas:1 salida, un QString que contiene la estructura de mapa.xml en formato string.
Restricciones: La matriz debe ser diferente de null.
Version: 1.0
*
*/
QString CCrearArchivoXml::mCrea_Mapa_Xml_String(cv::Mat pMatriz, int* pSignificados){
    QString aPartea = "<mapa>""\n\t<Regiones>";
    QString aParteb = "";


    for(int i = 0;i<pMatriz.rows; i++){
        for(int j=0; j<pMatriz.cols;j++){
        aParteb = "\n\t\t<region x=\"";
        aParteb += QString::number(i);
        aParteb += "\" y=\"";
        aParteb += QString::number(j);
        aParteb += "\" color=\"";
        aParteb += QString::number(pMatriz.at<cv::Vec3b>(i,j)[0]);
        aParteb += "\"/>";
        aPartea+=aParteb;
        }
    }
    aPartea += "\n\t</Regiones>";
    aPartea += "\n\t<Valores>";
    for(int j = 0;j<= 26; j++){

        aParteb = "\n\t\t<valor color=\"";
        aParteb += QString::number(j);
        aParteb += "\" dificultad=\"";
        aParteb += QString::number(*(pSignificados));
        aParteb += "\"/>";
        aPartea+=aParteb;
        pSignificados++;
    }
    aPartea += "\n\t</Valores>";

    aPartea += "\n</mapa>";
    return aPartea;
}






/*
*
mCrea_Mapa_Xml
Autor: Michael Varela
Resumen: Se encarga de crear el archivo mapa.xml en una ruta determinada.
Entradas: no entradas.
Salidas:no salidas.
Restricciones: La ruta elegida debe ser correcta, el mapa.xml en formato
string debe estar bien estructura para asi poder crear el archivo xml.
Version: 1.0
*
*/
void CCrearArchivoXml::mCrea_Mapa_Xml(QString pMapaxmlstring, QString pRuta){
    QFile file(pRuta);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << pMapaxmlstring;
        stream.flush();
        file.close();
    }
}




