#include "contenusimple.h"
#include "DTD.h"
#include "VisitorInterface.hpp"

ContenuSimple::ContenuSimple()
{
}

ContenuSimple::ContenuSimple(std::string name, DTD * d)
{
    dtd = d;
    nom = name;

}

std::string ContenuSimple::getName()
{
    return nom;
}

ContenuSimple::~ContenuSimple()
{

}

std::string ContenuSimple::accept(VisitorInterface* v)

{
    return v->build(this);

}

DeclarationElement* ContenuSimple::getElementByName(std::string name){

    return dtd->getElementByName(name);
}
