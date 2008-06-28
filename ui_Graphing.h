/********************************************************************************
** Form generated from reading ui file 'Graphing.ui'
**
** Created: Sat Jun 28 16:50:42 2008
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
#include "GraphWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *equationLineEdit;
    QLabel *label_3;
    QLineEdit *independentVariableLineEdit;
    QLabel *label_2;
    QDoubleSpinBox *lowerDoubleSpinBox;
    QDoubleSpinBox *higherDoubleSpinBox;
    QLabel *label;
    QTableView *constantsTableView;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *addConstantsModelPointPushButton;
    QPushButton *clearConstantsModelPushButton;
    QPushButton *evaluatePushButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *equationLabel;
    QTextBrowser *textBrowser;
    GraphWidget *graphWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 631);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 26, 800, 582));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    equationLineEdit = new QLineEdit(centralwidget);
    equationLineEdit->setObjectName(QString::fromUtf8("equationLineEdit"));

    gridLayout->addWidget(equationLineEdit, 0, 0, 1, 3);

    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    label_3->setFont(font);

    gridLayout->addWidget(label_3, 0, 3, 1, 1);

    independentVariableLineEdit = new QLineEdit(centralwidget);
    independentVariableLineEdit->setObjectName(QString::fromUtf8("independentVariableLineEdit"));
    independentVariableLineEdit->setMaximumSize(QSize(50, 16777215));

    gridLayout->addWidget(independentVariableLineEdit, 0, 4, 1, 1);

    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFont(font);
    label_2->setTextFormat(Qt::PlainText);

    gridLayout->addWidget(label_2, 0, 5, 1, 1);

    lowerDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    lowerDoubleSpinBox->setObjectName(QString::fromUtf8("lowerDoubleSpinBox"));

    gridLayout->addWidget(lowerDoubleSpinBox, 0, 6, 1, 1);

    higherDoubleSpinBox = new QDoubleSpinBox(centralwidget);
    higherDoubleSpinBox->setObjectName(QString::fromUtf8("higherDoubleSpinBox"));

    gridLayout->addWidget(higherDoubleSpinBox, 0, 7, 1, 1);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label, 1, 0, 1, 1);

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

    gridLayout->addWidget(constantsTableView, 1, 1, 4, 2);

    verticalSpacer = new QSpacerItem(20, 97, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer, 1, 3, 4, 1);

    verticalSpacer_3 = new QSpacerItem(72, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_3, 1, 5, 2, 1);

    addConstantsModelPointPushButton = new QPushButton(centralwidget);
    addConstantsModelPointPushButton->setObjectName(QString::fromUtf8("addConstantsModelPointPushButton"));

    gridLayout->addWidget(addConstantsModelPointPushButton, 2, 0, 1, 1);

    clearConstantsModelPushButton = new QPushButton(centralwidget);
    clearConstantsModelPushButton->setObjectName(QString::fromUtf8("clearConstantsModelPushButton"));

    gridLayout->addWidget(clearConstantsModelPushButton, 3, 0, 1, 1);

    evaluatePushButton = new QPushButton(centralwidget);
    evaluatePushButton->setObjectName(QString::fromUtf8("evaluatePushButton"));

    gridLayout->addWidget(evaluatePushButton, 3, 4, 1, 3);

    verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

    verticalSpacer_4 = new QSpacerItem(72, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 4, 5, 1, 1);

    equationLabel = new QLabel(centralwidget);
    equationLabel->setObjectName(QString::fromUtf8("equationLabel"));
    equationLabel->setFont(font);
    equationLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(equationLabel, 5, 0, 1, 8);

    textBrowser = new QTextBrowser(centralwidget);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
    textBrowser->setSizePolicy(sizePolicy1);
    textBrowser->setMinimumSize(QSize(0, 400));

    gridLayout->addWidget(textBrowser, 6, 0, 1, 2);

    graphWidget = new GraphWidget(centralwidget);
    graphWidget->setObjectName(QString::fromUtf8("graphWidget"));

    gridLayout->addWidget(graphWidget, 6, 2, 1, 6);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 26));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 608, 800, 23));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Independent Variable:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Range:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Constants:", 0, QApplication::UnicodeUTF8));
    addConstantsModelPointPushButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    clearConstantsModelPushButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
    evaluatePushButton->setText(QApplication::translate("MainWindow", "Evaluate", 0, QApplication::UnicodeUTF8));
    equationLabel->setText(QApplication::translate("MainWindow", "Equation", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHING_H
