#include "Graphing.h"

#include "ShuntingYardAlgorithm.h"


#include <QHeaderView>
#include <QMessageBox>

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
	main.show();
}

void Graphing::EvaluateEquation() {

	ShuntingYardAlgorithm sya;
	QString equation = sya.FormatEquation(mainWindow.equationLineEdit->text());
		
	QString ErrorMessage;
	if (sya.ValidateEquation(equation, this->model, mainWindow.independentVariableLineEdit->text(), ErrorMessage)) {
		mainWindow.equationLabel->setText("Equation: " + equation);

		equation = sya.GenerateReversePolishNotation(equation);
		mainWindow.textBrowser->setText("Equation: " + equation);
	} else {
		QMessageBox::critical(
				0,
				"Invalid Equation",
				ErrorMessage);
	}
}

void Graphing::AddConstantsModelPoint() {
	model.insertRow(model.rowCount(QModelIndex()));
}

void Graphing::ClearConstantsModel() {
	model.removeRows(0, model.rowCount(), QModelIndex());
}
