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

string DeclarationAttribut::accept(VisitorInterface * visitor)
{
    return visitor->build(this);
}


string DeclarationAttribut::getName()
{
    return nomAttribut;
}

list<Attribut*> *DeclarationAttribut::getAttributes()
{
    return attributs;
}
