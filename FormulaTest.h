#ifndef __FormulaTest__
#define __FormulaTest__
#include "Formula.h"
#define _formulaTest FormulaTest::getInstance()

class FormulaTest{
public:
	bool TestFormula(Element*);
	void TestFormula(int);

	void TestValue(QString);
public:
	static FormulaTest* getInstance();
private:
	static FormulaTest* _instance;
};
#endif
