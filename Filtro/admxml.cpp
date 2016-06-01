#include "admxml.h"

AdmXML::AdmXML()
{
}
void AdmXML::mCrear_XML(QString pRuta, cv::Mat pMatriz, int* pSignificados){
    this->aCrearXML.mCrea_Mapa_Xml(this->aCrearXML.mCrea_Mapa_Xml_String(pMatriz,pSignificados),pRuta);
}
