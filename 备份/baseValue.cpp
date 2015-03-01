#include "baseValue.h"
#include "mainwindow.h"
#include "DebugUtils.h"

int REDNUMBER::getValue(int lotter_index) const
{
	return getRand(1, 33);
}

int REDNUMBER::getValue(Lotter inLotter) const
{
	return getRand(1, 33);
}

int ACS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int ACS::getValue(Lotter inLotter) const
{
	QList<int> lotter = inLotter.redBall;
	int baseNumber = lotter.size();
	QList<int> reduceValue;

	for (auto& obj1 : lotter)
	{
		for (auto& obj2 : lotter)
		{
			if (obj1 > obj2)
			{
				int reduce = obj2 - obj1;
				if (!reduceValue.contains(reduce))
				{
					reduceValue.push_back(reduce);
				}

			}
		}

	}

	return reduceValue.size() - (baseNumber - 1);
}

int T::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int T::getValue(Lotter inLotter) const
{
	return getMax(inLotter.redBall);
}

int V::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int V::getValue(Lotter inLotter) const
{
	return getMin(inLotter.redBall);
}

int QGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int QGS::getValue(Lotter inLotter) const
{
	return getOddNumber(inLotter.redBall).size();
}

int OGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int OGS::getValue(Lotter inLotter) const
{
	return getEvenNumber(inLotter.redBall).size();

}

int ZGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int ZGS::getValue(Lotter inLotter) const
{
	return getPrimeNumber(inLotter.redBall).size();
}

int HGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HGS::getValue(Lotter inLotter) const
{
	return getCompositeNumber(inLotter.redBall).size();
}

int DGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int DGS::getValue(Lotter inLotter) const
{
	int number = 0;
	for (auto& obj : inLotter.redBall)
	{
		if (obj > 16)
		{
			number++;
		}
	}

	return number;
}

int XGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int XGS::getValue(Lotter inLotter) const
{
	int number = 0;
	for (auto& obj :inLotter.redBall)
	{
		if (obj <= 16)
		{
			number++;
		}
	}

	return number;
}

int JGJSH::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGJSH::getValue(Lotter inLotter) const
{
	int sum = 0;
	for (auto& obj : inLotter.redBall)
	{
		if (obj % 2 == 1)
		{
			sum += obj;
		}
	}

	return sum;
}

int JGOSH::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGOSH::getValue(Lotter inLotter) const
{
	int sum = 0;

	for (auto& obj : inLotter.redBall)
	{
		if (obj % 2 == 0)
		{
			sum += obj;
		}

	}
	return sum;
}

int HZ::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HZ::getValue(Lotter inLotter) const
{
	int sum = 0;

	for (auto& obj : inLotter.redBall)
	{
		sum += obj;
	}

	return sum;
}

int HV::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HV::getValue(Lotter inLotter) const
{
	int sum = 0;

	for (auto& obj : inLotter.redBall)
	{
		int obj_w = obj;
		sum += obj_w;
	}

	return getTailNumber(sum);
}

int JJ::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JJ::getValue(Lotter inLotter) const
{
	QList<int> in = inLotter.redBall;
	return getMax(in) - getMin(in);
}


int HQO::getValue(int lotter_index) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return hz.getValue(lotter_index) % 2 + 1;
}

int HQO::getValue(Lotter inLotter) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return hz.getValue(inLotter) % 2 + 1;
}

int HYT::getValue(int lotter_index) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return hz.getValue(lotter_index) % 3;
}

int HYT::getValue(Lotter inLotter) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return hz.getValue(inLotter) % 3;
}

int HZH::getValue(int lotter_index) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return isPrimeNumber(hz.getValue(lotter_index)) + 1;
}

int HZH::getValue(Lotter inLotter) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	return isPrimeNumber(hz.getValue(inLotter)) + 1;
}

