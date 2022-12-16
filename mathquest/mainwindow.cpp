#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QString>
#include <QInputDialog>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRandomGenerator64>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QList>



QString active_name, active_category, add_drpdwn_diff; //sa customized to
int active_user_id, active_category_id; //sa customized to
int q_num_e = 1, q_num_m =1, q_num_h = 1;

int db_temp_id;
int korik = 0;
QString db_temp_ques;
bool db_temp_ans_e, users_ans_e;
QString users_ans_m, users_ans_h, db_temp_ans_m, db_temp_ans_h, db_temp_opt1, db_temp_opt2, db_temp_opt3, db_temp_opt4;
bool inp_ans_e;
QString optn1, optn2, optn3, optn4, inp_ans_m, inp_ans_h;
bool pauseBtn_, resumeBtn_;

int chosen_cat_id = 1, chosen_user_id; //sa quiz na
QString chosen_cat, chosen_diff, chosen_note, chosen_user; //sa quiz na
QString insE = "Choose TRUE if the statement is correct, otherwise choose FALSE";
QString insM = "Read the following questions carefully and choose the letter that best describes the answer";
QString insH = "Identify what is being asked in the displayed question. Enter your answers on the textbox below.";
int quesnum = 10, score = 0;

//qqq
QString db_cat, q_diff;
int question_no_easy = 1, question_no_med = 1, question_no_hard = 1;
int cat_id = 1;
int q_cat=1, q_item;


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
                 "category VARCHAR(20) not null,"
                 "difficulty VARCHAR(20) not null,"
                 "q_num integer not null,"
                 "score integer not null);");
    if (!qry1.exec() ||
            !qry2.exec() ||
            !qry3.exec() ||
            !qry4.exec() ||
            !qry5.exec() ||
            !qry6.exec()) {
        qDebug() << "table not created";
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}


void MainWindow::showtable(int user_id) {
    QSqlQuery qry;
    int row;
    qry.prepare("SELECT MAX(ID) FROM category WHERE owner_id = ?");
    qry.bindValue(0, user_id);
    if (qry.exec()) {
        if (qry.next()) {
            row = qry.value(0).toInt();
            qDebug() << row;
            ui->editList->setRowCount(row);
        }
    }

    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM category WHERE owner_id = ?");
    qry1.bindValue(0, user_id);
    if (qry1.exec()) {
        int i = 0;
        while (qry1.next() && i < ui->editList->rowCount()) {
            cat_id = qry1.value(0).toInt();
            db_cat = qry1.value(1).toString();
            QTableWidgetItem *item;
            for (int j = 0; j < ui->editList->columnCount(); j++) {
                item = new QTableWidgetItem;
                if (j==0) {
                    item->setText(db_cat);
                }
                ui->editList->setItem(i, j, item);
            }
            i++;
        }
    }
}

void MainWindow::check_db_open() {
    if (!db.isOpen()) {
        qDebug() << "db not connected";
        return;
    }
}


// tigil sya for 1 sec
void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}



// mag add sa user table
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


// mag add sa category table
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


// mag add sa questionsEasy table
void addQuestionEasy (QString ques, bool ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionsEasy ("
                "question,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error easy";
    }
}


// mag add sa questionMedium table
void addQuestionMed (QString ques, QString opt1, QString opt2, QString opt3,
                     QString opt4, QString ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionMedium ("
                "question,"
                "option1,"
                "option2,"
                "option3,"
                "option4,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(opt1);
    qry.addBindValue(opt2);
    qry.addBindValue(opt3);
    qry.addBindValue(opt4);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error med";
    }
}

// mag add sa questionHard table
void addQuestionHard (QString ques, QString ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionHard ("
                "question,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error hard";
    }
}

// mag add sa leaderboard
void addLeaderboard (QString name, QString cat, QString diff, int q_num, int score) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO leaderboard("
                "name,"
                "category,"
                "difficulty,"
                "q_num,"
                "score)"
                "VALUES (?, ?, ?, ?, ?);");
    qry.addBindValue(name);
    qry.addBindValue(cat);
    qry.addBindValue(diff);
    qry.addBindValue(q_num);
    qry.addBindValue(score);
    if (!qry.exec()) {
        qDebug() << "error leaderboard";
    }
}


