#ifndef SHUNTINGYARDALGORITHM_H
#define SHUNTINGYARDALGORITHM_H

#include "ConstantsModel.h"

#include <QtGui/QWidget>
#include <QList>
#include <QStack>
#include <QStringList>

enum Validation //Used when validating the equation
{
	NUMERIC,
	VARIABLE,
	OPERATOR,
	UNKNOWN
};

class ShuntingYardAlgorithm
{
 public:
  ShuntingYardAlgorithm();
  ~ShuntingYardAlgorithm();

  QList<QStringList> OrderOfOperations;
  QStringList RightToLeftOperations;

  QStack<QString> Output;
  QStack<QString> MathOperators;

  bool ValidateEquation(
		  QString formattedEquation, 
		  const ConstantsModel &ConstantValues, 
		  const QString &IndependentVariable,
		  QString &ErrorMessage);
  
  QString FormatEquation(QString equation);
  QString GenerateReversePolishNotation(QString equation);

  void Clear();
  void PrintStack(const QStack<QString> &stack, const QString &stackName);
};

#endif // SHUNTINGYARDALGORITHM_H
