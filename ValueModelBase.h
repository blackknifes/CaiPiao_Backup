#ifndef __ValueModelBase__
#define __ValueModelBase__
#include "mainwindow.h"
#include <time.h>
#include "Formula.h"

struct Lotter;

#define FactorCreate(A)				\
static LotterTag* createTag(Formula* parent){\
	LotterTag* a = new	A(parent);\
	return a;						\
}

#define INIT_VALUE(A)	\
A():ValueModelBase(#A){init();}		\
A(Formula* parent):ValueModelBase(#A,parent){init();};\
FactorCreate(A)

struct _timeb
{
	time_t time;
	unsigned short millitm;
	short timezone, dstflag;
};									

class ValueModelBase: public LotterTag{
public:
	INIT_STRUCT(ValueModelBase, LotterTag);
	
	virtual void Calculate(DataType) override;

	static int getRand(unsigned int min, unsigned int max);
	static int getMax(QList<int>);
	static int getMin(QList<int>);

	static QList<int> getOddNumber(QList<int>);
	static QList<int> getEvenNumber(QList<int>);
	static QList<int> getPrimeNumber(QList<int>);
	static QList<int> getCompositeNumber(QList<int>);
	static int hasContinue(int,QList<int>);
	static int hasContinue(QList<int>,QList<int>);
	static QList<QList<int>> getContinueNumber(QList<int>);
	static bool isPrimeNumber(int);
	static int getTailNumber(int);
	static int getSum(QList<int>);

	
public:
    const QList<Lotter>* lotter_list = &MainWindow::allLotters;
	friend class FormulaTest;
};

#endif
