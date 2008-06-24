#ifndef GRAPHING_H_
#define GRAPHING_H_

#include <QObject>
#include "ui_Graphing.h"

enum Validation //Used when validating the equation
{
	NUMERIC,
	VARIABLE,
	OPERATOR,
	UNKNOWN
};

class Graphing : public QObject
{
	Q_OBJECT
	
public:
	Graphing();
	virtual ~Graphing();
	
	void initialize(QMainWindow &main);
	QString FormatEquation(QString equation);
	bool ValidateEquation(QString formattedEquation);
	
public slots:
	void EvaluateEquation();

public:
	Ui::MainWindow mainWindow;
};

#endif /*GRAPHING_H_*/
