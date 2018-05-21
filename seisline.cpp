#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QPointF>

#include "seisline.h"

SeisLine::SeisLine(): mShotResp(MIN_SHOT_RESPONSE), mPreMult(DEFAULT_PRE_MULT), mPostMult(DEFAULT_POST_MULT)
{
    /*
    SeisData *sd = new SeisData();
    sd->dId(1);
    // sd->
    mLineData.push_back(sd);
    // mLineData.push_back(new SeisData());
*/
}

SeisLine::SeisLine(QString filePath)
{
    SeisLine();
    readFromFile(filePath);
}

QVector<int> SeisLine::shotIds() {
    QVector<int> shotIds;
    for (int i = 0; i < mLineData.size(); ++i) {
        if (mLineData[i]->getTri() >= MIN_SHOT_RESPONSE) {
            shotIds.append(i);
        }
    }
    return shotIds;
}

QList<QPointF> SeisLine::getNE(int from, int to)
{
    QList<QPointF> res;

    if (from<0) {
        from=0;
    }

    if (to==0) {
        to=mLineData.length();
    }

    for (int i = from; i < to; ++i) {
        QPointF p = QPointF(mLineData.at(i)->getTime(), mLineData.at(i)->getNS());
        res.append(p);
    }

    return res;
}

QList<QPointF> SeisLine::getEW(int from, int to)
{
    QList<QPointF> res;

    if (from<0) {
        from=0;
    }

    if (to==0) {
        to=mLineData.length();
    }

    for (int i = from; i < to; ++i) {
        QPointF p = QPointF(mLineData.at(i)->getTime(), mLineData.at(i)->getEW());
        res.append(p);
    }

    return res;
}

QList<QPointF> SeisLine::getZ(int from, int to)
{
    QList<QPointF> res;

    if (from<0) {
        from=0;
    }

    if (to==0) {
        to=mLineData.length();
    }

    for (int i = from; i < to; ++i) {
        QPointF p = QPointF(mLineData.at(i)->getTime(), mLineData.at(i)->getZ());
        res.append(p);
    }

    return res;
}

QList<QPointF> SeisLine::getTri(int from, int to)
{
    QList<QPointF> res;

    if (from<0) {
        from=0;
    }

    if (to==0) {
        to=mLineData.length();
    }

    for (int i = from; i < to; ++i) {
        QPointF p = QPointF(mLineData.at(i)->getTime(), mLineData.at(i)->getTri());
        res.append(p);
    }

    return res;
}

void SeisLine::readFromFile(QString filePath)
{
    QFile file(filePath);
    try {
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        }

        QTextStream strf(&file);

        QString line;

        // First line
        line = strf.readLine();
        if (line.length()>0) {
            mSiteId = line.trimmed().split('\t')[1].trimmed();
            qDebug() << "mSiteId: " << mSiteId;
        }

        strf.readLine();

        line = strf.readLine();
        if (line.length()>0) {
            mInstId  = line.trimmed().split('\t')[1].trimmed();
            qDebug() << "mInstId: " << mInstId;
        }

        line = strf.readLine(); qDebug() << line;
        line = strf.readLine(); qDebug() << line;

        line = strf.readLine(); qDebug() << line;
        if (line.length()>0) {
            mNumChan  = line.trimmed().split('\t')[1].trimmed().toInt();
            qDebug() << "mNumChan: " << mNumChan;
        }

        line = strf.readLine();
        if (line.length()>0) {
            mSampRate  = line.trimmed().split('\t')[1].trimmed().split(' ')[0].toInt();
            qDebug() << "mSampRate: " << mSampRate;
        }

        strf.readLine();

        line = strf.readLine(); qDebug() << line;
        if (line.length()>0) {

            mStartDT =  QDateTime::fromString(
                        line.trimmed().split('\t')[1].trimmed(),
                    "dd/MM/yy hh:mm:ss"
                    );
            //qDebug() << line.trimmed().split('\t')[1].trimmed();
            qDebug() << "mStartDT: " << mStartDT;
        }

        line = strf.readLine(); qDebug() << line;
        if (line.length()>0) {
            mStopDT =  QDateTime::fromString(line.trimmed().split('\t')[1].trimmed(), "dd/MM/yy hh:mm:ss");
            qDebug() << "mStopDT: " << mStopDT;
        }


        for (int i = 0; i < 21; ++i) {
            qDebug() << strf.readLine();
        }

        int cont = 0;
        double deltaT = 1.0/mSampRate;
        double cT = 0.00;
        while (!strf.atEnd()) {
            QString line = strf.readLine();
            // qDebug() << line;
            if (line.length()>0) {
                cont = cont + 1;
                SeisData * sd = new SeisData(cont, cT, line.trimmed(), " ");
                cT = cT + deltaT;
                // qDebug() << sd->getId() << sd->getTime() << sd->getNS() << sd->getEW() << sd->getZ() << sd->getTri();
                mLineData.append(sd);
            }
        }
        file.close();
    } catch (...) {
        file.close();
        qDebug() << "Handling exception";
    }

}
