/* Copyright Nathan Findley
 * Using the GPLv3
 */

#ifndef GRAPHING_H_
#define GRAPHING_H_

#include "ui_Graphing.h"
#include "ConstantsModel.h"
#include "Point.h"

#include <QObject>

/*

Author: Nate Findley

Description: The main window for the gui.

08/27/08 -- Added comment

*/

class Graphing : public QObject
{
  Q_OBJECT

 public:

  Graphing();
  virtual ~Graphing();

  /*
   * Summary:    Sets up the main window.
   */
  void initialize(QMainWindow &main);

  public slots:

  /*
   * Summary:    Takes the entry in the equation text box and runs the Shunting Yard Algorithm and then evaluates the result.
   */
  void EvaluateEquation();

  void AddConstantsModelPoint();
  void ClearConstantsModel();

 public:
  Ui::MainWindow mainWindow;
  ConstantsModel model;

  QList<Point> graphPoints;
};

#endif /*GRAPHING_H_*/
