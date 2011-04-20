#include "contenusequence.h"
#include "VisitorInterface.hpp"

ContenuSequence::ContenuSequence()
{
}



ContenuSequence::ContenuSequence(list<Contenu*> *l)
{

    contenus = l;
}

ContenuSequence::~ContenuSequence()
{

}


std::string ContenuSequence::accept(VisitorInterface* v)
{
    return v->build(this);

}

list<Contenu*> * ContenuSequence::getContents()
{
    return contenus;
}
