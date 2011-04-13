#ifndef CONTENU_NON_TEXTUEL_H
#define CONTENU_NON_TEXTUEL_H


#include<list>

#include"Contenu.h"

using namespace std;

class ContenuNonTextuel : public Contenu
{
	public:
	ContenuNonTextuel();
	virtual ~ContenuNonTextuel();
	
	protected:
	list<Contenu*> contenu; 

};

#endif