// mag show sya ng note based sa category id
void show_note(int cat_id) {
    QSqlQuery qry;

    // mafifilter yung table category kasi ang need is yung row lang na
    //may id na {cat_id}. nakadepende sya sa ipapasa mong argument
    // pag ni call yung function.
    qry.prepare("SELECT category, note, owner_id FROM category WHERE ID = ?");
    qry.bindValue(0, cat_id);
    if (qry.exec()) {
        if (qry.next()) {

            // temporarily niset ko muna yung makukuhang value sa variables na ito.
            // Di sya fixed kasi everytime na matatwag tong function mababago
            // yung value ng chosen note and chosen user id. And since unique ang id per row, isa lang talaga value na makukuha mo
            chosen_cat = qry.value(0).toString();
            chosen_note = qry.value(1).toString();
            chosen_user_id = qry.value(2).toInt();
        }
    }

    QSqlQuery qry1;
    // since nadefine mo na sa line 296 yung chosen user id,
    // ifilter din natin yung table user na may ganong id
    // para maget natin yung name from that table. Isang value lang ulit sya.
    qry1.prepare("SELECT name FROM users WHERE ID = ?");
    qry1.bindValue(0, chosen_user_id);
    if (qry1.exec()) {
        if (qry1.next()) {
            chosen_user = qry1.value(0).toString();
        }
    }
}


// tatlo parameters natin dito, difficulty owner id, and category id.
// Itong function na 'to is mag cocount lang sya kung ilang question na
// ang naimput mo per category sa customized
void q_num(QString diff, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("SELECT owner_id, category_id FROM \'" + diff +
                "\' WHERE owner_id = ? AND category_id = ?");
    qry.bindValue(0, owner_id);
    qry.bindValue(1, category_id);

    if (qry.exec()) {
        if (qry.next()) {
            if (diff == "questionsEasy") {
                q_num_e += 1;
            } else if (diff == "questionMedium") {
                q_num_m += 1;
            } else {
                q_num_h += 1;
            }
        }
    }
}


//void


void MainWindow::item_num(QString diff_, int range_, int num) { // random number para sa random questions din
    int max_range, min_range;

    QSqlQuery qryy;
    qryy.prepare("SELECT MIN(ID), MAX(ID) FROM \'" + diff_ + "\' WHERE category_id = ?");
    qryy.bindValue(0, chosen_cat_id);
    if (qryy.exec()) {
        if (qryy.next()) {
            min_range = qryy.value(0).toInt();
            max_range = qryy.value(1).toInt();
        }
    }

    qDebug() << min_range << max_range;

    QSqlQuery qry;
    int randArr[range_];
    int k = min_range;
    for (int j = 0; j < range_; j++) {
        randArr[j] = k;
        k++;
    }

    int array[num];
    for (int i = 0; i < num; i++) {
            int r = i + rand() % (range_ - i);
            array[i] = randArr[r];
            randArr[r] = randArr[i];
    }
    for (int g=0; g<range_; g++) {
        qDebug() << array[g];
    }

    for (int g=0; g<range_; g++) {
//        qDebug() << array[g];
        int temp_q_id = array[g];

//        qDebug() << chosen_diff << "chosen_diff";
        if (chosen_diff == "questionsEasy") {
            qry.prepare("SELECT * FROM questionsEasy WHERE ID = ?");
            qry.bindValue(0, temp_q_id);
//            qry.bindValue(1, chosen_cat_id);
            if (qry.exec()) {
                if (qry.next()) {

                    db_temp_id = qry.value(0).toInt();
                    db_temp_ques = qry.value(1).toString();
                    db_temp_ans_e = qry.value(2).toBool();
                    ui->qstnLbl->setText(db_temp_ques);
                    timer_();
                }
            }
        } else if (chosen_diff == "questionMedium") {
            qry.prepare("SELECT * FROM questionMedium WHERE ID = ?");
            qry.bindValue(0, temp_q_id);
            if (qry.exec()) {
                if (qry.next()) {
                    db_temp_id = qry.value(0).toInt();
                    db_temp_ques = qry.value(1).toString();
                    db_temp_opt1 = qry.value(2).toString();
                    db_temp_opt2 = qry.value(3).toString();
                    db_temp_opt3 = qry.value(4).toString();
                    db_temp_opt4 = qry.value(5).toString();
                    db_temp_ans_m = qry.value(6).toString();
                    ui->qstnLbl->setText(db_temp_ques);
                    ui->aBtn->setText(db_temp_opt1);
                    ui->bBtn->setText(db_temp_opt2);
                    ui->cBtn->setText(db_temp_opt3);
                    ui->dbtn->setText(db_temp_opt4);
                    timer_();
                }
            }
        } else {
            qry.prepare("SELECT * FROM questionHard WHERE ID = ?");
            qry.bindValue(0, temp_q_id);
            if (qry.exec()) {
                if (qry.next()) {
                    db_temp_id = qry.value(0).toInt();
                    db_temp_ques = qry.value(1).toString();
                    db_temp_ans_h = qry.value(2).toString();
                    ui->qstnLbl->setText(db_temp_ques);
                    timer_();
                }
            }
        }
//        qDebug() << "a";
    }
    ui->MainStack->setCurrentIndex(5);
    ui->caLbl->setText(QString::number(korik));
    ui->scre->setText(QString::number(score));
}


