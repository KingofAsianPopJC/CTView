/********************************************************************************
** Form generated from reading UI file 'Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CTViewer
{
public:
    QAction *Open;
    QAction *Save;
    QWidget *centralwidget;
    QVTKWidget *DisplayWindow_1;
    QVTKWidget *DisplayWindow_2;
    QVTKWidget *DisplayWindow_3;
    QSlider *ChangeCorona;
    QSlider *ChangeSagittal;
    QSlider *ChangeTransversal;
    QLabel *Transversal;
    QLabel *Corona;
    QLabel *Sagittal;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CTViewer)
    {
        if (CTViewer->objectName().isEmpty())
            CTViewer->setObjectName(QStringLiteral("CTViewer"));
        CTViewer->resize(800, 844);
        CTViewer->setStyleSheet(QStringLiteral(""));
        Open = new QAction(CTViewer);
        Open->setObjectName(QStringLiteral("Open"));
        Save = new QAction(CTViewer);
        Save->setObjectName(QStringLiteral("Save"));
        centralwidget = new QWidget(CTViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        DisplayWindow_1 = new QVTKWidget(centralwidget);
        DisplayWindow_1->setObjectName(QStringLiteral("DisplayWindow_1"));
        DisplayWindow_1->setGeometry(QRect(20, 40, 350, 350));
        DisplayWindow_1->setStyleSheet(QStringLiteral(""));
        DisplayWindow_2 = new QVTKWidget(centralwidget);
        DisplayWindow_2->setObjectName(QStringLiteral("DisplayWindow_2"));
        DisplayWindow_2->setGeometry(QRect(430, 40, 350, 350));
        DisplayWindow_2->setStyleSheet(QStringLiteral(""));
        DisplayWindow_3 = new QVTKWidget(centralwidget);
        DisplayWindow_3->setObjectName(QStringLiteral("DisplayWindow_3"));
        DisplayWindow_3->setGeometry(QRect(20, 430, 350, 350));
        DisplayWindow_3->setStyleSheet(QStringLiteral(""));
        ChangeCorona = new QSlider(centralwidget);
        ChangeCorona->setObjectName(QStringLiteral("ChangeCorona"));
        ChangeCorona->setGeometry(QRect(490, 580, 281, 22));
        ChangeCorona->setOrientation(Qt::Horizontal);
        ChangeSagittal = new QSlider(centralwidget);
        ChangeSagittal->setObjectName(QStringLiteral("ChangeSagittal"));
        ChangeSagittal->setGeometry(QRect(490, 660, 281, 22));
        ChangeSagittal->setOrientation(Qt::Horizontal);
        ChangeTransversal = new QSlider(centralwidget);
        ChangeTransversal->setObjectName(QStringLiteral("ChangeTransversal"));
        ChangeTransversal->setGeometry(QRect(490, 500, 281, 22));
        ChangeTransversal->setStyleSheet(QStringLiteral(""));
        ChangeTransversal->setOrientation(Qt::Horizontal);
        Transversal = new QLabel(centralwidget);
        Transversal->setObjectName(QStringLiteral("Transversal"));
        Transversal->setGeometry(QRect(420, 500, 51, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Transversal->setFont(font);
        Corona = new QLabel(centralwidget);
        Corona->setObjectName(QStringLiteral("Corona"));
        Corona->setGeometry(QRect(420, 580, 51, 21));
        Corona->setFont(font);
        Sagittal = new QLabel(centralwidget);
        Sagittal->setObjectName(QStringLiteral("Sagittal"));
        Sagittal->setGeometry(QRect(420, 660, 51, 21));
        Sagittal->setFont(font);
        CTViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CTViewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        CTViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(CTViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CTViewer->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Open);
        menu->addAction(Save);

        retranslateUi(CTViewer);

        QMetaObject::connectSlotsByName(CTViewer);
    } // setupUi

    void retranslateUi(QMainWindow *CTViewer)
    {
        CTViewer->setWindowTitle(QApplication::translate("CTViewer", "CT\346\237\245\347\234\213\345\231\250", Q_NULLPTR));
        Open->setText(QApplication::translate("CTViewer", "\346\211\223\345\274\200", Q_NULLPTR));
        Save->setText(QApplication::translate("CTViewer", "\344\277\235\345\255\230", Q_NULLPTR));
        Transversal->setText(QApplication::translate("CTViewer", "\346\250\252\345\210\207\351\235\242", Q_NULLPTR));
        Corona->setText(QApplication::translate("CTViewer", "\345\206\240\347\212\266\351\235\242", Q_NULLPTR));
        Sagittal->setText(QApplication::translate("CTViewer", "\347\237\242\347\212\266\351\235\242", Q_NULLPTR));
        menu->setTitle(QApplication::translate("CTViewer", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CTViewer: public Ui_CTViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
