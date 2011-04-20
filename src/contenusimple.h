#ifndef CONTENUSIMPLE_H
#define CONTENUSIMPLE_H

#include "Contenu.h"
#include "DeclarationElement.h"


class DTD;
class ContenuSimple : public Contenu
{
public:
    ContenuSimple();
    ContenuSimple(std::string , DTD*);
    std::string getName();
    std::string accept(VisitorInterface*);
    virtual ~ContenuSimple();
    DeclarationElement* getElementByName(std::string name);

protected:
    std::string nom;
    DTD * dtd;
};

#endif // CONTENUSIMPLE_H
