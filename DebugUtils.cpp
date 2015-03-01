#include "DebugUtils.h"
#include "QFile"
#include "mainwindow.h"
#include "Element.h"

DebugUtils* DebugUtils::_DebugUtils = nullptr;

DebugUtils* DebugUtils::getInstance()
{
	if (_DebugUtils == nullptr)
	{
		_DebugUtils = new DebugUtils();
	}
	return _DebugUtils;
}

void DebugUtils::TurnOn(bool on_off)
{
	_onoff = on_off;
}

void DebugUtils::addError(QString text)
{
	_error.push_back(text);
}

void DebugUtils::addDebug(QString text)
{
	_debug.push_back(text);
}

void DebugUtils::addInfo(QString text)
{
	_info.push_back(text);
}

void DebugUtils::addWaring(QString text)
{
	_waring.push_back(text);
}

void DebugUtils::printList(QStringList list,QString before)
{
	if (_onoff)
	{
		for (auto& obj : list)
		{
			obj.push_front(before);
			qDebug() << obj;
		}
	}

}

void DebugUtils::printError()
{
	printList(_error, "Error: ");
}

void DebugUtils::printDebug()
{
	printList(_debug, "Debug: ");
}

void DebugUtils::printInfo()
{
	printList(_info, "Info: ");
}

void DebugUtils::printWaring()
{
	printList(_waring, "Waring: ");
}

void DebugUtils::printAll()
{
	printInfo();
	printDebug();
	printWaring();
	printError();
}

void DebugUtils::writeFile(QString path)
{
	if (_onoff)
	{
		QFile file(MainWindow::genPath + path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			qDebug() << "Can't open the file!" << endl;
		}
		QTextStream out(&file);
		for (auto& obj : _info)
		{
			out << "Info: " + obj + "\n";
		}

		for (auto& obj : _debug)
		{
			out << "Debug: " + obj + "\n";
		}

		for (auto& obj : _waring)
		{
			out << "Waring: " + obj + "\n";
		}

		for (auto& obj : _error)
		{
			out << "Error: " + obj + "\n";
		}
		file.close();
	}
}

void DebugUtils::isOutRange(QList<Element*> list, int index, QString out,QString file,int line)
{
	if (index < 0 || index >= list.size())
	{
		qDebug() << out + "list is out of range!";
		qDebug() << file << line;
	}
}

void DebugUtils::isOutRange(QVector<QString> list, int index, QString out, QString file, int line)
{
	if (index < 0 || index >= list.size())
	{
		qDebug() << out + "vector is out of range!";
		qDebug() << file << line;
	}
}

void DebugUtils::addOut(QString key, QString value)
{
	if (_out.contains(key))
	{
		QString out = _out[key];
		out.append("\n");
		out.append(value);
		_out.insert(key, out);
	}
	else
	{
		_out.insert(key, value);
	}
	
	
}

void DebugUtils::writeAllOut()
{
	for (auto& key: _out.keys())
	{

		if (_onoff)
		{
			QFile file(MainWindow::genPath + key+".txt");
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				qDebug() << "Can't open the file!" << endl;
				qDebug() << MainWindow::genPath + key;
			}
			QTextStream out(&file);

			out << _out[key];
			file.close();
		}
		
	}
}

