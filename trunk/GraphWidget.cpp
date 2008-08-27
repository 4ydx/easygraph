#include <iostream>

#include "GraphWidget.h"

GraphWidget::GraphWidget(QWidget * parent)
	:QGLWidget(parent) {

  Points = NULL;
}

GraphWidget::~GraphWidget() {
}

void GraphWidget::initializeGL() {

  glShadeModel(GL_SMOOTH);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void GraphWidget::resizeGL( int width, int height ) {

  height = height?height:1;

  //std::cout << "Width: " << QString::number(width).toStdString() 
  //	    << "; Height: " << QString::number(height).toStdString() << std::endl;

  glViewport( 0, 0, (GLint)width, (GLint)height );

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void GraphWidget::paintGL(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if(Points == NULL || Points->size() == 0) {

    defaultView();

  } else {

    glTranslatef(0.0f, 0.0f, -25.0f);

    const Point *Temp;
    Temp = NULL;

    for(int i = 0; i < Points->size(); i++) {

      if(Temp != NULL) {

	glBegin(GL_LINES);
	glVertex3f( Temp->X, Temp->Y, 0.0f);
	glVertex3f( Points->at(i).X, Points->at(i).Y, 0.0f);
	glEnd(); 
      }
      Temp = &Points->at(i);
    }      
  }
}

void GraphWidget::drawGraph(QList<Point> &points) {
  
  Points = &points;

  updateGL();
}

void GraphWidget::defaultView() {

  glTranslatef(-1.5f,0.0f,-6.0f);

  glBegin(GL_TRIANGLES);
  glVertex3f( 0.0f, 1.0f, 0.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);
  glVertex3f( 1.0f,-1.0f, 0.0f);
  glEnd(); 

  glTranslatef(3.0f,0.0f,0.0f);

  glBegin(GL_QUADS);
  glVertex3f(-1.0f, 1.0f, 0.0f);
  glVertex3f( 1.0f, 1.0f, 0.0f);
  glVertex3f( 1.0f,-1.0f, 0.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);
  glEnd();   
}
