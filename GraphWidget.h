/* Copyright Nathan Findley
 * Using the GPLv3
 */

#ifndef GRAPHWIDGET_H_
#define GRAPHWIDGET_H_

#include "Point.h"

#include <qgl.h>
#include <QWidget>

/*

Author: Nate Findley

Description: The widget where graphing takes place.

08/27/08 -- Updated comment
08/27/08 -- Deriving from QGLWidget; Removed drawing to widget

*/

class GraphWidget: public QGLWidget
{
  Q_OBJECT

 public:

  GraphWidget(QWidget *parent);
  ~GraphWidget();

  void initializeGL();
  void resizeGL( int width, int height );
  void paintGL();
  void drawGraph(QList<Point> &points, double lowerRange, double upperRange);
	
  QList<Point> *Points;
  Point Range;

 private:
  
  void defaultView();
};

#endif /*GRAPHWIDGET_H_*/
