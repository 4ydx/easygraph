#include "ShuntingYardAlgorithm.h"

#include "ReversePolishNotationCalculation.h"
#include <iostream>

ShuntingYardAlgorithm::ShuntingYardAlgorithm() {
	OrderOfOperations.append(QStringList() << "+" << "-");
	OrderOfOperations.append(QStringList() << "*" << "/");
	OrderOfOperations.append(QStringList() << "^");
	OrderOfOperations.append(QStringList() << "!");

	RightToLeftOperations << "^";
}

ShuntingYardAlgorithm::~ShuntingYardAlgorithm() {
}

void ShuntingYardAlgorithm::Clear() {
	Output.clear();
	MathOperators.clear();
}

//TODO: This needs to receive all of the variable names as strings in order
//		to determine what values are non-operators.  otherwise an "x" variable
//		will end up being compared to integer values...
QString ShuntingYardAlgorithm::GenerateReversePolishNotation(QString equation) {
	QStringList list = equation.split(" ");
	for (int i = 0; i < list.count(); i++) {

		bool ok = false;
		list[i].toDouble(&ok);

		if (ok) {
			Output.push(list[i]);
		} else if (list[i] == "(") {
			MathOperators.push(list[i]);
		} else if (list[i] == ")") {
			QString op = "";
			while (op != "(") {
				op = MathOperators.pop();
				Output.push(op);
			}
			Output.pop();
		} else { //Finally we must be dealing with the remaining math operators 
			if (MathOperators.count() == 0) {
				MathOperators.push(list[i]);
			} else if (MathOperators.top() == "(") {
				MathOperators.push(list[i]);
			} else {

				//Determine if the operator in the equation or the operator in the stack
				//has a higher order of operation
				int EquationLevel = 0;
				for (int j = 0; j < OrderOfOperations.count(); j++) {
					EquationLevel++;
					if (OrderOfOperations[j].contains(list[i])) {
						j = OrderOfOperations.count(); //end the loop
					}
				}

				QString topOperator = MathOperators.top();
				int StackLevel = 0;
				for (int j = 0; j < OrderOfOperations.count(); j++) {
					StackLevel++;
					if (OrderOfOperations[j].contains(topOperator)) {
						j = OrderOfOperations.count(); //end the loop
					}
				}

				if (EquationLevel > StackLevel) {
					MathOperators.push(list[i]);
				}
				
				if(list[i] == "+")
					std::cout << "WTF: " << list[i].toStdString() 
						<< " " + QString::number(EquationLevel).toStdString()
						<< " " + topOperator.toStdString() 
						<< " " + QString::number(StackLevel).toStdString()
						<< std::endl;

				if (EquationLevel < StackLevel || EquationLevel == StackLevel) {
					//Right to left are left alone:
					bool IsRightToLeft = RightToLeftOperations.contains(topOperator);
									//&& RightToLeftOperations.contains(list[i]);

					if (IsRightToLeft) {
						MathOperators.push(list[i]);
					} else {
						topOperator = MathOperators.pop();
						Output.push(topOperator);
						MathOperators.push(list[i]);
					}
				}
			}
		}
	}

	while (MathOperators.count() > 0) {
		Output.push(MathOperators.pop());
	}

	QString ReversePolishNotation = "";
	for (int k = 0; k < Output.count(); k++) {
		ReversePolishNotation = ReversePolishNotation + " " + Output.at(k);
	}

	this->Clear();
	return ReversePolishNotation.trimmed();
}

//Take the users input equation and insert/remove spacing until all tokens have exactly one space between them
QString ShuntingYardAlgorithm::FormatEquation(QString equation) {

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
bool ShuntingYardAlgorithm::ValidateEquation(QString formattedEquation,
		const ConstantsModel &model, const QString &IndependentVariable,
		QString &ErrorMessage) 
{
	bool IsValid = true; //Innocent until proven guilty

	Validation PreviousValue = UNKNOWN;
	bool IndependentVariableFound = false; //Check that the user's entered independent variable exists
	bool AllConstantsHaveValues = true; //Look through constants model for presence of key/value pair
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

					if(Token == IndependentVariable)
					{
						IndependentVariableFound = true;
					}
					else //Either independent or a constant
					{
						bool ConstantFound = false;
						QList<ConstantsModelPoint>::const_iterator i;
						for(i = model.getConstantValues()->begin(); i < model.getConstantValues()->end(); i++)
						{
							if(!ConstantFound)
							{
								ConstantFound = Token == (*i).VariableName;
							}
						}

						if(AllConstantsHaveValues) //The instant this goes "bad" they are all bad.
						{
							AllConstantsHaveValues = ConstantFound;
						}
					}
					PreviousValue = VARIABLE;
				}
				else //This is a parenthesis
				{
					ParenthesisMatching += Token == "(" ? 1 : -1;
				}
			}
		}
	}

	if (ParenthesisMatching != 0)
		ErrorMessage = "Parenthesis mismatch.";
	if (!AllConstantsHaveValues)
		ErrorMessage
				= "Some of the constants in your equation don't have values.";
	if (!IndependentVariableFound)
		ErrorMessage
				= "Please make sure that the independent variable is present in the equation.";

	return IsValid && ParenthesisMatching == 0 && IndependentVariableFound
			&& AllConstantsHaveValues;
}

void ShuntingYardAlgorithm::PrintStack(const QStack<QString> &stack,
		const QString &stackName) {
	QString currentStack;

	for (int i = 0; i < stack.count(); i++) {
		currentStack = currentStack + " " + stack[i];
	}

	std::cout << "Current Stack " << stackName.toStdString() << ": "
			<< currentStack.toStdString() << std::endl;
}
