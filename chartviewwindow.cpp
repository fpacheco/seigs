#include <QGridLayout>
#include <QVBoxLayout>
#include <QPen>
#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
#include <ctime>
#include <stdlib.h>
#else
#include <QRandomGenerator>
#endif

#include "chartviewwindow.h"

ChartViewWindow::ChartViewWindow(QWidget *parent) : QWidget(parent)
{

#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
  srand((int)time(0));
#endif

  setMinimumSize(QSize(800,600));
  setMaximumSize(QSize(10000000,10000000));

  // Size Policy ... needed????
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());

  // Grid layout
  QGridLayout *gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setMargin(0);

  // palette for charts
  QPalette pal = palette();
  // set black background
  pal.setColor(QPalette::Background, Qt::white);
  //setAutoFillBackground(true);

  QLineSeries *series = new QLineSeries();

  for (int i = 0; i < 5000; i++) {
      QPointF p((qreal) i, qSin(M_PI / 50 * i) * 100);
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
      p.ry() += (rand() % 10 + 1)*2;
#else
      p.ry() += QRandomGenerator::global()->bounded(20);
#endif
      *series << p;
    }

  Chart *chart = new Chart();
  chart->addSeries(series);
  chart->setTitle("Zoom in/out example");
  chart->setAnimationOptions(QChart::SeriesAnimations);
  chart->legend()->hide();
  chart->createDefaultAxes();
  chart->setMargins(QMargins());

  QPen pen(Qt::red);
  pen.setWidth(1);

  QtCharts::QLineSeries *mLChanNS = new QtCharts::QLineSeries();
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

  // NS signal
  mCVNS = new ChartView();
  mCVNS->setParent(this);
  //mCVNS->setContentsMargins(0,0,0,0);
  mCVNS->chart()->addSeries(mLChanNS);
  mCVNS->chart()->legend()->hide();
  mCVNS->chart()->createDefaultAxes();
  mCVNS->chart()->axisX()->setGridLineVisible(false);
  mCVNS->chart()->axisY()->setGridLineVisible(false);
  //mCVNS->chart()->setTitle("NS signal");
  //mCVNS->chart()->setWindowFrameMargins(0,0,0,0);
  //mCVNS->chart()->setMargins(QMargins());
  //mCVNS->chart()->setContentsMargins(0,0,0,0);
  //mCVNS->chart()->setBackgroundRoundness(0);
  //mCVNS->setRenderHint(QPainter::Antialiasing);
  //mCVNS->setMaximumHeight(1000000);
  mCVNS->setSizePolicy(sizePolicy);


  // EW signal
  mCVEW = new ChartView();
  mCVEW->setParent(this);
  mCVEW->chart()->addSeries(mLChanEW);
  mCVEW->chart()->legend()->hide();
  mCVEW->chart()->createDefaultAxes();
  mCVEW->chart()->setWindowFrameMargins(0,0,0,0);
  mCVEW->chart()->setMargins(QMargins());
  mCVEW->chart()->setContentsMargins(0,0,0,0);
  mCVEW->chart()->setBackgroundRoundness(0);
  mCVEW->setRenderHint(QPainter::Antialiasing);

  // Vertical signal
  mCVZ = new ChartView();
  mCVZ->setParent(this);
  //mCVZ->setContentsMargins(0,0,0,0);
  //mCVZ->setChart(mChartZ);
  //mCVZ->setRenderHint(QPainter::Antialiasing);
  mCVZ->setSizePolicy(sizePolicy);

  // Trigger signal
  mCVTri = new ChartView();
  mCVTri->setParent(this);
  //mCVTri->setContentsMargins(0,0,0,0);
  //mCVTri->setChart(mChartTri);
  //mCVTri->setRenderHint(QPainter::Antialiasing);
  mCVTri->setSizePolicy(sizePolicy);

  gridLayout->addWidget(mCVNS, 0, 0, 1, 1);
  gridLayout->addWidget(mCVEW, 1, 0, 1, 1);
  gridLayout->addWidget(mCVZ, 2, 0, 1, 1);
  gridLayout->addWidget(mCVTri, 3, 0, 1, 1);

  mCVNS->chart()->layout()->setContentsMargins(0,0,0,0);
  mCVEW->chart()->layout()->setContentsMargins(0,0,0,0);
  mCVZ->chart()->layout()->setContentsMargins(0,0,0,0);
  mCVTri->chart()->layout()->setContentsMargins(0,0,0,0);

  setContentsMargins(0,0,0,0);
  setLayout(gridLayout);
}

ChartViewWindow::~ChartViewWindow()
{

}
