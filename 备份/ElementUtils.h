#ifndef __ElementUtils__
#define __ElementUtils__
#include <QtCore>
#include "CustomDefine.h"

#define _ElementUtils ElementUtils::getInstance()
class Element;
class FormulaBase;
class Formula;
class MathSignal;
class MathSignal_1;
class MathSignal_2;
class MathSignal_3;
class MathSignal_4;
class MathNumber;
class LotterTag;

class ElementUtils{
public:
	static ElementUtils* getInstance();
private:
	static ElementUtils* _instance;

public://¹¤¾ßº¯Êý
	Element* getFirstElement(QString, Formula*);
	bool nextElement(QString, int&, Formula*);
	Formula* nextFormula(QString, int&, Formula*);
	MathSignal* nextMathSignal(QString,int&,Formula*);
	MathNumber* nextMathNumber(QString, int&, Formula*);
	LotterTag* nextLotterTag(QString,int&,Formula*);

private:
	Formula_Type judgeCharType(QChar);
	bool judgeContainsVector(QString,QVector<QString>);
	int SearchIndexFirst(QString,QVector<QString>,int);

};

#define Type_Judge(A) judgeCharType(text.at(index))!=A
#define Type_Judge_Index(A,B) judgeCharType(text.at(B))!=A
#define Type_Judge_Char(A,B) judgeCharType(B)!=A

#define Loop_If	tmp_index < text.length() && tmp_index > -1
#endif
