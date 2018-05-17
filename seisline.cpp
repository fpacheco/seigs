#include <QDebug>
#include <QFile>
#include <QStringList>

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
        if (mLineData[i]->dTri() >= MIN_SHOT_RESPONSE) {
            shotIds.append(i);
        }
    }
    return shotIds;
}

void SeisLine::readFromFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }

    QTextStream strf(&file);
    for (int i = 0; i < 32; ++i) {
        qDebug() << strf.readLine();
    }
    file.close();

    /*
    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList.append(line.split(',').first());
    }

    qDebug() << wordList;
    */
}
