#include "contenusequence.h"

ContenuSequence::ContenuSequence()
{
}



ContenuSequence::ContenuSequence(list<Contenu*> *l)
{
    contenus = l;
}

ContenuSequence::~ContenuSequence()
{
	for (list<Contenu *>::iterator it = contenus->begin(); it != contenus->end(); ++it)
	{
		delete (*it);
	}
}


void ContenuSequence::setCardinality(std::string card)
{
	cardinalite = card;
}



list<Contenu *> *ContenuSequence::getContent()
{
	return contenus;
}
