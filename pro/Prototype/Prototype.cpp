#include"Prototype.h"

int testPrototype() //test
{
	CPrototype* pItem = new CConcretePrototype1();
	CPrototype* pItem2 = pItem->Clone();
	CPrototype* pItem3 = pItem->Clone();
	delete pItem3;
	delete pItem2;
	delete pItem;

	return 0;
}