void MainWindow::on_readyBtn_clicked()
{
    ui->MainStack->setCurrentIndex(3);
    ::show_note(chosen_cat_id);
//    qDebug() << chosen_cat;
    ui->categoryLbl->setText(chosen_cat);
    ui->scoreNum->setText(QString::number(score));
//    qDebug() << q_item -1 << quesnum;
    item_num(chosen_diff, q_item-1, quesnum);
//    timer_();
}


//timer
void MainWindow::timer_() {
    pauseBtn_ = false;
    resumeBtn_ = false;
    int num, num_f;

    if (chosen_diff == "questionsEasy") {
        num = 10;
        num_f = 10;
    } else if (chosen_diff == "questionMedium") {
        num = 20;
        num_f = 20;
    } else {
        num = 30;
        num_f = 30;
    }

    int i = 0;
//    qDebug() << chosen_diff;
    while(i < num+1) {
        ui->timeText->setText(QString::number(num-i));
        delay();
        if (pauseBtn_ == true && resumeBtn_ == false) {
            continue;
        } else if (chosen_diff == "questionsEasy") {
            if (ui->trueBtn->styleSheet() != "background:rgb(85, 0, 255);\ncolor:white;" ||
                       ui->falseBtn->styleSheet() != "background:rgb(85, 0, 255);\ncolor:white;") {
//                qDebug() << "as";
                if (users_ans_e == db_temp_ans_e) {
    //                    score++;
                    korik++;
//                    qDebug() << num;
                    if (num-i >= 2*num_f/3) {
                        score += 3;
                    } else if (num-i >= num_f/3) {
                        score += 2;
                    } else if (num-i < num_f/3) {
                        score += 1;
                    }
                    if (users_ans_e == true) {
                        ui->trueBtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    } else {
                        ui->falseBtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    }
                    break;
                } else {
                    if (users_ans_e == false) {
                        ui->falseBtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    } else {
                        ui->trueBtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    }
                    break;
                }
            } else {
                i += 1;
            }

        } else if (chosen_diff == "questionMedium") {
//            qDebug() << ui->aBtn->styleSheet();
            if (ui->aBtn->styleSheet() != "background:rgb(170, 85, 255);color:black" ||
                    ui->bBtn->styleSheet() != "background:rgb(170, 85, 255);color:black" ||
                    ui->cBtn->styleSheet() != "background:rgb(170, 85, 255);color:black" ||
                    ui->dbtn->styleSheet() != "background:rgb(170, 85, 255);color:black") {
//                qDebug() << "as";
//                qDebug() << users_ans_m << db_temp_ans_m;
                if (users_ans_m == db_temp_ans_m) {
    //                    score++;
                    korik++;
                    qDebug() << num;
                    if (num-i >= 2*num_f/3) {
                        score += 3;
                    } else if (num-i >= num_f/3) {
                        score += 2;
                    } else if (num-i < num_f/3) {
                        score += 1;
                    }
                    if (users_ans_m == ui->aBtn->text()) {
                        ui->aBtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->bBtn->text()) {
                        ui->bBtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->cBtn->text()) {
                        ui->cBtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->dbtn->text()) {
                        ui->dbtn->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    }
                    break;
                } else {
                    if (users_ans_m == ui->aBtn->text()) {
                        ui->aBtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->bBtn->text()) {
                        ui->bBtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->cBtn->text()) {
                        ui->cBtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    } else if (users_ans_m == ui->dbtn->text()) {
                        ui->dbtn->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    }
                    break;
                }
            } else {
                i += 1;
            }
        } else {
            users_ans_h = ui->identiLine->text();
            qDebug() << users_ans_h.toLower();
            qDebug() << db_temp_ans_h.toLower();
            qDebug() << ui->submitBtn->styleSheet();
            if (ui->submitBtn->styleSheet() != "background:rgb(151,84,203);\ncolor: white") {
                if (users_ans_h.toLower() == db_temp_ans_h.toLower()) {
    //                    score++;
                    korik++;
                    qDebug() << num;
                    if (num-i >= 2*num_f/3) {
                        score += 3;
                    } else if (num-i >= num_f/3) {
                        score += 2;
                    } else if (num-i < num_f/3) {
                        score += 1;
                    }
                    if (users_ans_h == ui->identiLine->text()) {
                        ui->identiLine->setStyleSheet("background:rgb(0, 255, 0);\ncolor:white;");
                    }
                    break;
                } else {
                    ui->identiLine->setStyleSheet("background:rgb(255, 0, 0);\ncolor:white;");
                    break;
                }
            } else {
                i += 1;
            }
        }
    }
    ui->scoreNum->setText(QString::number(score));
    delay();
    ui->identiLine->setStyleSheet("background:#9754cb");
    ui->aBtn->setStyleSheet("background:rgb(170, 85, 255);color:black");
    ui->bBtn->setStyleSheet("background:rgb(170, 85, 255);color:black");
    ui->cBtn->setStyleSheet("background:rgb(170, 85, 255);color:black");
    ui->dbtn->setStyleSheet("background:rgb(170, 85, 255);color:black");
    ui->trueBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");
    ui->falseBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");
    ui->submitBtn->setStyleSheet("background:rgb(151,84,203);\ncolor: white");
    ui->identiLine->setStyleSheet("background:#9754cb");
}


