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
#include "application.h"

using namespace std;

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    return app.run();
}

