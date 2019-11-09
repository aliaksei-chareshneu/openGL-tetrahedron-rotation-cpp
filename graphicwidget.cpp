#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include <QFileDialog>

#include "graphicwidget.h"

#include <QTimer>

using namespace std;

void GraphicWidget::mousePressEvent(QMouseEvent *event)
{
    posX = event->x();
    posY = event->y();
    
    update();
    
    cout << "A mouse button was pressed" << endl;
    cout << "Mouse cursor coordinates: ";
    cout << event->x() << ", " << event->y() << endl;
    if (event->button() == Qt::LeftButton)
    {
        cout << "Left ";
    }
    if (event->button() == Qt::MidButton)
    {
        cout << "Middle ";
    }
    if (event->button() == Qt::RightButton)
    {
        cout << "Right ";
    }
    cout << "mouse button was pressed" << endl;
    
    lastPosX = event->x();
    lastPosY = event->y();
}

GraphicWidget::GraphicWidget()
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
    displayRectangle = true;
    fileName = "No file supplied";
    
    lastPosX = 0;
    lastPosY = 0;
    rotationX = 10;
    rotationY = 60;
    
    timer = new QTimer;
    
    connect(timer, SIGNAL(timeout()),  this, SLOT(timerTick()));
}

GraphicWidget::~GraphicWidget()
{
    if (timer != 0)
        delete timer;
    timer = 0;
}

void GraphicWidget::paintGL()
{
    glViewport(0, 0, width(), height());
    
    glEnable(GL_DEPTH_TEST);
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    
    glBegin(GL_TRIANGLES);
    
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, -0.4, 0.8);
        glVertex3f(0.7, -0.4, -0.4);
        glVertex3f(-0.7, -0.4, -0.4);
        
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -0.4, 0.8);
        glVertex3f(-0.7, -0.4, -0.4);
        glVertex3f(0.0, 0.8, 0.0);
        
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, -0.4, 0.8);
        glVertex3f(0.0, 0.8, 0.0);
        glVertex3f(0.7, -0.4, -0.4);
        
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.7, -0.4, -0.4);
        glVertex3f(0.0, 0.8, 0.0);
        glVertex3f(-0.7, -0.4, -0.4);
        
    glEnd();
}

void GraphicWidget::mouseMoveEvent(QMouseEvent *event)
{
    rotationX += 0.5 * (lastPosY - event->y());
    rotationY += 0.5 * (lastPosX - event->x());
    
    updateGL();
    
    lastPosX = event->x();
    lastPosY = event->y();
}

void GraphicWidget::startRotation()
{
    cout << "'Start' button was pressed" << endl;
//     set to 10 instead of 100 in order to reach more smooth rotation in combination with rotationY += 1 instead of 10
    timer->start(10);
}

void GraphicWidget::stopRotation()
{
    cout << "'Stop' button was pressed" << endl;
    timer->stop();
}

void GraphicWidget::timerTick()
{
    cout << "Printing the timer" << endl;
//     set to 1 instead of 10 in order to reach more smooth rotation in combination with timer->start(10) instead of 100
    rotationY += 1;
    updateGL();
}

