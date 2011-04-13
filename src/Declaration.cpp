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
	for (AttList::const_iterator it; it = attributs->begin(); it != attributs->end(); ++it)
	{
		delete (*it);
	}
	delete attributs;
}


