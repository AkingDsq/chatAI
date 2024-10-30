#include "chatAI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatAI w;
    w.show();
    return a.exec();
}
