#include "Formula.h"
#include "ElementUtils.h"
#include "Element.h"
#include "DebugUtils.h"
#include "ValueModelBase.h"
#include "BaseValueFactory.h"
#include "DataUtils.h"
#include "mainwindow.h"

int FormulaBase::IndexOf(Element* ele) const
{
	return formula_list.indexOf(ele);
}

void FormulaBase::push_back(Element* ele)
{
	formula_list.push_back(ele);
}

void FormulaBase::insertEle(Element* ele, int index)
{
	formula_list.insert(index, ele);
}

void FormulaBase::removeEle(int index)
{
	_debugUtils->isOutRange(formula_list, index, "FormulaBase::removeEle",FILE_LINE);
	formula_list.removeAt(index);
}

void FormulaBase::removeEle(Element* ele)
{
	formula_list.removeOne(ele);
}

Element* FormulaBase::at(int index) const
{
	_debugUtils->isOutRange(formula_list, index, "FormulaBase::removeEle", FILE_LINE);
	return formula_list.at(index);
}

int FormulaBase::getListLength() const
{
	return formula_list.length();
}

bool FormulaBase::isEmpty() const
{
	return formula_list.isEmpty();
}

void FormulaBase::clear()
{
	SAFE_DELETE_VEC(formula_list);
}

bool FormulaBase::containsEle(Element* ele) const
{
	return formula_list.contains(ele);
}


QString Formula::getText() const
{
	QString out = "";

	for (auto obj: getList())
	{
		QString _append = obj->getText();
		if (typeid(*obj) == typeid(Formula))
		{
			_append.push_front('(');
			_append.push_back(')');
		}
		out.append(_append);
	}

	if (out.isEmpty())
	{
		out = Element::getText();
	}
	
	return out;
}

void Formula::Parse()
{
	int index = 0;

	while (_ElementUtils->nextElement(Element::getText(), index, this));

	for (auto& obj: getList())
	{
		obj->Parse();	
	}

}

void Formula::setHighestParent()
{
	_parent = nullptr;
}

void MathSignal::MergeLeft(int index)
{
	QString out = "";
	for (auto&obj : getParent()->CalculatePoor)
	{
		out.append(obj->getText());
	}
	//qDebug() << "merge l:" << getText() << index << getParent()->CalculatePoor.size() << out + " : " + getParent()->getText();
	auto& vec = getParent()->CalculatePoor;
	//qDebug() << "at :" << index - 1;

	_debugUtils->isOutRange(vec, index - 1, "FormulaBase::removeEle", FILE_LINE);
	Element* left = vec.at(index - 1);
	vec.removeAt(index - 1);
	vec.removeAt(index - 1);
	if (!getParent()->containsEle(left))
	{
		SAFE_DELETE(left);
	}
	auto ret = new MathNumber(QString::number(getValue()));
	ret->setParentDetach(getParent());
	ret->Calculate(DataNormal);
	vec.insert(index - 1, ret);
}

void MathSignal::MergeRight(int index)
{
	QString out = "";
	for (auto&obj:getParent()->CalculatePoor)
	{
		out.append(obj->getText());
	}
	auto& vec = getParent()->CalculatePoor;
	_debugUtils->isOutRange(vec, index + 1, "FormulaBase::removeEle", FILE_LINE);
	Element* right = vec.at(index + 1);

	ADD_INFO(getText() + right->getText() + "=" + QString::number(getValue()));

	vec.removeAt(index);
	vec.removeAt(index);
	if (!getParent()->containsEle(right))
	{
		SAFE_DELETE(right);
	}
	auto ret = new MathNumber(QString::number(getValue()));
	ret->setParentDetach(getParent());
	ret->Calculate(DataNormal);
	vec.insert(index, ret);
}

