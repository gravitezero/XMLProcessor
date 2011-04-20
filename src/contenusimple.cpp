#include "contenusimple.h"
#include "DTD.h"

ContenuSimple::ContenuSimple()
{
}

ContenuSimple::ContenuSimple(std::string name, DTD * d)
{
    dtd = d;
    nom = name;

}

ContenuSimple::~ContenuSimple()
{
	delete dtd;
}


void ContenuSimple::setCardinality(std::string card)
{
	cardinalite = card;
}



std::string ContenuSimple::getName()
{
	return nom;
}
