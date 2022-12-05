#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QString>
#include <QInputDialog>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRandomGenerator64>

QString active_name, active_category;
int active_user_id, active_category_id;
int q_num_e = 1, q_num_m =1, q_num_h = 1;
bool inp_ans_e, inp_ans_m, inp_ans_h;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainStack->setCurrentIndex(0);
    ui->addeditStack->setCurrentIndex(0);
    ui->optionCBox->setCurrentIndex(0);
    ui->ls_box->setCurrentIndex(0);
    ui->diffStacked->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./sqlite.db");
    if (db.open()) {
        qDebug() << "db is open";
    } else {
        qDebug() << "failed to open db";
    }

    QSqlQuery qry(db);
    qry.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery qry1(db);
    QSqlQuery qry2(db);
    QSqlQuery qry3(db);
    QSqlQuery qry4(db);
    QSqlQuery qry5(db);
    QSqlQuery qry6(db);
    QSqlQuery qry7(db);

    qry1.prepare("CREATE TABLE IF NOT EXISTS users ("
                "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                "name VARCHAR(20) not null unique,"
                "hashed_pass VARCHAR(20) not null);");
    qry2.prepare("CREATE TABLE IF NOT EXISTS category ("
                 "ID integer PRIMARY KEY AUTOINCREMENT not null,"
                 "category VARCHAR(20) not null,"
                 "note VARCHAR(100),"
                 "owner_id integer not null,"
                 "foreign key (owner_id) references users(ID));");
    qry3.prepare("CREATE TABLE IF NOT EXISTS questionsEasy ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "answer BOOLEAN not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry4.prepare("CREATE TABLE IF NOT EXISTS questionMedium ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "option1 VARCHAR(100) not null,"
                 "option2 VARCHAR(100) not null,"
                 "option3 VARCHAR(100) not null,"
                 "option4 VARCHAR(100) not null,"
                 "answer VARCHAR(100) not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry5.prepare("CREATE TABLE IF NOT EXISTS questionHard ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "answer VARCHAR(100) not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry6.prepare("CREATE TABLE IF NOT EXISTS leaderboard ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "name VARCHAR(20) not null unique,"
                 "difficulty VARCHAR(20) not null,"
                 "score integer not null);");
    qry7.prepare("CREATE TABLE IF NOT EXISTS reviewers ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "file_name VARCHAR(50) not null,"
                 "file blob null);");
    if (!qry1.exec() ||
            !qry2.exec() ||
            !qry3.exec() ||
            !qry4.exec() ||
            !qry5.exec() ||
            !qry6.exec() ||
            !qry7.exec()) {
        qDebug() << "table not created";
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::check_db_open() {
    if (!db.isOpen()) {
        qDebug() << "db not connected";
        return;
    }
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void addUsers (QString name, QString hashed_pass) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO users ("
                "name,"
                "hashed_pass)"
                "VALUES (?, ?);");
    qry.addBindValue(name);
    qry.addBindValue(hashed_pass);

    if (!qry.exec()) {
        qDebug() << "Error add user";
    }
}

void addCategory(QString category, QString note, int owner_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO category ("
                "category,"
                "note,"
                "owner_id)"
                "VALUES (?, ?, ?);");
    qry.addBindValue(category);
    qry.addBindValue(note);
    qry.addBindValue(owner_id);
    if (!qry.exec()) {
        qDebug() << "Error add category";
    }
}


void MainWindow::on_playBtn_clicked()
{
    ui->MainStack->setCurrentIndex(1);
}


void MainWindow::on_customBtn_clicked()
{
    ui->MainStack->setCurrentIndex(6);
    ui->ls_box->setCurrentIndex(0);
//    ui->addeditStack->setCurrentIndex(0);
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("");
}


void MainWindow::on_login_sec_clicked()
{
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("");
    ui->ls_box->setCurrentIndex(0);

//    clear textbox in sign sec
    ui->pass_inp_auth_s->clear();
    ui->name_inp_auth_s->clear();
    ui->cpass_->clear();
    ui->error_msg->clear();
}


void MainWindow::on_sign_sec_clicked()
{
    ui->login_sec->setStyleSheet("");
    ui->sign_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                 "text-decoration: underline;");
    ui->ls_box->setCurrentIndex(1);

//    clear textbox in login sec
    ui->pass_inp_auth->clear();
    ui->name_inp_auth->clear();
    ui->error_msg_l->clear();
}


void MainWindow::on_lsbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
//    clear textbox in loginpg
    ui->pass_inp_auth_s->clear();
    ui->name_inp_auth_s->clear();
    ui->cpass_->clear();
    ui->error_msg->clear();
    ui->pass_inp_auth->clear();
    ui->name_inp_auth->clear();
    ui->error_msg_l->clear();
}


void MainWindow::on_signup_btn_clicked()
{
    QString name_inps, pass_inps, cpass_inps;
    check_db_open();

    name_inps = ui->name_inp_auth_s->text();
    pass_inps = ui->pass_inp_auth_s->text();
    cpass_inps = ui->cpass_->text();

    if (name_inps == "" ||
            pass_inps == "" ||
            cpass_inps == "") {
        ui->error_msg->setText("empty");
        return;
    }

    QSqlQuery qry(db);

    if  (qry.exec("SELECT name FROM users "
                 "WHERE name=\'" + name_inps + "\'")) {
        if (qry.next()) {
            ui->error_msg->setText(name_inps + " is already taken");
        } else {
            if (pass_inps == cpass_inps) {
                QString hashedPass = QCryptographicHash::hash((pass_inps.toLocal8Bit()),QCryptographicHash::Md5);
                ::addUsers(name_inps, hashedPass);
                ui->error_msg->setText("Acc created");
            } else {
                ui->error_msg->setText("pass not equal");
            }
        }
    }
}


