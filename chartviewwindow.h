#ifndef CHARTVIEWWINDOW_H
#define CHARTVIEWWINDOW_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QMap>
//
#include <QtCharts>

class ChartViewWindow : public QWidget
{
public:
    ChartViewWindow(QWidget *parent);
    ~ChartViewWindow();

private:
    // Line series
    // Channels
    QtCharts::QLineSeries *mLChanNS;
    QtCharts::QLineSeries *mLChanEW;
    QtCharts::QLineSeries *mLChanZ;
    QtCharts::QLineSeries *mLChanTri;
    QVector<QtCharts::QLineSeries *> mLShots;

    // Charts
    QtCharts::QChart *mChartNS;
    QtCharts::QChart *mChartEW;
    QtCharts::QChart *mChartZ;
    QtCharts::QChart *mChartTri;
    QVector<QtCharts::QChart *> mChartShots;

    // Views
    QtCharts::QChartView *mCVNS;
    QtCharts::QChartView *mCVEW;
    QtCharts::QChartView *mCVZ;
    QtCharts::QChartView *mCVTri;
    QVector<QtCharts::QChartView *> mCVShots;
};

#endif // CHARTSVIEWWINDOW_H
