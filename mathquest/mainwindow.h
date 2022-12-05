#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QPushButton>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QCryptographicHash>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playBtn_clicked();

    void on_customBtn_clicked();

    void on_sign_sec_clicked();

    void on_login_sec_clicked();

    void on_lsbackBtn_clicked();

    void on_login_btn_clicked();

    void on_signup_btn_clicked();

    void check_db_open();

    void on_cstmbackBtn_clicked();

    void on_addIndex_clicked();

    void on_editIndex_clicked();

    void on_reviewerBtn_clicked();

    void on_addBtn_cat_clicked();

    void on_difficultyCBox_activated(int index);

    void on_addtrueBtn_clicked();

    void on_addfalseBtn_clicked();

    void on_addaBtn_clicked();

    void on_addbBtn_clicked();

    void on_addcBtn_clicked();

    void on_adddBtn_clicked();

    void on_addBtn_clicked();

    void on_addbackBtn_clicked();

    void on_lbbackBtn_clicked();

    void on_aubackBtn_clicked();

    void on_ibackBtn_clicked();

    void on_nextBtn_2_clicked();

    void on_readyBtn_clicked();

    void on_nextBtn_clicked();

    void on_diffCBox_activated(int index);

    void on_pauseBtn_clicked();

    void on_quesnumCBox_activated(int index);

    void on_submitBtn_clicked();

    void on_menuBtn_clicked();

    void maxnum(QString diff_, int cat_id);

    void timer_();

    void Showdiff(int cat_id);

    void on_aboutusBtn_clicked();

    void on_lbBtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
