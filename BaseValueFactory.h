#ifndef __BaseValueFactory__
#define __BaseValueFactory__
#include <QtCore>

class LotterTag;
class Formula;

typedef LotterTag*(*create_ptr)(Formula*);

#define MAP_TAG(A) {#A,A::createTag}


class BaseValueFactory{
public:
	static LotterTag* createLotterTag(QString,Formula*);

private:
	static QMap<QString, create_ptr> create_list;

};
#endif