//questionNumber
void MainWindow::maxnum(QString diff_, int cat_id) {
    qDebug() << diff_ << cat_id;
    QSqlQuery qry;
    q_item = 1;
    ui->quesnumCBox->clear();
    ui->q_num_combo->clear();
    qry.prepare("SELECT ID FROM \'" + diff_ + "\' WHERE category_id = ?");
//    qDebug() << diff_ << cat_id;
    qry.bindValue(0, cat_id);
    if (qry.exec()) {

        while (qry.next()) {
//            int q_id = qry.value(0).toInt();
            q_item += 1;
        }
    }

    if (q_item >= 0 && q_item <19) {
        ui->q_num_combo->addItem(QString::number(10));
        ui->quesnumCBox->addItem(QString::number(10));
    }
    if (q_item >= 20 && q_item <29) {
        ui->quesnumCBox->addItem(QString::number(10));
        ui->quesnumCBox->addItem(QString::number(20));
        ui->q_num_combo->addItem(QString::number(10));
        ui->q_num_combo->addItem(QString::number(20));
    }
    if (q_item >= 30 && q_item <39) {
        ui->quesnumCBox->addItem(QString::number(10));
        ui->quesnumCBox->addItem(QString::number(20));
        ui->quesnumCBox->addItem(QString::number(30));
        ui->q_num_combo->addItem(QString::number(10));
        ui->q_num_combo->addItem(QString::number(20));
        ui->q_num_combo->addItem(QString::number(30));
    }
}


void MainWindow::showleaderboard(int cat_id, QString cat, QString diff, int q_num) {
    ui->lbText->setStyleSheet("color:white;");
    QSqlQuery qry1;
    int row;
    qry1.prepare("SELECT MAX(ID) FROM leaderboard WHERE category = ? AND difficulty = ? AND q_num = ?");
    qry1.bindValue(0, cat);
    qry1.bindValue(1, diff);
    qry1.bindValue(2, q_num);
    if (qry1.exec()) {
        if (qry1.next()) {
            row = qry1.value(0).toInt();
            qDebug() << row;
            ui->tableLead->setRowCount(row);
        }
    }
    QList <QString> list_name[row];
    QList <int> list_score[row];

    QSqlQuery qry;
    qry.prepare("SELECT * from leaderboard WHERE category = ? AND difficulty = ? AND q_num = ?");
    qry.bindValue(0, cat);
    qry.bindValue(1, diff);
    qry.bindValue(2, q_num);
    if(qry.exec()) {
        while(qry.next() ) {
            int l_id = qry.value(0).toInt();
            QString l_name = qry.value(1).toString();
            QString l_cat = qry.value(2).toString();
            QString l_diff = qry.value(3).toString();
            int l_q_num = qry.value(4).toInt();
            int l_score = qry.value(5).toInt();

            list_name->append(l_name);
            list_score->append(l_score);
        }
    }
    for (int i = 0; i < list_name->size(); i++) {
        for (int j = 0; j < list_name->size()-i-1; j++) {
            if (list_score->value(j) > list_score->value(j+1)) {

                list_score->swapItemsAt(j, j+1);
                list_name->swapItemsAt(j, j+1);
            }
        }
        qDebug() << list_name[i];
    }

//    qDebug() << list_score->at(0) << "lol";
//    qDebug() << list_score->at(1) << "lol";
//    qDebug() << list_score->at(2) << "lol";
//    qDebug() << list_score->at(3) << "lol";
//    qDebug() << list_score->at(4) << "lol";

    QString name_l;
    int score_l;
    int i = 0;
    while(i < ui->tableLead->rowCount()) {
        name_l = list_name->value(ui->tableLead->rowCount() - i - 1);
        score_l = list_score->value(ui->tableLead->rowCount() - i - 1);
        qDebug() << name_l;
        qDebug() << score_l;
        QTableWidgetItem *item;

        for (int j = 0; j < ui->tableLead->columnCount(); j++) {
            item = new QTableWidgetItem;
            if (j==0) {
                item->setText(name_l);
            } else if (j==1) {
                item->setText(QString::number(score_l));
            }
            ui->tableLead->setItem(i, j, item);
        }
        i++;
    }
}


