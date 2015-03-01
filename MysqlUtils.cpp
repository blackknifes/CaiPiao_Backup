#include "MysqlUtils.h"
#include "QFile"


MysqlUtils* MysqlUtils::_instance = nullptr;


MysqlUtils* MysqlUtils::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MysqlUtils();
		
	}
	return _instance;
}

MysqlUtils::MysqlUtils()
{
	init("DB.property");
}


void MysqlUtils::init(QString _file)
{
	initDatabase(_file);
}

bool MysqlUtils::close()
{
	if (db.isOpen())
	{
		db.close();
		return true;
	}
	else
	{
		qDebug() << "db has been closed!";
		return false;
	}
}

QSqlQuery MysqlUtils::excute(QString sql)
{
	QSqlQuery query;
	if (!db.isOpen())
	{
		qDebug("DB is not open!");
		return query;
	}

	query.exec(sql);

	if (query.lastError().text().size()>1)
	{
		qDebug() << query.lastError().text();
	}

	return query;
}

QSqlQuery MysqlUtils::excute(const char* format, ...)
{
	va_list argp;
	va_start(argp, format);
	QString out;
	out.vsprintf(format, argp);
	return excute(out);
}

void MysqlUtils::initDatabase(QString _file)
{	
	
	QFile file(QDir::currentPath() + "/" + _file);
	qDebug() << QDir::currentPath() + "/" + _file;

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Can't open the file!" << endl;
	}

	QTextStream inText(&file);
	QString inString = inText.readAll();
	inString.replace("\n", "");
	inString.replace("\r", "");
	QStringList DataList = inString.split(',');
	_database = DataList.at(0);
	_databaseName = DataList.at(1);
	_hostName = DataList.at(2);
	_username = DataList.at(3);
	_password = DataList.at(4);

	for (auto& obj: DataList)
	{
		qDebug() << obj;
		
	}

	db = QSqlDatabase::addDatabase(_database);
	db.setHostName(_hostName);
	db.setDatabaseName(_databaseName);
	db.setUserName(_username);
	db.setPassword(_password);
	file.close();
}

QSqlQuery MysqlUtils::excuteCall(QString _call)
{
	return excute("CALL " + _call);
}

QSqlQuery MysqlUtils::excuteCall(const char* format, ...)
{
	va_list _list;
	va_start(_list,format);
	QString _sql = "";
	_sql.vsprintf(format, _list);
	return excuteCall(_sql);
}

int MysqlUtils::excuteFunc(QString _func)
{
	 auto query = excute("SELECT " + _func);
	 
	 if (query.lastError().text().size() > 1) {
		 qDebug() << query.lastError().text();
	 }
	 query.next();
	 return query.value(0).toInt();
}

int MysqlUtils::excuteFunc(const char* format, ...)
{
	va_list _list;
	va_start(_list, format);
	QString _sql = "";
	_sql.vsprintf(format, _list);
	return excuteFunc(_sql);
}

void MysqlUtils::openDB()
{
	if (!db.open())
	{
		qDebug() << "error:" << db.lastError();
	}
	return;
}

void MysqlUtils::PrintAllSql(QSqlQuery query)
{
	if (query.lastError().text().size()>1)
	{
		qDebug() << "error:" + query.lastError().text();
	}
	else
	{
		qDebug() << query.lastError().text().size();
		qDebug() << query.numRowsAffected();
	}

	while (query.next())
	{
		QString out = "";
		size_t i = 0;
		while (!query.value(i).toString().isEmpty())
		{
			out.append(query.value(i).toString() + ",");
			i++;
		}
		out.remove(out.size() - 1, 1);
		qDebug() << out;
	}

}
