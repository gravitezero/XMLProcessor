#include"DeclarationAttribut.h"
#include "VisitorInterface.hpp"



DeclarationAttribut::DeclarationAttribut()
{

}

DeclarationAttribut::DeclarationAttribut(string elmt, list<Attribut*>  *l)
{
    nomElement = elmt;
    attributs = l;
}

DeclarationAttribut::~DeclarationAttribut()
{
    for (list<Attribut *>::iterator it = attributs->begin(); it != attributs->end(); ++it)
    {
        delete (*it);
    }
}

void DeclarationAttribut::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}


string DeclarationAttribut::getName()
{
    return nomElement;
}

list<Attribut*> *DeclarationAttribut::getAttributes()
{
    return attributs;
}
