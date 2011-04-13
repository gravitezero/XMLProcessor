#include"DeclarationAttribut.h"
#include "VisitorInterface.hpp"



DeclarationAttribut::DeclarationAttribut()
{

}

DeclarationAttribut::DeclarationAttribut(string elmt, list<Attribut*>  *attributs)
{
    //TODO
}

DeclarationAttribut::~DeclarationAttribut()
{

}

void DeclarationAttribut::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}


string DeclarationAttribut::getName()
{
    return nomAttribut;
}

list<Attribut*> *DeclarationAttribut::getAttributes()
{
    return attributs;
}
