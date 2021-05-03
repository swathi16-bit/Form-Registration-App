#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void mainwindow::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->lbl_image->width(),Qt::SmoothTransformation);
            ui->lbl_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {

        }
    }
}

void mainwindow::on_pushButton_2_clicked()
{
    /*swetaa_from2 swetaaform2;
    swetaaform2.setModal(true);
    swetaaform2.exec();*/
    swetaaform2 =new swetaa_from2(this);
    swetaaform2->show();
    QMessageBox::information(this,"Swetaa_212218104169","You are redirected to next page");
}

void mainwindow::on_lineEdit_6_returnPressed()
{
    QRegularExpression re("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
       QRegularExpressionMatch match = re.match(ui->lineEdit_6->text());
       bool hasMatch = match.hasMatch();
       if (!hasMatch)
       {
          QMessageBox::information(this,"Swetaa_212218104169","Invalid Format");
       }
}
