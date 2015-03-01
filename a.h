/********************************************************************************
** Form generated from reading UI file 'formulaui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULAUI_H
#define UI_FORMULAUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FormulaUI
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *FormulaListUI;
    QLineEdit *eleEdit;
    QLineEdit *FormulaEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *GenerateFormula;
    QPushButton *predictBT;
    QLabel *label_3;
    QLineEdit *PredictNumberEdit;

    void setupUi(QDialog *FormulaUI)
    {
        if (FormulaUI->objectName().isEmpty())
            FormulaUI->setObjectName(QStringLiteral("FormulaUI"));
        FormulaUI->resize(800, 600);
        FormulaUI->setMinimumSize(QSize(800, 600));
        FormulaUI->setMaximumSize(QSize(800, 600));
        FormulaUI->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        buttonBox = new QDialogButtonBox(FormulaUI);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(500, 490, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FormulaListUI = new QListWidget(FormulaUI);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(FormulaListUI);
        __qlistwidgetitem->setFlags(Qt::NoItemFlags);
        FormulaListUI->setObjectName(QStringLiteral("FormulaListUI"));
        FormulaListUI->setGeometry(QRect(40, 10, 591, 421));
        eleEdit = new QLineEdit(FormulaUI);
        eleEdit->setObjectName(QStringLiteral("eleEdit"));
        eleEdit->setGeometry(QRect(90, 450, 113, 20));
        FormulaEdit = new QLineEdit(FormulaUI);
        FormulaEdit->setObjectName(QStringLiteral("FormulaEdit"));
        FormulaEdit->setGeometry(QRect(280, 450, 113, 20));
        label = new QLabel(FormulaUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 450, 81, 16));
        label_2 = new QLabel(FormulaUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 450, 71, 16));
        GenerateFormula = new QPushButton(FormulaUI);
        GenerateFormula->setObjectName(QStringLiteral("GenerateFormula"));
        GenerateFormula->setGeometry(QRect(80, 490, 111, 31));
        predictBT = new QPushButton(FormulaUI);
        predictBT->setObjectName(QStringLiteral("predictBT"));
        predictBT->setGeometry(QRect(240, 490, 121, 31));
        label_3 = new QLabel(FormulaUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 450, 71, 16));
        PredictNumberEdit = new QLineEdit(FormulaUI);
        PredictNumberEdit->setObjectName(QStringLiteral("PredictNumberEdit"));
        PredictNumberEdit->setGeometry(QRect(470, 450, 113, 20));

        retranslateUi(FormulaUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormulaUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormulaUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormulaUI);
    } // setupUi

    void retranslateUi(QDialog *FormulaUI)
    {
        FormulaUI->setWindowTitle(QApplication::translate("FormulaUI", "Dialog", 0));

        const bool __sortingEnabled = FormulaListUI->isSortingEnabled();
        FormulaListUI->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = FormulaListUI->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("FormulaUI", "\345\205\254\345\274\217\357\274\232                                                                      \346\234\200\345\244\247\350\277\236\345\257\271\357\274\232           \346\234\200\350\277\221\350\277\236\345\257\271\357\274\232", 0));
        FormulaListUI->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("FormulaUI", "\345\205\203\347\264\240\344\270\252\346\225\260", 0));
        label_2->setText(QApplication::translate("FormulaUI", "\345\205\254\345\274\217\344\270\252\346\225\260", 0));
        GenerateFormula->setText(QApplication::translate("FormulaUI", "\347\224\237\346\210\220\345\205\254\345\274\217", 0));
        predictBT->setText(QApplication::translate("FormulaUI", "\351\242\204\346\265\213\344\270\213\346\234\237\345\217\267\347\240\201", 0));
        label_3->setText(QApplication::translate("FormulaUI", "\351\242\204\346\265\213\344\270\252\346\225\260", 0));
        PredictNumberEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormulaUI: public Ui_FormulaUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULAUI_H
