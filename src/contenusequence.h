#ifndef CONTENUSEQUENCE_H
#define CONTENUSEQUENCE_H

#include "Contenu.h"
#include <list>
using namespace std;

class ContenuSequence : public Contenu
{
public:
    ContenuSequence();
    ContenuSequence(list<Contenu*>);
    virtual ~ContenuSequence();

    protected:
    list<Contenu*>  contenus;
};


#endif // CONTENUSEQUENCE_H
