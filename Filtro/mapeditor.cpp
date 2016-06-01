#include "mapeditor.h"
#include "ui_mapeditor.h"



MapEditor::MapEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapEditor)
{
    ui->setupUi(this);
    ui->radioButton01->setVisible(false);
    ui->radioButton02->setVisible(false);
    ui->radioButton03->setVisible(false);
    ui->radioButton04->setVisible(false);
    ui->radioButton05->setVisible(false);
    ui->radioButton06->setVisible(false);
    ui->radioButton07->setVisible(false);
    ui->radioButton08->setVisible(false);
    ui->radioButton09->setVisible(false);
    ui->radioButton10->setVisible(false);
    ui->radioButton11->setVisible(false);
    ui->radioButton12->setVisible(false);
    ui->radioButton13->setVisible(false);
    ui->radioButton14->setVisible(false);
    ui->radioButton15->setVisible(false);
    ui->radioButton16->setVisible(false);
    ui->radioButton17->setVisible(false);
    ui->radioButton18->setVisible(false);
    ui->radioButton19->setVisible(false);
    ui->radioButton20->setVisible(false);
    ui->radioButton21->setVisible(false);
    ui->radioButton22->setVisible(false);
    ui->radioButton23->setVisible(false);
    ui->radioButton24->setVisible(false);
    ui->radioButton25->setVisible(false);
    ui->radioButton26->setVisible(false);
    ui->radioButton27->setVisible(false);
    ui->tableView->setVisible(false);
    ui->actionGuardar->setEnabled(false);
    aEdit=false;

    aDelegate= new Delegate(this);
    aModel = new QStandardItemModel(9,3,this);
    aColor=0;

    for(int row=0;row<9;row++){
        for(int col=0;col<3;col++){
            QModelIndex Index= aModel->index(row,col,QModelIndex());
            aModel->setData(Index,row+1+col*9-2);

        }
    }

    ui->tableView->setModel(aModel);
    ui->tableView->setItemDelegate(aDelegate);

}

MapEditor::~MapEditor()
{
    delete ui;
}

void MapEditor::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Abrir Imagen"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    string File = fileName.toStdString();
    if (fileName.size()==0)return;
    aAdmImage=AdmImagen(File);
    aAdmMatriz=AdmMatriz();
    QPixmap Aux(fileName);
    ui->ImageShow->setPixmap(Aux);
    ui->ImageShow->setAlignment(0);
    ui->Siguiente->setEnabled(false);
}

void MapEditor::on_Procesar_pressed()
{
    if (aAdmImage.mImage_Null()){
        aAdmImage=AdmImagen("Qpixmap.jpg");
    }
    aAdmImage.mProcesar_Imagen((int)ui->CantDiv->value());
    cv::imwrite("Qpixmap.jpg",aAdmImage.mReconstruir());
    QPixmap Aux("Qpixmap.jpg");
    ui->ImageShow->setPixmap(Aux);
    ui->ImageShow->setAlignment(0);
    AdmMatriz Matriz(aAdmImage.mGet_Image());
    aAdmMatriz=Matriz;
    aAdmImage.mSet_Image("Qpixmap.jpg");
    ui->Siguiente->setEnabled(true);
    ui->actionGuardar->setEnabled(true);
}

void MapEditor::on_Siguiente_pressed()
{
    if (aAdmImage.mImage_Null()){
        on_Procesar_pressed();
    }

    ui->actionAbrir->blockSignals(true);
    ui->Procesar->setVisible(false);
    ui->label->setVisible(false);
    ui->Siguiente->setVisible(false);
    ui->CantDiv->setVisible(false);
    ui->radioButton01->setVisible(true);
    ui->radioButton02->setVisible(true);
    ui->radioButton03->setVisible(true);
    ui->radioButton04->setVisible(true);
    ui->radioButton05->setVisible(true);
    ui->radioButton06->setVisible(true);
    ui->radioButton07->setVisible(true);
    ui->radioButton08->setVisible(true);
    ui->radioButton09->setVisible(true);
    ui->radioButton10->setVisible(true);
    ui->radioButton11->setVisible(true);
    ui->radioButton12->setVisible(true);
    ui->radioButton13->setVisible(true);
    ui->radioButton14->setVisible(true);
    ui->radioButton15->setVisible(true);
    ui->radioButton16->setVisible(true);
    ui->radioButton17->setVisible(true);
    ui->radioButton18->setVisible(true);
    ui->radioButton19->setVisible(true);
    ui->radioButton20->setVisible(true);
    ui->radioButton21->setVisible(true);
    ui->radioButton22->setVisible(true);
    ui->radioButton23->setVisible(true);
    ui->radioButton24->setVisible(true);
    ui->radioButton25->setVisible(true);
    ui->radioButton26->setVisible(true);
    ui->radioButton27->setVisible(true);
    ui->tableView->setVisible(true);
    aEdit=true;
}

