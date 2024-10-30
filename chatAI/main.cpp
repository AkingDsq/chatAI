#include "chatAI.h"
#include <Python.h>
#include <QtWidgets/QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatAI w;

    w.show();
    return a.exec();
}
