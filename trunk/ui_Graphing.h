/********************************************************************************
** Form generated from reading ui file 'Graphing.ui'
**
** Created: Wed Sep 3 23:00:29 2008
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
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "GraphWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QLineEdit *equationLineEdit;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QPushButton *addConstantsModelPointPushButton;
    QPushButton *clearConstantsModelPushButton;
    QTableView *constantsTableView;
    QGridLayout *gridLayout2;
    QLabel *label_3;
    QLineEdit *independentVariableLineEdit;
    QCheckBox *useRangeCheckBox;
    QHBoxLayout *hboxLayout;
    QDoubleSpinBox *lowerDoubleSpinBox;
    QDoubleSpinBox *higherDoubleSpinBox;
    QPushButton *evaluatePushButton;
    QLabel *equationLabel;
    QTextBrowser *textBrowser;
    GraphWidget *graphWidget;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 631);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout1 = new QGridLayout();
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    equationLineEdit = new QLineEdit(centralwidget);
    equationLineEdit->setObjectName(QString::fromUtf8("equationLineEdit"));
    equationLineEdit->setMaximumSize(QSize(250, 16777215));

    gridLayout1->addWidget(equationLineEdit, 0, 0, 1, 2);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    vboxLayout->addWidget(label);

    addConstantsModelPointPushButton = new QPushButton(centralwidget);
    addConstantsModelPointPushButton->setObjectName(QString::fromUtf8("addConstantsModelPointPushButton"));

    vboxLayout->addWidget(addConstantsModelPointPushButton);

    clearConstantsModelPushButton = new QPushButton(centralwidget);
    clearConstantsModelPushButton->setObjectName(QString::fromUtf8("clearConstantsModelPushButton"));

    vboxLayout->addWidget(clearConstantsModelPushButton);


    gridLayout1->addLayout(vboxLayout, 1, 0, 1, 1);

    constantsTableView = new QTableView(centralwidget);
    constantsTableView->setObjectName(QString::fromUtf8("constantsTableView"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(constantsTableView->sizePolicy().hasHeightForWidth());
    constantsTableView->setSizePolicy(sizePolicy);
    constantsTableView->setMaximumSize(QSize(256, 100));
    constantsTableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    constantsTableView->setTabKeyNavigation(true);
    constantsTableView->setProperty("showDropIndicator", QVariant(false));
    constantsTableView->setDragDropOverwriteMode(false);
    constantsTableView->setSelectionMode(QAbstractItemView::NoSelection);

    gridLayout1->addWidget(constantsTableView, 1, 1, 1, 1);


    gridLayout->addLayout(gridLayout1, 0, 0, 1, 2);

    gridLayout2 = new QGridLayout();
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setFont(font);

    gridLayout2->addWidget(label_3, 0, 0, 1, 1);

    independentVariableLineEdit = new QLineEdit(centralwidget);
    independentVariableLineEdit->setObjectName(QString::fromUtf8("independentVariableLineEdit"));
    independentVariableLineEdit->setMaximumSize(QSize(16666215, 16777215));

    gridLayout2->addWidget(independentVariableLineEdit, 0, 1, 1, 1);

    useRangeCheckBox = new QCheckBox(centralwidget);
    useRangeCheckBox->setObjectName(QString::fromUtf8("useRangeCheckBox"));

    gridLayout2->addWidget(useRangeCheckBox, 1, 0, 1, 2);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    lowerDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    lowerDoubleSpinBox->setObjectName(QString::fromUtf8("lowerDoubleSpinBox"));
    lowerDoubleSpinBox->setMinimum(-99.99);

    hboxLayout->addWidget(lowerDoubleSpinBox);

    higherDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    higherDoubleSpinBox->setObjectName(QString::fromUtf8("higherDoubleSpinBox"));
    higherDoubleSpinBox->setMinimum(-99.99);

    hboxLayout->addWidget(higherDoubleSpinBox);


    gridLayout2->addLayout(hboxLayout, 2, 0, 1, 2);

    evaluatePushButton = new QPushButton(centralwidget);
    evaluatePushButton->setObjectName(QString::fromUtf8("evaluatePushButton"));

    gridLayout2->addWidget(evaluatePushButton, 3, 0, 1, 2);


    gridLayout->addLayout(gridLayout2, 0, 2, 1, 1);

    equationLabel = new QLabel(centralwidget);
    equationLabel->setObjectName(QString::fromUtf8("equationLabel"));
    equationLabel->setFont(font);
    equationLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(equationLabel, 1, 0, 1, 3);

    textBrowser = new QTextBrowser(centralwidget);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
    textBrowser->setSizePolicy(sizePolicy1);
    textBrowser->setMinimumSize(QSize(0, 400));
    textBrowser->setMaximumSize(QSize(250, 16777215));

    gridLayout->addWidget(textBrowser, 2, 0, 1, 1);

    graphWidget = new GraphWidget(centralwidget);
    graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
    graphWidget->setAcceptDrops(true);

    gridLayout->addWidget(graphWidget, 2, 1, 1, 2);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 26));
    menuQuit = new QMenu(menubar);
    menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuQuit->menuAction());

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Constants:", 0, QApplication::UnicodeUTF8));
    addConstantsModelPointPushButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    clearConstantsModelPushButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Independent Variable:", 0, QApplication::UnicodeUTF8));
    useRangeCheckBox->setText(QApplication::translate("MainWindow", "Use The Following Range:", 0, QApplication::UnicodeUTF8));
    evaluatePushButton->setText(QApplication::translate("MainWindow", "Evaluate", 0, QApplication::UnicodeUTF8));
    equationLabel->setText(QApplication::translate("MainWindow", "Equation", 0, QApplication::UnicodeUTF8));
    menuQuit->setTitle(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHING_H
