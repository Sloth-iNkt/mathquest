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

    void timer_();

    void maxnum(QString diff_, int cat_id);

    void Showdiff (int cat_id);

    void ShowCat();

    void on_readyBtn_clicked();

    void on_lbbackBtn_clicked();

    void on_ibackBtn_clicked();

    void on_aubackBtn_clicked();

    void on_aboutusBtn_clicked();

    void on_lbBtn_clicked();

    void on_nextBtn_2_clicked();

    void on_nextBtn_clicked();

    void on_diffCBox_activated(int index);

    void on_pauseBtn_clicked();

    void on_quesnumCBox_activated(int index);

    void on_submitBtn_clicked();

    void on_menuBtn_clicked();

    void on_retryBtn_clicked();

    void on_resueBtn_clicked();

    void on_addSaveBtn_clicked();

    void on_aBtn_clicked();

    void on_bBtn_clicked();

    void on_cBtn_clicked();

    void on_dbtn_clicked();

    void on_trueBtn_clicked();

    void on_falseBtn_clicked();

    void on_leadsubmitBtn_clicked();

    void on_catCBox_activated(int index);

    void item_num(int range_, int num);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

    void showtable(int user_id);

    void on_editBtn_clicked();

    void on_cat_combo_activated(int index);

    void on_diif_combo_activated(int index);

    void showleaderboard(int cat_id, QString cat, QString diff, int q_num);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