int HDX::getValue(int lotter_index) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	if (hz.getValue(lotter_index)>16)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int HDX::getValue(Lotter inLotter) const
{
	HZ hz;
	hz.lotter_list = this->lotter_list;
	if (hz.getValue(inLotter) > 16)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int JGHVH::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGHVH::getValue(Lotter inLotter) const
{
	int sum = 0;
	for (auto& obj1 : inLotter.redBall)
	{
		sum += getTailNumber(obj1);
	}

	return sum;
}

int JGHVHH::getValue(int lotter_index) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	return !isPrimeNumber(jghvh.getValue(lotter_index));
}

int JGHVHH::getValue(Lotter inLotter) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	return !isPrimeNumber(jghvh.getValue(inLotter));
}

int JGHVHV::getValue(int lotter_index) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	if (jghvh.getValue(lotter_index) > 10)
	{
		return getTailNumber(jghvh.getValue(lotter_index));
	}

	return jghvh.getValue(lotter_index);
}

int JGHVHV::getValue(Lotter inLotter) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	if (jghvh.getValue(inLotter) > 10)
	{
		return getTailNumber(jghvh.getValue(inLotter));
	}

	return jghvh.getValue(inLotter);
}

int JGHVHDX::getValue(int lotter_index) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;

	if (jghvh.getValue(lotter_index)>16)
	{
		return 2;
	}
	return 1;
}

int JGHVHDX::getValue(Lotter inLotter) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;

	if (jghvh.getValue(inLotter) > 16)
	{
		return 2;
	}
	return 1;
}

int JGHVHJO::getValue(int lotter_index) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	return jghvh.getValue(lotter_index) % 2 + 1;
}

int JGHVHJO::getValue(Lotter inLotter) const
{
	JGHVH jghvh;
	jghvh.lotter_list = this->lotter_list;
	return jghvh.getValue(inLotter) % 2 + 1;
}

int JGTVS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGTVS::getValue(Lotter inLotter) const
{
	int end = 0;
	QList<int> lotters = inLotter.redBall;
	for (size_t i = 0; i < lotters.size(); i++)
	{
		for (size_t j = i + 1; j < lotters.size(); j++)
		{
			if (getTailNumber(lotters.at(i)) == getTailNumber(lotters.at(j)))
			{
				end++;
			}
		}

	}

	return end;
}

int JGBMJ::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGBMJ::getValue(Lotter inLotter) const
{
	QList<int> lotters = inLotter.redBall;
	QList<int> mj;
	for (size_t i = 0; i < lotters.size() - 1; i++)
	{
		mj.push_back(abs(lotters.at(i + 1) - lotters.at(i)));
	}

	return getMax(mj);
}

int JGMMJ::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int JGMMJ::getValue(Lotter inLotter) const
{
	QList<int> lotters = inLotter.redBall;
	QList<int> mj;
	for (size_t i = 0; i < lotters.size() - 1; i++)
	{
		mj.push_back(abs(lotters.at(i + 1) - lotters.at(i)));
	}
	return getMin(mj);
}

int HVYT::getValue(int lotter_index) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	return hv.getValue(lotter_index) % 3;
}

int HVYT::getValue(Lotter inLotter) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	return hv.getValue(inLotter) % 3;
}

int HVZH::getValue(int lotter_index) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	return isPrimeNumber(hv.getValue(lotter_index)) + 1;
}

int HVZH::getValue(Lotter inLotter) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	return isPrimeNumber(hv.getValue(inLotter)) + 1;
}

int HVDX::getValue(int lotter_index) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	if (hv.getValue(lotter_index)>16)
	{
		return 2;
	}
	return 1;
}

int HVDX::getValue(Lotter inLotter) const
{
	HV hv;
	hv.lotter_list = this->lotter_list;
	if (hv.getValue(inLotter) > 16)
	{
		return 2;
	}
	return 1;
}

int HVYTS0::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HVYTS0::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj % 3 == 0)
		{
			number++;
		}
	}
	return number;
}

int HVYTS1::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HVYTS1::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj % 3 == 1)
		{
			number++;
		}
	}
	return number;
}

int HVYTS2::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int HVYTS2::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj % 3 == 2)
		{
			number++;
		}
	}
	return number;
}

int LS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int LS::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	auto vec = getContinueNumber(lotters);
	for (auto& obj : vec)
	{
		number += obj.size();
	}

	return number;
}

