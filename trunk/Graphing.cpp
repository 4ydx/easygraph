#include "Graphing.h"

#include "ShuntingYardAlgorithm.h"
#include "ReversePolishNotationCalculation.h"

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
	QObject::connect(mainWindow.evaluatePushButton, SIGNAL(clicked()), this, SLOT(EvaluateEquation()));
	main.show();
}

void Graphing::EvaluateEquation() {
	QString equation = FormatEquation(mainWindow.equationLineEdit->text());
	if (ValidateEquation(equation)) {
		mainWindow.equationLabel->setText("Equation: " + equation);

		ShuntingYardAlgorithm sya;
		equation = sya.GenerateReversePolishNotation(equation);
		mainWindow.textBrowser->setText("Equation: " + equation);
	} else {
		QMessageBox::critical(
				0,
				"Invalid Equation",
				"The equation appears to be poorly formatted.  Be sure to use \"*\" between variables.");
	}
}

//Take the users input equation and insert/remove spacing until all tokens have exactly one space between them
QString Graphing::FormatEquation(QString equation) {
	
	bool PreviousValueIsNumeric = false; //If a number is encountered, the first number must be preceded by a space
	
	QString formattedEquation = "";
	for (int i = 0; i < equation.size(); i++) {
		bool ok = false;
		QString c = QString(equation[i]);
		int temp = c.toInt(&ok);

		if (ok) {
			if (PreviousValueIsNumeric)
				formattedEquation += c;
			else
				formattedEquation += " " + c;

			PreviousValueIsNumeric = true;
		} else {
			if (c != ",") {
				PreviousValueIsNumeric = false;
				if (c == ".") //This might be a constant with a decimal
				{
					if (i + 1 == equation.size())//If this is a constant w/ decimal, needs to have numeric value beyond
						throw "Poorly formatted equation.";

					ok = false;
					QString c2 = QString(equation[i + 1]);
					temp = c2.toInt(&ok);

					if (!ok) //If ok, simply let this proceed
					{
						throw "Poorly formatted equation.";
					} else {
						formattedEquation += c;
					}
				} else {
					if (c != " ") {
						formattedEquation += " " + c;
					}
				}
			}
		}
	}
	return formattedEquation.trimmed();
}

//Pass in a formatted equation (single spaces between each token)
//Return Value: If valid, true.  
bool Graphing::ValidateEquation(QString formattedEquation) {
	bool IsValid = true; //Innocent until proven guilty

	Validation PreviousValue = UNKNOWN;
	bool IndependentVariableFound = false; //Check that the user's entered independent variable exists
	bool AllConstantsHaveValues = mainWindow.constantsTableView->model()->rowCount(QModelIndex()) == 0; //Look through constants model for presence of key/value pair
	int ParenthesisMatching = 0; //If non-zero by the end, a parenthesis is missing
	
	QStringList Tokens = formattedEquation.split(' ');
	foreach(QString Token, Tokens)
	{
		bool ok = false;
		Token.toInt(&ok);

		if(ok) //Current value is numeric
		{
			if(PreviousValue == VARIABLE)//"a 4" doesn't make sense in the context of an equation
				if(IsValid) IsValid = false;

			if(PreviousValue == NUMERIC) // "5 34" doesn't make sense
				if(IsValid) IsValid = false;

			PreviousValue = NUMERIC;
		}
		else //An operator or a variable
		{
			if(ReversePolishNotationCalculation::PermittedOperators.contains(Token))//operator
			{
				if(PreviousValue == OPERATOR) // "+ -" doesn't make sense
					if(IsValid) IsValid = false;

				PreviousValue = OPERATOR;
			}
			else//variable
			{
				if(Token != ")" && Token != "(")
				{
					if(PreviousValue == NUMERIC) // "5 d" does make sense if "*" is implied.  i don't bother w/ that though.
						if(IsValid) IsValid = false;

					if(PreviousValue == VARIABLE) // "c g" (as variables/constants) doesn't make sense
						if(IsValid) IsValid = false;

					if(Token == mainWindow.independentVariableLineEdit->text().trimmed())
						IndependentVariableFound = true;
					
					

					PreviousValue = VARIABLE;
				}
				else //This is a parenthesis
				{
					ParenthesisMatching += Token == "(" ? 1 : -1;
				}
			}
		}
	}
	
	//TODO: add some error message that indicates what exactly failed
	return IsValid && ParenthesisMatching == 0 && IndependentVariableFound && AllConstantsHaveValues;
}

void Graphing::AddConstantsModelPoint() {
	model.insertRow(model.rowCount(QModelIndex()));
}
