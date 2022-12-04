/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *MainStack;
    QWidget *Startpg;
    QPushButton *playBtn;
    QPushButton *lbBtn;
    QPushButton *aboutusBtn;
    QWidget *categorypg;
    QLabel *diffLbl;
    QLabel *qnLbl;
    QComboBox *diffCBox;
    QPushButton *nextBtn;
    QLabel *catLbl;
    QComboBox *quesnumCBox;
    QComboBox *catCBox;
    QPushButton *nextBtn_2;
    QWidget *readypg;
    QPushButton *readyBtn;
    QLabel *instrucLbl;
    QPushButton *ibackBtn;
    QWidget *quizpg;
    QStackedWidget *diffStacked;
    QWidget *multipg;
    QPushButton *aBtn;
    QPushButton *bBtn;
    QPushButton *cBtn;
    QPushButton *dbtn;
    QWidget *identipg;
    QLineEdit *identiLine;
    QPushButton *pushButton;
    QWidget *tofpg;
    QPushButton *trueBtn;
    QPushButton *falseBtn;
    QLabel *qstnLbl;
    QPushButton *pauseBtn;
    QLabel *scoreLbl;
    QLabel *scoreNum;
    QLabel *timeLbl;
    QLabel *categoryLbl;
    QLabel *quesNumLbl;
    QWidget *pausepg;
    QPushButton *resueBtn;
    QPushButton *retryBtn_3;
    QPushButton *menuBtn;
    QWidget *resultspg;
    QLineEdit *name_inp;
    QLabel *nameLbl;
    QLabel *caLbl;
    QLabel *scrLbl;
    QLabel *remarksLbl;
    QLabel *caText;
    QLabel *scre;
    QWidget *loginpg;
    QStackedWidget *ls_box;
    QWidget *login_top;
    QLabel *name_lbl;
    QLabel *pass_lbl;
    QPushButton *login_btn;
    QLineEdit *name_inp_auth;
    QLineEdit *pass_inp_auth;
    QLabel *label_3;
    QLabel *error_msg_l;
    QWidget *sign_up_top;
    QLabel *name_lbl_s;
    QLabel *pass_lbl_s;
    QLabel *pass_lbl_s_c;
    QPushButton *signup_btn;
    QLineEdit *name_inp_auth_s;
    QLineEdit *pass_inp_auth_s;
    QLineEdit *cpass_;
    QLabel *userLbl;
    QLabel *error_msg;
    QPushButton *sign_sec;
    QPushButton *login_sec;
    QPushButton *lsbackBtn;
    QWidget *addeditpg;
    QStackedWidget *addeditStack;
    QWidget *addStack;
    QWidget *layoutWidget_7;
    QHBoxLayout *categoryLayout;
    QLabel *addcategoryLbl;
    QLineEdit *categorylineEdit;
    QWidget *layoutWidget_8;
    QHBoxLayout *nameLayout;
    QLabel *nameLbl_3;
    QLineEdit *namelineEdit;
    QLineEdit *noteTextbox;
    QLabel *addnoteLbl;
    QWidget *layoutWidget_9;
    QHBoxLayout *reviewerLayout;
    QLabel *label_17;
    QLineEdit *reviewereditLine;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *reviewerBtn;
    QLabel *onadderrorLbl;
    QPushButton *nextBtn_3;
    QWidget *editStack;
    QListView *editlistView;
    QPushButton *editBtn;
    QPushButton *delBtn;
    QPushButton *cstmbackBtn;
    QPushButton *editIndex;
    QPushButton *addIndex;
    QWidget *addpg;
    QLabel *addcatLbl;
    QLabel *nameLbl_4;
    QLineEdit *questionLineEdit;
    QLabel *qnoLbl;
    QLabel *quesText;
    QStackedWidget *optionCBox;
    QWidget *tofStacked;
    QPushButton *addtrueBtn;
    QPushButton *addfalseBtn;
    QWidget *multiStacked;
    QPushButton *addaBtn;
    QPushButton *addbBtn;
    QPushButton *addcBtn;
    QPushButton *adddBtn;
    QLineEdit *alineEdit;
    QLineEdit *blineEdit;
    QLineEdit *clineEdit;
    QLineEdit *dlineEdit;
    QWidget *identiStacked;
    QLineEdit *hardLineEdit;
    QPushButton *addBtn;
    QPushButton *addsaveBtn;
    QComboBox *difficultyCBox;
    QPushButton *addbackBtn;
    QWidget *leaderboardspg;
    QLabel *lbText;
    QPushButton *lbbackBtn;
    QWidget *aboutuspg;
    QLabel *auText;
    QPushButton *aubackBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(360, 394);
        MainWindow->setMaximumSize(QSize(360, 640));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainStack = new QStackedWidget(centralwidget);
        MainStack->setObjectName("MainStack");
        MainStack->setGeometry(QRect(0, 0, 360, 351));
        MainStack->setMaximumSize(QSize(360, 640));
        MainStack->setStyleSheet(QString::fromUtf8("background:#28104e"));
        Startpg = new QWidget();
        Startpg->setObjectName("Startpg");
        playBtn = new QPushButton(Startpg);
        playBtn->setObjectName("playBtn");
        playBtn->setGeometry(QRect(70, 180, 211, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Poppins Black")});
        font.setPointSize(14);
        font.setBold(true);
        playBtn->setFont(font);
        playBtn->setStyleSheet(QString::fromUtf8("background:#6237A0;\n"
"color:white\n"
""));
        lbBtn = new QPushButton(Startpg);
        lbBtn->setObjectName("lbBtn");
        lbBtn->setGeometry(QRect(70, 230, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Poppins Black")});
        font1.setBold(true);
        lbBtn->setFont(font1);
        lbBtn->setStyleSheet(QString::fromUtf8("background:#9754CB;\n"
"color: white"));
        aboutusBtn = new QPushButton(Startpg);
        aboutusBtn->setObjectName("aboutusBtn");
        aboutusBtn->setGeometry(QRect(210, 230, 71, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Poppins")});
        font2.setBold(true);
        aboutusBtn->setFont(font2);
        aboutusBtn->setStyleSheet(QString::fromUtf8("background:#9754CB;\n"
"color: white"));
        MainStack->addWidget(Startpg);
        categorypg = new QWidget();
        categorypg->setObjectName("categorypg");
        diffLbl = new QLabel(categorypg);
        diffLbl->setObjectName("diffLbl");
        diffLbl->setGeometry(QRect(70, 90, 91, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Poppins")});
        font3.setPointSize(10);
        font3.setBold(true);
        diffLbl->setFont(font3);
        qnLbl = new QLabel(categorypg);
        qnLbl->setObjectName("qnLbl");
        qnLbl->setGeometry(QRect(70, 140, 151, 21));
        qnLbl->setFont(font3);
        diffCBox = new QComboBox(categorypg);
        diffCBox->setObjectName("diffCBox");
        diffCBox->setGeometry(QRect(90, 110, 171, 26));
        nextBtn = new QPushButton(categorypg);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setGeometry(QRect(250, 220, 93, 29));
        nextBtn->setFont(font2);
        catLbl = new QLabel(categorypg);
        catLbl->setObjectName("catLbl");
        catLbl->setGeometry(QRect(70, 40, 161, 21));
        catLbl->setFont(font3);
        quesnumCBox = new QComboBox(categorypg);
        quesnumCBox->setObjectName("quesnumCBox");
        quesnumCBox->setGeometry(QRect(90, 160, 171, 26));
        quesnumCBox->setEditable(false);
        catCBox = new QComboBox(categorypg);
        catCBox->setObjectName("catCBox");
        catCBox->setGeometry(QRect(90, 60, 171, 26));
        catCBox->setStyleSheet(QString::fromUtf8("color: rgba"));
        nextBtn_2 = new QPushButton(categorypg);
        nextBtn_2->setObjectName("nextBtn_2");
        nextBtn_2->setGeometry(QRect(20, 220, 93, 29));
        nextBtn_2->setFont(font2);
        MainStack->addWidget(categorypg);
        readypg = new QWidget();
        readypg->setObjectName("readypg");
        readyBtn = new QPushButton(readypg);
        readyBtn->setObjectName("readyBtn");
        readyBtn->setGeometry(QRect(130, 240, 80, 31));
        readyBtn->setFont(font3);
        instrucLbl = new QLabel(readypg);
        instrucLbl->setObjectName("instrucLbl");
        instrucLbl->setGeometry(QRect(150, 100, 41, 14));
        ibackBtn = new QPushButton(readypg);
        ibackBtn->setObjectName("ibackBtn");
        ibackBtn->setGeometry(QRect(20, 40, 80, 31));
        ibackBtn->setFont(font3);
        MainStack->addWidget(readypg);
        quizpg = new QWidget();
        quizpg->setObjectName("quizpg");
        diffStacked = new QStackedWidget(quizpg);
        diffStacked->setObjectName("diffStacked");
        diffStacked->setGeometry(QRect(20, 150, 311, 191));
        diffStacked->setStyleSheet(QString::fromUtf8("background:#6237A0"));
        multipg = new QWidget();
        multipg->setObjectName("multipg");
        aBtn = new QPushButton(multipg);
        aBtn->setObjectName("aBtn");
        aBtn->setGeometry(QRect(50, 20, 221, 31));
        aBtn->setStyleSheet(QString::fromUtf8("background:rgb(170, 85, 255);"));
        bBtn = new QPushButton(multipg);
        bBtn->setObjectName("bBtn");
        bBtn->setGeometry(QRect(50, 60, 221, 31));
        bBtn->setStyleSheet(QString::fromUtf8("background:rgb(170, 85, 255);"));
        cBtn = new QPushButton(multipg);
        cBtn->setObjectName("cBtn");
        cBtn->setGeometry(QRect(50, 100, 221, 31));
        cBtn->setStyleSheet(QString::fromUtf8("background:rgb(170, 85, 255);"));
        dbtn = new QPushButton(multipg);
        dbtn->setObjectName("dbtn");
        dbtn->setGeometry(QRect(50, 140, 221, 31));
        dbtn->setStyleSheet(QString::fromUtf8("background:rgb(170, 85, 255);"));
        diffStacked->addWidget(multipg);
        identipg = new QWidget();
        identipg->setObjectName("identipg");
        identiLine = new QLineEdit(identipg);
        identiLine->setObjectName("identiLine");
        identiLine->setGeometry(QRect(20, 40, 271, 101));
        identiLine->setStyleSheet(QString::fromUtf8("background:#9754cb"));
        pushButton = new QPushButton(identipg);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 160, 91, 21));
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background:#9754cb;\n"
"color: white"));
        diffStacked->addWidget(identipg);
        tofpg = new QWidget();
        tofpg->setObjectName("tofpg");
        trueBtn = new QPushButton(tofpg);
        trueBtn->setObjectName("trueBtn");
        trueBtn->setGeometry(QRect(50, 50, 201, 31));
        trueBtn->setStyleSheet(QString::fromUtf8("background:rgb(85, 0, 255)"));
        falseBtn = new QPushButton(tofpg);
        falseBtn->setObjectName("falseBtn");
        falseBtn->setGeometry(QRect(50, 100, 201, 31));
        falseBtn->setStyleSheet(QString::fromUtf8("background:rgb(85, 0, 255);"));
        diffStacked->addWidget(tofpg);
        qstnLbl = new QLabel(quizpg);
        qstnLbl->setObjectName("qstnLbl");
        qstnLbl->setGeometry(QRect(40, 80, 281, 41));
        qstnLbl->setFont(font3);
        qstnLbl->setStyleSheet(QString::fromUtf8("background:#9754cb;\n"
"color: white"));
        qstnLbl->setAlignment(Qt::AlignCenter);
        pauseBtn = new QPushButton(quizpg);
        pauseBtn->setObjectName("pauseBtn");
        pauseBtn->setGeometry(QRect(10, 10, 61, 21));
        pauseBtn->setFont(font2);
        pauseBtn->setStyleSheet(QString::fromUtf8("background: #9754cb;\n"
"color: white"));
        scoreLbl = new QLabel(quizpg);
        scoreLbl->setObjectName("scoreLbl");
        scoreLbl->setGeometry(QRect(250, 20, 63, 20));
        scoreLbl->setFont(font3);
        scoreNum = new QLabel(quizpg);
        scoreNum->setObjectName("scoreNum");
        scoreNum->setGeometry(QRect(300, 20, 51, 20));
        scoreNum->setFont(font3);
        timeLbl = new QLabel(quizpg);
        timeLbl->setObjectName("timeLbl");
        timeLbl->setGeometry(QRect(110, 50, 41, 14));
        timeLbl->setFont(font3);
        categoryLbl = new QLabel(quizpg);
        categoryLbl->setObjectName("categoryLbl");
        categoryLbl->setGeometry(QRect(110, 30, 71, 20));
        categoryLbl->setFont(font3);
        quesNumLbl = new QLabel(quizpg);
        quesNumLbl->setObjectName("quesNumLbl");
        quesNumLbl->setGeometry(QRect(20, 130, 61, 16));
        quesNumLbl->setFont(font2);
        MainStack->addWidget(quizpg);
        pausepg = new QWidget();
        pausepg->setObjectName("pausepg");
        resueBtn = new QPushButton(pausepg);
        resueBtn->setObjectName("resueBtn");
        resueBtn->setGeometry(QRect(100, 120, 161, 31));
        resueBtn->setFont(font3);
        resueBtn->setStyleSheet(QString::fromUtf8("background: #6237A0;\n"
"color:white"));
        retryBtn_3 = new QPushButton(pausepg);
        retryBtn_3->setObjectName("retryBtn_3");
        retryBtn_3->setGeometry(QRect(100, 160, 161, 31));
        retryBtn_3->setFont(font3);
        retryBtn_3->setStyleSheet(QString::fromUtf8("background: #9754cb;\n"
"color:white"));
        menuBtn = new QPushButton(pausepg);
        menuBtn->setObjectName("menuBtn");
        menuBtn->setGeometry(QRect(100, 200, 161, 31));
        menuBtn->setFont(font3);
        menuBtn->setStyleSheet(QString::fromUtf8("background: #deacf5;\n"
"color:white"));
        MainStack->addWidget(pausepg);
        resultspg = new QWidget();
        resultspg->setObjectName("resultspg");
        name_inp = new QLineEdit(resultspg);
        name_inp->setObjectName("name_inp");
        name_inp->setGeometry(QRect(170, 220, 113, 26));
        nameLbl = new QLabel(resultspg);
        nameLbl->setObjectName("nameLbl");
        nameLbl->setGeometry(QRect(40, 220, 63, 20));
        caLbl = new QLabel(resultspg);
        caLbl->setObjectName("caLbl");
        caLbl->setGeometry(QRect(180, 140, 63, 20));
        scrLbl = new QLabel(resultspg);
        scrLbl->setObjectName("scrLbl");
        scrLbl->setGeometry(QRect(40, 170, 71, 31));
        remarksLbl = new QLabel(resultspg);
        remarksLbl->setObjectName("remarksLbl");
        remarksLbl->setGeometry(QRect(110, 40, 111, 51));
        caText = new QLabel(resultspg);
        caText->setObjectName("caText");
        caText->setGeometry(QRect(40, 130, 121, 31));
        scre = new QLabel(resultspg);
        scre->setObjectName("scre");
        scre->setGeometry(QRect(180, 170, 63, 20));
        MainStack->addWidget(resultspg);
        loginpg = new QWidget();
        loginpg->setObjectName("loginpg");
        ls_box = new QStackedWidget(loginpg);
        ls_box->setObjectName("ls_box");
        ls_box->setGeometry(QRect(20, 90, 321, 251));
        login_top = new QWidget();
        login_top->setObjectName("login_top");
        name_lbl = new QLabel(login_top);
        name_lbl->setObjectName("name_lbl");
        name_lbl->setGeometry(QRect(20, 40, 63, 20));
        pass_lbl = new QLabel(login_top);
        pass_lbl->setObjectName("pass_lbl");
        pass_lbl->setGeometry(QRect(20, 90, 91, 20));
        login_btn = new QPushButton(login_top);
        login_btn->setObjectName("login_btn");
        login_btn->setGeometry(QRect(110, 180, 93, 29));
        login_btn->setStyleSheet(QString::fromUtf8(""));
        name_inp_auth = new QLineEdit(login_top);
        name_inp_auth->setObjectName("name_inp_auth");
        name_inp_auth->setGeometry(QRect(120, 40, 161, 26));
        pass_inp_auth = new QLineEdit(login_top);
        pass_inp_auth->setObjectName("pass_inp_auth");
        pass_inp_auth->setGeometry(QRect(120, 90, 161, 26));
        pass_inp_auth->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(login_top);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 220, 131, 20));
        error_msg_l = new QLabel(login_top);
        error_msg_l->setObjectName("error_msg_l");
        error_msg_l->setGeometry(QRect(20, 140, 271, 20));
        ls_box->addWidget(login_top);
        sign_up_top = new QWidget();
        sign_up_top->setObjectName("sign_up_top");
        name_lbl_s = new QLabel(sign_up_top);
        name_lbl_s->setObjectName("name_lbl_s");
        name_lbl_s->setGeometry(QRect(20, 40, 63, 20));
        pass_lbl_s = new QLabel(sign_up_top);
        pass_lbl_s->setObjectName("pass_lbl_s");
        pass_lbl_s->setGeometry(QRect(20, 80, 81, 20));
        pass_lbl_s_c = new QLabel(sign_up_top);
        pass_lbl_s_c->setObjectName("pass_lbl_s_c");
        pass_lbl_s_c->setGeometry(QRect(20, 120, 131, 20));
        signup_btn = new QPushButton(sign_up_top);
        signup_btn->setObjectName("signup_btn");
        signup_btn->setGeometry(QRect(110, 180, 93, 29));
        name_inp_auth_s = new QLineEdit(sign_up_top);
        name_inp_auth_s->setObjectName("name_inp_auth_s");
        name_inp_auth_s->setGeometry(QRect(160, 40, 141, 26));
        pass_inp_auth_s = new QLineEdit(sign_up_top);
        pass_inp_auth_s->setObjectName("pass_inp_auth_s");
        pass_inp_auth_s->setGeometry(QRect(160, 80, 141, 26));
        pass_inp_auth_s->setEchoMode(QLineEdit::Password);
        cpass_ = new QLineEdit(sign_up_top);
        cpass_->setObjectName("cpass_");
        cpass_->setGeometry(QRect(160, 120, 141, 26));
        cpass_->setEchoMode(QLineEdit::Password);
        userLbl = new QLabel(sign_up_top);
        userLbl->setObjectName("userLbl");
        userLbl->setGeometry(QRect(20, 220, 111, 20));
        error_msg = new QLabel(sign_up_top);
        error_msg->setObjectName("error_msg");
        error_msg->setGeometry(QRect(30, 160, 271, 20));
        ls_box->addWidget(sign_up_top);
        sign_sec = new QPushButton(loginpg);
        sign_sec->setObjectName("sign_sec");
        sign_sec->setGeometry(QRect(180, 40, 151, 29));
        login_sec = new QPushButton(loginpg);
        login_sec->setObjectName("login_sec");
        login_sec->setGeometry(QRect(30, 40, 151, 29));
        login_sec->setStyleSheet(QString::fromUtf8(""));
        lsbackBtn = new QPushButton(loginpg);
        lsbackBtn->setObjectName("lsbackBtn");
        lsbackBtn->setGeometry(QRect(0, 0, 80, 21));
        MainStack->addWidget(loginpg);
        addeditpg = new QWidget();
        addeditpg->setObjectName("addeditpg");
        addeditStack = new QStackedWidget(addeditpg);
        addeditStack->setObjectName("addeditStack");
        addeditStack->setGeometry(QRect(20, 100, 321, 231));
        addStack = new QWidget();
        addStack->setObjectName("addStack");
        layoutWidget_7 = new QWidget(addStack);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(10, 50, 231, 28));
        categoryLayout = new QHBoxLayout(layoutWidget_7);
        categoryLayout->setObjectName("categoryLayout");
        categoryLayout->setContentsMargins(0, 0, 0, 0);
        addcategoryLbl = new QLabel(layoutWidget_7);
        addcategoryLbl->setObjectName("addcategoryLbl");

        categoryLayout->addWidget(addcategoryLbl);

        categorylineEdit = new QLineEdit(layoutWidget_7);
        categorylineEdit->setObjectName("categorylineEdit");
        categorylineEdit->setFocusPolicy(Qt::StrongFocus);
        categorylineEdit->setReadOnly(false);

        categoryLayout->addWidget(categorylineEdit);

        layoutWidget_8 = new QWidget(addStack);
        layoutWidget_8->setObjectName("layoutWidget_8");
        layoutWidget_8->setGeometry(QRect(10, 10, 171, 28));
        nameLayout = new QHBoxLayout(layoutWidget_8);
        nameLayout->setObjectName("nameLayout");
        nameLayout->setContentsMargins(0, 0, 0, 0);
        nameLbl_3 = new QLabel(layoutWidget_8);
        nameLbl_3->setObjectName("nameLbl_3");

        nameLayout->addWidget(nameLbl_3);

        namelineEdit = new QLineEdit(layoutWidget_8);
        namelineEdit->setObjectName("namelineEdit");
        namelineEdit->setFocusPolicy(Qt::StrongFocus);
        namelineEdit->setReadOnly(true);

        nameLayout->addWidget(namelineEdit);

        noteTextbox = new QLineEdit(addStack);
        noteTextbox->setObjectName("noteTextbox");
        noteTextbox->setGeometry(QRect(80, 120, 231, 41));
        noteTextbox->setFocusPolicy(Qt::StrongFocus);
        noteTextbox->setReadOnly(false);
        addnoteLbl = new QLabel(addStack);
        addnoteLbl->setObjectName("addnoteLbl");
        addnoteLbl->setGeometry(QRect(10, 120, 58, 26));
        layoutWidget_9 = new QWidget(addStack);
        layoutWidget_9->setObjectName("layoutWidget_9");
        layoutWidget_9->setGeometry(QRect(10, 80, 250, 28));
        reviewerLayout = new QHBoxLayout(layoutWidget_9);
        reviewerLayout->setObjectName("reviewerLayout");
        reviewerLayout->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_9);
        label_17->setObjectName("label_17");

        reviewerLayout->addWidget(label_17);

        reviewereditLine = new QLineEdit(layoutWidget_9);
        reviewereditLine->setObjectName("reviewereditLine");

        reviewerLayout->addWidget(reviewereditLine);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");

        reviewerLayout->addLayout(horizontalLayout_12);

        reviewerBtn = new QToolButton(layoutWidget_9);
        reviewerBtn->setObjectName("reviewerBtn");

        reviewerLayout->addWidget(reviewerBtn);

        onadderrorLbl = new QLabel(addStack);
        onadderrorLbl->setObjectName("onadderrorLbl");
        onadderrorLbl->setGeometry(QRect(10, 170, 101, 20));
        nextBtn_3 = new QPushButton(addStack);
        nextBtn_3->setObjectName("nextBtn_3");
        nextBtn_3->setGeometry(QRect(220, 180, 93, 29));
        addeditStack->addWidget(addStack);
        editStack = new QWidget();
        editStack->setObjectName("editStack");
        editlistView = new QListView(editStack);
        editlistView->setObjectName("editlistView");
        editlistView->setGeometry(QRect(10, 50, 291, 131));
        editBtn = new QPushButton(editStack);
        editBtn->setObjectName("editBtn");
        editBtn->setGeometry(QRect(50, 190, 80, 21));
        delBtn = new QPushButton(editStack);
        delBtn->setObjectName("delBtn");
        delBtn->setGeometry(QRect(180, 190, 80, 21));
        addeditStack->addWidget(editStack);
        cstmbackBtn = new QPushButton(addeditpg);
        cstmbackBtn->setObjectName("cstmbackBtn");
        cstmbackBtn->setGeometry(QRect(0, 0, 81, 21));
        editIndex = new QPushButton(addeditpg);
        editIndex->setObjectName("editIndex");
        editIndex->setGeometry(QRect(180, 50, 151, 29));
        addIndex = new QPushButton(addeditpg);
        addIndex->setObjectName("addIndex");
        addIndex->setGeometry(QRect(30, 50, 151, 29));
        addIndex->setStyleSheet(QString::fromUtf8(""));
        MainStack->addWidget(addeditpg);
        addpg = new QWidget();
        addpg->setObjectName("addpg");
        addcatLbl = new QLabel(addpg);
        addcatLbl->setObjectName("addcatLbl");
        addcatLbl->setGeometry(QRect(10, 30, 63, 20));
        nameLbl_4 = new QLabel(addpg);
        nameLbl_4->setObjectName("nameLbl_4");
        nameLbl_4->setGeometry(QRect(90, 30, 63, 20));
        questionLineEdit = new QLineEdit(addpg);
        questionLineEdit->setObjectName("questionLineEdit");
        questionLineEdit->setGeometry(QRect(20, 110, 321, 91));
        qnoLbl = new QLabel(addpg);
        qnoLbl->setObjectName("qnoLbl");
        qnoLbl->setGeometry(QRect(260, 30, 91, 20));
        quesText = new QLabel(addpg);
        quesText->setObjectName("quesText");
        quesText->setGeometry(QRect(20, 90, 63, 20));
        optionCBox = new QStackedWidget(addpg);
        optionCBox->setObjectName("optionCBox");
        optionCBox->setGeometry(QRect(20, 200, 321, 101));
        optionCBox->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        tofStacked = new QWidget();
        tofStacked->setObjectName("tofStacked");
        addtrueBtn = new QPushButton(tofStacked);
        addtrueBtn->setObjectName("addtrueBtn");
        addtrueBtn->setGeometry(QRect(30, 40, 93, 29));
        addtrueBtn->setStyleSheet(QString::fromUtf8(""));
        addfalseBtn = new QPushButton(tofStacked);
        addfalseBtn->setObjectName("addfalseBtn");
        addfalseBtn->setGeometry(QRect(190, 40, 93, 29));
        addfalseBtn->setStyleSheet(QString::fromUtf8(""));
        optionCBox->addWidget(tofStacked);
        multiStacked = new QWidget();
        multiStacked->setObjectName("multiStacked");
        addaBtn = new QPushButton(multiStacked);
        addaBtn->setObjectName("addaBtn");
        addaBtn->setGeometry(QRect(20, 10, 31, 29));
        addbBtn = new QPushButton(multiStacked);
        addbBtn->setObjectName("addbBtn");
        addbBtn->setGeometry(QRect(20, 60, 31, 29));
        addcBtn = new QPushButton(multiStacked);
        addcBtn->setObjectName("addcBtn");
        addcBtn->setGeometry(QRect(170, 10, 31, 29));
        adddBtn = new QPushButton(multiStacked);
        adddBtn->setObjectName("adddBtn");
        adddBtn->setGeometry(QRect(170, 60, 31, 29));
        alineEdit = new QLineEdit(multiStacked);
        alineEdit->setObjectName("alineEdit");
        alineEdit->setGeometry(QRect(60, 10, 71, 31));
        blineEdit = new QLineEdit(multiStacked);
        blineEdit->setObjectName("blineEdit");
        blineEdit->setGeometry(QRect(60, 60, 71, 31));
        clineEdit = new QLineEdit(multiStacked);
        clineEdit->setObjectName("clineEdit");
        clineEdit->setGeometry(QRect(210, 10, 71, 31));
        dlineEdit = new QLineEdit(multiStacked);
        dlineEdit->setObjectName("dlineEdit");
        dlineEdit->setGeometry(QRect(210, 60, 71, 31));
        optionCBox->addWidget(multiStacked);
        identiStacked = new QWidget();
        identiStacked->setObjectName("identiStacked");
        hardLineEdit = new QLineEdit(identiStacked);
        hardLineEdit->setObjectName("hardLineEdit");
        hardLineEdit->setGeometry(QRect(20, 30, 281, 41));
        optionCBox->addWidget(identiStacked);
        addBtn = new QPushButton(addpg);
        addBtn->setObjectName("addBtn");
        addBtn->setGeometry(QRect(50, 310, 93, 29));
        addsaveBtn = new QPushButton(addpg);
        addsaveBtn->setObjectName("addsaveBtn");
        addsaveBtn->setGeometry(QRect(220, 310, 93, 29));
        difficultyCBox = new QComboBox(addpg);
        difficultyCBox->addItem(QString());
        difficultyCBox->addItem(QString());
        difficultyCBox->addItem(QString());
        difficultyCBox->setObjectName("difficultyCBox");
        difficultyCBox->setGeometry(QRect(60, 60, 231, 26));
        addbackBtn = new QPushButton(addpg);
        addbackBtn->setObjectName("addbackBtn");
        addbackBtn->setGeometry(QRect(0, 0, 81, 21));
        MainStack->addWidget(addpg);
        leaderboardspg = new QWidget();
        leaderboardspg->setObjectName("leaderboardspg");
        lbText = new QLabel(leaderboardspg);
        lbText->setObjectName("lbText");
        lbText->setGeometry(QRect(160, 30, 71, 16));
        lbbackBtn = new QPushButton(leaderboardspg);
        lbbackBtn->setObjectName("lbbackBtn");
        lbbackBtn->setGeometry(QRect(140, 320, 80, 21));
        MainStack->addWidget(leaderboardspg);
        aboutuspg = new QWidget();
        aboutuspg->setObjectName("aboutuspg");
        auText = new QLabel(aboutuspg);
        auText->setObjectName("auText");
        auText->setGeometry(QRect(160, 30, 41, 14));
        aubackBtn = new QPushButton(aboutuspg);
        aubackBtn->setObjectName("aubackBtn");
        aubackBtn->setGeometry(QRect(140, 320, 80, 21));
        MainStack->addWidget(aboutuspg);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 360, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        MainStack->setCurrentIndex(0);
        diffStacked->setCurrentIndex(1);
        ls_box->setCurrentIndex(1);
        addeditStack->setCurrentIndex(1);
        optionCBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWindow", "                                                 PLAY", nullptr));
        lbBtn->setText(QCoreApplication::translate("MainWindow", "   LEADERBOARDS", nullptr));
        aboutusBtn->setText(QCoreApplication::translate("MainWindow", "ABOUT US", nullptr));
        diffLbl->setText(QCoreApplication::translate("MainWindow", "Difficulty:", nullptr));
        qnLbl->setText(QCoreApplication::translate("MainWindow", "Number of Questions", nullptr));
        nextBtn->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        catLbl->setText(QCoreApplication::translate("MainWindow", "Category:", nullptr));
        nextBtn_2->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        readyBtn->setText(QCoreApplication::translate("MainWindow", "Ready", nullptr));
        instrucLbl->setText(QCoreApplication::translate("MainWindow", "instruc", nullptr));
        ibackBtn->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        aBtn->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        bBtn->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        cBtn->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        dbtn->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        trueBtn->setText(QCoreApplication::translate("MainWindow", "True", nullptr));
        falseBtn->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        qstnLbl->setText(QCoreApplication::translate("MainWindow", "Question:", nullptr));
        pauseBtn->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        scoreLbl->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        scoreNum->setText(QCoreApplication::translate("MainWindow", "scoreLbl", nullptr));
        timeLbl->setText(QCoreApplication::translate("MainWindow", "time:", nullptr));
        categoryLbl->setText(QCoreApplication::translate("MainWindow", "category:", nullptr));
        quesNumLbl->setText(QCoreApplication::translate("MainWindow", "quesnum", nullptr));
        resueBtn->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        retryBtn_3->setText(QCoreApplication::translate("MainWindow", "Retry", nullptr));
        menuBtn->setText(QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
        nameLbl->setText(QCoreApplication::translate("MainWindow", "Name: ", nullptr));
        caLbl->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        scrLbl->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        remarksLbl->setText(QCoreApplication::translate("MainWindow", "Remarks", nullptr));
        caText->setText(QCoreApplication::translate("MainWindow", "Correct Answer/s:", nullptr));
        scre->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        name_lbl->setText(QCoreApplication::translate("MainWindow", "name:", nullptr));
        pass_lbl->setText(QCoreApplication::translate("MainWindow", "password:", nullptr));
        login_btn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Check lang", nullptr));
        error_msg_l->setText(QString());
        name_lbl_s->setText(QCoreApplication::translate("MainWindow", "name:", nullptr));
        pass_lbl_s->setText(QCoreApplication::translate("MainWindow", "password:", nullptr));
        pass_lbl_s_c->setText(QCoreApplication::translate("MainWindow", "confirm password:", nullptr));
        signup_btn->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        userLbl->setText(QCoreApplication::translate("MainWindow", "Insert into user", nullptr));
        error_msg->setText(QString());
        sign_sec->setText(QCoreApplication::translate("MainWindow", "Sign-up", nullptr));
        login_sec->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        lsbackBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        addcategoryLbl->setText(QCoreApplication::translate("MainWindow", "category", nullptr));
        categorylineEdit->setText(QString());
        nameLbl_3->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        namelineEdit->setText(QString());
        noteTextbox->setText(QString());
        addnoteLbl->setText(QCoreApplication::translate("MainWindow", "note", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "reviewer", nullptr));
        reviewerBtn->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        onadderrorLbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        nextBtn_3->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        editBtn->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        cstmbackBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        editIndex->setText(QCoreApplication::translate("MainWindow", "Edit/Delete", nullptr));
        addIndex->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addcatLbl->setText(QCoreApplication::translate("MainWindow", "category", nullptr));
        nameLbl_4->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        qnoLbl->setText(QCoreApplication::translate("MainWindow", "question no.", nullptr));
        quesText->setText(QCoreApplication::translate("MainWindow", "Question", nullptr));
        addtrueBtn->setText(QCoreApplication::translate("MainWindow", "True", nullptr));
        addfalseBtn->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        addaBtn->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        addbBtn->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        addcBtn->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        adddBtn->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addsaveBtn->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        difficultyCBox->setItemText(0, QCoreApplication::translate("MainWindow", "True or False", nullptr));
        difficultyCBox->setItemText(1, QCoreApplication::translate("MainWindow", "Multiple Choices", nullptr));
        difficultyCBox->setItemText(2, QCoreApplication::translate("MainWindow", "Identification", nullptr));

        addbackBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        lbText->setText(QCoreApplication::translate("MainWindow", "Leaderboards", nullptr));
        lbbackBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        auText->setText(QCoreApplication::translate("MainWindow", "About Us", nullptr));
        aubackBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
