#include"DeclarationElement.h"
#include "VisitorInterface.hpp"
#include"Contenu.h"


DeclarationElement::DeclarationElement()
{

}

DeclarationElement::DeclarationElement(string n, Contenu *c)
{
	nomElement = n;
	contenu = c;
	
}

DeclarationElement::~DeclarationElement()
{
	delete contenu;
}

void DeclarationElement::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}


string DeclarationElement::getElementName()
{
    return nomElement;
}

Contenu* DeclarationElement::getContent()
{
    return contenu;
}
