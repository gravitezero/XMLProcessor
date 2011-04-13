#ifndef CONTENUCHOIX_H
#define CONTENUCHOIX_H


#include "Contenu.h"
#include <list>

using namespace std;

class ContenuChoix : public Contenu
{
public:
    ContenuChoix();
    ContenuChoix(list<Contenu*> *l);
    virtual ~ContenuChoix();

    protected:
    list<Contenu*>  *contenus;
};

#endif // CONTENUCHOIX_H
