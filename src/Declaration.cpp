#include "Declaration.h"


Declaration::Declaration()
{

}


Declaration::Declaration(AttList *a)
{
	attributs = a;
}

Declaration::~Declaration()
{
	for (AttList::iterator it = attributs->begin(); it != attributs->end(); ++it)
	{
		delete (*it);
	}
	delete attributs;
}


