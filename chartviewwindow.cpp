#include <QGridLayout>
#include <QVBoxLayout>
#include <QPen>

#include "chartviewwindow.h"

ChartViewWindow::ChartViewWindow(QWidget *parent) : QWidget(parent)
{
  QPalette pal = palette();
  // set black background
  pal.setColor(QPalette::Background, Qt::white);
  setAutoFillBackground(true);
  //setPalette(pal);

  QLineSeries *series = new QLineSeries();
   for (int i = 0; i < 5000; i++) {
       QPointF p((qreal) i, qSin(M_PI / 50 * i) * 100);
       p.ry() += QRandomGenerator::global()->bounded(20);
       *series << p;
   }

   Chart *chart = new Chart();
   chart->addSeries(series);
   chart->setTitle("Zoom in/out example");
   chart->setAnimationOptions(QChart::SeriesAnimations);
   chart->legend()->hide();
   chart->createDefaultAxes();

   ChartView *chartView = new ChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);

  QtCharts::QLineSeries *mLChanNS = new QtCharts::QLineSeries();
  QPen pen(Qt::red);
  pen.setWidth(1);
  mLChanNS->setPen(pen);
  mLChanNS->append(0, 6);
  mLChanNS->append(0.110, 3.22);
  mLChanNS->append(2.23, 4.56);
  mLChanNS->append(5, -8);
  mLChanNS->append(7, 4);
  mLChanNS->append(10, -5);
  *mLChanNS << QPointF(11.14, 1) << QPointF(13.45, 3) << QPointF(17.22, 6) << QPointF(18.33, 3) << QPointF(20, 2);

  QtCharts::QLineSeries *mLChanEW = new QtCharts::QLineSeries();
  pen.setColor(Qt::green);
  pen.setWidth(1);
  mLChanEW->setPen(pen);
  mLChanEW->append(0, 6);
  mLChanEW->append(0.110, 3.22);
  mLChanEW->append(2.23, 4.56);
  mLChanEW->append(3, 8);
  mLChanEW->append(7, 4);
  mLChanEW->append(10, 5);
  *mLChanEW << QPointF(11.14, 1) << QPointF(13.45, 3) << QPointF(17.22, 6) << QPointF(18.33, 3) << QPointF(20, 2);

  mCVNS = new QChartView();
  mCVNS->setContentsMargins(0,0,0,0);
  mCVNS->chart()->addSeries(mLChanNS);
  mCVNS->chart()->legend()->hide();
  mCVNS->chart()->createDefaultAxes();
  mCVNS->chart()->axisX()->setGridLineVisible(false);
  mCVNS->chart()->axisY()->setGridLineVisible(false);
  //mCVNS->chart()->setTitle("NS signal");
  mCVNS->chart()->setWindowFrameMargins(0,0,0,0);
  mCVNS->chart()->setMargins(QMargins());
  mCVNS->chart()->setContentsMargins(0,0,0,0);
  mCVNS->chart()->setBackgroundRoundness(0);
  mCVNS->setRenderHint(QPainter::Antialiasing);
  mCVNS->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mCVNS->setAutoFillBackground(true);

  //mCVEW = new QChartView(mChartEW);
  mCVEW = new QChartView();
  mCVEW->setContentsMargins(0,0,0,0);
  mCVEW->chart()->addSeries(mLChanEW);
  mCVEW->chart()->legend()->hide();
  mCVEW->chart()->createDefaultAxes();
  //mCVEW->chart()->setTitle("EW signal");
  mCVEW->chart()->setWindowFrameMargins(0,0,0,0);
  mCVEW->chart()->setMargins(QMargins());
  mCVEW->chart()->setContentsMargins(0,0,0,0);
  mCVEW->chart()->setBackgroundRoundness(0);
  mCVEW->setRenderHint(QPainter::Antialiasing);
  mCVEW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mCVNS->setAutoFillBackground(true);

  //mCVZ = new QChartView(mChartZ);
  mCVZ = new QChartView();
  mCVZ->setContentsMargins(0,0,0,0);
  //mCVZ->setChart(mChartZ);
  mCVZ->setRenderHint(QPainter::Antialiasing);
  //mCVZ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  //mCVTri = new QChartView(mChartTri);
  mCVTri = new QChartView();
  mCVNS->setContentsMargins(0,0,0,0);
  //mCVTri->setChart(mChartTri);
  mCVTri->setRenderHint(QPainter::Antialiasing);
  //mCVTri->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  //QVBoxLayout *vbox = new QVBoxLayout(this);
  QGridLayout *vbox = new QGridLayout(this);
  //QPalette Pal(palette());
  // Asignar el color de fondo como Negro
  //Pal.setColor(QPalette::Background, Qt::red);
  //vbox->setAutoFillBackground(true);
  //vbox->setPalette(Pal);
  //vbox->set setStyleSheet("QWidget { background: red; }");
  vbox->setSpacing(0);
  vbox->setHorizontalSpacing(0);
  vbox->setVerticalSpacing(0);
  vbox->setMargin(0);
  vbox->setContentsMargins(0,0,0,0);

  vbox->addWidget(mCVNS, 0, 0);
  vbox->addWidget(chartView, 1, 0);
  //vbox->addWidget(mCVEW, 1, 0);
  vbox->addWidget(mCVZ, 2, 0);
  vbox->addWidget(mCVTri, 3, 0);

  // Layout
  setContentsMargins(0,0,0,0);
  setLayout(vbox);
}

ChartViewWindow::~ChartViewWindow()
{

}
