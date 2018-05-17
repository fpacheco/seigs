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

const float MIN_SHOT_RESPONSE = 300.0;
const float DEFAULT_PRE_MULT = 0.5;
const float DEFAULT_POST_MULT = 2.0;

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


private:
    void readFromFile(QString filePath);

private:
    float mShotResp;
    float mPreMult;
    float mPostMult;

    QString mSiteId; //! Site Id
    QString mInstId; //! Instrument Id
    QDateTime mIDT; //! Init date time
    QDateTime mEDT; //! End date time
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
