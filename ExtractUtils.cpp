#include "ExtractUtils.h"
#include "MysqlUtils.h"
#include "mainwindow.h"
#include "TrueFormula.h"


ExtractUtils* ExtractUtils::_ExtractUtils = nullptr;

ExtractUtils* ExtractUtils::getInstance()
{
	if (_ExtractUtils == nullptr)
	{
		_ExtractUtils = new ExtractUtils();
	}
	return _ExtractUtils;
}

void ExtractUtils::getAllLotter()
{
	QSqlQuery query = _sqlUT->excuteCall("getAllLotter()");
	insertTheLotter(query);
}

void ExtractUtils::insertTheLotter(QSqlQuery query)
{
	auto& lotters = MainWindow::allLotters;

	if (query.numRowsAffected()>0)
	{
		lotters.clear();
	}
	while (query.next())
	{
		auto ddate = query.value(0).toDate();
		QList<int> redBall;
		for (size_t i = 1; i < 7;i++)
		{
			redBall.push_back(query.value(i).toInt());
		}
		int greenBall = query.value(8).toInt();
		lotters.push_back(Lotter(redBall,greenBall,ddate));
	}
}

QList<TrueFormula*> ExtractUtils::getFromQuery(QSqlQuery query)
{
	QList<TrueFormula*> vec;
	while (query.next())
	{
		auto d1 = query.value(0).toString();
		auto d2 = query.value(1).toInt();
		auto d3 = query.value(2).toInt();
		auto d5 = query.value(4).toInt();
		auto d6 = query.value(5).toInt();
		if (query.value(1).isNull())
		{
			vec.push_back(TrueFormula::createBy3V(d1, d5, d6));
		}
		else
		{
			vec.push_back(TrueFormula::createBy5V(d1, d5, d6, d2, d3));
		}
	}
	return vec;
}

QList<TrueFormula*> ExtractUtils::getAllFormula()
{
	return getFromQuery(_sqlUT->excuteCall("getAllFormula()"));
}
