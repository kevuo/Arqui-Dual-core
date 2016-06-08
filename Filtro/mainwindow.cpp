#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//qmessagebox
//https://www.youtube.com/watch?v=tKdfpA74HYY
//QMessageBox::information(this, tr("Información"), tr("Imagen cargada correctamente"));

void MainWindow::on_pushButton_clicked()
{
    QString ruta = "";
    try {
        ruta = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "/home/wagner/Escritorio/Qt/Proyecto2", tr("Formato de imagen (*.png *.jpg *.bmp)"));
        if(ruta == "")
            QMessageBox::warning(this, tr("Información"), tr("Debe seleccionar una imagen, intente nuevamente"));
        else{
            string File = ruta.toStdString();
            this->aAdmImage = AdmImagen(File);
            QPixmap pixmap(ruta);
            ui->labelImagen1->setPixmap(pixmap);
        }

    } catch (...) {
        QMessageBox::critical(this, tr("Información"), tr("No se pudo abrir la imagen"));
    }

}

void MainWindow::on_paralelismo_sliderMoved()
{
    ui->labelPorcentaje->setText(QString::number(ui->paralelismo->value()));
}

void MainWindow::on_pushButtonIniciar_clicked()
{
    if (aAdmImage.mImage_Null()){
        this->aAdmImage=AdmImagen("Qpixmap.jpg");
        QPixmap pixmap("Qpixmap.jpg");
        ui->labelImagen1->setPixmap(pixmap);
    }
    double procTime;
    procTime = aAdmImage.mProcesar_Imagen((int)ui->paralelismo->value());
    cv::imwrite("Qpixmap.jpg",aAdmImage.mReconstruir());
    QPixmap pixmap("Qpixmap.jpg");
    ui->labelImagen2->setPixmap(pixmap);
    ui->label_3->setText(QString::number(procTime));
}
