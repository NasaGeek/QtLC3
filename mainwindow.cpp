#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QFileDialog>

QString int2lc3str(int num);
QString GetTranslation(QString mInst);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 65536; ++i){
          QTableWidgetItem* mItem = new QTableWidgetItem;
          QTableWidgetItem* mItemD = new QTableWidgetItem;
          QTableWidgetItem* mItemT = new QTableWidgetItem;
          QString nop = "x0000";
          QString trans = GetTranslation(nop);
          mItemD->setText(nop);
          mItem->setText("x" + QString("%1").arg(i,4, 16, QChar('0')));
          mItemT->setText(trans);
          ui->tableMem->setItem(i,1,mItem);
          ui->tableMem->setItem(i,2,mItemD);
          ui->tableMem->setItem(i,3,mItemT);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("Open Program"), QDir::currentPath(), tr("Object Files (*.obj);;All files (*.*)"));
}

void MainWindow::on_actionReset_triggered()
{
    
}

void MainWindow::on_actionStep_triggered()
{
    
}

void MainWindow::on_actionNext_triggered()
{
    
}

void MainWindow::on_actionContinue_triggered()
{
    
}

void MainWindow::createGrid(){

}

void MainWindow::on_actionAbout_triggered()
{
//    QMessageBox mAbout(this);
    QMessageBox::about(this, "About LC3-sim", "This QT LC3 Simulator was written by:\n Michael Bartling\nmichael.bartling15@gmail.com\ngithub.com/mbartling\n\nUniversity of Texas at Austin\nComputer Architecture and Embedded Processing Group.\nSpring 2015");
}

int lc3hex2int(QString& mStr){
    QString temp = mStr;
    bool ok;
    int res = temp.remove(0,1).toInt(&ok,16);
    qDebug() << "Converting from x to int status: " << ok;
    return res;

}

QString int2lc3str(int num){
    return QString("x%1").arg(num,4, 16, QChar('0'));
}

void MainWindow::on_GoButton_clicked()
{
    QString mAddr = ui->lineMem->text();
    bool ok;
    mAddr.remove(0,1);
    int mLoc = mAddr.toInt(&ok, 16);
    if(ok){
        ui->tableMem->setCurrentCell(mLoc, 1);
    }
}

void MainWindow::on_lineMem_returnPressed()
{
    QString mAddr = ui->lineMem->text();
    bool ok;
    mAddr.remove(0,1);
    int mLoc = mAddr.toInt(&ok, 16);
    if(ok){
        ui->tableMem->setCurrentCell(mLoc, 1);
    }
}
void MainWindow::setCurrentRow(int rowId){
    ui->tableMem->setCurrentCell(rowId, 1);

}
QString GetTranslation(QString mInst){
    QString res;
    if(mInst == "x0000") res = "NOP";
    else res = ".FILL " + mInst;

    return res;
}

void MainWindow::on_actionConsole_triggered()
{

}
