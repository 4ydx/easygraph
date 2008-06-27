/* Copyright Nathan Findley
 * Using the GPLv3
 */

#ifndef GRAPHING_H_
#define GRAPHING_H_

#include "ui_Graphing.h"
#include "ConstantsModel.h"

#include <QObject>

class Graphing : public QObject
{
	Q_OBJECT
	
public:
	Graphing();
	virtual ~Graphing();
	
	void initialize(QMainWindow &main);
	
public slots:
	void EvaluateEquation();
	void AddConstantsModelPoint();
	void ClearConstantsModel();
	
public:
	Ui::MainWindow mainWindow;
	ConstantsModel model;
};

#endif /*GRAPHING_H_*/
