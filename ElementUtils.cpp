#include "ElementUtils.h"
#include "Formula.h"
#include "DataUtils.h"
#include "BaseValueFactory.h"
#include "ValueModelBase.h"
ElementUtils* ElementUtils::_instance = nullptr;

ElementUtils* ElementUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ElementUtils();
	}
	return _instance;
}


Formula_Type ElementUtils::judgeCharType(QChar _char)
{
	if (Formula::getSignal().contains(_char))
	{
		return _formula;
	}
	else if (MathSignal_1::getSignal().contains(_char)
		|| MathSignal_2::getSignal().contains(_char)
		|| MathSignal_3::getSignal().contains(_char)
		|| MathSignal_4::getSignal().contains(_char))
	{
		return _mathSignal;
	}
	else if (MathNumber::getSignal().contains(_char))
	{
		return _mathNumber;
	}

	return _formula_unknown;
}

bool ElementUtils::judgeContainsVector(QString text,QVector<QString> vec)
{
	for (auto& obj: vec)
	{
		if (text.contains(obj))
		{
			return true;
		}
	}
	return false;
}

Element* ElementUtils::getFirstElement(QString text, Formula*)
{
	return nullptr;
}

bool ElementUtils::nextElement(QString text, int& index, Formula* parent)
{
	Element* ret = nullptr;
	if (index == -1 || index>=text.size())
		return false;
	
	if (ret = nextMathNumber(text,index,parent))
		return true;
	else if (ret = nextMathSignal(text,index,parent))
		return true;
	else if (ret = nextFormula(text, index, parent))
		return true;
	else if (ret = nextLotterTag(text,index,parent))
		return true;

	return false;
}

Formula* ElementUtils::nextFormula(QString text, int& index, Formula* parent)
{
	if (Type_Judge(_formula))
	{
		return nullptr;
	}

	QString init_text = _DataUtils->MatchParentheses(index, text).at(0);
	Formula* ret = new Formula(init_text, parent);
	index += init_text.length() + 2;

	return ret;
}

MathSignal* ElementUtils::nextMathSignal(QString text, int& index, Formula* parent)
{
	int tmp = SearchIndexFirst(text, MathSignal_1::getSignal(), index);

	MathSignal* ret = nullptr;

	if (Type_Judge(_mathSignal))
	{
		if (tmp == -1 && tmp != index)
		{
			return nullptr;
		}
		
		if (text.mid(index,4) == "abs:")
		{
			ret = new MathSignal_1("abs:", parent);
			index += 4;
			return ret;
		}
		else if (text.mid(index, 5) == "sqrt:")
		{
			ret = new MathSignal_1("sqrt:", parent);
			index += 5;
			return ret;
		}
	}

	QString _signal = text.at(index);

	if (MathSignal_2::getSignal().contains(_signal))
	{
		ret = new MathSignal_2(_signal, parent);
		index++;
	}
	else if (MathSignal_3::getSignal().contains(_signal))
	{
		ret = new MathSignal_3(_signal, parent);
		index++;
	}
	else if (MathSignal_4::getSignal().contains(_signal))
	{
		ret = new MathSignal_4(_signal, parent);
		index++;
	}

	return ret;
}

MathNumber* ElementUtils::nextMathNumber(QString text, int& index, Formula* parent)
{
	if (Type_Judge(_mathNumber))
	{
		return nullptr;
	}
	int tmp_index = index;
	QString init_text = "";

	while (Loop_If)
	{
		QChar _char = text.at(tmp_index);
		if (!MathNumber::getSignal().contains(_char))
		{
			break;
		}
		init_text.append(_char);
		tmp_index++;
	}

	
	MathNumber* ret = new MathNumber(init_text, parent);
	index = tmp_index;

	return ret;
}


LotterTag* ElementUtils::nextLotterTag(QString text, int& index, Formula* parent)
{
	int tmp_index = index;
	for (auto obj : LotterTag::getSignal())
	{
		int search_index = text.indexOf(obj,tmp_index);
		if (search_index != -1 && index == search_index)
		{
			index += obj.length();
			return BaseValueFactory::createLotterTag(obj,parent);
		}
	}

	return nullptr;
}


int ElementUtils::SearchIndexFirst(QString text, QVector<QString> vec, int)
{
	QVector<int> list_int;
	for (auto& obj: vec)
	{
		int tmp_index = text.indexOf(obj);
		if (tmp_index != -1)
		{
			list_int.push_back(tmp_index);
		}
	}
	int min = -1;

	for (auto& obj: list_int)
	{
		if (min == -1 || obj < min)
		{
			min = obj;
		}
	}

	return min;
}
