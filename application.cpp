#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "graphicwidget.h"
#include "application.h"

using namespace std;

Application::Application(int &argc, char *argv[]) : QApplication(argc, argv)
{
    graphicWidget = 0;
    mainWindow = 0;
}

Application::~Application()
{
    if (graphicWidget != 0)
        delete graphicWidget;
    graphicWidget = 0;
    
    if (mainWindow !=0)
        delete mainWindow;
    mainWindow = 0;
}

int Application::run()
{
    mainWindow = new QWidget;
    mainWindow->setWindowTitle("This title was set by Application class");
    
    graphicWidget = new GraphicWidget;
    graphicWidget->setMinimumSize(300, 350);
    QPushButton* buttonStart = new QPushButton("Start");
    QPushButton* buttonStop = new QPushButton("Stop");
    
    QObject::connect(buttonStart, SIGNAL(clicked()), graphicWidget, SLOT(startRotation()));
    
    QObject::connect(buttonStop, SIGNAL(clicked()), graphicWidget, SLOT(stopRotation()));
    
    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(buttonStart);
    rightLayout->addWidget(buttonStop);
    rightLayout->addStretch();
    
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(graphicWidget);
    mainLayout->addLayout(rightLayout);
    
    mainWindow->setLayout(mainLayout);
    
    mainWindow->show();
    
    return QApplication::exec();
}