#include "ReversePolishNotationCalculation.h"

#include <iostream>
#include <math.h>

QStringList ReversePolishNotationCalculation::PermittedOperators = QStringList() << "+" << "-" << "*" << "/" << "^" << "!";

ReversePolishNotationCalculation::ReversePolishNotationCalculation() {
	//Wow...don't ever do something like this again!!!  
	//ReversePolishNotationCalculation::PermittedOperators << "+" << "-" << "*" << "/" << "^" << "!";
}

ReversePolishNotationCalculation::~ReversePolishNotationCalculation() {
}

double ReversePolishNotationCalculation::Calculate(
		QString ReversePolishNotationExpression,
		ConstantsModelPoint IndependentVariable,
		const QList<ConstantsModelPoint> *Constants) 
{
	QStringList Tokens = ReversePolishNotationExpression.split(' ');
	QStack<double> Stack;

	foreach(QString Token, Tokens)
	{
		if(ReversePolishNotationCalculation::PermittedOperators.contains(Token))
		{
			if(Token == "!") //This is currently the only unary operator.
			{
				int x = (int)Stack.pop();
				for(int i = x - 1; i > 0; i--) {
					x = x * i;
				}				
				Stack.push(x);
			}
			else
			{
				double y = Stack.pop();
				double x = Stack.pop();
				
				if(Token == "+") {
					x = x + y;
				}
				else if (Token == "-") {
					x = x - y;
				}
				else if (Token == "*") {
					x = x * y;
				}
				else if (Token == "/") {
					x = x / y;
				}
				else if (Token == "^") {
					x = pow(x, y); 
				}				
				Stack.push(x);				
			}
		}
		else
		{
			bool IndependentVariableFound = false;
			
			if(Token == IndependentVariable.VariableName)
			{
				IndependentVariableFound = true;				
				Stack.push(IndependentVariable.Value);	
			}
			
			foreach(ConstantsModelPoint point, *Constants)
			{
				if(!IndependentVariableFound)
				{
					if(point.VariableName == Token)
					{
						IndependentVariableFound = true;
						Stack.push(point.Value);	
					}						
				}
			}
			
			if(!IndependentVariableFound)
			{
				bool ok = false;
				double Constant = Token.toDouble(&ok);
				
				if(ok)
				{
					Stack.push(Constant);
				}
				else
					throw "ReversePolishNotationCalculation::Calculate: An independent variable in the expression doesn't have a value in the hash.";
			}
		}
	}
	
	//Now the stack should contain the answer
	if(Stack.size() != 1)
		throw "ReversePolishNotationCalculation::Calculate: The stack doesn't contain one value, which is expected.";
	
	return Stack.pop();
}
