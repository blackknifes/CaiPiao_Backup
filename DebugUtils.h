#ifndef __DebugUtils__
#define __DebugUtils__
#include <QtDebug>
#define _debugUtils DebugUtils::getInstance()
#define ADD_ERROR(A) _debugUtils->addError(A)
#define ADD_DEBUG(A) _debugUtils->addDebug(A)
#define ADD_INFO(A) _debugUtils->addInfo(A)
#define ADD_WARING(A) _debugUtils->addWaring(A)
#define ADD_OUT(A,B) _debugUtils->addOut(A,B)

#define FILE_LINE __FILE__,__LINE__

class Element;
struct Lotter;

class DebugUtils{
public:
	void addError(QString);
	void addDebug(QString);
	void addInfo(QString);
	void addWaring(QString);

	void printList(QStringList,QString);
	void printError();
	void printDebug();
	void printInfo();
	void printWaring();
	void printAll();

	void writeFile(QString);

	void TurnOn(bool);

	void isOutRange(QList<Element*>, int, QString, QString, int);
	void isOutRange(QVector<QString>, int, QString, QString, int);

	template<class T>
	void isOutRange_T(QList<T>, int, QString, QString, int);

	void addOut(QString,QString);
	void writeAllOut();
private:
	QStringList _error;
	QStringList _debug;
	QStringList _info;
	QStringList _waring;
	QMap<QString, QString> _out;

	bool _onoff;

public:
	static DebugUtils* getInstance();
private:
	static DebugUtils* _DebugUtils;
	DebugUtils(){ _onoff = false; };
};

template<class T>
void DebugUtils::isOutRange_T(QList<T> list, int index, QString out, QString file, int line)
{
	if (index < 0 || index >= list.size())
	{
		qDebug() << out + "list is out of range! size:" + QString::number(list.size()) + "  currentIndex:" + QString::number(index);
		qDebug() << file << line;
	}
}

#endif
