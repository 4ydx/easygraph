/* Copyright Nathan Findley
 * Using the GPLv3
 */

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

/* Generates a reverse polish notation expression. */  
class ShuntingYardAlgorithm
{
 public:
  ShuntingYardAlgorithm();
  ~ShuntingYardAlgorithm();

  QList<QStringList> OrderOfOperations;
  QStringList RightToLeftOperations;

  QStack<QString> Output;
  QStack<QString> MathOperators;

  /* Ensures that all constants have values and that the independent variable has been specified. */
  bool ValidateEquation(
		  QString formattedEquation, 
		  const ConstantsModel &ConstantValues, 
		  const QString &IndependentVariable,
		  QString &ErrorMessage);
  
  /* - Returns tolkenized equation (one space between each element)
   * - Throws an error if the equation isn't properly formatted. */
  QString FormatEquation(QString equation);
		  
  
  QString GenerateReversePolishNotation(QString equation,
		  ConstantsModelPoint IndependentVariable,
		  const QList<ConstantsModelPoint> *Constants);

  void Clear();
  void PrintStack(const QStack<QString> &stack, const QString &stackName);
};

#endif // SHUNTINGYARDALGORITHM_H
