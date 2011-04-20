#ifndef DECLARATION_ELEMENT_H
#define DECLARATION_ELEMENT_H

#include<string>
#include<list>

//#include"ContgetElementNameenu.h"

using namespace std;

class Contenu;
class VisitorInterface;

class DeclarationElement 
{
	public:
	DeclarationElement();
        DeclarationElement(string n, Contenu *c);
	virtual ~DeclarationElement();
        void accept(VisitorInterface*);
        string getElementName();
        Contenu *getContent();

	protected:
	Contenu *contenu;
	string nomElement; 
	
};

#endif
