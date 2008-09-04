/* Copyright Nathan Findley
 * Using the GPLv3
 */

#include "Graphing.h"

#include "ShuntingYardAlgorithm.h"
#include "ReversePolishNotationCalculation.h"

#include <QGLWidget>
#include <QHeaderView>
#include <QMessageBox>

#include <iostream>

Graphing::Graphing() {
}

Graphing::~Graphing() {
}

void Graphing::initialize(QMainWindow &main) {

  mainWindow.setupUi(&main);

  mainWindow.constantsTableView->setModel(&model);
  mainWindow.constantsTableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

  QObject::connect(mainWindow.addConstantsModelPointPushButton, SIGNAL(clicked()), this, SLOT(AddConstantsModelPoint()));
  QObject::connect(mainWindow.clearConstantsModelPushButton, SIGNAL(clicked()), this, SLOT(ClearConstantsModel()));
  QObject::connect(mainWindow.evaluatePushButton, SIGNAL(clicked()), this, SLOT(EvaluateEquation()));

  QObject::connect(mainWindow.useRangeCheckBox, SIGNAL(clicked(bool)), mainWindow.lowerDoubleSpinBox, SLOT(setEnabled(bool)));
  QObject::connect(mainWindow.useRangeCheckBox, SIGNAL(clicked(bool)), mainWindow.higherDoubleSpinBox, SLOT(setEnabled(bool)));

  QObject::connect(mainWindow.graphWidget, SIGNAL(gridMoved()), this, SLOT(ReevaluateEquation()));

  main.show();
}

void Graphing::EvaluateEquation() {

  ShuntingYardAlgorithm sya;
  QString equation = sya.FormatEquation(mainWindow.equationLineEdit->text());

  QString ErrorMessage;
  if (sya.ValidateEquation(equation, this->model, mainWindow.independentVariableLineEdit->text(), ErrorMessage)) {

    ConstantsModelPoint p;
    p.VariableName = mainWindow.independentVariableLineEdit->text();

    mainWindow.equationLabel->setText("Equation: " + equation);
    equation =  sya.GenerateReversePolishNotation(equation,
						  p,
						  model.getConstantValues());

    mainWindow.textBrowser->setText(" ==> " + equation + "\n");

    double low, high, step = 0.0;

    if(mainWindow.useRangeCheckBox->isChecked()) {

      low = mainWindow.lowerDoubleSpinBox->text().toDouble();
      high = mainWindow.higherDoubleSpinBox->text().toDouble();

    } else {

      low = mainWindow.graphWidget->GetDomainMinimum(); 
      high = mainWindow.graphWidget->GetDomainMaximum();

      //Generate a tail on each end so that dragging still reveals a line
      float width = high - low;
      low = low < 0 ? low - width : - 1 * width;
      high = high < 0 ? width : high + width;
    }
    step = (high - low) / 1000;

    ReversePolishNotationCalculation rpn;
    graphPoints.clear();

    while(low < high)
      {
	p.Value = low;
	double answer = rpn.Calculate(equation, p, model.getConstantValues());
	mainWindow.textBrowser->append("X: " + QString::number(low) + " Y: " + QString::number(answer) + "\n");

	Point graphPoint(D2);
	graphPoint.X = low;
	graphPoint.Y = answer;
	graphPoints.append(graphPoint);
	low += step;
      }

    //Now draw the points to the QGLWidget
    mainWindow.graphWidget->drawGraph(graphPoints);

  } else {

    QMessageBox::critical(0,
			  "Invalid Equation",
			  ErrorMessage);
  }
}

void Graphing::ReevaluateEquation() {

  EvaluateEquation();
}

void Graphing::AddConstantsModelPoint() {
  
  model.insertRow(model.rowCount(QModelIndex()));
}

void Graphing::ClearConstantsModel() {
	
  model.removeRows(0, model.rowCount(), QModelIndex());
}
