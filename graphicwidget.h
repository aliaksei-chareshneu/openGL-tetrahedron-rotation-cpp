#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QGLWidget>

class GraphicWidget : public QGLWidget
{
    Q_OBJECT
public:
    GraphicWidget();
    ~GraphicWidget();
    
protected:
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent *event);
    
    virtual void mouseMoveEvent(QMouseEvent *event);
    
private:
    int posX, posY;
    bool displayRectangle;
    QString fileName;
    
    int lastPosX, lastPosY;
    double rotationX, rotationY;
    
    QTimer* timer;
    
private slots:
    void startRotation();
    void stopRotation();
    
    void timerTick();
};

#endif