#ifndef DECLARATION_H
#define DECLARATION_H

#include "commun.h"


class Declaration 
{
public : 
	Declaration();
	Declaration(AttList *a);
	virtual ~Declaration();


private : 
	AttList *attributs;

};

#endif
