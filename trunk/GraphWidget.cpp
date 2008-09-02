#include <iostream>

#include "GraphWidget.h"

GraphWidget::GraphWidget(QWidget * parent)
  :QGLWidget(parent), 
   DEFAULT_DEPTH(-25.0) {

  DEFAULT_GRID_COLOR[0] = 0.5f;
  DEFAULT_GRID_COLOR[1] = 0.5f;
  DEFAULT_GRID_COLOR[2] = 0.5f;

  Points = NULL;

  setCursor(Qt::OpenHandCursor);
  setAcceptDrops(true);
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

  glViewport(0, 0, (GLint)width, (GLint)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void GraphWidget::paintGL(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  drawGrid();

  if(Points != NULL && Points->size() > 0) {

    const Point *Temp;
    Temp = NULL;

    glColor3f(1, 1, 1);
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

void GraphWidget::drawGrid() {

  glTranslatef(0.0f, 0.0f, DEFAULT_DEPTH);

  for(int i = 0; i < 30; i++) {

    //Horizontal
    glBegin(GL_LINES);

    if( i == 10) {

      glColor3f(1,0,0);

    } else {

      glColor3f(DEFAULT_GRID_COLOR[0],DEFAULT_GRID_COLOR[1],DEFAULT_GRID_COLOR[2]);

    }
    glVertex3f( -15.0f, 10.0f - i, 0.0f);
    glVertex3f( 15.0f, 10.0f - i, 0.0f);

    glEnd(); 

    //Vertical
    glBegin(GL_LINES);

    if( i == 15) {

      glColor3f(1,0,0);

    } else {

      glColor3f(DEFAULT_GRID_COLOR[0],DEFAULT_GRID_COLOR[1],DEFAULT_GRID_COLOR[2]);

    }
    glVertex3f( -15.0f + i, 15.0f, 0.0f);
    glVertex3f( -15.0f + i, -15.0f, 0.0f);

    glEnd(); 
  }
}

/*
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
*/

//-------- PROTECTED -----------

void GraphWidget::mousePressEvent(QMouseEvent * event) {

  if(event->button() != Qt::LeftButton) {

    event->ignore();
    return;
  }
  setCursor(Qt::ClosedHandCursor);

  QByteArray array;

  QDrag *drag = new QDrag(this);
  QMimeData *mimeData = new QMimeData;

  mimeData->setData("application/text", array);
  drag->setMimeData(mimeData);

  Qt::DropAction dropAction = drag->exec(Qt::MoveAction | Qt::CopyAction);
}

void GraphWidget::mouseReleaseEvent(QMouseEvent * event) {

  std::cout << "Mouse release event" << std::endl;
  setCursor(Qt::OpenHandCursor);
}

void GraphWidget::dragMoveEvent(QDragMoveEvent *event) {

  std::cout << "Drag move event" << std::endl;
  std::cout << "X: " << event->pos().x() << std::endl;
  std::cout << "Y: " << event->pos().y() << std::endl;
}

void GraphWidget::dragEnterEvent(QDragEnterEvent *event) {

  std::cout << "Drag enter event" << std::endl;
  std::cout << "X: " << event->pos().x() << std::endl;
  std::cout << "Y: " << event->pos().y() << std::endl;
  event->acceptProposedAction();
}

void GraphWidget::dropEvent(QDropEvent *event) {

  std::cout << "Drop event" << std::endl;
  event->acceptProposedAction();

}