void MainWindow::on_login_btn_clicked()
{
    QString name_inpl, pass_inpl, pass_inph;
    check_db_open();
    name_inpl = ui->name_inp_auth->text();
    pass_inpl = ui->pass_inp_auth->text();

    if (name_inpl == "" || pass_inpl == "") {
        ui->error_msg_l->setText("don't leave it blank");
        return;
    }

    pass_inph = QCryptographicHash::hash((pass_inpl.toLocal8Bit()),QCryptographicHash::Md5);

    QSqlQuery qry(db);
    if (qry.exec("SELECT name, ID FROM users "
             "WHERE name=\'" + name_inpl + "\' AND hashed_pass=\'" + pass_inph + "\'")) {
        if (qry.next()) {
            active_name = qry.value(0).toString();
            active_user_id = qry.value(1).toInt();

      //    clear textbox in loginpg
            ui->pass_inp_auth_s->clear();
            ui->name_inp_auth_s->clear();
            ui->cpass_->clear();
            ui->error_msg->clear();
            ui->pass_inp_auth->clear();
            ui->name_inp_auth->clear();
            ui->error_msg_l->clear();

            ui->namelineEdit->setText(active_name);
            ui->addIndex->setStyleSheet("color: red;");
            ui->addeditStack->setCurrentIndex(0);
            ui->MainStack->setCurrentIndex(7);
        }
        else {
            ui->error_msg_l->setText("wrong name or pass");
        }
    }
}


void MainWindow::on_cstmbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}




void MainWindow::on_addIndex_clicked()
{
    ui->addeditStack->setCurrentIndex(0);
    ui->addIndex->setStyleSheet("color: red;");
    ui->editIndex->setStyleSheet("");
}


void MainWindow::on_editIndex_clicked()
{
    ui->addeditStack->setCurrentIndex(1);
    ui->addIndex->setStyleSheet("");
    ui->editIndex->setStyleSheet("color: red;");
}

void MainWindow::on_reviewerBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "C://");
    ui->reviewereditLine->setText(filename);
}

void MainWindow::on_addBtn_cat_clicked()
{
    QString cat_inp, note_inp;
    cat_inp = ui->categorylineEdit->text();
    note_inp = ui->noteTextbox->text();

    if (cat_inp == "" || note_inp == "") {
        ui->onadderror->setText("empty");
        return;
    }
    QMessageBox msgBox;
     msgBox.setText("blah blah");
     msgBox.setInformativeText("Do you want to save your inputs?");
     msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
     msgBox.setDefaultButton(QMessageBox::Save);
     int ret = msgBox.exec();
     switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            ::addCategory(cat_inp, note_inp, active_user_id);
            active_category = cat_inp;

            ui->categorylineEdit->clear();
            ui->noteTextbox->clear();

            ui->MainStack->setCurrentIndex(8);
            ui->optionCBox->setCurrentIndex(0);
            ui->difficultyCBox->setCurrentIndex(0);
            ui->addcatLbl->setText(active_category);
            ui->nameLbl_4->setText(active_name);

//            ui->
            break;
        case QMessageBox::Discard:
           // Don't Save was clicked
            qDebug() << "bye";
            break;
     }

     QSqlQuery qry;

     if (qry.exec("SELECT ID FROM category WHERE ID = "
                  "(SELECT MAX(ID) FROM category);")) {
         if (qry.next()) {
             active_category_id = qry.value(0).toInt();
         }
     }
}


void MainWindow::on_difficultyCBox_activated(int index)
{
    if (index == 0) {
        ui->optionCBox->setCurrentIndex(index);
        ui->qnoLbl->setText(QString::number(q_num_e));
    } else if (index == 1) {
        ui->optionCBox->setCurrentIndex(index);
        ui->qnoLbl->setText(QString::number(q_num_m));
    } else {
        ui->optionCBox->setCurrentIndex(index);
        ui->qnoLbl->setText(QString::number(q_num_h));
    }
    ui->addtrueBtn->setStyleSheet("");
    ui->addfalseBtn->setStyleSheet("");
    ui->addaBtn->setStyleSheet("");
    ui->addbBtn->setStyleSheet("");
    ui->addcBtn->setStyleSheet("");
    ui->adddBtn->setStyleSheet("");
    ui->alineEdit->clear();
    ui->blineEdit->clear();
    ui->clineEdit->clear();
    ui->dlineEdit->clear();
    ui->hardLineEdit->clear();
}


void MainWindow::on_addtrueBtn_clicked()
{
    inp_ans_e = true;
    ui->addtrueBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addfalseBtn->setStyleSheet("");
}

void MainWindow::on_addfalseBtn_clicked()
{
    inp_ans_e = false;
    ui->addfalseBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addtrueBtn->setStyleSheet("");
}


void MainWindow::on_addBtn_clicked()
{
    QString question = ui->questionLineEdit->text();
    if (question == "") {
        ui->error_add->setText("empty");
        return;
    }
    int index_ = ui->optionCBox->currentIndex();
    if (index_ == 0) {
        qDebug() << "lasd";
    }
}


void MainWindow::on_addbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(7);
    ui->addeditStack->setCurrentIndex(1);
}


