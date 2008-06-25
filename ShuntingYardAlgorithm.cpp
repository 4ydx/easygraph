/****************************************************************************
 **
 ** Trolltech hereby grants a license to use the Qt/Eclipse Integration
 ** plug-in (the software contained herein), in binary form, solely for the
 ** purpose of creating code to be used with Trolltech's Qt software.
 **
 ** Qt Designer is licensed under the terms of the GNU General Public
 ** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
 ** right to use certain no GPL licensed software under the terms of its GPL
 ** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
 **
 ** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
 ** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 ** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 ** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 ** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 ** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 ** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 ** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 ** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 ** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 ** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** Since we now have the GPL exception I think that the "special exception
 ** is no longer needed. The license text proposed above (other than the
 ** special exception portion of it) is the BSD license and we have added
 ** the BSD license as a permissible license under the exception.
 **
 ****************************************************************************/

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

QString ShuntingYardAlgorithm::GenerateReversePolishNotation(QString equation) {
	QStringList list = equation.split(" ");
	for (int i = 0; i < list.count(); i++) {
		//std::cout << list[i].toStdString() << std::endl;

		bool ok = false;
		list[i].toDouble(&ok);

		if (ok) {
			Output.push(list[i]);
			//PrintStack(Output, "Output");
		} else if (list[i] == "(") {
			MathOperators.push(list[i]);
			//PrintStack(MathOperators, "MathOperators");
		} else if (list[i] == ")") {
			QString op = "";
			while (op != "(") {
				op = MathOperators.pop();
				//PrintStack(MathOperators, "MathOperators");
				Output.push(op);
				//PrintStack(Output, "Output");
			}
			Output.pop();
			//PrintStack(Output, "Output");
		} else { //Finally we must be dealing with the remaining math operators 
			if (MathOperators.count() == 0) {
				MathOperators.push(list[i]);
				//PrintStack(MathOperators, "MathOperators");
			} else if (MathOperators.top() == "(") {
				MathOperators.push(list[i]);
				//PrintStack(MathOperators, "MathOperators");
			} else {

				//Determine if the operator in the equation or the operator in the stack
				//has a higher order of operation
				int EquationLevel = 0;
				for (int j = 0; j < OrderOfOperations.count(); j++) {
					EquationLevel++;
					if (OrderOfOperations[j].contains(list[i])) {
						j = OrderOfOperations.count();
					}
				}

				QString topOperator = MathOperators.top();
				int StackLevel = 0;
				for (int j = 0; j < OrderOfOperations.count(); j++) {
					StackLevel++;
					if (OrderOfOperations[j].contains(topOperator)) {
						j = OrderOfOperations.count();
					}
				}

				if (EquationLevel > StackLevel) {
					MathOperators.push(list[i]);
					//PrintStack(MathOperators, "MathOperators");
				}

				if (EquationLevel < StackLevel || EquationLevel == StackLevel) {
					//Right to left are left alone:
					bool IsRightToLeft =
							RightToLeftOperations.contains(topOperator)
									&& RightToLeftOperations.contains(list[i]);

					if (IsRightToLeft) {
						MathOperators.push(list[i]);
						//PrintStack(MathOperators, "MathOperators");
					} else {
						topOperator = MathOperators.pop();
						//PrintStack(MathOperators, "MathOperators");

						Output.push(topOperator);
						//PrintStack(Output, "Output");

						MathOperators.push(list[i]);
						//PrintStack(MathOperators, "MathOperators");
					}
				}
			}
		}
	}

	while (MathOperators.count() > 0) {
		//PrintStack(MathOperators, "MathOperators");
		Output.push(MathOperators.pop());
		//PrintStack(Output, "Output");
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
								ConstantFound = Token == (*i).X;
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
