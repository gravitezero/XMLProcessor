#include"DeclarationElement.h"
#include "VisitorInterface.hpp"
#include"Contenu.h"


DeclarationElement::DeclarationElement()
{

}

DeclarationElement::DeclarationElement(string nomElt, list<Contenu*>  contents)
{
    //TODO
}

DeclarationElement::~DeclarationElement()
{

}

void DeclarationElement::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}


string DeclarationElement::getElementName()
{
    return nomElement;
}

list<Contenu*> DeclarationElement::getContents()
{
    return contenus;
}
