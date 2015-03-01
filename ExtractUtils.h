#ifndef __ExtractUtils__
#define __ExtractUtils__
#include <QtCore>
#include <QtSql>

class TrueFormula;

class ExtractUtils{
public:
	void getAllLotter();
	QList<TrueFormula*> getAllFormula();

private:
	void insertTheLotter(QSqlQuery);
	QList<TrueFormula*> getFromQuery(QSqlQuery);
public:
	static ExtractUtils* getInstance();
	
private:
	static ExtractUtils* _ExtractUtils;
		
};
#endif
