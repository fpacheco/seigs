#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QString filePath = "/home/fpacheco/workspace/seigs/data/ASCII_cada_3m_001part1/EqualizedFile.dat";
    //SeisLine *sline = new SeisLine(filePath);

    return a.exec();
}
