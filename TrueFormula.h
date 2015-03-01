#ifndef __TrueFormula__
#define __TrueFormula__
#include "Formula.h"
#include <QtCore>

struct Lotter;

class TrueFormula{
public:
	static TrueFormula* RandGenerate(int);
	static QList<TrueFormula*> RandGenerate(int, int);
	static TrueFormula* CreateByString(QString);
	static TrueFormula* createBy3V(QString, int, int);
	static TrueFormula* createBy5V(QString, int, int, int, int);


	int getMax();
	int getMin();
	int getValue();
	QString getText();

	int getRedBall();
	int getGreenBall();
	
	bool isLegal();
	bool CompareFormula(TrueFormula*);

	bool releaseThis();

	inline int getRecentContinue() const { return recent_continue; }
	inline int getMaxContinue() const { return max_continue; }
private:
	TrueFormula(Element*);
	~TrueFormula();
	Formula* _formula;
	int _min, _max;
	const QList<Lotter>* const lotter_list;
	int* const _index;

	int max_continue, recent_continue;
};

class FormulaList{
public:
	FormulaList();
	static FormulaList* RandGenerate(int,int);
	static FormulaList* GenerateFromFile();
	void push_back(QString);
	inline int size(){ return _list.size(); };
	inline TrueFormula* get(int index){ return _list.at(index); };
	
	void writeToFile();
	QList<TrueFormula*> getList(){ return _list; };

	void releaseAll();
	void releaseOnly();

	void addList(FormulaList*);
	bool containsByText(TrueFormula*);
private:
	~FormulaList(){};
	QList<TrueFormula*> _list;
	int PageCount;
	int CurrentPage;
};

#endif
