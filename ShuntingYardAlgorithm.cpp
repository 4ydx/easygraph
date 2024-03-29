/* Copyright Nathan Findley
 * Using the GPLv3
 */

#include "ShuntingYardAlgorithm.h"

#include "ReversePolishNotationCalculation.h"
#include "ConstantsModel.h"
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

QString ShuntingYardAlgorithm::GenerateReversePolishNotation(QString equation,
							     ConstantsModelPoint IndependentVariable,
							     const QList<ConstantsModelPoint> *Constants) {
  
  QStringList expressionList = equation.split(" ");

  for (int i = 0; i < expressionList.count(); i++) {

    bool ok = false;
    expressionList[i].toDouble(&ok);

    if (ok) { //This is numeric

      Output.push(expressionList[i]);

    } else if (expressionList[i] == "(") {

      MathOperators.push(expressionList[i]);

    } else if (expressionList[i] == ")") {

      QString op = "";
      while (op != "(") {

	op = MathOperators.pop();

	Output.push(op);
      }
      Output.pop();

    } else { //Operator or constant/independent variable

      bool VariableFound = false;
      if (expressionList[i] == IndependentVariable.VariableName) { //Independent variable

	Output.push(expressionList[i]);
	VariableFound = true;

      } else {

	foreach(ConstantsModelPoint point, *Constants) { //Constant

	  if(point.VariableName == expressionList[i]) {

	    Output.push(expressionList[i]);
	    VariableFound = true;
	  }
	}
      }

      if (!VariableFound) { //Must be a mathematical operator

	if(expressionList[i] == "-") { //Testing for subtraction or a negative sign

	  if(i > 0) {

	    bool previousIsOperator = false;

	    foreach(QStringList t, OrderOfOperations) {

	      if(t.contains(expressionList[i - 1]) && expressionList[i - 1] != ")" ) {

		if(!previousIsOperator) expressionList[i + 1] = "-" + expressionList[i + 1];
		previousIsOperator = true;
	      }
	    }

	    if(!previousIsOperator) {

	      GenerateReversePolishNotationHelper(expressionList[i]);
	    }

	  } else { // this is the first value in the expression e.g. - 5 + x; must be negative sign

	    expressionList[i + 1] = "-" + expressionList[i + 1];	    

	  }

	} else if (MathOperators.count() == 0) {

	  MathOperators.push(expressionList[i]);

	} else if (MathOperators.top() == "(") {

	  MathOperators.push(expressionList[i]);

	} else {

	  GenerateReversePolishNotationHelper(expressionList[i]);
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

void ShuntingYardAlgorithm::GenerateReversePolishNotationHelper(QString item) {

  if(MathOperators.count() == 0) {

    MathOperators.push(item);
    return;
  }

  //Determine if the operator in the equation or the operator in the stack
  //has a higher order of operation
  int EquationLevel = 0;
  for (int j = 0; j < OrderOfOperations.count(); j++) {

    EquationLevel++;
    if (OrderOfOperations[j].contains(item)) {

      j = OrderOfOperations.count(); //end the loop
    }
  }

  int StackLevel = 0;
  QString topOperator = MathOperators.top();
  for (int j = 0; j < OrderOfOperations.count(); j++) {

    StackLevel++;
    if (OrderOfOperations[j].contains(topOperator)) {

      j = OrderOfOperations.count(); //end the loop
    }
  }

  if (EquationLevel > StackLevel) {

    MathOperators.push(item);

  } else {

    //If the Top Operator in the list and in the stack are right to left then leave alone.
    bool IsRightToLeft = RightToLeftOperations.contains(topOperator) && RightToLeftOperations.contains(item);

    if (IsRightToLeft || MathOperators.top() == "(") {

      MathOperators.push(item);

    } else {

      topOperator = MathOperators.pop();
      Output.push(topOperator);
      MathOperators.push(item);
    }
  }
}

QString ShuntingYardAlgorithm::FormatEquation(QString equation, QString &ErrorMessage) {

  bool PreviousValueIsNumeric = false; //If a number is encountered, the first number must be preceded by a space

  QString formattedEquation = "";
  for (int i = 0; i < equation.size(); i++) {

    bool ok = false;
    QString c = QString(equation[i]);
    c.toInt(&ok);

    if (ok) {

      if (PreviousValueIsNumeric) {

	formattedEquation += c;

      } else {

	formattedEquation += " " + c;
      }

      PreviousValueIsNumeric = true;

    } else {

      if (c != ",") { //Ignore commas

	if (c == ".") { //This might be a constant with a decimal

	  if(PreviousValueIsNumeric == false) {

	    ErrorMessage = "Poorly formatted equation.";
	  }

	  if (i + 1 == equation.size()) {//If this is a constant w/ decimal, needs to have numeric value beyond

	    ErrorMessage = "Poorly formatted equation.";
	  }

	  ok = false;


	  QString c2 = QString(equation[i + 1]);
	  c2.toInt(&ok);

	  if (!ok) { //If ok, simply let this proceed

	    ErrorMessage = "Poorly formatted equation.";

	  } else {

	    PreviousValueIsNumeric = true; //Ensures no gap
	    formattedEquation += c;
	  }

	} else {

	  PreviousValueIsNumeric = false;
	  if (c != " ") {

	    formattedEquation += " " + c;

	  }
	}
      }
    }
  }
  return formattedEquation.trimmed();
}

bool ShuntingYardAlgorithm::ValidateEquation(QString formattedEquation,
					     const ConstantsModel &model, const QString &IndependentVariable,
					     QString &ErrorMessage) {

  bool IsValid = true;
  Validation PreviousValue = UNKNOWN;

  bool IndependentVariableFound = false; // Check that the user's entered independent variable exists

  bool AllConstantsHaveValues = true;    // Look through constants model for presence of key/value pair

  int ParenthesisMatching = 0;           // If non-zero by the end, a parenthesis is missing

  QStringList Tokens = formattedEquation.split(' ');
  foreach(QString Token, Tokens) {

    bool ok = false;
    Token.toDouble(&ok);

    if(ok) { //Current value is numeric

      if(PreviousValue == VARIABLE) { //"a 4" doesn't make sense in the context of an equation

	if(IsValid) IsValid = false;
      }

      if(PreviousValue == NUMERIC) { // "5 34" doesn't make sense

	if(IsValid) IsValid = false;
      }

      PreviousValue = NUMERIC;

    } else { //An operator or a variable

      if(ReversePolishNotationCalculation::PermittedOperators.contains(Token)) { //operator

	if(PreviousValue == OPERATOR && Token != "-") { // "5 + * 4" doesn't make sense but "5 + - 4" does => 5 + (-4)

	  if(IsValid) IsValid = false;
	}

	PreviousValue = OPERATOR;

      } else { //variable

	if(Token != ")" && Token != "(") {

	  if(PreviousValue == NUMERIC) { // "5 d" does make sense if "*" is implied.  i don't bother w/ that though.

	    if(IsValid) IsValid = false;
	  }

	  if(PreviousValue == VARIABLE) { // "c g" (as variables/constants) doesn't make sense

	    if(IsValid) IsValid = false;
	  }

	  if(Token == IndependentVariable) {

	    IndependentVariableFound = true;

	  } else { //Either independent or a constant

	    bool ConstantFound = false;
	    QList<ConstantsModelPoint>::const_iterator i;

	    for(i = model.getConstantValues()->begin(); i < model.getConstantValues()->end(); i++) {

	      if(!ConstantFound) {

		ConstantFound = Token == (*i).VariableName;
	      }
	    }

	    if(AllConstantsHaveValues) {//The instant this goes "bad" they are all bad.

	      AllConstantsHaveValues = ConstantFound;
	    }
	  }
	  PreviousValue = VARIABLE;

	} else { //This is a parenthesis

	  ParenthesisMatching += Token == "(" ? 1 : -1;
	}
      }
    }
  }


  if (ParenthesisMatching != 0) {

    ErrorMessage = "Parenthesis mismatch.";
  }

  if (!AllConstantsHaveValues) {

    ErrorMessage = "Some of the constants in your equation don't have values.";
  }

  if (!IndependentVariableFound) {

    ErrorMessage = "Please make sure that the independent variable is present in the equation.";
  }

  return IsValid && ParenthesisMatching == 0 && IndependentVariableFound && AllConstantsHaveValues;
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
