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
            QPixmap pixmap(ruta);
            ui->labelImagen1->setPixmap(pixmap);
            QPixmap imagen2("/home/wagner/Escritorio/Qt/Proyecto2/caballo.jpg");
            ui->labelImagen2->setPixmap(imagen2);
        }

    } catch (...) {
        QMessageBox::critical(this, tr("Información"), tr("No se pudo abrir la imagen"));
    }

}

void MainWindow::on_paralelismo_sliderMoved(int position)
{
    ui->labelPorcentaje->setText(QString::number(ui->paralelismo->value()));
}

void MainWindow::on_pushButtonIniciar_clicked()
{
    ui->label_3->setText(QString::number(ui->paralelismo->value()));
}
