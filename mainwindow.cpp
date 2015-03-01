#include "mainwindow.h"
#include <fstream>
#include "DataUtils.h"
#include "baseValue.h"
#include "Formula.h"
#include "DebugUtils.h"
#include "FormulaTest.h"
#include "ui_mainwindow.h"
#include "formulaui.h"

QList<Lotter> MainWindow::allLotters;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	formula_list(FormulaList::GenerateFromFile())
{	
	if (formula_list == nullptr)
	{
		formula_list = new FormulaList();
	}
	ui->setupUi(this);
	currentListIndex = 0;
	net = new QNetworkAccessManager(this);
	connect(net, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(TEST_1()));
	connect(ui->showList, SIGNAL(currentRowChanged(int)), this, SLOT(RowChanged(int)));
	connect(ui->formulaBT, SIGNAL(clicked()), this, SLOT(formulaBT()));
	net->get(QNetworkRequest(QUrl("http://f.opencai.net/utf8/ssq-50.json")));
	int i = 0;
}

void MainWindow::replyFinished(QNetworkReply* reply){
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString all = codec->toUnicode(reply->readAll());

	QString outPath = QDir::currentPath();
	outPath.append("/data.txt");
	//qDebug() << outPath;
	std::ofstream out(outPath.toStdString());

	out.close();
	reply->deleteLater();

	//qDebug() << 1;

	allLotters = getLottersFromJson(all);

	//qDebug() << 2;

	allLotters = getLotter(allLotters);

	//qDebug() << 3;

	exportCSV(allLotters);

	//qDebug() << 4;

	for (auto& obj : allLotters)
	{
		QString oout = "";
		oout.append(obj.date.toString("yyyy-MM-dd"));
		oout.append("         ");
		for (auto& obj: obj.redBall)
		{
			if (obj<10)
			{
				oout.append("0");
			}
			oout.append(QString::number(obj));
			oout.append(" ");
		}

		
		oout.append("           ");
		if (obj.greenBall<10)
		{
			oout.append("0");
		}
		oout.append(QString::number(obj.greenBall));
		oout.append("\n");
		//qDebug() << 5;
		ui->showList->insertItem(1, oout);
	}

	//qDebug() << 6;
}

MainWindow::~MainWindow()
{
	formula_list->writeToFile();
	delete ui;
}

QList<Lotter> MainWindow::getLottersFromJson(QString in){
	QList<Lotter> outLotter;

	QJsonParseError parse_error;
	QJsonDocument parse_document = QJsonDocument::fromJson(in.toUtf8(), &parse_error);
	if (parse_error.error == QJsonParseError::NoError)
	{
		if (parse_document.isObject())
		{
			QJsonObject obj = parse_document.object();
			if (obj.contains("data") && obj.find("data").value().isArray())
			{
				QJsonArray array = obj.find("data").value().toArray();
				for (auto tmp : array)
				{
					if (tmp.isObject())
					{
						auto obj = tmp.toObject();
						if (obj.contains("opencode") && obj.contains("opentime") && obj.find("opencode").value().isString() && obj.find("opentime").value().isString())
						{
							QList<int> redBall;
							int greenBall;
							QString TmpData = obj.find("opencode").value().toString();
							QString TmpDate = obj.find("opentime").value().toString();
						//	qDebug() << "debug:  date: "+TmpDate+"  lotter:"+TmpData;
							

							QStringList qsl1 = TmpData.split('+');
							
							QStringList redList = qsl1.at(0).split(',');
							greenBall = qsl1.at(1).toInt();
							for (auto& obj: redList){
								redBall.push_back(obj.toInt());
							}

							Lotter lotter = Lotter(redBall, greenBall, TmpDate.split(" ").at(0));
							qDebug() << lotter.date.toString("yyyy-MM-dd");
							outLotter.push_back(lotter);
						}
					}
				}
			}
		}
	}
	else
	{
		//qDebug() << "json is error!";
	}

	return outLotter;
}

void MainWindow::exportCSV(QList<Lotter> in)
{
	QFile file(QDir::currentPath()+"/record.csv");

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

	{

		qDebug() << "Cannot open file for writing: "

			<< qPrintable(file.errorString()) << "\n";

		return;

	}

	QTextStream out(&file);
	out << tr(TO_UTF8("期数,")) << tr(TO_UTF8("                      红        球                 ,,,,,,")) << tr(TO_UTF8("蓝球,\n"));

	
	for (auto& obj: in)
	{
		auto& redBall = obj.redBall;
		QString greeBall = QString::number(obj.greenBall);
		QString the_date = QString::number(obj.date.year()) + "-" + QString::number(obj.date.month()) + "-" + QString::number(obj.date.day());
		out << the_date + ",";
		for (auto& obj2: redBall)
		{
			out << QString::number(obj2) + ",";
		}

		out << greeBall+",\n";
	}

	file.close();

	getLotterFromCSV();
}

QList<Lotter> MainWindow::getLotterFromCSV()
{
	QList<Lotter> out;
	QFile file(QDir::currentPath() + "/record.csv");

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

	{

		qDebug() << "Cannot open file for read: "

			<< qPrintable(file.errorString()) << "\n";

		return out;

	}


	QTextStream in(&file);

	in.readLine();
	//qDebug() << 211;
	while (!in.atEnd())
	{
		QStringList splits = in.readLine().split(',');
		//qDebug() << splits.size();
		QList<int> redBallV;
		for (int i = 1; i < 7; i++)
		{
			redBallV.push_back(splits.at(i).toInt());
		}
		QString date_ = splits.at(0);
		//qDebug() << 2111;
		out.push_back(Lotter(redBallV, splits.at(7).toInt(), date_));
		//qDebug() << 2112;
	}

	return out;
}

