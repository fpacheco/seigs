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
  setMaximumSize(QSize(1000000,1000000));

  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());

  //
  // setSizePolicy(sizePolicy);

  // Widget sizepolicy
  //setSizePolicy(sizePolicy);
  //sizePolicy.setHeightForWidth(true);
  //sizePolicy.setWidthForHeight(true);

  // Vertical layout
  QVBoxLayout * verticalLayout = new QVBoxLayout(this);
  verticalLayout->setMargin(0);
  verticalLayout->setSpacing(0);
  verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
  verticalLayout->setContentsMargins(0, 0, 0, 0);

  // Grid layout
  QGridLayout *gridLayout = new QGridLayout();
  /*
  gridLayout->setContentsMargins(0,0,0,0);
  gridLayout->setColumnStretch(0,0);
  gridLayout->setRowStretch(0,0);
  gridLayout->setRowStretch(1,0);
  gridLayout->setRowStretch(2,0);
  gridLayout->setRowStretch(3,0);
  */
  gridLayout->setSpacing(0);
  gridLayout->setMargin(0);

  //gridLayout->setHorizontalSpacing(0);
  //gridLayout->setVerticalSpacing(0);
  //gridLayout->setSizeConstraint();
  //gridLayout->setSizeConstraint(QLayout::SetNoConstraint);

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

  ChartView *chartView = new ChartView(chart);
  chartView->setParent(this);
  //chartView->setRenderHint(QPainter::Antialiasing);
  //chartView->setMaximumHeight(1000000);
  //chartView->setMaximumWidth(1000000);
  chartView->setSizePolicy(sizePolicy);
  //chartView->setContentsMargins(0,0,0,0);

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

  //mCVEW = new QChartView(mChartEW);
  /*
  mCVEW = new QChartView();
  mCVEW->setParent(this);
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
  //mCVEW->setSizePolicy(sizePolicy);
  */
  //mCVZ = new QChartView(mChartZ);

  mCVZ = new QChartView();
  mCVZ->setParent(this);
  //mCVZ->setContentsMargins(0,0,0,0);
  //mCVZ->setChart(mChartZ);
  //mCVZ->setRenderHint(QPainter::Antialiasing);
  mCVZ->setSizePolicy(sizePolicy);

  //mCVTri = new QChartView(mChartTri);

  mCVTri = new QChartView();
  mCVTri->setParent(this);
  //mCVTri->setContentsMargins(0,0,0,0);
  //mCVTri->setChart(mChartTri);
  //mCVTri->setRenderHint(QPainter::Antialiasing);
  mCVTri->setSizePolicy(sizePolicy);

  gridLayout->addWidget(mCVNS, 0, 0, 1, 1);
  gridLayout->setVerticalSpacing(0);

  gridLayout->addWidget(chartView, 1, 0, 1, 1);
  gridLayout->setVerticalSpacing(0);

  //gridLayout->addWidget(mCVEW, 1, 0);
  gridLayout->addWidget(mCVZ, 2, 0, 1, 1);
  gridLayout->setVerticalSpacing(0);

  gridLayout->addWidget(mCVTri, 3, 0, 1, 1);
  gridLayout->setVerticalSpacing(0);
  //QSpacerItem * verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
  //gridLayout->addItem(verticalSpacer, 4, 0, 1, 1, Qt::AlignTop);
  //gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);
  //gridLayout->update();

  // Layout
  // setSizePolicy(sizePolicy);
  setContentsMargins(0,0,0,0);
  verticalLayout->addLayout(gridLayout);

  setLayout(verticalLayout);
}

ChartViewWindow::~ChartViewWindow()
{

}
