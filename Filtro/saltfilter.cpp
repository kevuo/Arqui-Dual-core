#include "saltfilter.h"
#include "ui_saltfilter.h"



SaltFilter::SaltFilter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaltFilter)
{
    ui->setupUi(this);
}

SaltFilter::~SaltFilter()
{
    delete ui;
}

void SaltFilter::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Abrir Imagen"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    string File = fileName.toStdString();
    if (fileName.size()==0)return;
    this->aAdmImage = AdmImagen(File);
    QPixmap Aux(fileName);
    ui->ImageShow->setPixmap(Aux);
    ui->ImageShow->setAlignment(0);
}

void SaltFilter::on_Procesar_pressed()
{
    if (aAdmImage.mImage_Null()){
        this->aAdmImage=AdmImagen("Qpixmap.jpg");
    }
    //aAdmImage.mProcesar_Imagen((int)ui->CantDiv->value());
    aAdmImage.mProcesar_Imagen();
    cv::imwrite("Qpixmap.jpg",aAdmImage.mReconstruir());
    QPixmap Aux("Qpixmap.jpg");
    ui->ImageShow->setPixmap(Aux);
    ui->ImageShow->setAlignment(0);
    ui->actionGuardar->setEnabled(true);
}

void SaltFilter::on_actionSalir_triggered()
{
    this->destroy(true,true);
}

void SaltFilter::on_actionGuardar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
          tr("Guardar Imagen"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    if (fileName.size()==0)return;
    string File = fileName.toStdString();
    cv::imwrite(File,aAdmImage.mReconstruir());
}