void MathSignal::MergeDouble(int index)
{
	QString out = "";
	for (auto&obj : getParent()->CalculatePoor)
	{
		out.append(obj->getText());
	}
	//qDebug() << "merge d:" << getText() << index << getParent()->CalculatePoor.size() << out + " : " + getParent()->getText();
	auto& vec = getParent()->CalculatePoor;

	//qDebug() << "at :" << index -1;

	_debugUtils->isOutRange(vec, index -1, "FormulaBase::removeEle", FILE_LINE);
	Element* left = vec.at(index - 1);
	_debugUtils->isOutRange(vec, index, "FormulaBase::removeEle", FILE_LINE);
	Element* right = vec.at(index + 1);



	ADD_INFO(left->getText() + getText() + right->getText() + "=" + QString::number(getValue()));

	vec.removeAt(index - 1);
	vec.removeAt(index - 1);
	vec.removeAt(index - 1);
	if (!getParent()->containsEle(left))
	{
		SAFE_DELETE(left);
	}
	if (!getParent()->containsEle(right))
	{
		SAFE_DELETE(right);
	}
	auto ret = new MathNumber(QString::number(getValue()));
	ret->setParentDetach(getParent());

	ret->Calculate(DataNormal);
	vec.insert(index - 1, ret);
}

void MathNumber::Calculate(DataType)
{
	setValue(getText().toInt());
}

Element* MathNumber::RandGenerate()
{
	int value = ValueModelBase::getRand(1, 100);
	return new MathNumber(QString::number(value));
}

void Formula::CalcualteByPriorty(int priorty,DataType type)
{	

	for (auto& obj: CalculatePoor)
	{
		if (obj->getPriority() == priorty)
		{
			obj->Calculate(type);
		}
	}


}


void Formula::clearCalculatePoor()
{
	for (auto& obj : CalculatePoor)
	{
		if (!getList().contains(obj))
		{
			SAFE_DELETE(obj);
		}
	}
	CalculatePoor.clear();
}


void Formula::Calculate(DataType type)
{
	CalculatePoor = getList();

	for (size_t i = 0; i <= MaxPrority; i++)
	{
		CalcualteByPriorty(i,type);
	}
	
	_debugUtils->isOutRange(CalculatePoor, 0, "FormulaBase::removeEle", FILE_LINE);
	setValue(CalculatePoor.at(0)->getValue());
	clearCalculatePoor();
}

