#ifndef CONTENUSIMPLE_H
#define CONTENUSIMPLE_H

#include "Contenu.h"

class DTD;
class ContenuSimple : public Contenu
{
public:
    ContenuSimple();
    ContenuSimple(std::string , DTD*);
    virtual ~ContenuSimple();

protected:
    std::string nom;
    DTD * dtd;
};

#endif // CONTENUSIMPLE_H
