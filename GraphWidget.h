/* Copyright Nathan Findley
 * Using the GPLv3
 */

#ifndef GRAPHWIDGET_H_
#define GRAPHWIDGET_H_

#include "Point.h"

#include <qgl.h>
#include <QWidget>
#include <QMouseEvent>

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

  /*
   * Summary:    Draw the graph from the list of points
   *
   * Parameters: The list of points.
   */
  void drawGraph(QList<Point> &points);
	
  QList<Point> *Points;
  Point Range;

  float GetDomainMinimum();
  float GetDomainMaximum();

  /*
   * Summary:    Set the min/max values for the domain and range of the viewspace
   *
   * Parameters: The current height and width of the viewspace
   */  
  void SetDomainRange(int WindowWidth, int WindowHeight);

 signals:
  void gridMoved();

 protected:

  void mousePressEvent(QMouseEvent * event);
  void mouseReleaseEvent(QMouseEvent * event);
  void dragMoveEvent(QDragMoveEvent *event);
  void dragEnterEvent(QDragEnterEvent *event);
  void dropEvent(QDropEvent *event);

 private:

  /* The upper and lower values for the domain (the x-axis values)
   *
   * Set these values based on the current PreviousCenterOffset
   */
  float domainMinimum;
  float domainMaximum;
  float rangeMinimum;
  float rangeMaximum;

  Point centerOffset;
  Point previousCenterOffset;
  Point dragStartPosition;

  const float DEFAULT_DEPTH;
  float DEFAULT_GRID_COLOR[3];
  
  void drawGrid();
};

#endif /*GRAPHWIDGET_H_*/
