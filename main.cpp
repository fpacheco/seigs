#include "mainwindow.h"
#include <QApplication>
#include "seisline.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString filePath = "/ingesur/publico_001/Trabajos/COPASA-Espina/1-Sismica_puentes/3-Ejecucion/Borrar/ASCII_cada_3m_001part1/EqualizedFile.dat";
    SeisLine * sline = new SeisLine(filePath);

    return a.exec();
}
