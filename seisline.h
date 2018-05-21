#ifndef SEISLINE_H
#define SEISLINE_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDateTime>

#include "seisdata.h"

/*
Site ID:         	20180427_illescas,

Instrument:      	TE3-0328/02-17

Data format: 	16 byte

No. of channels: 	 4
Sampling rate:    	 512 Hz

Start recording: 	16/05/18 16:58:51
End recording:   	16/05/18 17:18:51
Trace length:     	0h20'00''
 */

const double MIN_SHOT_RESPONSE = 300.0;
const double DEFAULT_PRE_MULT = 0.5;
const double DEFAULT_POST_MULT = 2.0;

const QString SITE_ID="Site ID";
const QString INSTRUMENT="Instrument";
const QString NUM_CHANNELS="No. of channels";
const QString SAMP_RATE="Sampling rate";
const QString START_RECORD="Start recording";
const QString END_RECORD="End recording";

class SeisLine
{
public:
    Q_PROPERTY(QString siteId READ getSiteId WRITE setSiteId)
    Q_PROPERTY(QString instId READ getInstId WRITE setInstId)
    Q_PROPERTY(QVect<float> shotDistances READ getShotDistances WRITE setShotDistances)

    SeisLine();
    SeisLine(QString filePath);

    void setSiteId(QString id) { mSiteId = id; }
    QString getSiteId () { return mSiteId; }

    void getInstId(QString id) { mInstId = id; }
    QString setInstId () { return mInstId; }

    QVector<int> shotIds();

    QVector<float> getShotDistances() { return mShotDist; }
    void setShotDistances(QVector<float> shots) { mShotDist = shots; }
    void setShotDistances(float first, float delta, int nShots);

    /* Util functions ... QLineSeries can do void QXYSeries::append(const QList<QPointF> &points) */
    QList<QPointF> getNE(int from=0, int to=0);
    QList<QPointF> getEW(int from=0, int to=0);
    QList<QPointF> getZ(int from=0, int to=0);
    QList<QPointF> getTri(int from=0, int to=0);

private:
    void readFromFile(QString filePath);

private:
    float mShotResp;
    float mPreMult;
    float mPostMult;

    QString mSiteId; //! Site Id
    QString mInstId; //! Instrument Id
    int mNumChan;
    QDateTime mStartDT; //! Init date time
    QDateTime mStopDT; //! End date time
    int mSampRate; //! Sample rate in Hz

    QVector<float> mShotDist; //! Sample rate in Hz

    /*
    QVector<int> mDId;
    QVector<float> mDTime;
    QVector<float> mDNZ;
    QVector<float> mDEW;
    QVector<float> mDZ;
    QVector<float> mDTri;
    */
    QVector<SeisData *> mLineData;
};

#endif // SEISLINE_H