//show category
void MainWindow::ShowCat() {
    QSqlQuery qry;
    QString db_cat;
    ui->catCBox->clear();
    ui->cat_combo->clear();

    qry.prepare("SELECT * FROM category");
    if (qry.exec()) {
        while (qry.next()) {
            db_cat = qry.value(1).toString();
            ui->cat_combo->addItem(db_cat);
            ui->catCBox->addItem(db_cat);
        }
    }
}


// show difficulty
void MainWindow::Showdiff(int cat_id) {
    QSqlQuery qry;
//    qDebug() << cat_id;
    ui->diffCBox->clear();
    ui->diif_combo->clear();
    qry.prepare("SELECT ID FROM questionsEasy WHERE category_id = ?");
    qry.bindValue(0, cat_id);
    if (qry.exec()) {
        if (qry.next()) {
            ui->diffCBox->addItem("True or False");
            ui->diif_combo->addItem("True or False");
        }
    }

    qry.prepare("SELECT ID FROM questionMedium WHERE category_id = ?");
    qry.bindValue(0, cat_id);
    if (qry.exec()) {
        if (qry.next()) {
            ui->diffCBox->addItem("Multiple Choices");
            ui->diif_combo->addItem("Multiple Choices");
        }
    }

    qry.prepare("SELECT ID FROM questionHard WHERE category_id = ?");
    qry.bindValue(0, cat_id);
    if (qry.exec()) {
        if (qry.next()) {
            ui->diffCBox->addItem("Identification");
            ui->diif_combo->addItem("Identification");
        }
    }
}

void MainWindow::on_catCBox_activated(int index)
{
    chosen_cat_id = index + 1;

    Showdiff(chosen_cat_id);
    QString testType = ui->diffCBox->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->quesnumCBox->setCurrentIndex(0);
}

void MainWindow::on_diffCBox_activated(int index)
{
    QString testType = ui->diffCBox->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->quesnumCBox->setCurrentIndex(0);
//    ui->trueBtn->setStyleSheet("");
//    ui->falseBtn->setStyleSheet("");
//    ui->identiLine->setText("");
//    qDebug() << q_diff;
//    maxnum(q_diff, q_cat);
}


void MainWindow::on_playBtn_clicked()
{
    ui->MainStack->setCurrentIndex(1);
    ui->diffCBox->setCurrentIndex(0);
    ui->quesnumCBox->setCurrentIndex(0);
    ui->catCBox->setCurrentIndex(0);
    ShowCat();
    Showdiff(chosen_cat_id);
    chosen_diff = "questionsEasy";
    maxnum(chosen_diff, chosen_cat_id);
}


void MainWindow::on_customBtn_clicked()
{
    ui->MainStack->setCurrentIndex(6);
    ui->ls_box->setCurrentIndex(0);
//    ui->addeditStack->setCurrentIndex(0);
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                 "background: #9754cb;"
                                 "color: white;"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("background: #9754cb;"
                                "color: white;");
}


void MainWindow::on_login_sec_clicked()
{
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                 "background: #9754cb;"
                                 "color: white;"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("background: #9754cb;"
                                "color: white;");
    ui->ls_box->setCurrentIndex(0);

//    clear textbox in sign sec
    ui->pass_inp_auth_s->clear();
    ui->name_inp_auth_s->clear();
    ui->cpass_->clear();
    ui->error_msg->clear();
}


void MainWindow::on_sign_sec_clicked()
{
    ui->sign_sec->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                 "background: #9754cb;"
                                 "color: white;"
                                 "text-decoration: underline;");
    ui->login_sec->setStyleSheet("background: #9754cb;"
                                "color: white;");
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
            ui->addIndex->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                        "background: #9754cb;"
                                        "color: white;"
                                        "text-decoration: underline;");
            ui->addeditStack->setCurrentIndex(0);
            ui->MainStack->setCurrentIndex(7);
            showtable(active_user_id);
        }
        else {
            ui->error_msg_l->setText("wrong name or pass");
        }
    }
}


//CUSTOM
void MainWindow::on_cstmbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}


void MainWindow::on_addIndex_clicked()
{
    ui->addeditStack->setCurrentIndex(0);
    ui->addIndex->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                "background: #9754cb;"
                                "color: white;"
                                "text-decoration: underline;");
    ui->editIndex->setStyleSheet("background: #9754cb;"
                                 "color: white;");
}