QList<Lotter> MainWindow::getLotter(QList<Lotter> json_in)
{
	QList<Lotter> out;
	
	//qDebug() << 21;

	auto CSV_in = getLotterFromCSV();

	//qDebug() << 22;

	for (auto& obj: CSV_in)
	{
		out.push_back(obj);
	}

	//qDebug() << 23;

	for (size_t i = json_in.length()-1; i >=0 && i<json_in.length(); i--)
	{
		
		auto obj1 = json_in.at(i);
		bool condition = true;
		for (auto& obj2 : out)
		{
			condition = condition && !(obj1 == obj2);
		}

		if (condition)
		{
			out.push_front(obj1);
		}
	}
// 	for (auto& obj1: json_in)
// 	{
// 		bool condition = true;
// 		for (auto& obj2 : out)
// 		{
// 			condition = condition && !(obj1 == obj2);
// 		}
// 
// 		if (condition)
// 		{
// 			out.push_front(obj1);
// 		}
// 
// 	}

	//qDebug() << 24;

	return out;
}

void MainWindow::TEST_1()
{
	const int &index = ui->TestMath->currentIndex();
	int out;
	ValueModelBase* vmb;
	switch (index)
	{
	case 0:
		vmb = new REDNUMBER();
		break; 
	case 1:
		vmb = new ACS();
		break;
	case 2:
		vmb = new T();
		break;
	case 3:
		vmb = new V();
		break;
	case 4:
		vmb = new QGS();
		break;
	case 5:
		vmb = new OGS();
		break;
	case 6:
		vmb = new ZGS();
		break;
	case 7:
		vmb = new HGS();
		break;
	case 8:
		vmb = new DGS();
		break;
	case 9:
		vmb = new XGS();
		break;
	case 10:
		vmb = new JGJSH();
		break;
	case 11:
		vmb = new JGOSH();
		break;
	case 12:
		vmb = new HZ();
		break;
	case 13:
		vmb = new HV();
		break;
	case 14:
		vmb = new JJ();
		break;
	case 15:
		vmb = new HQO();
		break;
	case 16:
		vmb = new HYT();
		break;
	case 17:
		vmb = new HZH();
		break;
	case 18:
		vmb = new HDX();
		break;
	case 19:
		vmb = new JGHVH();
		break;
	case 20:
		vmb = new JGHVHH();
		break;
	case 21:
		vmb = new JGHVHV();
		break;
	case 22:
		vmb = new JGHVHDX();
		break;
	case 23:
		vmb = new JGHVHJO();
		break;
	case 24:
		vmb = new JGTVS();
		break;
	case 25:
		vmb = new JGBMJ();
		break;
	case 26:
		vmb = new JGMMJ();
		break;
	case 27:
		vmb = new HVYT();
		break;
	case 28:
		vmb = new HVZH();
	case 29:
		vmb = new HVDX();
		break;
	case 30:
		vmb = new HVYTS0();
		break;
	case 31:
		vmb = new HVYTS1();
		break;
	case 32:
		vmb = new HVYTS2();
		break;
	case 33:
		vmb = new LS();
		break;
	case 34:
		vmb = new LZS();
		break;
	case 35:
		vmb = new YLH();
		break;
	case 36:
		vmb = new PD();
		break;
	case 37:
		vmb = new SD();
		break;
	case 38:
		vmb = new QS1();
		break;
	case 39:
		vmb = new QS2();
		break;
	case 40:
		vmb = new QS3();
		break;
	case 41:
		vmb = new GWGS();
		break;
	case 42:
		vmb = new SWGS();
		break;
	case 43:
		vmb = new BLUENUMBER();
		break;
	case 44:
		vmb = new BLUEZF();
		break;
	case 45:
		vmb = new BLUEDX();
		break;
	case 46:
		vmb = new BLUEQO();
		break;
	case 47:
		vmb = new BLUEZH();
		break;
	case 48:
		vmb = new BLUEV();
		break;
	case 49:
		vmb = new BLUE012L();
		break;
	default:
		break;
	}
	
	out = vmb->getValue(currentListIndex);
	delete vmb;
	vmb = nullptr;

	ui->textEdit->setText(QString::number(out));

	Test1();
}

void MainWindow::RowChanged(int index)
{
	currentListIndex = ui->showList->count() - 1 - index;
}

void MainWindow::Test1()
{
	_debugUtils->TurnOn(true);

	Element* fo[50];

	for (auto& obj : fo)
	{
		obj = Formula::RandGenerate(8);

		Formula* testFormula = new Formula(obj->getText());
		testFormula->Parse();

		testFormula->Calculate(Element::DataMin);
		obj->Calculate(Element::DataMin);

		int testMin = testFormula->getValue();
		int minValue = obj->getValue();

		testFormula->Calculate(Element::DataMax);
		obj->Calculate(Element::DataMax);

		int testMax = testFormula->getValue();
		int maxValue = obj->getValue();

		qDebug() << obj->getText() << minValue << maxValue;
		ADD_DEBUG(obj->getText() + "  " + QString::number(minValue) + "  " + QString::number(maxValue));
		ADD_DEBUG("test:" + testFormula->getText() + "  " + QString::number(testMin) + "  " + QString::number(testMax));

		_formulaTest->TestFormula(obj);

	}

	_debugUtils->writeFile("log.txt");
	_debugUtils->writeAllOut();
}

void MainWindow::formulaBT()
{
	FormulaUI formula_ui;
	formula_ui.initFormula(formula_list,this);
	formula_ui.exec();
}

int MainWindow::currentListIndex = 0;

QString MainWindow::genPath = QDir::currentPath() + "/";


