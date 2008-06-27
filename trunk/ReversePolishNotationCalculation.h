/* Copyright Nathan Findley
 * Using the GPLv3
 */

#ifndef REVERSEPOLISHNOTATIONCALCULATION_H_
#define REVERSEPOLISHNOTATIONCALCULATION_H_

#include <QString>
#include <QStack>
#include <QStringList>
#include <QHash>

#include "ConstantsModel.h"

/* Takes a Reverse Polish Notation Expression and calculates the resulting value. */
class ReversePolishNotationCalculation
{
public:

	static QStringList PermittedOperators;
	
	ReversePolishNotationCalculation();
	~ReversePolishNotationCalculation();
	
	double Calculate(
		QString ReversePolishNotationExpression, 
		ConstantsModelPoint IndependentVariable,
		const QList<ConstantsModelPoint> *Constants);
};

#endif /*REVERSEPOLISHNOTATIONCALCULATION_H_*/
