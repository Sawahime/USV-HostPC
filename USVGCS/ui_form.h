/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QChartView *graphicsView;
    QPushButton *Clear;
    QPushButton *StartAndStop;
    QPushButton *showVelocity;
    QPushButton *showXY;
    QPushButton *showCourse;
    QPushButton *showVel;
    QPushButton *showTurn;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(767, 749);
        graphicsView = new QChartView(Form);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 781, 721));
        Clear = new QPushButton(Form);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(100, 0, 93, 29));
        StartAndStop = new QPushButton(Form);
        StartAndStop->setObjectName(QString::fromUtf8("StartAndStop"));
        StartAndStop->setGeometry(QRect(0, 0, 93, 29));
        showVelocity = new QPushButton(Form);
        showVelocity->setObjectName(QString::fromUtf8("showVelocity"));
        showVelocity->setGeometry(QRect(300, 0, 93, 29));
        showXY = new QPushButton(Form);
        showXY->setObjectName(QString::fromUtf8("showXY"));
        showXY->setGeometry(QRect(200, 0, 93, 29));
        showCourse = new QPushButton(Form);
        showCourse->setObjectName(QString::fromUtf8("showCourse"));
        showCourse->setGeometry(QRect(400, 0, 93, 29));
        showVel = new QPushButton(Form);
        showVel->setObjectName(QString::fromUtf8("showVel"));
        showVel->setGeometry(QRect(500, 0, 93, 29));
        showTurn = new QPushButton(Form);
        showTurn->setObjectName(QString::fromUtf8("showTurn"));
        showTurn->setGeometry(QRect(600, 0, 93, 29));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Clear->setText(QCoreApplication::translate("Form", "clear", nullptr));
        StartAndStop->setText(QCoreApplication::translate("Form", "Start", nullptr));
        showVelocity->setText(QCoreApplication::translate("Form", "\350\210\252\351\200\237", nullptr));
        showXY->setText(QCoreApplication::translate("Form", "X-Y", nullptr));
        showCourse->setText(QCoreApplication::translate("Form", "\350\210\252\345\220\221", nullptr));
        showVel->setText(QCoreApplication::translate("Form", "\351\200\237\345\272\246", nullptr));
        showTurn->setText(QCoreApplication::translate("Form", "\350\275\254\345\220\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
