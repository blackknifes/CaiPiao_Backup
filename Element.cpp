#include "Element.h"
#include "Formula.h"

Element::Element(){ _parent = nullptr; init(); }

Element::Element(QString text){ _text = text; _parent = nullptr; init(); }

Element::Element(QString text, Formula* parent)
{
	_text = text;
	setParent(parent);
	init();
}

Element* Element::getLeftElement() const{
	int index = _parent->IndexOf(const_cast<Element*>(this)) - 1;
	if (index>=0)
	{
		return _parent->at(index);
	}
	return nullptr;
}

Element* Element::getRightElement() const{
	int index = _parent->IndexOf(const_cast<Element*>(this)) + 1;
	if (index<_parent->getListLength())
	{
		return _parent->at(index);
	}
	return nullptr;
}

void Element::setParent(Formula* val)
{
	_parent = val; 
	if (val != nullptr)
	{
		if (!val->containsEle(this)){
			val->push_back(this);
		}
	}
}

void Element::setParentDetach(Formula* val)
{
	_parent = val;
}

void Element::insertBefore(Element* ele)
{
	int index = ele->getParent()->IndexOf(ele);
	ele->getParent()->insertEle(this, index);
	setParentDetach(ele->getParent());
}

void Element::insertLast(Element* ele)
{
	int index = ele->getParent()->IndexOf(ele);
	ele->getParent()->insertEle(this, index + 1);
	setParentDetach(ele->getParent());
}

Element* Element::getLeftEleFromPoor()
{
	int index = getParent()->CalculatePoor.indexOf(this); 
	if (index - 1 < 0)
	{
		qDebug() <<"left out range"<< index << this->getText();
		qDebug() << getParent()->getText();
	}
	return getParent()->CalculatePoor.at(index - 1);
}

Element* Element::getRightEleFromPoor()
{
	int index = getParent()->CalculatePoor.indexOf(this); 
	if (index + 1 > getParent()->CalculatePoor.size() - 1)
	{
		qDebug() << "right out range" << index << this->getText();
		qDebug() << getParent()->getText();
	}
	return getParent()->CalculatePoor.at(index + 1); 
}
