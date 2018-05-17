#include "seisdata.h"

SeisData::SeisData() {

}

SeisData::SeisData(int did, float dtime, float dns, float dew, float dz, float dtri) {
    mDId = did;
    mDTime = dtime;
    mDNS = dns;
    mDEW = dew;
    mDZ = dz;
    mDTri = dtri;
}