void MainWindow::on_editIndex_clicked(){
    ui->addeditStack->setCurrentIndex(1);
    ui->addIndex->setStyleSheet("background: #9754cb;"
                                "color: white;");
    ui->editIndex->setStyleSheet("font: 900 9pt 'Segoe UI';"
                                 "background: #9754cb;"
                                 "color: white;"
                                 "text-decoration: underline;");

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
     msgBox.setText("Category:" + cat_inp);
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
            ui->qnoLbl->setText(QString::number(q_num_e));

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

void MainWindow::on_addaBtn_clicked()
{
    inp_ans_m = ui->alineEdit->text();
    ui->addaBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addbBtn->setStyleSheet("");
    ui->addcBtn->setStyleSheet("");
    ui->adddBtn->setStyleSheet("");
}



void MainWindow::on_addbBtn_clicked()
{
    inp_ans_m = ui->blineEdit->text();
    ui->addbBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addaBtn->setStyleSheet("");
    ui->addcBtn->setStyleSheet("");
    ui->adddBtn->setStyleSheet("");
}


void MainWindow::on_addcBtn_clicked()
{
    inp_ans_m = ui->clineEdit->text();
    ui->addcBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addbBtn->setStyleSheet("");
    ui->addaBtn->setStyleSheet("");
    ui->adddBtn->setStyleSheet("");
}


void MainWindow::on_adddBtn_clicked()
{
    inp_ans_m = ui->dlineEdit->text();
    ui->adddBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->addbBtn->setStyleSheet("");
    ui->addcBtn->setStyleSheet("");
    ui->addaBtn->setStyleSheet("");
}


void MainWindow::on_addBtn_clicked()
{
    qDebug() <<ui->questionLineEdit->toPlainText();
    QString question = ui->questionLineEdit->toPlainText();
    if (question == "") {
        ui->error_add->setText("empty");
        return;
    }
    int index_ = ui->optionCBox->currentIndex();
    if (index_ == 0) {
        QString true_btn = ui->addtrueBtn->styleSheet();
        QString false_btn = ui->addfalseBtn->styleSheet();

        if (true_btn == "" && false_btn == "") {
            ui->error_add->setText("Choose One");
            return;
        }

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
             add_drpdwn_diff = "questionsEasy";
             ::addQuestionEasy(question, inp_ans_e, active_user_id, active_category_id);
             ui->questionLineEdit->clear();
             ui->addtrueBtn->setStyleSheet("");
             ui->addfalseBtn->setStyleSheet("");
             ::q_num(add_drpdwn_diff, active_user_id, active_category_id);
             ui->qnoLbl->setText(QString::number(q_num_e));
             break;
           case QMessageBox::Discard:
             qDebug() << "byerz";
             break;
         }
    } else if (index_ == 1) {
        add_drpdwn_diff = "questionMedium";

        QString aC_btn = ui->addaBtn->styleSheet();
        QString bC_btn = ui->addbBtn->styleSheet();
        QString cC_btn = ui->addcBtn->styleSheet();
        QString dC_btn = ui->adddBtn->styleSheet();

        if (aC_btn == "" && bC_btn == "" && cC_btn == "" && dC_btn == "") {
            ui->error_add->setText("Choose one");
            return;
        }

        optn1 = ui -> alineEdit ->text();
        optn2 = ui -> blineEdit ->text();
        optn3 = ui -> clineEdit ->text();
        optn4 = ui -> dlineEdit ->text();

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               ::addQuestionMed(question, optn1, optn2, optn3,
                                optn4, inp_ans_m, active_user_id, active_category_id);
               ui->questionLineEdit->clear();
               ui->alineEdit->clear();
               ui->blineEdit->clear();
               ui->clineEdit->clear();
               ui->dlineEdit->clear();
               ui->addaBtn->setStyleSheet("");
               ui->addbBtn->setStyleSheet("");
               ui->addcBtn->setStyleSheet("");
               ui->adddBtn->setStyleSheet("");
               ::q_num(add_drpdwn_diff, active_user_id, active_category_id);
               ui->qnoLbl->setText(QString::number(q_num_m));
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               qDebug() << "bye";
               break;
         }
    } else {
        add_drpdwn_diff = "questionHard";

        inp_ans_h = ui->hardLineEdit->text();

        if (inp_ans_h == "") {
            ui->error_add->setText("Empty");
            return;
        }

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
             qDebug() << "ad";
             ::addQuestionHard(question, inp_ans_h, active_user_id, active_category_id);
             ui->hardLineEdit->clear();
             ui->questionLineEdit->clear();
             ::q_num(add_drpdwn_diff, active_user_id, active_category_id);
             ui->qnoLbl->setText(QString::number(q_num_h));
             break;
           case QMessageBox::Discard:
             qDebug() << "bye";
             break;
         }
    }
    ui->error_add->clear();
}


void MainWindow::on_addbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(7);
    ui->addeditStack->setCurrentIndex(1);
}

void MainWindow::on_lbbackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}


void MainWindow::on_aubackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}


