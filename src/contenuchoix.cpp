#include "contenuchoix.h"

ContenuChoix::ContenuChoix()
{
}



ContenuChoix::ContenuChoix(list<Contenu*>  *l)
{
    contenus = l;
}

ContenuChoix::~ContenuChoix()
{
	for (list<Contenu *>::iterator it = contenus->begin(); it != contenus->end(); ++it)
	{
		delete (*it);
	}
}


void ContenuChoix::setCardinality(std::string card)
{
	cardinalite = card;
}


list<Contenu *> *ContenuChoix::getContent()
{
	return contenus;
}
