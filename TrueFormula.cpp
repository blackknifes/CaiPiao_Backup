#include "TrueFormula.h"
#include "CustomDefine.h"
#include "mainwindow.h"
#include "ValueModelBase.h"
#include "MysqlUtils.h"

TrueFormula::TrueFormula(Element* ele) 
	:_min(-1), _max(-1), max_continue(-1), recent_continue(-1),
	lotter_list(&MainWindow::allLotters), _index(&MainWindow::currentListIndex)
{
	this->_formula = dynamic_cast<Formula*>(ele);
}

TrueFormula::~TrueFormula()
{
	SAFE_DELETE(_formula);
}

TrueFormula* TrueFormula::RandGenerate(int number)
{
	auto ele = Formula::RandGenerate(number);
	TrueFormula* tf = new TrueFormula(ele);
	return tf;
}

QList<TrueFormula*> TrueFormula::RandGenerate(int number, int numberFormula)
{	
	QList<TrueFormula*> formule_list;

	for (size_t i = 0; i < numberFormula; i++)
	{
		while (true)
		{
			auto ele = TrueFormula::RandGenerate(number);
			if (ele->isLegal())
			{
				formule_list.push_back(ele);
				break;
			}
			else
			{
				SAFE_DELETE(ele);
			}
		}

	}

	return formule_list;
}

int TrueFormula::getMin()
{
	if (_min == -1)
	{
		_formula->Calculate(Element::DataMin);
		_min = _formula->getValue();
	}

	return _min;
}

int TrueFormula::getMax()
{
	if (_max == -1)
	{
		_formula->Calculate(Element::DataMax);
		_max = _formula->getValue();
	}
	return _max;
}

int TrueFormula::getValue()
{
	_formula->Calculate(Element::DataNormal);
	return _formula->getValue();
}

bool TrueFormula::isLegal()
{
	if (getMin() > 0 && getMax() > 0 && getMax() - getMin() >= 33 && getMax() - getMin() <= 99999)
	{
		return true;
	}
	return false;
}

bool TrueFormula::releaseThis()
{
	delete this;
	return true;
}

TrueFormula* TrueFormula::CreateByString(QString text)
{
	Formula* ret = new Formula(text);
	ret->Parse();
	return new TrueFormula(ret);
}

QString TrueFormula::getText()
{
	return _formula->getText();
}

bool TrueFormula::CompareFormula(TrueFormula* tf)
{
	if (getText().compare(tf->getText()))
	{
		return true;
	}
	return false;
}

int TrueFormula::getRedBall()
{
	return getValue() % 33 + 1;
}

int TrueFormula::getGreenBall()
{
	return getValue() % 16 + 1;
}

TrueFormula* TrueFormula::createBy3V(QString text, int max_value, int min_value)
{
	auto ret = TrueFormula::CreateByString(text);
	ret->_max = max_value;
	ret->_min = min_value;
	return ret;
}

TrueFormula* TrueFormula::createBy5V(QString text, int max_value, int min_value, int max_continue, int recent_continue)
{
	auto ret = TrueFormula::createBy3V(text, max_value, min_value);
	ret->max_continue = max_continue;
	ret->recent_continue = recent_continue;
	return ret;
}

FormulaList* FormulaList::RandGenerate(int number, int numberFormula)
{
	FormulaList* fl = new FormulaList();
	fl->_list = TrueFormula::RandGenerate(number, numberFormula);
	return fl;
}

void FormulaList::push_back(QString text)
{
	_list.push_back(TrueFormula::CreateByString(text));
}

FormulaList* FormulaList::GenerateFromFile()
{
	FormulaList* fl = new FormulaList();

	QFile file(MainWindow::genPath+"FormulaList.txt");
	qDebug() << (MainWindow::genPath + "FormulaList.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Can't open the file!" << endl;
		SAFE_DELETE(fl);
		return nullptr;
	}
	QTextStream in(&file);
	QString in_text = in.readAll();
	file.close(); 
	
	if (in_text.isEmpty())
	{
		SAFE_DELETE(fl);
		return nullptr;
	}

	QList<QString> split_text = in_text.split(',');
	for (auto& obj: split_text)
	{
		fl->push_back(obj);
	}

	return fl;
}

void FormulaList::writeToFile()
{
	QFile file(MainWindow::genPath + "FormulaList.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		qDebug() << "Can't open the file!" << endl;
	}

	QTextStream out(&file);

	QString out_text = "";
	for (auto& obj: _list)
	{
		out_text.append(',');
		out_text.append(obj->getText());
	}

	out_text.remove(0, 1);
	out << out_text;
	file.close();
}

void FormulaList::addList(FormulaList* list)
{
	for (auto& obj: list->_list)
	{
		if (!containsByText(obj))
		{
			_list.push_back(obj);
		}
	}
//	list->releaseOnly();
}

bool FormulaList::containsByText(TrueFormula* formula)
{
	for (auto& obj: _list)
	{
		if (obj->getText() == formula->getText())
		{
			return true;
		}
	}
	return false;
}

void FormulaList::releaseOnly()
{
	delete this;
}

void FormulaList::releaseAll()
{
	for (auto& obj : _list)
	{
		obj->releaseThis();
	}
	delete this;
}

FormulaList::FormulaList()
{
	int tmp_Count = _sqlUT->excuteFunc("getCountFormula()");
	PageCount = tmp_Count / 100;
	CurrentPage = 0;
}
