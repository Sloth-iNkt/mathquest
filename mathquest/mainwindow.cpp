#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QString>
#include <QInputDialog>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRandomGenerator64>

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

