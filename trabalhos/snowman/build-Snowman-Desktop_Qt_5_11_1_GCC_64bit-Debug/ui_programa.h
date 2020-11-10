/********************************************************************************
** Form generated from reading UI file 'programa.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMA_H
#define UI_PROGRAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Programa
{
public:
    QGridLayout *gridLayout;
    GLWidget *widget;

    void setupUi(QWidget *Programa)
    {
        if (Programa->objectName().isEmpty())
            Programa->setObjectName(QStringLiteral("Programa"));
        Programa->setWindowModality(Qt::ApplicationModal);
        Programa->resize(600, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Programa->sizePolicy().hasHeightForWidth());
        Programa->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Programa);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new GLWidget(Programa);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Programa);

        QMetaObject::connectSlotsByName(Programa);
    } // setupUi

    void retranslateUi(QWidget *Programa)
    {
        Programa->setWindowTitle(QApplication::translate("Programa", "Snowman", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Programa: public Ui_Programa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMA_H
