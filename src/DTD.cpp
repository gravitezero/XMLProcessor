#include"DTD.h"
#include "VisitorInterface.hpp"



DTD::DTD()
{

}


DTD::DTD(Elements *declarationElements, Attributs *declarationAttributs)
{
    //TODO
}


DTD::~DTD()
{

}

void DTD::addDeclarationElement(DeclarationElement* e)
{
    declarationElements->push_back(e);
}

void DTD::addDeclarationAttributs(DeclarationAttribut* a)
{
    declarationAttributs->push_back(a);
}

void DTD::accept(VisitorInterface * visitor)
{
    for(Elements ::iterator it = declarationElements->begin(); it != declarationElements->end(); ++it)
    {
        (*it)->accept(visitor);
    }
    for(Attributs ::iterator it = declarationAttributs->begin(); it != declarationAttributs->end(); ++it)
    {
        (*it)->accept(visitor);
    }

}

