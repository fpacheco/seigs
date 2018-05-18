#include <QDebug>

#include "seisdata.h"

SeisData::SeisData() {

}

SeisData::SeisData(int did, double dtime, double dns, double dew, double dz, double dtri) {
    mDId = did;
    mDTime = dtime;
    mDNS = dns;
    mDEW = dew;
    mDZ = dz;
    mDTri = dtri;
}

SeisData::SeisData(int did, double dtime, QString line, QString spChars) {
  mDId = did;
  mDTime = dtime;

  QStringList sl = line.split(spChars);
  mDNS = mDEW = mDZ = mDTri = 0.000;
  try {
    mDNS = sl[0].toDouble();
    mDEW = sl[1].toDouble();
    mDZ = sl[2].toDouble();
    mDTri = sl[3].toDouble();
  } catch (...) {
    // Fallo
  }
}

/*
QDebug operator<<(QDebug dbg, const SeisData &type)
{
    dbg.nospace() << "SeisData(" <<
      t . << type.mDTime << type.mDNS <<
      ")";
    return dbg.maybeSpace();
}
*/
