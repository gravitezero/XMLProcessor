#include "contenuchoix.h"
#include "VisitorInterface.hpp"

ContenuChoix::ContenuChoix()
{
}



ContenuChoix::ContenuChoix(list<Contenu*>  *l)
{
    contenus = l;
}

ContenuChoix::~ContenuChoix()
{

}

std::string ContenuChoix::accept(VisitorInterface* v)
{
    return v->build(this);
}


list<Contenu*> * ContenuChoix::getContents()
{
    return contenus;
}
