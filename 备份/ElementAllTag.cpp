#include "Formula.h"

QVector<QString> Formula::_signal = { "(" };
QVector<QString> MathSignal_1::_signal = { "abs:", "sqrt:" };
QVector<QString> MathSignal_2::_signal = { "%", "^" };
QVector<QString> MathSignal_3::_signal = { "*", "/" };
QVector<QString> MathSignal_4::_signal = { "+", "-" };
QVector<QString> MathNumber::_signal = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

QVector<QString> LotterTag::_signal = {
	"REDNUMBER",
	"ACS",
	"T",
	"V",
	"QGS",
	"OGS",
	"ZGS",
	"HGS",
	"DGS",
	"XGS",
	"JGJSH",
	"JGOSH",
	"HZ",
	"HV",
	"JJ",
	"HQO",
	"HYT",
	"HZH",
	"HDX",
	"JGHVH",
	"JGHVHH",
	"JGHVHV",
	"JGHVHDX",
	"JGHVHJO",
	"JGTVS",
	"JGBMJ",
	"JGMMJ",
	"HVYT",
	"HVZH",
	"HVDX",
	"HVYTS0",
	"HVYTS1",
	"HVYTS2",
	"LS",
	"LZS",
	"PD",
	"SD",
	"QS1",
	"QS2",
	"QS3",
	"GWGS",
	"SWGS",
	"BLUENUMBER",
	"BLUEZF",
	"BLUEDX",
	"BLUEQO",
	"BLUEZH",
	"BLUEV",
	"BLUE012L"
};
