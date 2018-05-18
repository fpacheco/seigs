#ifndef CHARTVIEWWINDOW_H
#define CHARTVIEWWINDOW_H

#include <QDialog>
#include <QChart>
#include <QChartView>


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
};

#endif // CHARTVIEWWINDOW_H
