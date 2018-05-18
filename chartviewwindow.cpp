#include <QVBoxLayout>

#include "chartviewwindow.h"

ChartViewWindow::ChartViewWindow(QWidget *parent) : QWidget(parent)
{
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    series->append(0, 6);
    series->append(0.110, 3.22);
    series->append(2.23, 4.56);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11.14, 1) << QPointF(13.45, 3) << QPointF(17.22, 6) << QPointF(18.33, 3) << QPointF(20, 2);

    QtCharts::QChart *mChartNS = new QtCharts::QChart();
    mChartNS->legend()->hide();
    mChartNS->addSeries(series);
    mChartNS->createDefaultAxes();
    mChartNS->setTitle("NS signal");

    QtCharts::QChart *mChartEW = new QtCharts::QChart();
    mChartEW->legend()->hide();
    mChartEW->addSeries(series);
    mChartEW->createDefaultAxes();
    mChartEW->setTitle("EW signal");

    QtCharts::QChart *mChartZ = new QtCharts::QChart();
    mChartZ->legend()->hide();
    mChartZ->addSeries(series);
    mChartZ->createDefaultAxes();
    mChartZ->setTitle("Z signal");

    QtCharts::QChart *mChartTri = new QtCharts::QChart();
    mChartTri->legend()->hide();
    mChartTri->addSeries(series);
    mChartTri->createDefaultAxes();
    mChartTri->setTitle("Trigger signal");

    //QChartView *chartView = new QChartView(chart);

    mCVNS = new QChartView(mChartNS);
    //mCVNS->setChart(mChartNS);
    mCVNS->setRenderHint(QPainter::Antialiasing);
    mCVNS->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //mCVNS->setLayout(vbox);

    mCVEW = new QChartView(mChartEW);
    //mCVEW->setChart(mChartEW);
    mCVEW->setRenderHint(QPainter::Antialiasing);
    mCVEW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //mCVEW->setLayout(vbox);

    mCVZ = new QChartView(mChartZ);
    //mCVZ->setChart(mChartZ);
    mCVZ->setRenderHint(QPainter::Antialiasing);
    //mCVZ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mCVTri = new QChartView(mChartTri);
    //mCVTri->setChart(mChartTri);
    mCVTri->setRenderHint(QPainter::Antialiasing);
    //mCVTri->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setSpacing(0);
    vbox->setContentsMargins(0,0,0,0);

    vbox->addWidget(mCVNS);
    vbox->addWidget(mCVEW);
    vbox->addWidget(mCVZ);
    vbox->addWidget(mCVTri);

    // Layout
    setContentsMargins(0,0,0,0);
    setLayout(vbox);


    //setCentralWidget(vbox);

    //ui->chartView->setChart(chart);
    //ui->chartView->setRenderHint(QPainter::Antialiasing);
    // setCentralWidget(vbox);
    // resize(400, 300);
    // show();
}

ChartViewWindow::~ChartViewWindow()
{

}
