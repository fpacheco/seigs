#ifndef SEISDATA_H
#define SEISDATA_H

#include <QObject>
#include <QString>

class SeisData
{
  // Q_OBJECT

/*
public:
  Q_PROPERTY(QString id READ getId WRITE setId)
  Q_PROPERTY(QString time READ getTime WRITE setTime)
  Q_PROPERTY(QString ns READ getNS WRITE setNS)
  Q_PROPERTY(QString ew READ getEW WRITE setEW)
  Q_PROPERTY(QString z READ getZ WRITE setZ)
  Q_PROPERTY(QString tri READ getTri WRITE setTri)
*/

public:
  SeisData();
  SeisData(int did, double dtime, double dns, double dew, double dz, double dtri);
  SeisData(int did, double dtime, QString line, QString spChars=" ");

  int getId() { return mDId; }
  void setId(int did) { mDId = did; }

  double getTime() { return mDTime; }
  void setTime(double dtime) { mDTime = dtime; }

  double getNS() { return mDNS; }
  void setNS(double dns) { mDNS = dns; }

  double getEW() { return mDEW; }
  void setWE(double dew) { mDEW = dew; }

  double getZ() { return mDZ; }
  void setZ(double dz) { mDZ = dz; }

  double getTri() { return mDTri; }
  void setTri(double dtri) { mDTri = dtri; }

private:
  int mDId;
  double mDTime;
  double mDNS;
  double mDEW;
  double mDZ;
  double mDTri;
};

//QDebug operator<<(QDebug dbg, const SeisData &type);

#endif // SEISDATA_H
