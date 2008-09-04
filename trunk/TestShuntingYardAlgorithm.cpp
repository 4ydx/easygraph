#include <QtTest/QtTest>

#include "ShuntingYardAlgorithm.h"

class TestShuntingYardAlgorithm : public QObject
{
  Q_OBJECT

 private slots:

  void FormatEquation();
  void GenerateReversePolishNotation();

};

void TestShuntingYardAlgorithm::FormatEquation() {

  QString error = "";
  QString eq = "x  +5/4 * 12.0";
  ShuntingYardAlgorithm sya;

  QCOMPARE(sya.FormatEquation(eq, error), QString("x + 5 / 4 * 12.0"));
  QCOMPARE(error, QString(""));

  eq = "1x.3 + 4";
  sya.FormatEquation(eq, error);
  QCOMPARE(error, QString("Poorly formatted equation."));
}

void TestShuntingYardAlgorithm::GenerateReversePolishNotation() {

  ShuntingYardAlgorithm sya;  

  ConstantsModelPoint independentVariable;
  independentVariable.VariableName = "x";
  
  ConstantsModelPoint c;
  c.VariableName = "c";

  QList<ConstantsModelPoint> constants;
  constants.insert(0, c);

  QString eq = "x + 5 / 4 * 12.0 + c";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 4 / 12.0 * c + +"));

  eq = "x - 5";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 -"));

  eq = "x - ( 5 / 4 )";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 4 / -"));

  eq = "x - ( 5 / 4 ) ^ 2";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 4 / 2 ^ -"));

  eq = "x - 5 / 4 ^ 2";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 4 2 ^ / -"));

  eq = "x - 5 / ( 4 ^ 2 )";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("x 5 4 2 ^ / -"));

  eq = "- x + 5";
  QCOMPARE(sya.GenerateReversePolishNotation(eq, independentVariable, &constants), QString("-x 5 +"));
}

QTEST_MAIN(TestShuntingYardAlgorithm)
#include "TestShuntingYardAlgorithm.moc"
