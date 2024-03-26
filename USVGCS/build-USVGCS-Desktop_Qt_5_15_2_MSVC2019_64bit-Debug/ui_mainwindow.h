/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwebengineview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReload_Map;
    QAction *actionRuler;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QWebEngineView *widget_web;
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit_p;
    QLineEdit *lineEdit_i;
    QLineEdit *lineEdit_d;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_stop;
    QRadioButton *radioButton_run;
    QPushButton *pushButton_sendCommond;
    QPushButton *pushButton_test;
    QPushButton *pushButton_getCsvFile;
    QPushButton *pushButton_trackBack;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_ballLng;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_ballLat;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_ballColor;
    QPushButton *pushButton_addBall;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_setHome;
    QPushButton *pushButton_setEnd;
    QPushButton *pushButton_simulatorInit;
    QPushButton *pushButton_simulatorStart;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_mouse_lng;
    QLabel *label_mouse_lat;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_serial_open;
    QComboBox *comboBox_serial_name;
    QComboBox *comboBox_serial_baud;
    QPushButton *pushButton_serial_search;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_boat_lat;
    QLabel *label_boat_cmdvel;
    QLabel *label_10;
    QLabel *label_boat_velocity;
    QLabel *label_11;
    QLabel *label_4;
    QLabel *label_Y;
    QLabel *label_7;
    QLabel *label_boat_cmdturn;
    QLabel *label_X;
    QLabel *label_8;
    QLabel *label_boat_lng;
    QLabel *label_6;
    QLabel *label_boat_course;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_port;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_clearMap;
    QPushButton *pushButton_showoverlays;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(986, 749);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionReload_Map = new QAction(MainWindow);
        actionReload_Map->setObjectName(QString::fromUtf8("actionReload_Map"));
        actionRuler = new QAction(MainWindow);
        actionRuler->setObjectName(QString::fromUtf8("actionRuler"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_web = new QWebEngineView(centralWidget);
        widget_web->setObjectName(QString::fromUtf8("widget_web"));

        verticalLayout_4->addWidget(widget_web);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideNone);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout_3 = new QVBoxLayout(tab_1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        lineEdit_p = new QLineEdit(tab_1);
        lineEdit_p->setObjectName(QString::fromUtf8("lineEdit_p"));

        horizontalLayout_6->addWidget(lineEdit_p);

        lineEdit_i = new QLineEdit(tab_1);
        lineEdit_i->setObjectName(QString::fromUtf8("lineEdit_i"));

        horizontalLayout_6->addWidget(lineEdit_i);

        lineEdit_d = new QLineEdit(tab_1);
        lineEdit_d->setObjectName(QString::fromUtf8("lineEdit_d"));

        horizontalLayout_6->addWidget(lineEdit_d);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButton_stop = new QRadioButton(tab_1);
        radioButton_stop->setObjectName(QString::fromUtf8("radioButton_stop"));
        radioButton_stop->setChecked(false);

        horizontalLayout_7->addWidget(radioButton_stop);

        radioButton_run = new QRadioButton(tab_1);
        radioButton_run->setObjectName(QString::fromUtf8("radioButton_run"));
        radioButton_run->setEnabled(true);
        radioButton_run->setLayoutDirection(Qt::LeftToRight);
        radioButton_run->setAutoFillBackground(false);
        radioButton_run->setChecked(true);

        horizontalLayout_7->addWidget(radioButton_run);


        verticalLayout_3->addLayout(horizontalLayout_7);

        pushButton_sendCommond = new QPushButton(tab_1);
        pushButton_sendCommond->setObjectName(QString::fromUtf8("pushButton_sendCommond"));

        verticalLayout_3->addWidget(pushButton_sendCommond);

        pushButton_test = new QPushButton(tab_1);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));

        verticalLayout_3->addWidget(pushButton_test);

        pushButton_getCsvFile = new QPushButton(tab_1);
        pushButton_getCsvFile->setObjectName(QString::fromUtf8("pushButton_getCsvFile"));

        verticalLayout_3->addWidget(pushButton_getCsvFile);

        pushButton_trackBack = new QPushButton(tab_1);
        pushButton_trackBack->setObjectName(QString::fromUtf8("pushButton_trackBack"));
        pushButton_trackBack->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(pushButton_trackBack);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        lineEdit_ballLng = new QLineEdit(tab_2);
        lineEdit_ballLng->setObjectName(QString::fromUtf8("lineEdit_ballLng"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_ballLng->sizePolicy().hasHeightForWidth());
        lineEdit_ballLng->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_ballLng);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 8);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        lineEdit_ballLat = new QLineEdit(tab_2);
        lineEdit_ballLat->setObjectName(QString::fromUtf8("lineEdit_ballLat"));
        sizePolicy.setHeightForWidth(lineEdit_ballLat->sizePolicy().hasHeightForWidth());
        lineEdit_ballLat->setSizePolicy(sizePolicy);
        lineEdit_ballLat->setFrame(true);

        horizontalLayout_4->addWidget(lineEdit_ballLat);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 8);

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_ballColor = new QComboBox(tab_2);
        comboBox_ballColor->addItem(QString());
        comboBox_ballColor->addItem(QString());
        comboBox_ballColor->addItem(QString());
        comboBox_ballColor->addItem(QString());
        comboBox_ballColor->addItem(QString());
        comboBox_ballColor->setObjectName(QString::fromUtf8("comboBox_ballColor"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_ballColor->sizePolicy().hasHeightForWidth());
        comboBox_ballColor->setSizePolicy(sizePolicy1);
        comboBox_ballColor->setEditable(false);
        comboBox_ballColor->setFrame(true);

        horizontalLayout_5->addWidget(comboBox_ballColor);

        pushButton_addBall = new QPushButton(tab_2);
        pushButton_addBall->setObjectName(QString::fromUtf8("pushButton_addBall"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_addBall->sizePolicy().hasHeightForWidth());
        pushButton_addBall->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(pushButton_addBall);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_setHome = new QPushButton(tab_2);
        pushButton_setHome->setObjectName(QString::fromUtf8("pushButton_setHome"));
        sizePolicy2.setHeightForWidth(pushButton_setHome->sizePolicy().hasHeightForWidth());
        pushButton_setHome->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_setHome);

        pushButton_setEnd = new QPushButton(tab_2);
        pushButton_setEnd->setObjectName(QString::fromUtf8("pushButton_setEnd"));
        sizePolicy2.setHeightForWidth(pushButton_setEnd->sizePolicy().hasHeightForWidth());
        pushButton_setEnd->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_setEnd);

        pushButton_simulatorInit = new QPushButton(tab_2);
        pushButton_simulatorInit->setObjectName(QString::fromUtf8("pushButton_simulatorInit"));
        sizePolicy2.setHeightForWidth(pushButton_simulatorInit->sizePolicy().hasHeightForWidth());
        pushButton_simulatorInit->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_simulatorInit);

        pushButton_simulatorStart = new QPushButton(tab_2);
        pushButton_simulatorStart->setObjectName(QString::fromUtf8("pushButton_simulatorStart"));
        sizePolicy2.setHeightForWidth(pushButton_simulatorStart->sizePolicy().hasHeightForWidth());
        pushButton_simulatorStart->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_simulatorStart);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_mouse_lng = new QLabel(tab_2);
        label_mouse_lng->setObjectName(QString::fromUtf8("label_mouse_lng"));
        label_mouse_lng->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_mouse_lng);

        label_mouse_lat = new QLabel(tab_2);
        label_mouse_lat->setObjectName(QString::fromUtf8("label_mouse_lat"));
        label_mouse_lat->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_mouse_lat);


        verticalLayout_2->addLayout(horizontalLayout_10);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton_serial_open = new QPushButton(tab);
        pushButton_serial_open->setObjectName(QString::fromUtf8("pushButton_serial_open"));

        verticalLayout_5->addWidget(pushButton_serial_open);

        comboBox_serial_name = new QComboBox(tab);
        comboBox_serial_name->setObjectName(QString::fromUtf8("comboBox_serial_name"));

        verticalLayout_5->addWidget(comboBox_serial_name);

        comboBox_serial_baud = new QComboBox(tab);
        comboBox_serial_baud->addItem(QString());
        comboBox_serial_baud->addItem(QString());
        comboBox_serial_baud->addItem(QString());
        comboBox_serial_baud->addItem(QString());
        comboBox_serial_baud->setObjectName(QString::fromUtf8("comboBox_serial_baud"));

        verticalLayout_5->addWidget(comboBox_serial_baud);

        pushButton_serial_search = new QPushButton(tab);
        pushButton_serial_search->setObjectName(QString::fromUtf8("pushButton_serial_search"));

        verticalLayout_5->addWidget(pushButton_serial_search);

        tabWidget->addTab(tab, QString());

        horizontalLayout_8->addWidget(tabWidget);

        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_boat_lat = new QLabel(frame_4);
        label_boat_lat->setObjectName(QString::fromUtf8("label_boat_lat"));

        gridLayout->addWidget(label_boat_lat, 1, 3, 1, 1);

        label_boat_cmdvel = new QLabel(frame_4);
        label_boat_cmdvel->setObjectName(QString::fromUtf8("label_boat_cmdvel"));

        gridLayout->addWidget(label_boat_cmdvel, 3, 1, 1, 1);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        label_boat_velocity = new QLabel(frame_4);
        label_boat_velocity->setObjectName(QString::fromUtf8("label_boat_velocity"));

        gridLayout->addWidget(label_boat_velocity, 2, 1, 1, 1);

        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 0, 2, 1, 1);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_Y = new QLabel(frame_4);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));

        gridLayout->addWidget(label_Y, 0, 3, 1, 1);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_boat_cmdturn = new QLabel(frame_4);
        label_boat_cmdturn->setObjectName(QString::fromUtf8("label_boat_cmdturn"));

        gridLayout->addWidget(label_boat_cmdturn, 3, 3, 1, 1);

        label_X = new QLabel(frame_4);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        label_X->setFrameShape(QFrame::NoFrame);
        label_X->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_X, 0, 1, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_boat_lng = new QLabel(frame_4);
        label_boat_lng->setObjectName(QString::fromUtf8("label_boat_lng"));

        gridLayout->addWidget(label_boat_lng, 1, 1, 1, 1);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_boat_course = new QLabel(frame_4);
        label_boat_course->setObjectName(QString::fromUtf8("label_boat_course"));

        gridLayout->addWidget(label_boat_course, 2, 3, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 2);

        horizontalLayout_8->addWidget(frame_4);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ip = new QLabel(frame_3);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_ip);

        lineEdit_ip = new QLineEdit(frame_3);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        sizePolicy.setHeightForWidth(lineEdit_ip->sizePolicy().hasHeightForWidth());
        lineEdit_ip->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_ip);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_port = new QLabel(frame_3);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_port);

        lineEdit_port = new QLineEdit(frame_3);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        sizePolicy.setHeightForWidth(lineEdit_port->sizePolicy().hasHeightForWidth());
        lineEdit_port->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_port);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_connect = new QPushButton(frame_3);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        sizePolicy2.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButton_connect);

        pushButton_clearMap = new QPushButton(frame_3);
        pushButton_clearMap->setObjectName(QString::fromUtf8("pushButton_clearMap"));

        verticalLayout->addWidget(pushButton_clearMap);

        pushButton_showoverlays = new QPushButton(frame_3);
        pushButton_showoverlays->setObjectName(QString::fromUtf8("pushButton_showoverlays"));

        verticalLayout->addWidget(pushButton_showoverlays);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        verticalLayout_6->addLayout(verticalLayout);


        horizontalLayout_8->addWidget(frame_3);

        horizontalLayout_8->setStretch(0, 2);
        horizontalLayout_8->setStretch(1, 2);
        horizontalLayout_8->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_8);

        verticalLayout_4->setStretch(0, 7);
        verticalLayout_4->setStretch(1, 3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 986, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionReload_Map);
        menu->addAction(actionRuler);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "USVGCS V1.0", nullptr));
        actionReload_Map->setText(QCoreApplication::translate("MainWindow", "Reload Map", nullptr));
        actionRuler->setText(QCoreApplication::translate("MainWindow", "Ruler", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PID:", nullptr));
        lineEdit_p->setText(QCoreApplication::translate("MainWindow", "0.04", nullptr));
        lineEdit_i->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_d->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        radioButton_stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246", nullptr));
        radioButton_run->setText(QCoreApplication::translate("MainWindow", "\350\210\252\350\241\214", nullptr));
        pushButton_sendCommond->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\214\207\344\273\244", nullptr));
        pushButton_test->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        pushButton_getCsvFile->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245CSV\346\226\207\344\273\266", nullptr));
        pushButton_trackBack->setText(QCoreApplication::translate("MainWindow", "\345\233\236\346\224\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "\345\256\236\350\210\252", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246:", nullptr));
        lineEdit_ballLng->setText(QCoreApplication::translate("MainWindow", "113.6097846", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246:", nullptr));
        lineEdit_ballLat->setText(QCoreApplication::translate("MainWindow", "22.3796306", nullptr));
        comboBox_ballColor->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        comboBox_ballColor->setItemText(1, QCoreApplication::translate("MainWindow", "blue", nullptr));
        comboBox_ballColor->setItemText(2, QCoreApplication::translate("MainWindow", "yellow", nullptr));
        comboBox_ballColor->setItemText(3, QCoreApplication::translate("MainWindow", "green", nullptr));
        comboBox_ballColor->setItemText(4, QCoreApplication::translate("MainWindow", "black", nullptr));

        pushButton_addBall->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\220\203", nullptr));
        pushButton_setHome->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\216\237\347\202\271", nullptr));
        pushButton_setEnd->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\273\210\347\202\271", nullptr));
        pushButton_simulatorInit->setText(QCoreApplication::translate("MainWindow", "\344\273\277\347\234\237\345\210\235\345\247\213\345\214\226", nullptr));
        pushButton_simulatorStart->setText(QCoreApplication::translate("MainWindow", "\344\273\277\347\234\237\345\274\200\345\247\213", nullptr));
        label_mouse_lng->setText(QString());
        label_mouse_lat->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\344\273\277\347\234\237", nullptr));
        pushButton_serial_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        comboBox_serial_baud->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBox_serial_baud->setItemText(1, QCoreApplication::translate("MainWindow", "38400", nullptr));
        comboBox_serial_baud->setItemText(2, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboBox_serial_baud->setItemText(3, QCoreApplication::translate("MainWindow", "115200", nullptr));

        pushButton_serial_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\220\221\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246\357\274\232", nullptr));
        label_boat_lat->setText(QString());
        label_boat_cmdvel->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "X\357\274\232", nullptr));
        label_boat_velocity->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246\357\274\232", nullptr));
        label_Y->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\210\252\345\220\221\357\274\232", nullptr));
        label_boat_cmdturn->setText(QString());
        label_X->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_boat_lng->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\210\252\351\200\237\357\274\232", nullptr));
        label_boat_course->setText(QString());
        label_ip->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        lineEdit_ip->setText(QCoreApplication::translate("MainWindow", "192.168.31.202", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineEdit_port->setText(QCoreApplication::translate("MainWindow", "8080", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        pushButton_clearMap->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\350\246\206\347\233\226\347\211\251", nullptr));
        pushButton_showoverlays->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\246\206\347\233\226\347\211\251", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