void MainWindow::on_ibackBtn_clicked()
{
    ui->MainStack->setCurrentIndex(1);
}


void MainWindow::on_nextBtn_2_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}



void MainWindow::on_nextBtn_clicked()
{
    qDebug() << chosen_cat_id;
    qDebug() << chosen_diff;
    qDebug() << q_item;
    ui->MainStack->setCurrentIndex(2);

    if (chosen_diff == "questionsEasy") {
        ui->instrucLbl->setText(insE + "\n\n" + chosen_note);
        ui->diffStacked->setCurrentIndex(0);
    } else if (chosen_diff == "questionMedium") {
        ui->instrucLbl->setText(insM + "\n\n" + chosen_note);
        ui->diffStacked->setCurrentIndex(1);
    } else {
        ui->instrucLbl->setText(insH + "\n\n" + chosen_note);
        ui->diffStacked->setCurrentIndex(2);
    }
}


//timer pause

void MainWindow::on_pauseBtn_clicked()
{
    resumeBtn_ = false;
    pauseBtn_ = true;
    ui->MainStack->setCurrentIndex(4);
}



void MainWindow::on_retryBtn_clicked()
{
    ui->MainStack->setCurrentIndex(3);
    ui->trueBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");
    ui->falseBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");

    timer_();
}


void MainWindow::on_resueBtn_clicked()
{
    ui->MainStack->setCurrentIndex(3);
    resumeBtn_ = true;
    pauseBtn_ = false;
}


void MainWindow::on_quesnumCBox_activated(int index)
{
//    qDebug() << index << "this";
    quesnum = 10;
    if (index == 1) {
        quesnum = 20;
    } else {
        quesnum = 30;
    }
}


void MainWindow::on_menuBtn_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}


void MainWindow::on_aboutusBtn_clicked()
{
     ui->MainStack->setCurrentIndex(10);
}




void MainWindow::on_lbBtn_clicked()
{
     //dito palabasin yung sa leaderboards huh unwhpiq
    QString d;

    Showdiff(chosen_cat_id);
    ShowCat();
    chosen_cat = ui->cat_combo->currentText();
    chosen_diff = ui->diif_combo->currentText();
    maxnum(chosen_diff, chosen_cat_id);
    int max_num = ui->q_num_combo->currentText().toInt();
    qDebug() << chosen_cat;
    if (chosen_diff == "True or False") {
        d = "questionsEasy";
    } else if (chosen_diff == "Multiple Choices") {
        d = "questionMedium";
    } else {
        d = "questionHard";
    }
    qDebug() << chosen_diff;

    showleaderboard(chosen_cat_id, chosen_cat, d, max_num);
    ui->MainStack->setCurrentIndex(9);
}

void MainWindow::on_addSaveBtn_clicked()
{
    int rem_e = 11-q_num_e;
    int rem_m = 11-q_num_m;
    int rem_h = 11-q_num_h;
    if (q_num_e != 1 && q_num_e < 11) {
        ui->error_add->setText("questions should be atleast 10. \nAdd " + QString::number(rem_e) + " more");
        ui->optionCBox->setCurrentIndex(0);
        ui->difficultyCBox->setCurrentIndex(0);
        ui->qnoLbl->setText(QString::number(q_num_e));
        return;
    }
    if (q_num_m != 1 && q_num_m < 11) {
        ui->error_add->setText("questions should be atleast 10. \nAdd " + QString::number(rem_m) + " more");
        ui->optionCBox->setCurrentIndex(1);
        ui->difficultyCBox->setCurrentIndex(1);
        ui->qnoLbl->setText(QString::number(q_num_m));
        return;
    }
    if (q_num_h != 1 && q_num_h < 11) {
        ui->error_add->setText("questions should be atleast 10. \nAdd " + QString::number(rem_h) + " more");
        ui->optionCBox->setCurrentIndex(2);
        ui->difficultyCBox->setCurrentIndex(2);
        ui->qnoLbl->setText(QString::number(q_num_h));
        return;
    }
    ui->MainStack->setCurrentIndex(0);
}


void MainWindow::on_submitBtn_clicked()
{
    ui->submitBtn->setStyleSheet("background:rgb(151,85,203);\ncolor: white");
//    if(quesnum == question_no_hard){
//        ui->MainStack->setCurrentIndex(5);
//    }
}

void MainWindow::on_aBtn_clicked()
{
    users_ans_m = ui->aBtn->text();
    ui->aBtn->setStyleSheet("background:rgb(170, 86, 255);color:black");
//    if(quesnum == question_no_med){
//        ui->MainStack->setCurrentIndex(5);
//    }
}


void MainWindow::on_bBtn_clicked()
{
//    if(quesnum == question_no_med){
//        ui->MainStack->setCurrentIndex(5);
//    }
    users_ans_m = ui->bBtn->text();
    ui->bBtn->setStyleSheet("background:rgb(170, 86, 255);color:black");
}


