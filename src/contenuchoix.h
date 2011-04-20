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
    void setCardinality(std::string card);
    virtual ~ContenuChoix();
    list<Contenu *> *getContent();
    protected:
    list<Contenu*>  *contenus;

};

#endif // CONTENUCHOIX_H
