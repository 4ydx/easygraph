#include <iostream>

#include "GraphWidget.h"

GraphWidget::GraphWidget(QWidget * parent)
  :QGLWidget(parent), 
   domainMinimum(0.0), 
   domainMaximum(0.0), 
   rangeMinimum(0.0), 
   rangeMaximum(0.0), 
   DEFAULT_DEPTH(-20.0) {

  DEFAULT_GRID_COLOR[0] = 0.5f;
  DEFAULT_GRID_COLOR[1] = 0.5f;
  DEFAULT_GRID_COLOR[2] = 0.5f;

  Points = NULL;

  setCursor(Qt::OpenHandCursor);
  setAcceptDrops(true);
}

GraphWidget::~GraphWidget() {
}

float GraphWidget::GetDomainMinimum() {

  return domainMinimum;
}

float GraphWidget::GetDomainMaximum() {

  return domainMaximum;
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

  glViewport(0, 0, (GLint)width, (GLint)height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void GraphWidget::paintGL(){

  SetDomainRange(this->width(), this->height());

  //  glEnable(GL_LINE_SMOOTH);
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

	glVertex3f( Temp->X + centerOffset.X + previousCenterOffset.X, 
		    Temp->Y + centerOffset.Y + previousCenterOffset.Y, 
		    0.0f );

	glVertex3f( Points->at(i).X + centerOffset.X + previousCenterOffset.X, 
		    Points->at(i).Y + centerOffset.Y + previousCenterOffset.Y, 
		    0.0f);

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

void GraphWidget::SetDomainRange(int WindowWidth, int WindowHeight) {

  float ReadjustedWidth = -0.5 * (float)WindowWidth / DEFAULT_DEPTH;
  float ReadjustedHeight = -0.5 * (float)WindowHeight / DEFAULT_DEPTH;

  domainMinimum = (float)-1.0 * ( ReadjustedWidth + ( centerOffset.X + previousCenterOffset.X ) );
  domainMaximum = ReadjustedWidth - ( centerOffset.X + previousCenterOffset.X );

  rangeMinimum = (float)-1.0 * ( ReadjustedHeight + ( centerOffset.Y + previousCenterOffset.Y ) );
  rangeMaximum = ReadjustedHeight - ( centerOffset.Y + previousCenterOffset.Y );
}

void GraphWidget::drawGrid() {

  glTranslatef(0.0f, 0.0f, DEFAULT_DEPTH);

  for(int i = (int)domainMinimum - 1; i <= (int)domainMaximum + 1; i++) {

    //Vertical
    glBegin(GL_LINES);

    if( i == 0 ) {

      glColor3f(1,0,0);

    } else {

      glColor3f(DEFAULT_GRID_COLOR[0],DEFAULT_GRID_COLOR[1],DEFAULT_GRID_COLOR[2]);

    }
    glVertex3f(i + centerOffset.X + previousCenterOffset.X, -1 * (this->width() / DEFAULT_DEPTH), 0.0f);
    glVertex3f(i + centerOffset.X + previousCenterOffset.X, (this->width() / DEFAULT_DEPTH), 0.0f);

    glEnd(); 
  }

  for(int i = (int)rangeMinimum - 1; i <= (int)rangeMaximum + 1; i++) {

    //Horizontal
    glBegin(GL_LINES);

    if( i == 0 ) {

      glColor3f(1,0,0);

    } else {

      glColor3f(DEFAULT_GRID_COLOR[0],DEFAULT_GRID_COLOR[1],DEFAULT_GRID_COLOR[2]);

    }
    glVertex3f(-1 * (this->height() / DEFAULT_DEPTH), i + centerOffset.Y + previousCenterOffset.Y, 0.0f);
    glVertex3f((this->height() / DEFAULT_DEPTH), i + centerOffset.Y + previousCenterOffset.Y, 0.0f);

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

  dragStartPosition.X = event->pos().x();
  dragStartPosition.Y = event->pos().y();

  QDrag *drag = new QDrag(this);
  QMimeData *mimeData = new QMimeData;

  //Dummby data for now...
  QByteArray array;
  mimeData->setData("application/text", array);
  drag->setMimeData(mimeData);

  drag->exec(Qt::MoveAction | Qt::CopyAction);
}

void GraphWidget::mouseReleaseEvent(QMouseEvent * /*event*/) {

  setCursor(Qt::OpenHandCursor);
}

void GraphWidget::dragMoveEvent(QDragMoveEvent *event) {

  centerOffset.X = ( dragStartPosition.X - event->pos().x() ) / DEFAULT_DEPTH;
  centerOffset.Y = ( event->pos().y() - dragStartPosition.Y ) / DEFAULT_DEPTH;

  updateGL();
}

void GraphWidget::dragEnterEvent(QDragEnterEvent *event) {

  event->acceptProposedAction();
}

void GraphWidget::dropEvent(QDropEvent *event) {

  event->acceptProposedAction();

  previousCenterOffset.X = centerOffset.X + previousCenterOffset.X;
  previousCenterOffset.Y = centerOffset.Y + previousCenterOffset.Y;

  centerOffset.X = centerOffset.Y = 0; 
}
