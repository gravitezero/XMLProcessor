#include"DTD.h"
#include "VisitorInterface.hpp"
#include <iostream>
using namespace std;


DTD::DTD()
{
    declarationElements = new list<DeclarationElement*>() ;
}


DTD::DTD(Elements *declarationElements, Attributs *declarationAttributs)
{
    //TODO
}


DTD::~DTD()
{

}

DeclarationElement* DTD::getElementByName(string name)
{
    for(Elements::iterator it=declarationElements->begin(); it != declarationElements->end(); it++){

        if((*it)->getElementName() == name){

            return *it;
        }
    }
    return 0;
}

void DTD::addDeclarationElement(DeclarationElement* e)
{

    declarationElements->push_back(e);
}

void DTD::addDeclarationAttributs(DeclarationAttribut* a)
{
    declarationAttributs->push_back(a);
}

std::string DTD::accept(VisitorInterface * visitor)
{
    cout<<"SUPPOSONS QU'ON A LE 1ER"<<endl;

    std::string result = (*declarationElements->begin())->accept(visitor);

    /*for(Attributs ::iterator it = declarationAttributs->begin(); it != declarationAttributs->end(); ++it)
    {
        (*it)->
    }
    */
return result;
}

