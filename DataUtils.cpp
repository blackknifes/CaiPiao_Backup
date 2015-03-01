#include "DataUtils.h"
#include <fstream>
#include <windows.h>
#include "Formula.h"
#include <QDebug>


DataUtils* DataUtils::_dataUtils = nullptr;
QVector<QString> DataUtils::_MathNumber = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
QVector<QString> DataUtils::_MathSignal = { "+", "-", "*", "/", "%", "^" };

const char* DataUtils::GB2312ToUTF8(const char* gb2312){
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

int DataUtils::QStringContains(QString text, QString _ptr, int index1, int index2)
{
	int sum = 0;

	int rollback_index = index1;

	while (rollback_index != -1 && rollback_index < index2 && rollback_index >= index1)
	{
		rollback_index = text.indexOf(_ptr, rollback_index + 1);
		if (rollback_index != -1 && rollback_index < index2)
		{
			sum++;
		}
	}

	return sum;
}

int DataUtils::SearchIndexByString(QString text, QString _ptr, int _begin, int _count)
{
	int search_begin = _begin;
	for (size_t i = 0; i < _count; i++)
	{
		search_begin = text.indexOf(_ptr, search_begin + 1);
		if (search_begin == -1)
		{
			return -1;
		}
	}

	return search_begin;
}

DataUtils* DataUtils::getInstance()
{
	if (_dataUtils == nullptr)
	{
		_dataUtils = new DataUtils();
	}
	return _dataUtils;
}



// Element* DataUtils::NextElement(QString in_text, Element* ele, FormulaBase* formula)
// {
// 	int begin_index = ele->getEndIndex() + 1;
// 	if (begin_index >= in_text.length())
// 	{
// 		ele->linkEnd();
// 		return nullptr;
// 	}
// 
// 	if (FormulaBase* ret = getNextFormula(in_text,begin_index,formula))
// 	{
// 		ele->linkRight(ret);
// 		ele->set_parent(formula);
// 		qDebug() << "next formula!!";
// 		return ret;
// 	}
// 	else if (MathElement* ret = getNextNumber(in_text, begin_index))
// 	{
// 		ele->linkRight(ret);
// 		ele->set_parent(formula);
// 		return ret;
// 	}
// 	else if (MathSignal* ret = getNextSignal(in_text, begin_index)){
// 		ele->linkRight(ret);
// 		ele->set_parent(formula);
// 		return ret;
// 	}
// 
// 	return nullptr;
// 	
// }
// 
// MathElement* DataUtils::getNextNumber(QString text, int& begin)
// {
// 	if (!_MathNumber.contains(text.at(begin)))
// 	{
// 		return nullptr;
// 	}
// 	QString out_text = "";
// 	int be = begin;
// 	while (_MathNumber.contains(text.at(begin)))
// 	{
// 		out_text.append(text.at(begin));
// 		begin++;
// 		if (begin >= text.length())
// 		{
// 			break;
// 		}
// 	}
// 
// 
// 	MathElement* ret = new MathElement(out_text);
// 	
// 	ret->setLen(be, begin - 1);
// 
// 	return ret;
// }
// 
// FormulaBase* DataUtils::getNextFormula(QString text, int& begin,FormulaBase* _parent)
// {
// 	if (text.at(begin) != '('
// 		&& text.mid(begin, begin + 4) != "abs:"
// 		&& text.mid(begin, begin + 5) != "sqrt:")
// 	{
// 		return nullptr;
// 	}
// 	FormulaBase::special_signal type = FormulaBase::noHave;
// 	if (text.mid(begin, begin + 4) == "abs:")
// 	{
// 		type = FormulaBase::abs_signal;
// 		begin += 4;
// 	}
// 
// 	if (text.mid(begin, begin + 5) == "sqrt:")
// 	{
// 		type = FormulaBase::sqrt_signal;
// 		begin += 5;
// 	}
// 	int be = begin;
// 	QVector<QString> tmpVec = MatchParentheses(begin, text);
// 
// 	QString out_text = tmpVec.at(0);
// 	
// 	begin += out_text.length() + 2;
// 	qDebug() << out_text;
// 	FormulaBase* ret = new FormulaBase(out_text);
// 
// 	if (_parent != nullptr)
// 	{
// 		_parent->AddFormula(ret);
// 	}
// 
// 	ret->setPreType(type);
// 	ret->setLen(be, begin-1);
// 
// 	return ret;
// }
// 
// MathSignal* DataUtils::getNextSignal(QString text, int& begin)
// {
// 	if (!_MathSignal.contains(text.at(begin)))
// 	{
// 		return nullptr;
// 	}
// 	MathSignal* ret = new MathSignal(text.at(begin++));
// 	ret->setLen(begin-1, begin-1);
// 	return ret;
// }

QVector<QString> DataUtils::MatchParentheses(int begin, QString text)
{
	QVector<QString> out;
	int index_1 = text.indexOf('(', begin);
	int index_2 = text.indexOf(')', index_1);
	int num_left = _DataUtils->QStringContains(text, "(", index_1, index_2);
	int num_right = _DataUtils->QStringContains(text, ")", index_1, index_2);

	while (index_1 != -1)
	{
		while (num_left != num_right)
		{
			index_2 = _DataUtils->SearchIndexByString(text, ")", index_1, num_left + 1);
//			qDebug() << num_left << num_right << index_2;

			num_left = _DataUtils->QStringContains(text, "(", index_1, index_2);
			num_right = _DataUtils->QStringContains(text, ")", index_1, index_2);
		}
		out.push_back(text.mid(index_1 + 1, index_2 - index_1 - 1));
		index_1 = text.indexOf('(', index_2);
		index_2 = text.indexOf(')', index_1);
		num_left = _DataUtils->QStringContains(text, "(", index_1, index_2);
		num_right = _DataUtils->QStringContains(text, ")", index_1, index_2);
	}

	return out;
}

int DataUtils::squareInt(int, int right)
{
	int end = 1;
	for (size_t i = 1; i <= right; i++)
	{
		end *= right;
	}
	return end;
}

// void DataUtils::parseFormula(QString in, FormulaBase* object)
// {	
// 
// 	int begin_index = 0;
// 	Element* begin_element = getFirstElement(in, begin_index,object);
// 	object->setBeginElement(begin_element);
// 	Element* ret = begin_element;
// 	qDebug() << ret->getText();
// 	while ((ret = NextElement(in, ret, object))!=nullptr)
// 	{
// 		qDebug() << ret->getText() << ret->getType();
// 	}
// 
// }
// 
// Element* DataUtils::getFirstElement(QString in_text, int& index,FormulaBase* _parent)
// {
// 	if (FormulaBase* ret = getNextFormula(in_text, index, _parent))
// 	{
// 		ret->set_parent(_parent);
// 		ret->linkStart();
// 		return ret;
// 	}
// 	else if (MathElement* ret = getNextNumber(in_text, index))
// 	{
// 		ret->set_parent(_parent);
// 		ret->linkStart();
// 		return ret;
// 	}
// 	else if (MathSignal* ret = getNextSignal(in_text, index))
// 	{
// 		ret->set_parent(_parent);
// 		ret->linkStart();
// 		return ret;
// 	}
// 
// 	return nullptr;
// }
// 
// index_signal::index_signal(int begin, int end)
// {
// 	this->begin = begin;
// 	this->end = end;
// }
// 
// index_signal::index_signal()
// {
// 	begin = -1;
// 	end = -1;
// }
