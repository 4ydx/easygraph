#ifndef REVERSEPOLISHNOTATIONCALCULATION_H_
#define REVERSEPOLISHNOTATIONCALCULATION_H_

#include <QString>
#include <QStack>
#include <QStringList>
#include <QHash>



class ReversePolishNotationCalculation
{
public:

	static QStringList PermittedOperators;
	
	ReversePolishNotationCalculation();
	~ReversePolishNotationCalculation();
	
	double Calculate(QString ReversePolishNotationExpression, QHash<QString, double> IndependentVariables);
};

#endif /*REVERSEPOLISHNOTATIONCALCULATION_H_*/
