#ifndef CHARTVIEWWINDOW_H
#define CHARTVIEWWINDOW_H

#include <QDialog>
#include <QChart>
#include <QChartView>
#include <QMap>
//
#include <QtCharts>

//using namespace QtCharts;

namespace Ui {
  class ChartViewWindow;
}

class ChartViewWindow : public QDialog
{
  Q_OBJECT

public:
  explicit ChartViewWindow(QWidget *parent = 0);
  ~ChartViewWindow();

private:
  Ui::ChartViewWindow *ui;
  // Line series
  // Channels
  QtCharts::QLineSeries *mLChanNS;
  QtCharts::QLineSeries *mLChanEW;
  QtCharts::QLineSeries *mLChanZ;
  QtCharts::QLineSeries *mLChanTri;
  // Shots
  QMap<int, QLineSeries *> mLShots;

};

#endif // CHARTVIEWWINDOW_H
