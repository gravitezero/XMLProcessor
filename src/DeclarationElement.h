#ifndef DECLARATION_ELEMENT_H
#define DECLARATION_ELEMENT_H

#include<string>
#include<list>

//#include"Contenu.h"

using namespace std;

class Contenu;
class VisitorInterface;

class DeclarationElement 
{
	public:
	DeclarationElement();
        DeclarationElement(string nomElt, Contenu *contents);
	virtual ~DeclarationElement();
        void accept(VisitorInterface*);
        string getElementName();
        Contenu *getContents();

	protected:
	Contenu *contenus;
	string nomElement; 
	
};

#endif
