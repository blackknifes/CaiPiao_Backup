#ifndef __MysqlUtils__
#define __MysqlUtils__
#include <QtCore>
#include <QtSql>

#define _sqlUT MysqlUtils::getInstance()

class MysqlUtils{
public:
	static MysqlUtils* getInstance();
	MysqlUtils();

	//调试信息输出
public:
	void PrintAllSql(QSqlQuery);

	//数据库操作接口
public:
	void openDB();
	bool close();

	//执行接口
public:
	QSqlQuery excuteCall(const char* format, ...);
	int excuteFunc(const char* format, ...);
	QSqlQuery excute(const char* format,...);
private:
	QSqlQuery excuteCall(QString);
	int excuteFunc(QString);
	QSqlQuery excute(QString);

	//初始化
private:
	void init(QString);
	void initDatabase(QString _file);

	//数据库属性
private:
	static MysqlUtils* _instance;
	QSqlDatabase db;
	QString _database;
	QString _databaseName;
	QString _hostName;
	QString _username;
	QString _password;
};
#endif
