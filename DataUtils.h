#ifndef __DataUtils__
#define __DataUtils__
#include <QString>
#include <QVector>
#include "Formula.h"

class flateData;

#define _DataUtils DataUtils::getInstance()
#define TO_UTF8(A) _DataUtils->GB2312ToUTF8(A)

class DataUtils{
public:
	QVector<QString> MatchParentheses(int, QString);
	static DataUtils* getInstance();
	const char* GB2312ToUTF8(const char* gb2312);

	int QStringContains(QString,QString,int,int);
	int SearchIndexByString(QString,QString,int,int);


	Element* getFirstElement(QString,int&,FormulaBase*);

	void parseFormula(QString, FormulaBase*);
	Element* NextElement(QString, Element*, FormulaBase*);

	inline QVector<QString> getNumber() const { return _MathNumber; }
	inline QVector<QString> getSignal() const { return _MathSignal; }

	int squareInt(int,int);
public:
// 	MathElement* getNextNumber(QString,int&);
// 	FormulaBase* getNextFormula(QString,int&,FormulaBase*);
// 	MathSignal* getNextSignal(QString,int&);

	static QVector<QString> _MathNumber;
	static QVector<QString> _MathSignal;
	static DataUtils* _dataUtils;
};
#endif
