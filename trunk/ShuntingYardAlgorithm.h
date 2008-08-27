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

/*

Author: Nate Findley

Description: Formats equations in preparation for generating a reverse polish notation 
             expression and also generates an rpn expression.

08/27/08 -- Updated comment

*/

class ShuntingYardAlgorithm
{
 public:
  ShuntingYardAlgorithm();
  ~ShuntingYardAlgorithm();

  QList<QStringList> OrderOfOperations;
  QStringList RightToLeftOperations;

  QStack<QString> Output;
  QStack<QString> MathOperators;

  /*
   * Summary:    Ensures that all constants have values and that the independent variable has been specified. 
   *
   * Parameters: A formatted equation, the expected constants in the equation, the independent variable, potential error message.
   * Return:     True if a valid equation
   */
  bool ValidateEquation(
		  QString formattedEquation, 
		  const ConstantsModel &ConstantValues, 
		  const QString &IndependentVariable,
		  QString &ErrorMessage);
  

  /*
   * Summary:    Reformats the equation so that there are single spaces between elements.
   *
   * Parameters: The equation to be formatted.
   * Return:     A tolkenized equation (one space between each element). Throws an error if the equation isn't properly formatted.
   */
  QString FormatEquation(QString equation);
		  
  
  QString GenerateReversePolishNotation(QString equation,
		  ConstantsModelPoint IndependentVariable,
		  const QList<ConstantsModelPoint> *Constants);

  
  void GenerateReversePolishNotationHelper(QString item);

  /*
   * Summary:    Aids in debugging the state of a stack.
   *
   * Parameters: The stack and it's name.
   */
  void PrintStack(const QStack<QString> &stack, const QString &stackName);

  void Clear();
};

#endif // SHUNTINGYARDALGORITHM_H
