#include "ValueModelBase.h"
#include <fstream>
#include <windows.h>

int ValueModelBase::getRand(unsigned int min, unsigned int max)
{
	LARGE_INTEGER t1;
	QueryPerformanceCounter(&t1);
	srand(t1.QuadPart+time(0));

	if (max == 0 && min == 0)
	{
		//qdebug() << "rand % error";
		return 0;
	}
	else if (max == 0)
	{
		max = min;
		min = 0;
	}

	return rand() % max + min;
}

int ValueModelBase::getMax(QList<int> in)
{
	int max;

	max = in.at(0);
	for (size_t i = 1; i < in.size(); i++)
	{
		if (in.at(i) > max)
		{
			max = in.at(i);
		}
	}
	return max;
}

int ValueModelBase::getMin(QList<int> in)
{
	int min;

	min = in.at(0);
	for (size_t i = 1; i < in.size(); i++)
	{
		if (in.at(i) < min)
		{
			min = in.at(i);
		}
	}
	return min;
}

QList<int> ValueModelBase::getOddNumber(QList<int> in)
{
	QList<int> odd;

	for (auto& obj: in)
	{
		if (obj%2 == 1)
		{
			odd.push_back(obj);
		}	
	}

	return odd;
}

QList<int> ValueModelBase::getEvenNumber(QList<int> in)
{
	QList<int> even;

	for (auto& obj : in)
	{
		if (obj % 2 == 0)
		{
			even.push_back(obj);
		}
	}

	return even;
}

QList<int> ValueModelBase::getPrimeNumber(QList<int> in)
{
	QList<int> prime;
	std::ifstream inStream("primeList.txt");
	std::string in_string;
	inStream >> in_string;
	
	QString in_qstring = QString(in_string.c_str());
	QStringList prime_1_10000 = in_qstring.split(',');
	int max = getMax(in);
	int endIndex = 0;
	for (size_t i = 0; i < prime_1_10000.size(); i++)
	{
		//qdebug() << prime_1_10000.at(i).toInt();
		if (prime_1_10000.at(i).toInt() >= max)
		{
			//qdebug() << i;
			endIndex = i;
			break;
		}
	}

	for (size_t i = 0; i <= endIndex; i++)
	{
		for (auto& obj: in)
		{
			if (obj == prime_1_10000.at(i).toInt())
			{
				prime.push_back(obj);
			}
			
		}
		
	}

	return prime;
}

QList<int> ValueModelBase::getCompositeNumber(QList<int> in)
{
	QList<int> prime = getPrimeNumber(in);
	QList<int> composite = in;
	for (auto& obj: composite)
	{
		if (prime.contains(obj))
		{
			composite.removeOne(obj);
			
		}
	}

	return composite;
}

bool ValueModelBase::isPrimeNumber(int in)
{
	std::ifstream inStream("primeList.txt");
	std::string in_string;
	inStream >> in_string;
	QString in_qstring = QString(in_string.c_str());
	QStringList prime_1_10000 = in_qstring.split(',');
	QString tmp_string = QString::number(in);
	return prime_1_10000.contains(tmp_string);
}

int ValueModelBase::hasContinue(int obj, QList<int> in)
{
	if (in.contains(obj+1))
	{
		return obj+1;
	}

	return 0;
}

int ValueModelBase::hasContinue(QList<int> vec, QList<int> in)
{
	int max = getMax(vec);

	return hasContinue(max, in);
}

QList<QList<int>> ValueModelBase::getContinueNumber(QList<int> in)
{
	QList<QList<int>> out;
	for (auto& obj: in)
	{
		bool has_vec = false;
		QList<int> tmp_vector;

		for (auto& obj2: out)
		{
			if (obj2.contains(obj))
			{
				tmp_vector = obj2;
				out.removeOne(obj2);
				//qdebug() << out.removeOne(obj2);
				has_vec = true;
				break;
			}
		}
		if (!has_vec)
		{
			tmp_vector.push_back(obj);
		}
		if (hasContinue(tmp_vector,in))
		{
			tmp_vector.push_back(obj + 1);
		}
		if (tmp_vector.size()>1)
		{
			out.push_back(tmp_vector);
		}
	}

	return out;
}

int ValueModelBase::getTailNumber(int in)
{
	if (in > 10)
	{
		return in % 10;
	}
	
	return in;
}

int ValueModelBase::getSum(QList<int> in)
{
	int sum = 0;
	for (auto& obj: in)
	{
		sum += obj;
	}

	return sum;
}

void ValueModelBase::Calculate(DataType type)
{
	switch (type)
	{
	case Element::DataMin:
		setValue(_min);
		break;
	case Element::DataNormal:
		setValue(getValue(MainWindow::currentListIndex));
		break;
	case Element::DataMax:
		setValue(_max);
		break;
	default:
		break;
	}
}
