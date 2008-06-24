/********************************************************************************
** Form generated from reading ui file 'Graphing.ui'
**
** Created: Mon Jun 23 15:40:14 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GRAPHING_H
#define UI_GRAPHING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *equationLineEdit;
    QLabel *label_2;
    QDoubleSpinBox *lowerDoubleSpinBox;
    QDoubleSpinBox *higherDoubleSpinBox;
    QPushButton *evaluatePushButton;
    QLabel *label;
    QTableView *constantsTableView;
    QSpacerItem *verticalSpacer;
    QLabel *equationLabel;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 21, 800, 560));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    equationLineEdit = new QLineEdit(centralwidget);
    equationLineEdit->setObjectName(QString::fromUtf8("equationLineEdit"));

    gridLayout->addWidget(equationLineEdit, 0, 0, 1, 1);

    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    label_2->setFont(font);
    label_2->setTextFormat(Qt::PlainText);

    gridLayout->addWidget(label_2, 0, 1, 1, 1);

    lowerDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    lowerDoubleSpinBox->setObjectName(QString::fromUtf8("lowerDoubleSpinBox"));

    gridLayout->addWidget(lowerDoubleSpinBox, 0, 2, 1, 1);

    higherDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    higherDoubleSpinBox->setObjectName(QString::fromUtf8("higherDoubleSpinBox"));

    gridLayout->addWidget(higherDoubleSpinBox, 0, 3, 1, 1);

    evaluatePushButton = new QPushButton(centralwidget);
    evaluatePushButton->setObjectName(QString::fromUtf8("evaluatePushButton"));

    gridLayout->addWidget(evaluatePushButton, 0, 4, 1, 1);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setFont(font);
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label, 1, 0, 1, 2);

    constantsTableView = new QTableView(centralwidget);
    constantsTableView->setObjectName(QString::fromUtf8("constantsTableView"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(constantsTableView->sizePolicy().hasHeightForWidth());
    constantsTableView->setSizePolicy(sizePolicy);
    constantsTableView->setMaximumSize(QSize(256, 150));

    gridLayout->addWidget(constantsTableView, 1, 2, 2, 3);

    verticalSpacer = new QSpacerItem(20, 134, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

    equationLabel = new QLabel(centralwidget);
    equationLabel->setObjectName(QString::fromUtf8("equationLabel"));
    equationLabel->setFont(font);
    equationLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(equationLabel, 3, 0, 1, 5);

    textBrowser = new QTextBrowser(centralwidget);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    textBrowser->setMinimumSize(QSize(0, 330));

    gridLayout->addWidget(textBrowser, 4, 0, 1, 5);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 21));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 581, 800, 19));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Range:", 0, QApplication::UnicodeUTF8));
    evaluatePushButton->setText(QApplication::translate("MainWindow", "Evaluate", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Constants:", 0, QApplication::UnicodeUTF8));
    equationLabel->setText(QApplication::translate("MainWindow", "Equation", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHING_H
