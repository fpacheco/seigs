#ifndef SEISDATA_H
#define SEISDATA_H


class SeisData
{
public:
    SeisData();
    SeisData(int id, float dtime, float dns, float dew, float dz, float dtri);

    int dId() { return mDId; }
    void dId(int did) { mDId = did; }

    double dTime() { return mDTime; }
    void dTime(double dtime) { mDTime = dtime; }

    double dNS() { return mDNS; }
    void dNS(double dns) { mDNS = dns; }

    double dEW() { return mDEW; }
    void dWE(double dew) { mDEW = dew; }

    double dZ() { return mDZ; }
    void dZ(double dz) { mDZ = dz; }

    double dTri() { return mDTri; }
    void dTri(double dtri) { mDTri = dtri; }

private:
    int mDId;
    double mDTime;
    double mDNS;
    double mDEW;
    double mDZ;
    double mDTri;
};

#endif // SEISDATA_H
