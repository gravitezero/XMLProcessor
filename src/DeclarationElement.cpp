#include"DeclarationElement.h"
#include "VisitorInterface.hpp"
#include"Contenu.h"
#include <iostream>

using namespace std;

DeclarationElement::DeclarationElement()
{

}

DeclarationElement::DeclarationElement(string nomElt, Contenu *contents)
{
    nomElement = nomElt;
    contenus = contents;
}

DeclarationElement::~DeclarationElement()
{

}

string DeclarationElement::accept(VisitorInterface * visitor)
{

    return visitor->build(this);
}


string DeclarationElement::getElementName()
{
    return nomElement;
}

Contenu* DeclarationElement::getContents()
{
    return contenus;
}
