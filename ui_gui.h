/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "src/gui/area_widget.hpp"

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    AreaWidget *widget;
    QWidget *widget_2;
    QFrame *frame;
    QWidget *widget_3;
    QFrame *frame_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(800, 612);
        GUI->setAutoFillBackground(false);
        centralwidget = new QWidget(GUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new AreaWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(250, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:lightgrey;"));
        frame = new QFrame(widget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 9, 229, 200));
        frame->setStyleSheet(QString::fromUtf8("border: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(19, 19, 191, 111));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: black;"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(19, 150, 191, 31));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 0, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: darkblue;\n"
"color: white;"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 0, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: darkblue;\n"
"color: white;"));

        horizontalLayout->addWidget(widget_2);

        GUI->setCentralWidget(centralwidget);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("GUI", "Dolava", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GUI", "Doprava", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
