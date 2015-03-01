#ifndef __CustomDefine__
#define __CustomDefine__

#define SAFE_DELETE(A)	\
do						\
{						\
	if (A != nullptr)	\
	{					\
		delete A;		\
		A = nullptr;	\
	}					\
} while (false);

#define SAFE_DELETE_VEC(A)	\
	for (auto& obj: A)		\
	{						\
		SAFE_DELETE(obj);	\
	}						\
	A.clear()

enum Formula_Type
{
	_formula_unknown = 0, _formula, _mathSignal, _mathNumber
};

//计算优先级最大值：5
#define MaxPrority 5

#define FormulaPrority 0
#define Signal_1_Prority 1
#define Signal_2_Prority 2
#define Signal_3_Prority 3
#define Signal_4_Prority 4
#define NumberPrority 6
#define MathTagPrority 7

#endif
