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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FormulaUI
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *FormulaListUI;
    QLineEdit *eleEdit;
    QLineEdit *FormulaEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *GenerateFormula;
    QPushButton *predictBT;
    QLabel *label_3;
    QLineEdit *PredictNumberEdit;
    QTableWidget *LotterList;

    void setupUi(QDialog *FormulaUI)
    {
        if (FormulaUI->objectName().isEmpty())
            FormulaUI->setObjectName(QStringLiteral("FormulaUI"));
        FormulaUI->resize(800, 600);
        FormulaUI->setMinimumSize(QSize(800, 600));
        FormulaUI->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        FormulaUI->setFont(font);
        FormulaUI->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        buttonBox = new QDialogButtonBox(FormulaUI);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(500, 550, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        FormulaListUI = new QTableWidget(FormulaUI);
        if (FormulaListUI->columnCount() < 3)
            FormulaListUI->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        FormulaListUI->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        FormulaListUI->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        FormulaListUI->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        FormulaListUI->setObjectName(QStringLiteral("FormulaListUI"));
        FormulaListUI->setGeometry(QRect(30, 10, 731, 291));
        FormulaListUI->setMinimumSize(QSize(731, 291));
        FormulaListUI->setMaximumSize(QSize(731, 291));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        FormulaListUI->setFont(font1);
        FormulaListUI->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        FormulaListUI->setSelectionBehavior(QAbstractItemView::SelectRows);
        FormulaListUI->horizontalHeader()->setDefaultSectionSize(100);
        FormulaListUI->horizontalHeader()->setMinimumSectionSize(18);
        FormulaListUI->verticalHeader()->setVisible(false);
        eleEdit = new QLineEdit(FormulaUI);
        eleEdit->setObjectName(QStringLiteral("eleEdit"));
        eleEdit->setGeometry(QRect(90, 510, 113, 20));
        FormulaEdit = new QLineEdit(FormulaUI);
        FormulaEdit->setObjectName(QStringLiteral("FormulaEdit"));
        FormulaEdit->setGeometry(QRect(280, 510, 113, 20));
        label = new QLabel(FormulaUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 510, 81, 16));
        label_2 = new QLabel(FormulaUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 510, 71, 16));
        GenerateFormula = new QPushButton(FormulaUI);
        GenerateFormula->setObjectName(QStringLiteral("GenerateFormula"));
        GenerateFormula->setGeometry(QRect(80, 550, 111, 31));
        predictBT = new QPushButton(FormulaUI);
        predictBT->setObjectName(QStringLiteral("predictBT"));
        predictBT->setGeometry(QRect(240, 550, 121, 31));
        label_3 = new QLabel(FormulaUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 510, 71, 16));
        PredictNumberEdit = new QLineEdit(FormulaUI);
        PredictNumberEdit->setObjectName(QStringLiteral("PredictNumberEdit"));
        PredictNumberEdit->setGeometry(QRect(470, 510, 113, 20));
        LotterList = new QTableWidget(FormulaUI);
        if (LotterList->columnCount() < 7)
            LotterList->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        LotterList->setHorizontalHeaderItem(6, __qtablewidgetitem9);
        LotterList->setObjectName(QStringLiteral("LotterList"));
        LotterList->setGeometry(QRect(30, 310, 731, 191));
        LotterList->horizontalHeader()->setDefaultSectionSize(104);
        LotterList->verticalHeader()->setVisible(false);

        retranslateUi(FormulaUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormulaUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormulaUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormulaUI);
    } // setupUi

    void retranslateUi(QDialog *FormulaUI)
    {
        FormulaUI->setWindowTitle(QApplication::translate("FormulaUI", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = FormulaListUI->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormulaUI", "          \345\205\254          \345\274\217      ", 0));
        QTableWidgetItem *___qtablewidgetitem1 = FormulaListUI->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormulaUI", "\346\234\200\345\244\247\350\277\236\345\257\271", 0));
        QTableWidgetItem *___qtablewidgetitem2 = FormulaListUI->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FormulaUI", "\346\234\200\350\277\221\350\277\236\345\257\271", 0));
        label->setText(QApplication::translate("FormulaUI", "\345\205\203\347\264\240\344\270\252\346\225\260", 0));
        label_2->setText(QApplication::translate("FormulaUI", "\345\205\254\345\274\217\344\270\252\346\225\260", 0));
        GenerateFormula->setText(QApplication::translate("FormulaUI", "\347\224\237\346\210\220\345\205\254\345\274\217", 0));
        predictBT->setText(QApplication::translate("FormulaUI", "\351\242\204\346\265\213\344\270\213\346\234\237\345\217\267\347\240\201", 0));
        label_3->setText(QApplication::translate("FormulaUI", "\351\242\204\346\265\213\344\270\252\346\225\260", 0));
        PredictNumberEdit->setText(QString());
        QTableWidgetItem *___qtablewidgetitem3 = LotterList->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2031", 0));
        QTableWidgetItem *___qtablewidgetitem4 = LotterList->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2032", 0));
        QTableWidgetItem *___qtablewidgetitem5 = LotterList->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2033", 0));
        QTableWidgetItem *___qtablewidgetitem6 = LotterList->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2034", 0));
        QTableWidgetItem *___qtablewidgetitem7 = LotterList->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2035", 0));
        QTableWidgetItem *___qtablewidgetitem8 = LotterList->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("FormulaUI", "\347\272\242\347\220\2036", 0));
        QTableWidgetItem *___qtablewidgetitem9 = LotterList->horizontalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("FormulaUI", "\350\223\235\347\220\203", 0));
    } // retranslateUi

};

namespace Ui {
    class FormulaUI: public Ui_FormulaUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULAUI_H