void MainWindow::on_cBtn_clicked()
{
//    if(quesnum == question_no_med){
//        ui->MainStack->setCurrentIndex(5);
//    }
    users_ans_m = ui->cBtn->text();
    ui->cBtn->setStyleSheet("background:rgb(170, 86, 255);color:black");
}


void MainWindow::on_dbtn_clicked()
{
//    if(quesnum == question_no_med){
//        ui->MainStack->setCurrentIndex(5);
//    }
    users_ans_m = ui->dbtn->text();
    ui->dbtn->setStyleSheet("background:rgb(170, 86, 255);color:black");
}


void MainWindow::on_trueBtn_clicked()
{
//    if(quesnum == question_no_easy){
//        ui->MainStack->setCurrentIndex(5);
//    }
    users_ans_e = true;
    ui->trueBtn->setChecked(true);

    ui->trueBtn->setStyleSheet("background:rgb(85, 1, 255);\ncolor:white;");

//    ui->trueBtn->setStyleSheet("background:rgb(0, 255, 0)");
//    ui->falseBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");
}


void MainWindow::on_falseBtn_clicked()
{
//    if(quesnum == question_no_easy){
//        ui->MainStack->setCurrentIndex(5);
//    }
    users_ans_e = false;
    ui->trueBtn->setChecked(false);
    ui->falseBtn->setStyleSheet("background:rgb(85, 1, 255);\ncolor:white;");
//    ui->falseBtn->setStyleSheet("background:rgb(0, 255, 0)");
//    ui->trueBtn->setStyleSheet("background:rgb(85, 0, 255);\ncolor:white;");
}


void MainWindow::on_leadsubmitBtn_clicked()
{
    QString name_inp;
    name_inp = ui->name_inp->text();
    if (name_inp == "") {
        ui->error->setText("empty");
    } else {
        QSqlQuery qry;
        qry.prepare("SELECT name FROM leaderboard WHERE name = ?");
        qry.bindValue(0, name_inp);
        if (qry.exec()) {
            if (qry.next()) {
                ui->error->setText(name_inp + "is already taken");
            } else {
                ::addLeaderboard(name_inp, chosen_cat, chosen_diff, quesnum, score);

                Showdiff(chosen_cat_id);
                ShowCat();
                qDebug() << name_inp;
                qDebug() << chosen_cat;
                qDebug() << chosen_diff;
//                qDebug() << chosen_user;
                qDebug() << quesnum;
                qDebug() << score;

                ui->cat_combo->setCurrentIndex(chosen_cat_id - 1);
                if (chosen_diff == "questionsEasy") {
                    ui->diif_combo->setCurrentText("True or False");
                } else if (chosen_diff == "questionMedium") {
                    ui->diif_combo->setCurrentText("Multiple Choices");
                } else if (chosen_diff == "questionHard") {
                    ui->diif_combo->setCurrentText("Identification");
                }

                showleaderboard(chosen_cat_id, chosen_cat, chosen_diff, quesnum);

                ui->MainStack->setCurrentIndex(9);

                // add row sa table;
            }
        }
    }
}

void MainWindow::on_comboBox_activated(int index)
{
    chosen_cat_id = index + 1;
    //    maxnum(chosen_diff, chosen_cat_id);

    Showdiff(chosen_cat_id);
    //    chosen_diff = ui->diffCBox->currentText();
    QString testType = ui->diffCBox->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->quesnumCBox->setCurrentIndex(0);
    //    qDebug() << chosen_diff;
}


void MainWindow::on_comboBox_2_activated(int index)
{
    QString testType = ui->diffCBox->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->quesnumCBox->setCurrentIndex(0);
}




void MainWindow::on_comboBox_3_activated(int index)
{
//    qDebug() << index << "this";
    quesnum = 10;
    if (index == 1) {
        quesnum = 20;
    } else {
        quesnum = 30;
    }
}


void MainWindow::on_editBtn_clicked()
{

}

void MainWindow::on_cat_combo_activated(int index)
{
    chosen_cat_id = index + 1;

    Showdiff(chosen_cat_id);
    QString testType = ui->diffCBox->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->q_num_combo->setCurrentIndex(0);
}


void MainWindow::on_diif_combo_activated(int index)
{
    QString testType = ui->diif_combo->currentText();
    if (testType == "True or False") {
        chosen_diff = "questionsEasy";
    } else if (testType == "Multiple Choices") {
        chosen_diff ="questionMedium";
    } else {
        chosen_diff ="questionHard";
    }
    maxnum(chosen_diff, chosen_cat_id);
    ui->q_num_combo->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->MainStack->setCurrentIndex(0);
}