Element* Formula::RandGenerate(int number){
	Formula* ret = new Formula();

	int tmp = ValueModelBase::getRand(0, 48);
	_debugUtils->isOutRange(LotterTag::getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	BaseValueFactory::createLotterTag(LotterTag::getSignal().at(tmp), ret);

	bool bulidTag = false;
	if (ValueModelBase::getRand(0, number) >= 3)
	{
		if (ValueModelBase::getRand(0, 10) > 6)
		{
			bulidTag = true;
		}
	}



	for (size_t i = 0; i < number - 1; i++)
	{
		if (bulidTag && number - 1 - i > 3)
		{
			int tmp = ValueModelBase::getRand(i, number - 1);
			if (RandGenerate(tmp, ret))
			{
				i += tmp;
			}
			
		}
		LotterTag::RandGenerate(ret);
	}

	return ret;
}

Element* Formula::RandGenerate(int number, Formula* parent)
{
	if (number <= 1)
	{
		return nullptr;
	}

	Formula* ret = new Formula();

	int tmp = ValueModelBase::getRand(0, 48);
	_debugUtils->isOutRange(LotterTag::getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	BaseValueFactory::createLotterTag(LotterTag::getSignal().at(tmp), ret);

	bool bulidTag = false;
	if (ValueModelBase::getRand(0, number) >= 3)
	{
		if (ValueModelBase::getRand(0, 10) > 6)
		{
			bulidTag = true;
		}
	}

	for (size_t i = 0; i < number - 2; i++)
	{
		if (bulidTag && i < number - 3)
		{
			int tmp = ValueModelBase::getRand(3, number - 1);
			if (Formula::RandGenerate(tmp, ret))
			{
				i += tmp;
			}
		}
		LotterTag::RandGenerate(ret);
		
	}

	ret->setParent(parent);

	if (parent != nullptr)
	{
		MathSignal::RandGenerate(ret);
	}

	return ret;
}

void MathSignal_1::Calculate(DataType type)
{
	int index = getParent()->CalculatePoor.indexOf(this,0);
	auto rightEle = getRightEleFromPoor();

	rightEle->Calculate(Element::DataMin);
	int minvalue = rightEle->getValue();

	
	rightEle->Calculate(Element::DataMax);
	int maxvalue = rightEle->getValue();

	rightEle->Calculate(type);
	int rightValue = rightEle->getValue();

	

	if (getText()=="abs:" )
	{
		switch (type)
		{
		case Element::DataMin:
			setValue(std::min(abs(minvalue),abs(maxvalue)));
			break;
		case Element::DataNormal:
			setValue(abs(rightValue));
			break;
		case Element::DataMax:
			setValue(std::max(abs(minvalue), abs(maxvalue)));
			break;
		default:
			break;
		}
		MergeRight(index);
	}
	else if (getText()==MathSignal_1::getSignal().at(1))
	{
		if (rightValue <= 0)
		{
			setValue(0);
		}
		else
		{
			setValue(sqrt(rightValue));
		}
		MergeRight(index);
	}
}

Element* MathSignal_1::RandGenerate(Formula* parent){
	auto ret = RandGenerate();
	ret->setParent(parent);
	return ret;
}

Element* MathSignal_1::RandGenerate()
{
	int i = ValueModelBase::getRand(0, 1);

	_debugUtils->isOutRange(MathSignal_1::getSignal(), i, "FormulaBase::removeEle", FILE_LINE);
	return new MathSignal_1(MathSignal_1::getSignal().at(i));
}

void MathSignal_2::Calculate(DataType type)
{
	int index = getParent()->CalculatePoor.indexOf(this);

	auto LeftEle = getLeftEleFromPoor();
	auto RightEle = getRightEleFromPoor();

	LeftEle->Calculate(Element::DataMin);
	LeftEle->Calculate(Element::DataMax);

	RightEle->Calculate(Element::DataMin);
	RightEle->Calculate(Element::DataMax);

	LeftEle->Calculate(type);
	RightEle->Calculate(type);
	int rightValue = RightEle->getValue();
	int leftValue = LeftEle->getValue();

	if (getText() == "%")
	{
		switch (type)
		{
		case Element::DataMin:
			setValue(0);
			break;
		case Element::DataNormal:
			setValue(leftValue % rightValue);
			break;
		case Element::DataMax:
			setValue(rightValue - 1);
			break;
		default:
			break;
		}
		MergeDouble(index);
	}else if (getText() == "^")
	{
		int tmp = _DataUtils->squareInt(leftValue, rightValue);
		setValue(tmp);
		MergeDouble(index);
	}
	//qDebug() << "Math_2" << getValue();
}

Element* MathSignal_2::RandGenerate(Formula* parent)
{
	auto ret = RandGenerate();
	ret->setParent(parent);
	return ret;
}

Element* MathSignal_2::RandGenerate()
{
	int tmp = ValueModelBase::getRand(0, 1);

	//qDebug() << "at :" << tmp;
	_debugUtils->isOutRange(getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	return new MathSignal_2(getSignal().at(tmp));
}

void MathSignal_3::Calculate(DataType type)
{
	int index = getParent()->CalculatePoor.indexOf(this);

	auto LeftEle = getLeftEleFromPoor();
	auto RightEle = getRightEleFromPoor();

	RightEle->Calculate(DataMin);
	int minvalue = RightEle->getValue();
	RightEle->Calculate(Element::DataMax);
	int maxvalue = RightEle->getValue();

	LeftEle->Calculate(type);
	RightEle->Calculate(type);
	int rightValue = RightEle->getValue();
	int leftValue = LeftEle->getValue();

	if (getText() == "*")
	{
		setValue(leftValue * rightValue);
		MergeDouble(index);
	}
	else if (getText() == "/")
	{
		if (rightValue == 0)
		{
			setValue(leftValue);
			MergeDouble(index); 
			return;
		}
		switch (type)
		{
		case Element::DataMin:
			setValue(leftValue / maxvalue);
			break;
		case Element::DataNormal:
			setValue(leftValue / rightValue);
			break;
		case Element::DataMax:
			setValue(leftValue / minvalue);
			break;
		default:
			break;
		}
		MergeDouble(index);
	}
	//qDebug() << "Math_3" << getValue();
}

Element* MathSignal_3::RandGenerate(Formula* parent)
{
	auto ret = RandGenerate();
	ret->setParent(parent);
	return ret;
}

Element* MathSignal_3::RandGenerate()
{
	int tmp = ValueModelBase::getRand(0, 1);
	//qDebug() << "at :" << tmp;

	_debugUtils->isOutRange(getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	return new MathSignal_3(getSignal().at(tmp));
}

void MathSignal_4::Calculate(DataType type)
{
	int index = getParent()->CalculatePoor.indexOf(this);
	
	auto LeftEle = getLeftEleFromPoor();
	auto RightEle = getRightEleFromPoor();

	RightEle->Calculate(DataMin);
	int minvalue = RightEle->getValue();
	RightEle->Calculate(Element::DataMax);
	int maxvalue = RightEle->getValue();

	LeftEle->Calculate(type);
	RightEle->Calculate(type);
	int rightValue = RightEle->getValue();
	int leftValue = LeftEle->getValue();

	if (getText() == "+")
	{
		setValue(leftValue + rightValue);
		//qDebug() << "Math_4" << getValue();
		MergeDouble(index);
	}
	else if (getText() == "-")
	{
		switch (type)
		{
		case Element::DataMin:
			setValue(leftValue - maxvalue);
			break;
		case Element::DataNormal:
			setValue(leftValue - rightValue);
			break;
		case Element::DataMax:
			setValue(leftValue - minvalue);
			break;
		default:
			break;
		}
		//qDebug() << "Math_4" << getValue();
		MergeDouble(index);
	}
	
}

Element* MathSignal_4::RandGenerate(Formula* parent)
{
	auto ret = RandGenerate();
	ret->setParent(parent);
	return ret;
}

Element* MathSignal_4::RandGenerate()
{
	int tmp = ValueModelBase::getRand(0, 1);
	//qDebug() << "at :" << tmp;
	_debugUtils->isOutRange(getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	return new MathSignal_4(getSignal().at(tmp));
}

Element* LotterTag::RandGenerate(Formula* parent)
{
	int tmp = ValueModelBase::getRand(0, 48);

	//qDebug() << "at :" << tmp;
	_debugUtils->isOutRange(getSignal(), tmp, "FormulaBase::removeEle", FILE_LINE);
	auto vmb = dynamic_cast<ValueModelBase*>(BaseValueFactory::createLotterTag(getSignal().at(tmp), parent));
	MathSignal::RandGenerate(vmb);

	return vmb;
}

void LotterTag::Calculate(DataType type)
{
	switch (type)
	{
	case Element::DataMin:
		setValue(getMinValue());
		break;
	case Element::DataNormal:
		setValue(getValue(MainWindow::currentListIndex));
		break;
	case Element::DataMax:
		setValue(getMaxValue());
		break;
	default:
		break;
	}
}


Element* MathSignal::RandGenerate(Element* ele)
{
	Element* leftEle = ele->getLeftElement();

	leftEle->Calculate(Element::DataMin);
	int lmin = leftEle->getValue();
	leftEle->Calculate(Element::DataMax);
	int lmax = leftEle->getValue();

	ele->Calculate(Element::DataMin);
	int min_value = ele->getValue() ;
	ele->Calculate(Element::DataMax);
	int max_value = ele->getValue();

	int ran = ValueModelBase::getRand(1, 10);

	Element* ele1 = nullptr;
	Element* ele2 = nullptr;
	if (min_value > 0 && max_value > 0)
	{
		if (ran > 8 && lmin > 0 && lmax > 0)
		{
			ele2 = MathSignal_2::RandGenerate();
		}
		else if (ran > 5 && ran <= 8)
		{
			ele2 = MathSignal_3::RandGenerate();
		}
		else
		{
			ele2 = MathSignal_4::RandGenerate();
		}
	}
	else if (min_value < 0 && max_value > 0 || min_value == 0 || max_value == 0)
	{
		if (ran > 7)
		{
			ele2 = new MathSignal_3("*");
		}
		else
		{
			ele2 = MathSignal_4::RandGenerate();
		}
	}
	else
	{
		if (ran > 7)
		{
			ele2 = MathSignal_3::RandGenerate();
		}
		else
		{
			ele2 = MathSignal_4::RandGenerate();
		}
	}

	ele2->insertBefore(ele);

	if (ValueModelBase::getRand(1, 10) > 8)
	{
		ele1 = new MathSignal_1(MathSignal_1::getSignal().at(1));
		ele1->insertLast(ele2);
	}

	if (min_value < 0)
	{
		ele1 = new MathSignal_1("abs:");
		ele1->insertLast(ele2);
	}

	return ele2;
}
