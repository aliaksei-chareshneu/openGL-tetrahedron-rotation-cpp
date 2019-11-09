/************ Application.h *************/
#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "graphicwidget.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char *argv[]);
    virtual ~Application();
    int run();
    
private:
    GraphicWidget* graphicWidget;
    QWidget* mainWindow;
};

#endif