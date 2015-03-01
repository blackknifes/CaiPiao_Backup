/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *showList;
    QComboBox *TestMath;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *formulaBT;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(700, 480);
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\245\267\344\275\223\";"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        showList = new QListWidget(centralWidget);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(showList);
        __qlistwidgetitem->setFlags(Qt::NoItemFlags);
        showList->setObjectName(QStringLiteral("showList"));
        showList->setGeometry(QRect(50, 10, 591, 371));
        showList->setMinimumSize(QSize(1, 0));
        showList->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        showList->setFont(font);
        showList->setStyleSheet(QStringLiteral(""));
        TestMath = new QComboBox(centralWidget);
        TestMath->setObjectName(QStringLiteral("TestMath"));
        TestMath->setGeometry(QRect(10, 390, 111, 21));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(250, 390, 131, 31));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 206, 206);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 390, 81, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 430, 101, 41));
        formulaBT = new QPushButton(centralWidget);
        formulaBT->setObjectName(QStringLiteral("formulaBT"));
        formulaBT->setGeometry(QRect(360, 430, 121, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));

        const bool __sortingEnabled = showList->isSortingEnabled();
        showList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = showList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\346\234\237\346\225\260:                   \347\272\242\347\220\203:                   \350\223\235\347\220\203:", 0));
        showList->setSortingEnabled(__sortingEnabled);

        TestMath->clear();
        TestMath->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\272\242\347\220\203\351\232\217\346\234\272", 0)
         << QApplication::translate("MainWindow", "AC\345\200\274", 0)
         << QApplication::translate("MainWindow", "\345\217\226\345\244\264", 0)
         << QApplication::translate("MainWindow", "\345\217\226\345\260\276", 0)
         << QApplication::translate("MainWindow", "\345\245\207\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\201\266\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\350\264\250\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\220\210\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\244\247\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\260\217\346\225\260\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\245\207\346\225\260\345\222\214", 0)
         << QApplication::translate("MainWindow", "\345\201\266\346\225\260\345\222\214", 0)
         << QApplication::translate("MainWindow", "\345\222\214\345\200\274", 0)
         << QApplication::translate("MainWindow", "\345\220\210\345\200\274", 0)
         << QApplication::translate("MainWindow", "\346\236\201\350\267\235", 0)
         << QApplication::translate("MainWindow", "\345\222\214\345\200\274\345\245\207\345\201\266", 0)
         << QApplication::translate("MainWindow", "\345\222\214\345\200\274012", 0)
         << QApplication::translate("MainWindow", "\345\222\214\345\200\274\350\264\250\345\220\210", 0)
         << QApplication::translate("MainWindow", "\345\222\214\345\200\274\345\244\247\345\260\217", 0)
         << QApplication::translate("MainWindow", "\345\260\276\346\225\260\345\222\214\345\200\274", 0)
         << QApplication::translate("MainWindow", "\345\260\276\345\222\214\345\220\210\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\260\276\345\222\214\345\260\276\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\260\276\345\222\214\345\244\247\345\260\217", 0)
         << QApplication::translate("MainWindow", "\345\260\276\345\222\214\345\245\207\345\201\266", 0)
         << QApplication::translate("MainWindow", "\345\220\214\345\260\276\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\346\234\200\345\244\247\347\240\201\350\267\235", 0)
         << QApplication::translate("MainWindow", "\346\234\200\345\260\217\347\240\201\350\267\235", 0)
         << QApplication::translate("MainWindow", "\345\220\210\345\200\274012", 0)
         << QApplication::translate("MainWindow", "\345\220\210\345\200\274\350\264\250\345\220\210", 0)
         << QApplication::translate("MainWindow", "\345\220\210\345\200\274\345\244\247\345\260\217", 0)
         << QApplication::translate("MainWindow", "0\350\267\257\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "1\350\267\257\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "2\350\267\257\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\350\277\236\345\217\267\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\350\277\236\345\217\267\347\273\204\346\225\260", 0)
         << QApplication::translate("MainWindow", "\351\201\227\346\274\217\345\222\214", 0)
         << QApplication::translate("MainWindow", "\345\201\217\345\272\246", 0)
         << QApplication::translate("MainWindow", "\346\225\243\345\272\246", 0)
         << QApplication::translate("MainWindow", "1\345\214\272\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "2\345\214\272\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "3\345\214\272\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\344\270\252\344\275\215\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\345\215\201\344\275\215\344\270\252\346\225\260", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\2031-16\351\232\217\346\234\272", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203\346\214\257\345\271\205", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203\345\244\247\345\260\217", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203\345\245\207\345\201\266", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203\350\264\250\345\220\210", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203\345\260\276\346\225\260", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\220\203012", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\347\273\223\346\236\234\357\274\232", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\346\265\213   \350\257\225", 0));
        formulaBT->setText(QApplication::translate("MainWindow", "\345\205\254\345\274\217\346\237\245\346\211\276", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
