#ifndef __baseValue__
#define __baseValue__
#include "ValueModelBase.h"
struct Lotter;

#define INIT_MIN_MAX(A,B) virtual void init()override{_min = A; _max = B;}

class REDNUMBER :public ValueModelBase{
public:
	INIT_VALUE(REDNUMBER);
	virtual int getValue(int) const;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 33);
};

class ACS :public ValueModelBase{
public:
	INIT_VALUE(ACS);
	virtual int getValue(int) const;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 10);
private:
	
};

class T :public ValueModelBase{
public:
	INIT_VALUE(T);
	virtual int getValue(int) const;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(7, 33);
};

class V : public ValueModelBase
{
public:
	INIT_VALUE(V);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 26);
};

class QGS:public ValueModelBase
{
public:
	INIT_VALUE(QGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class OGS:public ValueModelBase
{
public:
	INIT_VALUE(OGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class ZGS:public ValueModelBase
{
public:
	INIT_VALUE(ZGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class HGS:public ValueModelBase
{
public:
	INIT_VALUE(HGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class DGS:public ValueModelBase
{
public:
	INIT_VALUE(DGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class XGS:public ValueModelBase
{
public:
	INIT_VALUE(XGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 6);
};

class JGJSH:public ValueModelBase
{
public:
	INIT_VALUE(JGJSH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 168);
};

class JGOSH:public ValueModelBase
{
public:
	INIT_VALUE(JGOSH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 162);
};

class HZ:public ValueModelBase
{
public:
	INIT_VALUE(HZ);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(21, 210);
};

class HV:public ValueModelBase
{
public:
	INIT_VALUE(HV);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 9);
};

class JJ:public ValueModelBase
{
public:
	INIT_VALUE(JJ);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(6, 32);
};

class HQO:public ValueModelBase
{
public:
	INIT_VALUE(HQO);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class HYT:public ValueModelBase
{
public:
	INIT_VALUE(HYT);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 2);
};

class HZH:public ValueModelBase
{
public:
	INIT_VALUE(HZH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class HDX:public ValueModelBase
{
public:
	INIT_VALUE(HDX);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class JGHVH :public ValueModelBase
{
public:
	INIT_VALUE(JGHVH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(3, 51);
};

class JGHVHH :public ValueModelBase
{
public:
	INIT_VALUE(JGHVHH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 9);
};

class JGHVHV:public ValueModelBase
{
public:
	INIT_VALUE(JGHVHV);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 10);
};

class JGHVHDX:public ValueModelBase
{
public:
	INIT_VALUE(JGHVHDX);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class JGHVHJO:public ValueModelBase
{
public:
	INIT_VALUE(JGHVHJO);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class JGTVS:public ValueModelBase
{
public:
	INIT_VALUE(JGTVS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class JGBMJ:public ValueModelBase
{
public:
	INIT_VALUE(JGBMJ);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(6, 26);
};

class JGMMJ  :public ValueModelBase
{
public:
	INIT_VALUE(JGMMJ);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 27);
};

class HVYT  :public ValueModelBase
{
public:
	INIT_VALUE(HVYT);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 2);
};

class HVZH:public ValueModelBase
{
public:
	INIT_VALUE(HVZH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class HVDX:public ValueModelBase
{
public:
	INIT_VALUE(HVDX);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class HVYTS0:public ValueModelBase
{
public:
	INIT_VALUE(HVYTS0);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class HVYTS1:public ValueModelBase
{
public:
	INIT_VALUE(HVYTS1);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class HVYTS2:public ValueModelBase
{
public:
	INIT_VALUE(HVYTS2);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class LS:public ValueModelBase
{
public:
	INIT_VALUE(LS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class LZS:public ValueModelBase
{
public:
	INIT_VALUE(LZS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 3);
};

class YLH:public ValueModelBase
{
public:
	INIT_VALUE(YLH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 999);
};

class PD:public ValueModelBase
{
public:
	INIT_VALUE(PD);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 10);
};

class SD:public ValueModelBase
{
public:
	INIT_VALUE(SD);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(2,24);
};

class QS1:public ValueModelBase
{
public:
	INIT_VALUE(QS1);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class QS2:public ValueModelBase
{
public:
	INIT_VALUE(QS2);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class QS3:public ValueModelBase
{
public:
	INIT_VALUE(QS3);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class GWGS:public ValueModelBase
{
public:
	INIT_VALUE(GWGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class SWGS:public ValueModelBase
{
public:
	INIT_VALUE(SWGS);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 7);
};

class BLUENUMBER:public ValueModelBase
{
public:
	INIT_VALUE(BLUENUMBER);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 16);
};

class BLUEZF:public ValueModelBase
{
public:
	INIT_VALUE(BLUEZF);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 15);
};

class BLUEDX:public ValueModelBase
{
public:
	INIT_VALUE(BLUEDX);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class BLUEQO:public ValueModelBase
{
public:
	INIT_VALUE(BLUEQO);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class BLUEZH:public ValueModelBase
{
public:
	INIT_VALUE(BLUEZH);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(1, 2);
};

class BLUEV:public ValueModelBase
{
public:
	INIT_VALUE(BLUEV);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 9);
};

class BLUE012L:public ValueModelBase
{
public:
	INIT_VALUE(BLUE012L);
	virtual int getValue(int) const override;
	virtual int getValue(Lotter)const override;
	INIT_MIN_MAX(0, 2);
};

#endif