int LZS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int LZS::getValue(Lotter inLotter) const
{
	QList<int> lotters = inLotter.redBall;
	auto vec = getContinueNumber(lotters);
	return vec.size();
}

int PD::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int PD::getValue(Lotter inLotter) const
{
	QList<int> pdNumber;
	QList<int> rencent_lotters = inLotter.redBall;

	
	int lastIndex = lotter_list->indexOf(inLotter) + 1;

	if (lastIndex >= lotter_list->size())
	{
		return 2;
	}
	_debugUtils->isOutRange_T(*lotter_list, lastIndex, "HZ:", FILE_LINE);
	QList<int> last_lotters = lotter_list->at(lastIndex).redBall;

	for (auto obj1 : rencent_lotters)
	{
		QList<int> tmp;
		for (auto obj2 : last_lotters)
		{
// 			if (obj1 == obj2)
// 			{
// 				continue;
// 			}
			tmp.push_back(abs(obj1 - obj2));
		}
		pdNumber.push_back(getMin(tmp));
	}

	return getMax(pdNumber);
}

int SD::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int SD::getValue(Lotter inLotter) const
{
	QList<int> pdNumber;
	QList<int> rencent_lotters = inLotter.redBall;
	for (auto obj1 : rencent_lotters)
	{
		QList<int> tmp;
		for (auto obj2 : rencent_lotters)
		{
			if (obj1 == obj2)
			{
				continue;
			}
			tmp.push_back(abs(obj1 - obj2));
		}
		pdNumber.push_back(getMin(tmp));
	}

	return getMax(pdNumber);
}

int QS1::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int QS1::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj > 0 && obj <= 11)
		{
			number++;
		}
	}

	return number;
}

int QS2::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int QS2::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj > 11 && obj <= 22)
		{
			number++;
		}
	}

	return number;
}

int QS3::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int QS3::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj > 22 && obj <= 33)
		{
			number++;
		}
	}

	return number;
}

int GWGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int GWGS::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj < 10)
		{
			number++;
		}
	}

	return number;
}

int SWGS::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int SWGS::getValue(Lotter inLotter) const
{
	int number = 0;
	QList<int> lotters = inLotter.redBall;
	for (auto& obj : lotters)
	{
		if (obj >= 10)
		{
			number++;
		}
	}

	return number;
}

int BLUENUMBER::getValue(int lotter_index) const
{
	return getRand(1, 16);
}

int BLUENUMBER::getValue(Lotter inLotter) const
{
	return getRand(1, 16);
}

int BLUEZF::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUEZF::getValue(Lotter inLotter) const
{
	int lastIndex = lotter_list->indexOf(inLotter) + 1;

	if (lastIndex >= lotter_list->size())
	{
		return 2;
	}
	_debugUtils->isOutRange_T(*lotter_list, lastIndex, "HZ:", FILE_LINE);
	return abs(inLotter.greenBall - lotter_list->at(lastIndex).greenBall);
}

int BLUEDX::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUEDX::getValue(Lotter inLotter) const
{
	if (inLotter.greenBall > 8)
	{
		return 2;
	}
	return 1;
}

int BLUEQO::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUEQO::getValue(Lotter inLotter) const
{
	return inLotter.greenBall % 2 + 1;
}

int BLUEZH::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUEZH::getValue(Lotter inLotter) const
{
	return isPrimeNumber(inLotter.greenBall) + 1;
}

int BLUEV::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUEV::getValue(Lotter inLotter) const
{
	return getTailNumber(inLotter.greenBall);
}

int BLUE012L::getValue(int lotter_index) const
{
	_debugUtils->isOutRange_T(*lotter_list, lotter_index, "HZ:", FILE_LINE);
	return getValue(lotter_list->at(lotter_index));
}

int BLUE012L::getValue(Lotter inLotter) const
{
	return inLotter.greenBall % 3;
}

int YLH::getValue(int lotter_index) const
{
	return 0;
}

int YLH::getValue(Lotter inLotter) const
{
	return 0;
}