void MapEditor::on_actionSalir_triggered()
{
    this->destroy(true,true);
}

void MapEditor::on_ImageShow_clicked()
{
    if (aEdit==false)return;
    int X= cursor().pos().x()-this->pos().x()-29;
    int Y= cursor().pos().y()-this->pos().y()-50;
    if(X>aAdmImage.mGet_Width()||Y>aAdmImage.mGet_Height())return;
    X= X/aAdmImage.mGet_Pixel_Size();
    Y= Y/aAdmImage.mGet_Pixel_Size();
    aAdmMatriz.mCambiar_Color(aColor,Y,X);
    cv::imwrite("Qpixmap.jpg",aAdmImage.mReconstruir(aAdmMatriz.mGet_Matriz()));
    QPixmap Aux("Qpixmap.jpg");
    ui->ImageShow->setPixmap(Aux);
    ui->ImageShow->setAlignment(0);
}

void MapEditor::on_actionGuardar_triggered()
{
    int Color=0;
    for(int col=0;col<3;col++){
        for(int row=0;row<9;row++){
            QModelIndex Index= aModel->index(row,col,QModelIndex());
            aAdmMatriz.mCambiar_Significado(Color,ui->tableView->model()->data(Index,Qt::EditRole).toInt());
            Color++;
        }
    }
    QString fileName = QFileDialog::getSaveFileName(this,
          tr("Guardar XML"), "/home/", tr("XML Files (*.xml)"));
    if (fileName.size()==0)return;
    this->aAdmXML.mCrear_XML(fileName,aAdmMatriz.mGet_Matriz(),aAdmMatriz.mGet_Significados());
}

// Seccion FUERZA BRUTA... Cuidado, lea bajo su propio riesgo ///////////////////////////

void MapEditor::on_radioButton01_clicked()
{
    aColor=0;
    QModelIndex Index= aModel->index(0,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton02_clicked()
{
    aColor=1;
    QModelIndex Index= aModel->index(1,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton03_clicked()
{
    aColor=2;
    QModelIndex Index= aModel->index(2,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton04_clicked()
{
    aColor=3;
    QModelIndex Index= aModel->index(3,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton05_clicked()
{
    aColor=4;
    QModelIndex Index= aModel->index(4,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton06_clicked()
{
    aColor=5;
    QModelIndex Index= aModel->index(5,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton07_clicked()
{
    aColor=6;
    QModelIndex Index= aModel->index(6,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton08_clicked()
{
    aColor=7;
    QModelIndex Index= aModel->index(7,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton09_clicked()
{
    aColor=8;
    QModelIndex Index= aModel->index(8,0,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton10_clicked()
{
    aColor=9;
    QModelIndex Index= aModel->index(0,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton11_clicked()
{
    aColor=10;
    QModelIndex Index= aModel->index(1,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton12_clicked()
{
    aColor=11;
    QModelIndex Index= aModel->index(2,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton13_clicked()
{
    aColor=12;
    QModelIndex Index= aModel->index(3,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton14_clicked()
{
    aColor=13;
    QModelIndex Index= aModel->index(4,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton15_clicked()
{
    aColor=14;
    QModelIndex Index= aModel->index(5,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton16_clicked()
{
    aColor=15;
    QModelIndex Index= aModel->index(6,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton17_clicked()
{
    aColor=16;
    QModelIndex Index= aModel->index(7,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton18_clicked()
{
    aColor=17;
    QModelIndex Index= aModel->index(8,1,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton19_clicked()
{
    aColor=18;
    QModelIndex Index= aModel->index(0,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton20_clicked()
{
    aColor=19;
    QModelIndex Index= aModel->index(1,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton21_clicked()
{
    aColor=20;
    QModelIndex Index= aModel->index(2,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton22_clicked()
{
    aColor=21;
    QModelIndex Index= aModel->index(3,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton23_clicked()
{
    aColor=22;
    QModelIndex Index= aModel->index(4,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton24_clicked()
{
    aColor=23;
    QModelIndex Index= aModel->index(5,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton25_clicked()
{
    aColor=24;
    QModelIndex Index= aModel->index(6,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton26_clicked()
{
    aColor=25;
    QModelIndex Index= aModel->index(7,2,QModelIndex());
    ui->tableView->edit(Index);
}
void MapEditor::on_radioButton27_clicked()
{
    aColor=26;
    QModelIndex Index= aModel->index(8,2,QModelIndex());
    ui->tableView->edit(Index);
}


