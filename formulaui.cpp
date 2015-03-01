#include "formulaui.h"
#include "ui_formulaui.h"
#include "ValueModelBase.h"

FormulaUI::FormulaUI(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::FormulaUI)
{
	ui->setupUi(this);

	connect(ui->GenerateFormula, SIGNAL(clicked()), this, SLOT(generateFormulate()));
	connect(ui->predictBT, SIGNAL(clicked()), this, SLOT(predictNextLotter()));
	connect(this, SIGNAL(FormulaChanged(TrueFormula*)), this, SLOT(ChangedFormula(TrueFormula*)));
	connect(this, SIGNAL(initFunc()), this, SLOT(initFuncSlot()));
	
	ui->FormulaListUI->setColumnWidth(0, 527);
	ui->FormulaListUI->setShowGrid(false);
	ui->FormulaListUI->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->FormulaListUI->setEditTriggers(QTableWidget::NoEditTriggers);
	ui->FormulaListUI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	ui->LotterList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->LotterList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	
}

FormulaUI::~FormulaUI()
{
	delete ui;
}

void FormulaUI::generateFormulate()
{
	clearLotterItem();
	int eleInt = ui->eleEdit->text().toInt();
	int forInt = ui->FormulaEdit->text().toInt();
	if (eleInt <= 0 || forInt <= 0)
	{
		return;
	}

	FormulaList* tmpList = FormulaList::RandGenerate(eleInt, forInt);
	fl->addList(tmpList);

	for (auto& obj: tmpList->getList())
	{
		emit FormulaChanged(obj);
	}
	
}

void FormulaUI::predictNextLotter()
{
	int prcNum = ui->PredictNumberEdit->text().toInt();
	if (prcNum <= 0)
	{
		return;
	}
	QList<QList<int>> formula_index_list;
	QList<QString> for_text;
	for (size_t i = 0; i < prcNum; i++)
	{
		QList<int> rand_index;
		for (size_t j = 0; j < 7; j++)
		{
			int index = ValueModelBase::getRand(1, fl->size());
			rand_index.push_back(index);
		}
		formula_index_list.push_back(rand_index);
	}

	QList<Lotter> lotter_list;

	for (auto& obj: formula_index_list)
	{
		Lotter l;
		for (auto& obj2: obj)
		{
			MainWindow::currentListIndex = 0;
			int value = fl->get(obj2)->getValue();
			l.redBall.push_back(value);
			l.greenBall = value;
		}
		lotter_list.push_back(l);
	}

	QList<QString> out_list;

	for (auto& obj : lotter_list)
	{
		addLotterItem(obj);
	}
}

void FormulaUI::ChangedFormula(TrueFormula* ret)
{
	int cmax = ret->getContinusMax();
	int crecent = ret->getContinueRecent();

	qDebug() << cmax << crecent;
	addTableItem(ret->getText(),cmax,crecent);
}

void FormulaUI::initFuncSlot()
{
	for (auto& obj: fl->getList())
	{
		int cmax = obj->getContinusMax();
		int crecent = obj->getContinueRecent();

		qDebug() << cmax << crecent;
		addTableItem(obj->getText(), cmax, crecent);
	}
	updateTableItem(0, 5, 6);
}

void FormulaUI::addTableItem(QString text, int maxContinue, int recentContinue)
{
	auto flUI = ui->FormulaListUI;
	int count = flUI->rowCount();
	flUI->setRowCount(count + 1);
	flUI->setItem(count, 0, new QTableWidgetItem(text));
	if (maxContinue > -1 && recentContinue > -1)
	{
		flUI->setItem(count, 1, new QTableWidgetItem(QString::number(maxContinue)));
		flUI->setItem(count, 2, new QTableWidgetItem(QString::number(recentContinue)));
	}
}

void FormulaUI::addTableItem(QString text)
{
	addTableItem(text, -1, -1);
}

void FormulaUI::updateTableItem(int index, int maxContinue, int recentContinue)
{
	auto flUI = ui->FormulaListUI;
	int count = flUI->rowCount();
	if (index >= count)
	{
		qDebug() << "index is out range!";
		return;
	}
	
	if (maxContinue >= 0 && recentContinue >= 0)
	{
		flUI->setItem(index, 1, new QTableWidgetItem(QString::number(maxContinue)));
		flUI->setItem(index, 2, new QTableWidgetItem(QString::number(recentContinue)));
	}

}

void FormulaUI::updateTableItem(QString text, int maxContinue, int recentContinue)
{
	auto flUI = ui->FormulaListUI;
	int count = flUI->rowCount();
	int index = -1;
	for (size_t i = 0; i < count; i++)
	{
		auto obj = flUI->item(i, 0)->text();
		if (text == obj)
		{
			index = i;
			break;
		}
	}
	
	if (index >=0)
	{
		if (maxContinue >= 0 && recentContinue >= 0)
		{
			flUI->setItem(index, 1, new QTableWidgetItem(QString::number(maxContinue)));
			flUI->setItem(index, 2, new QTableWidgetItem(QString::number(recentContinue)));
		}
	}
	else
	{
		qDebug() << "is not exist this formula: " + text;
	}
}

void FormulaUI::addLotterItem(Lotter lotter)
{
	auto llUI = ui->LotterList;
	int count = llUI->rowCount();
	if (lotter.redBall.size() != 6 || lotter.greenBall <= 0 || lotter.greenBall > 16)
	{
		qDebug() << "lotter is error!";
		return;
	}
	llUI->setRowCount(count + 1);

	for (size_t i = 0; i < 6; i++)
	{
		int ball = lotter.redBall.at(i);
		llUI->setItem(count, i, new QTableWidgetItem(QString::number(ball)));
	}
	llUI->setItem(count, 6, new QTableWidgetItem(QString::number(lotter.greenBall)));
}

void FormulaUI::clearLotterItem()
{
	auto llUI = ui->LotterList;
	llUI->clearContents();
	llUI->setRowCount(0);
}

QList<Lotter> FormulaUI::getLottersFromItem()
{
	QList<Lotter> lotters;
	auto llUI = ui->LotterList;
	int count = llUI->rowCount();

	for (size_t i = 0; i < count; i++)
	{
		Lotter lotter;
		for (size_t j = 0; j < 6; j++)
		{
			lotter.redBall.push_back(llUI->item(i, j)->text().toInt());
		}
		lotter.greenBall = llUI->item(i, 6)->text().toInt();
		lotters.push_back(lotter);
	}
	return lotters;
}
