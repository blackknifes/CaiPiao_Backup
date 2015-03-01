#include "FormulaTest.h"
#include "mainwindow.h"
#include "DebugUtils.h"
#include "Formula.h"
#include "ValueModelBase.h"
#include "BaseValueFactory.h"

FormulaTest* FormulaTest::_instance = nullptr;

FormulaTest* FormulaTest::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new FormulaTest();
	}
	return _instance;
}

bool FormulaTest::TestFormula(Element* formula)
{
	bool end = true;

	formula->Calculate(Element::DataMin);
	int minValue = formula->getValue();
	formula->Calculate(Element::DataMax);
	int maxValue = formula->getValue();

	const QList<Lotter>* const lotter_list = &MainWindow::allLotters;
	
	for (size_t i = 0; i < lotter_list->size(); i++)
	{
		MainWindow::currentListIndex = i;
		formula->Calculate(Element::DataNormal);
		int value = formula->getValue();
		
		

		if (value < minValue || value > maxValue)
		{
			qDebug() << value;
			qDebug() << "value out of range!  :" + formula->getText();
			ADD_ERROR(formula->getText());
			ADD_ERROR(QString::number(value) + "value out of range!  " + QString::number(minValue)+"/"+QString::number(maxValue));

			auto fff = dynamic_cast<Formula*>(formula);
			for (auto obj : fff->getList())
			{
				if (auto oo = dynamic_cast<LotterTag*>(obj))
				{
					int objValue = oo->getValue(i);
					if (objValue<oo->getMinValue() || objValue>oo->getMaxValue())
					{
						ADD_OUT("testOut","over range"+oo->getText()+":"+QString::number(objValue)+" "+QString::number(oo->getMinValue())+" "+QString::number(oo->getMaxValue()));
					}
				}
				
			}

		}
	}
	

	return end;
}

void FormulaTest::TestValue(QString tag)
{
	QList<Lotter> lotter;
	
	for (size_t i = 0; i < 99999; i++)
	{
		QList<int> redBall;
		while (redBall.size() != 6)
		{
			int ball = ValueModelBase::getRand(1, 33);
			if (!redBall.contains(ball))
			{
				redBall.push_back(ball);
			}
		}
		Lotter lo(redBall, 4,QDate(2010,1,20));
		lotter.push_back(lo);
	}

	auto ele = dynamic_cast<ValueModelBase*>(BaseValueFactory::createLotterTag(tag, nullptr));
	
	ele->lotter_list = &lotter;

	int minV = ele->getMinValue();
	int maxV = ele->getMaxValue();
	ele->Calculate(Element::DataNormal);
	QList<int> outrange;
	for (auto obj: lotter)
	{
		int value = ele->getValue(obj);	
		if (value < minV || value > maxV)
		{
			ADD_OUT("TestValue", tag+"  :" + QString::number(value) + " :" + QString::number(minV) + "  " + QString::number(maxV));
			outrange.push_back(value);
		}
	}

	int maxError = -1;
	int minError = -1;
	if (!outrange.isEmpty())
	{
		maxError = ValueModelBase::getMax(outrange);
		minError = ValueModelBase::getMin(outrange);
	}
	ADD_OUT("TestValueEnd", tag+" outMax:" + QString::number(maxError) + "outMin:" + QString::number(minError));

}

void FormulaTest::TestFormula(int number)
{

	for (size_t i = 0; i < 500; i++)
	{
		QList<int> redBall;
		while (redBall.size() != 6)
		{
			int ball = ValueModelBase::getRand(1, 33);
			if (!redBall.contains(ball))
			{
				redBall.push_back(ball);
			}
		}
		Lotter lo(redBall, 4, QDate(2010, 1, 20));
		MainWindow::allLotters.push_back(lo);
	}

	Element* formula[160];

	QList<int> balls;
	
	for (auto& obj: formula)
	{
		obj = Formula::RandGenerate(number);
		obj->Calculate(Element::DataMin);
		int minValue = obj->getValue();
		obj->Calculate(Element::DataMax);
		int maxValue = obj->getValue();
		obj->Calculate(Element::DataNormal);
		int normalValue = obj->getValue();

		ADD_INFO(obj->getText() + "  :" + QString::number(normalValue) + " :" + QString::number(minValue) + "  " + QString::number(maxValue));
		
		if (normalValue < minValue || normalValue > maxValue)
		{
			ADD_OUT("TestValue", obj->getText() + "  :" + QString::number(normalValue) + " :" + QString::number(minValue) + "  " + QString::number(maxValue));
		}

		if (normalValue > 0)
		{
			normalValue = normalValue % 33 + 1;
		}
		if (normalValue > 0 && normalValue <= 33)
		{
			balls.push_back(normalValue);
		}
		
	}
	
	for (auto& obj: balls)
	{
		ADD_OUT("OutLotter", QString::number(obj));
	}
	

}
